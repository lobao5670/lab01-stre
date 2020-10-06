# Exercício 2

No arquivo pid.c, mostra como se identifica o processo filho e o processo pai, onde o processo filho é o que possui número pid = 0, e o pai maior que 0.

No arquivo fork.c, percebe-se o que acontece no uso de vários forks em sequência. No caso, foram utilizados 3 forks, resultando na criação de 8 processos.

No arquivo ex02.c, mostra a comunicação entre processos pai e filho por meio de mensagens. Para isso, foi utilizado o pipe, que nada mais é do que um meio para passar a mensagem. No caso, foi passado o número 10 por esse pipe, do filho para o pai.