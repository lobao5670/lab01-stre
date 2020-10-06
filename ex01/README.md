# Exercício 1 - Processos

## Descrição

O **exercício 1** busca trazer o conceito inicial do que é um processo. Para entender a importância do processador, ele pede para que um programa seja escrito de forma que o mesmo consuma o máximo possível do processador.

## Resolução

Para que o processador seja levado ao limite, é necessário que várias cálculos sejam requisitados à máquina.

Para isso, um *loop* utilizando a estrutura *for* foi utilizado. O *loop* só tem a função de contar até 1 milhão e mostrar o número no console.

~~~c
for (int i = 0; i < 1000000; i++) {
    printf("%d\n", i);
}
~~~

Ao colocar um *loop* para contar até 1 milhão, o processador é consumido o máximo possível.
