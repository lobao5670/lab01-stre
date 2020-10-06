# Exercício 3 - *Threads*

## Descrição

O tema abordado nesse exercício é a criação de *threads* utilizando a função ***clone()***, que nada mais é do que um ***fork()*** que mantém uma área da memória compartilhada entre os processos. A função ***clone()*** possui 4 argumentos na sua chamada:

1. Um ponteiro para uma função *fn* que é executada no momento da criação do processo;

2. O local e quantidade de memória a ser utilizada;

3. As *flags* que determina os tipos de recursos a serem compartilhados;

4. O argumento que será passado para função *fn*.

A tabela a seguir mostra alguns exemplos de *flags*.

*Flag*        | Significado
---------     | ------
CLONE_FS      | Sistema de arquivos é compartilhado
CLONE_VM      | Espaço de memória é compartilhado
CLONE_SIGHAND | Tratamento de sinais é compartilhado
CLONE_FILES   | Os arquivos são compartilhados

Após apresentar o conteúdo, o exercício pede para que seja criado um exemplo que represente a troca de informações de contexto entre a *thread* e o processo pai.

## Resolução

O arquivo **ex03.c** possui o exemplo que foi pedido para ser criado. No exemplo desenvolvido foi utilizado o compartilhamento de tratamento de sinal para mostrar o comportamento. O código criado foi baseado no exemplo apresentado no exercício.

Após fazer o *clone*, o processo pai declara um tratamento para o sinal SIGUSR1, onde é chamada a função ***funcaoCompartilhada*** que apenas mostra o *pid* do processo.

~~~c
signal(SIGUSR1, funcaoCompartilhada);
~~~

Na chamada da função *clone*, a função *threadFunction()* continua sendo a função argumento para o *clone*, porém houveram alterações na função.

~~~c
int threadFunction(void *argument)
{
    sleep(1);
    printf("Processo filho: %d\n", getpid());
    kill(getpid(), SIGUSR1);
    printf("child thread exiting\n");
    return 0;
}
~~~

O que a função *threadFunction* faz agora de diferente é mandar o sinal **SIGUSR1** para seu próprio *pid*. Como resultado, a função associada a esse sinal, a ***funcaoCompartilhada***, é chamada. Esse comportamento só é possível por estar utilizando *clone* ao invés de *fork* e por causa da *flag* **CLONE_SIGHAND**, pois ela compartilha como os sinais são tratados entre os processos.
