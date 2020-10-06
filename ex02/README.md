# Exercício 2 - Comunicação entre processos

## Descrição

O **exercício 2** apresenta as funções relacionadas a criação de processos. Ele primeiramente apresenta as principais funções voltadas aos processos da linguagem C:

* ***fork()***;

* ***wait()***;

* ***exit()***.

Em seguida, ele apresenta um código em C que exemplifica o uso das funções apresentadas. Esse código é encontrado no arquivo [pid.c](https://github.com/lobao5670/lab01-stre/blob/main/ex02/pid.c).

O código tem o intuito de mostrar como os processos se bifurcam e como eles podem ser identificados como pai ou filho.

O próximo código que o exercício apresenta, [fork.c](https://github.com/lobao5670/lab01-stre/blob/main/ex02/fork.c), é uma sequência de *forks* e *prints*. Ele tem como propósito mostrar o encadeamento da criação de processos filhos.

Ao final, o exercício pede para que seja criado um exemplo em que os processos pai e filho trocam mensagens entre si. A resolução se encontra no arquivo [ex02.c](https://github.com/lobao5670/lab01-stre/blob/main/ex02/ex02.c).

***

## Resolução

***

### **Pid.c**

Para identificar o processo filho e o processo pai, é necessário se antenar ao valor do **pid**, pois o valor do **pid** igual a zero indica que o processo é filho.

~~~c
if (pid == 0) {
    printf("I am the child %d\n", pid);
    execlp("/bin/ls", "ls", NULL);
}
~~~

No código acima, devido ao fato de que o valor do **pid** é zero, o trecho dentro do *if* será executado pelo filho. Diferente do código a seguir:

~~~c
if (pid > 0) {
    printf("i am the parent %d\n", pid);
    wait(NULL);

    printf("Child complete\n");
}
~~~

Nesse código, o *if* faz a verificação se o **pid** é maior que zero. Logo, p trecho dentro do *if* será executado pelo pai.

***

### **Fork.c**

No arquivo **fork.c**, percebe-se o que acontece no uso de vários *forks* em sequência. A cada uso de um *fork*, um processo filho é criado. Como consequência, o filho gerado de um *fork* gerará outro filho no *fork* seguinte.

1. Pai
    1. Filho 1
    1. Filho 2
    1. Filho 4
1. Filho 1
    1. Filho 3
    1. Filho 5
1. Filho 2
    1. Filho 6
1. Filho 3
    1. Filho 7
1. Filho 4
1. Filho 5
1. Filho 6
1. Filho 7

No total são 3 *forks*. No primeiro, o Pai gera o Filho 1. So segundo *fork*, o Pai gera o Filho 2 e o Filho 1 gera o Filho 3. E no último *fork*, o Pai gera o Filho 4, o Filho 1 gera o Filho 5, o Filho 2 gera o Filho 6, e o Filho 3 gera o Filho 7. Totalizando 8 processos criados.

***

### **Ex02.c**

Para exemplificar a comunicação entre processos pai e filho por meio de mensagens foi utilizado o *pipe*. O *pipe* é um modo de comunicação entre processos. Ele conecta a entrada de um processo com a saída de outro.

No exemplo desenvolvido, o filho apenas passa o número 10 para o pai. O trecho de código abaixo tem a função de fazer isso.

~~~c
int n = 10;

close(fd[READ]);
write(fd[WRITE], &n, sizeof(n));
close(fd[WRITE]);
~~~

Da mesma forma, o pai tem que executar um código para receber a mensagem.

~~~c
int n;

close(fd[WRITE]);
read(fd[READ], &n, sizeof(n));
close(fd[READ]);
~~~

A diferença entre os dois trechos de código é que o filho utiliza o canal de escrita, **WRITE**, e o pai utiliza o canal de leitura, **READ**.
