Aluno: Maxwell Oliveira Dos Reis 
Data: 26/02/2021

Descrição do trabalho:
    O trabalho foi realizado pensando em converter os bits recebidos para binário e depois processar os dados. Uma maneira mais eficaz de fazer a mesma coisa seria usar os operadores binários, porém optei por não fazer dessa forma. O código está comentado e foi testado com arquivos jpeg, jpg, ods, odt, pdf, png e txt com auxílio do comando base64 diretamente no terminal do linux. 
    Tive algumas dificuldades durante a criação do encode, pois não pensei que seria necessário usar unsigned char. O decode também me deu um certo trabalho, mas foi por pequenos erros de lógica.
    Em uma tentativa de evitar código repetido minizar o tamanho total, adicionei um módulo chamado "utilitarios" que contém funções que tanto a codificação quando a decodificação utilizam.

Como compilar:

    1) Foi dado um Makefile, então basta usar o terminal na pasta e usar o comando make para gerar o executável.

    2) Após gerar o executável, basta executar o arquivo com "./base64", junto com o modo de entrada "-c" para encode e "-d" para decode seguido do caminho dos dois arquivos. Por exemplo
    ./base64 -c entrada/cat.png gato.txt
    ./base64 -d gato.txt cat.png
