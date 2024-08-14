Projeto Torre de Hanói em C++
Este projeto implementa a solução clássica para o problema da Torre de Hanói utilizando a linguagem C++. O objetivo do problema é mover uma torre de discos de um pino para outro, seguindo regras específicas.

Descrição do Problema
A Torre de Hanói é um quebra-cabeça matemático que consiste em três pinos e uma série de discos de diferentes tamanhos. O objetivo é mover todos os discos do pino inicial (origem) para o pino final (destino), utilizando um pino intermediário, seguindo as seguintes regras:

Mover um disco por vez: Apenas um disco pode ser movido de um pino para outro a cada movimento.
Discos maiores não podem ficar sobre discos menores: Em qualquer momento, um disco maior não pode ser colocado sobre um disco menor.
Utilização de um pino intermediário: É permitido usar o pino intermediário para auxiliar na movimentação dos discos.
Estrutura do Código
O código em C++ resolve o problema utilizando uma abordagem recursiva. A função principal do programa implementa a solução da Torre de Hanói de forma simples e eficiente.

Exemplo de Execução
Ao executar o programa, o usuário define o número de discos a serem movidos, e o programa exibe o passo a passo das movimentações necessárias para transferir todos os discos do pino de origem para o pino de destino, seguindo as regras do problema.

Características Técnicas
Linguagem: C++
Paradigma: Programação Recursiva
Complexidade: O algoritmo resolve o problema em O(2^n - 1) movimentos, onde n é o número de discos.
