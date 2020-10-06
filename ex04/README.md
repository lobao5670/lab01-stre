# Exercício para casa

Para realizar o fatorial de forma multiprocessada, criou-se um processo filho que faz metade das operações matemáticas do fatorial.

Na resolução utilizando o fork(), referente ao arquivo ex04_fork.c, foram separados em dois processos, pai e filho, onde o pai faz a primeira metade dos cálculos e o filho faz a segunda metade. Foi criado também um pipe para fazer a troca de mensagens entre os dois processos. Ao finalizar os cálculos, o filho envia ao processo pai o resultado de seu cálculo e em seguida, o pai pega o resultado e multiplica com o que ele produziu, gerando o resultado do fatorial.

Já na resolução utilizando o clone(), referente ao arquivo ex04_clone.c, a separação dos processos foi igual. Porém, ao invés do pipe, o clone permitiu que a memória fosse compartilhada, não necessitando a troca de mensagens entre os dois processos.

Como no clone não se fez necessária a troca de mensagens entre os processos, ele se mostra tendo melhor desempenho comparado ao que utiliza o fork.
