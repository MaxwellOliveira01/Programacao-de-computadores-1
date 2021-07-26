cd ../Maxwell_Oliveira_Projeto_PC1/
make
make clean

for _ in {1..100}
do
    cd ../Script\ de\ teste
    python3 gerador_de_teste.py python3 > teste.txt
    cd ../Maxwell_Oliveira_Projeto_PC1
    ./main < ../Script\ de\ teste/teste.txt > saida.txt
    mv saida.txt ../Script\ de\ teste

    cd ../Script\ de\ teste

    cont=0
    input="teste.txt"

    while IFS= read -r line
    do
        ((cont++))
        if [ $cont -gt 11 ]
        then
            echo $line >> saida.txt
        fi
     
    done < "$input"

    python3 corrige_saida.py < saida.txt

done