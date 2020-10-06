# Exercício - Para casa

## Descrição

O exercício apresenta um código para o cálculo do fatorial de um número.

~~~c
#include <stdio.h>

int main()
{
    int i, num, j;
    printf ("Enter the number: ");
    scanf ("%d", &num );

    for (i=1; i<num; i++)
        j=j*i;

    printf("The factorial of %d is %d\n",num,j);
}
~~~

Como se pode ver no código acima, o fatorial é calculado de forma monoprocessual. O exercício proposto é a transformação do problema para um exemplo multiprocessado e comparar a resolução do exercício no caso do uso de *fork* e *clone*.

## Resolução

Para realizar o fatorial de forma multiprocessada, criou-se um processo filho que faz metade das operações matemáticas do fatorial. Para comparar o desempenho entre o *fork* e o *clone*, o exercício foi resolvido de ambos modos, sendo o [ex04_clone.c](https://github.com/lobao5670/lab01-stre/blob/main/ex04/ex04_clone.c) a resolução utilizando *clone* e o [ex04_fork.c](https://github.com/lobao5670/lab01-stre/blob/main/ex04/ex04_fork.c) a resolução utilizando *fork*.

***

### Fork

Nesta resolução onde a função *fork()* é utilizada, dois processos, pai e filho, foram criados. O pai faz a primeira metade dos cálculos do fatorial e o filho faz a segunda metade.

Para a troca de mensagens entre os dois processos foi criado um *pipe*, ferramenta previamente explicada na resolução do [**Exercício 2**](https://github.com/lobao5670/lab01-stre/tree/main/ex02). Ao finalizar os cálculos, o filho envia ao processo pai o resultado de seu cálculo utilizando o *pipe*. Logo em seguida, o pai pega o resultado gerado pelo filho e multiplica com o que ele produziu, gerando o resultado do fatorial.

***

### Clone

Já nesta resolução, onde o *clone()* é utilizado, a lógica para a utilidade do processo pai e o processo filho foi igual a da resolução anterior.

Porém, a lógica utilizada no *fork* não precisa ser replicada aqui, pois a função *clone* permite que a memória seja compartilhada, não necessitando a troca de mensagens entre os dois processos. Então, o resultado gerado pelo filho pode ser armazenado na mesma área de memória que o processo pai, facilitando o acesso pelo pai.

Portanto, enquanto o filho faz a metade dos cálculos, o pai faz o restante dos cálculos e, ao final, o pai acessa o resultado do filho e multiplica com o seu, gerando o resultado do fatorial.

***

### Conclusão

A memória compartilhada disponibilizada pelo *clone* facilita a comunicação entre os processos, não necessitando a criação de um *pipe*, como no *fork*. Logo, o *clone* se mostra tendo melhor desempenho comparado ao *fork*.
