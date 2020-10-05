# Exercício 2

No arquivo pid.c, mostra como se identifica o processo filho e o processo pai, onde o processo filho é o que possui número pid = 0, e o pai maior que 0.

No arquivo fork.c, percebe-se o que acontece no uso de vários forks em sequência. 
No caso, foram utilizados 3 forks, resultando na criação de 8 processos.

No arquivo ex02.c, mostra a comunicação entre processos pai e filho por meio de mensagens.
Para controlar o fluxo das mensagens foram utilizados sinais e sleep() para esperar alguma emissão de sinais.

O trecho do código "signal(SIGUSR1, filho_fim);" indica que quando o processo receber um sinal do tipo SIGUSR1 ele irá executar a função filho_fim.

O trecho "kill(pid, SIGUSR1);" é quando o sinal é enviado pelo pai para o filho, então ele executará a função filho_fim.