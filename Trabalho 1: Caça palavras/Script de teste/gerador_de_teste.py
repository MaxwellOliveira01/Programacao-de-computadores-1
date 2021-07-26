from random import randint as r

def gera_palavra():
    p = ""
    tam = r(1,15)
    for j in range(tam):
        p += chr(r(65,65+26-1))
    return p

def gera_direcao():
    return r(1,100)%4

def gera_sentido():
    return r(1,100)%2

def posicao_livre(mapa,dir,i,j,tam):
    di = [0,1,1,1]
    dj = [1,0,1,-1]

    for _ in range(tam):
        if(i < 0 or j < 0 or i >= 80 or j >= 80 or mapa[i][j] != '.'):
            return False

        i += di[dir]
        j += dj[dir]

    return True

def add_no_mapa(mapa,palavra,dir,sen):
    if sen:
        palavra = palavra[::-1]

    i, j, p = 0, 0, 0
    di = [0,1,1,1]
    dj = [1,0,1,-1]

    while True:
        i,j = r(-1,80),r(-1,80)

        if(posicao_livre(mapa,dir,i,j,len(palavra))):
            break

    for _ in range(len(palavra)):
        mapa[i][j] = palavra[p]
        i += di[dir]
        j += dj[dir]
        p += 1
        
mapa = []
palavras = []
quant = 10

for _ in range(80):
    mapa.append(['.']*80)

for _ in range(quant):
    palavra = gera_palavra()
    dir = gera_direcao()
    sen = gera_sentido()
    add_no_mapa(mapa,palavra,dir,sen)
    palavras.append(palavra)

print(80,quant)
for i in palavras:
    print(i)
for i in mapa:
    for j in i:
        print(j,end="")
    print()
