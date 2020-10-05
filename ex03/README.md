# Exercício 3

O arquivo ex03.c representa o compartilhamento de contexto entre o processo pai e filho.

Após fazer o clone, o processo pai declara um tratamento para o sinal SIGUSR1 e o processo filho executa a função threadFunction(). 
Na função threadFunction(), o processo filho manda o sinal SIGUSR1 para seu próprio pid e consegue executar a função associada ao sinal com sucesso.

Esse comportamento não ocorreria se a flag CLONE_SIGHAND não tivesse sido utilizada, pois a declaração de uma função para o sinal foi definida após o clone.