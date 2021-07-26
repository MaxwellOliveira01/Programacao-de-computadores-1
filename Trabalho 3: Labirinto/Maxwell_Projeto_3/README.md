Aluno: Maxwell Oliveira Dos Reis 11/03/2021

Descrição:

Este projeto  tem objetivo  de  encontrar  a saída  para um labirinto escrito  com espaços ' ' e paredes '#'. A ideia utilizada foi de DFS. Portanto, o caminho encontrado pode não ser o menor/melhor possível. O código se limita a encontrar um caminho possível entre a entrada e a saída. Não tive muitas dificuldades em escrever o trabalho, pois já conhecia a técnica necessária.

Como compilar:

1) Foi disponibilizado um Makefile, então utilize o comando make e será criado um arquivo executável chamando main. O makefile irá criar alguns arquivos .o, basta executar o comando make clean que serão apagados.

2) Execute o executável criado passando o caminho do arquivo de entrada seguido do caminho de arquivo de saída por linhas de comando. Exemplos:
    ./main entrada1.txt saida1.txt
    ./main ../casos/in1.txt ../saida/out1.txt