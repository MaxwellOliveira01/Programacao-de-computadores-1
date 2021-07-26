from os import close

def conta_adj(mapa,i,j):
    di = [0,0,1,-1,-1,1,-1,1]
    dj = [1,-1,0,0,-1,1,1,-1]

    c = 0
    for p in range(8):
        iAt, jAt = i + di[p], j + dj[p]
        if iAt >= 0 and jAt >= 0 and iAt < len(mapa) and jAt < len(mapa[0]) and mapa[iAt][jAt] == '@':
            c+=1
    return c


mapa_ori = []
mapa = []

f = open("in","r")
n,m = [int(i) for i in f.readline().split()]
for i in range(n):
    mapa_ori.append(f.readline()[:m])

temp = open("dj","r")
q = int(temp.readline())

if q != 1:
    print("Labirinto sem solução.")
    exit()

r = open("out","r")
for x in range(n):
    try:
        mapa.append(r.readline()[:m])
    except:
        print("Solução não encontrada")
        exit()

if conta_adj(mapa,0,1) == 0 or conta_adj(mapa,n-1,m-2) == 0 and q == 0:
    print("Labirinto sem solução e nada printado, ok.")
    exit()

for i in range(n):
    for j in range(m):
        if mapa[i][j] == '@':
            cont = conta_adj(mapa,i,j)
            if cont == 0:
                print("Fail, na posição [{}][{}] não há @'s adjacentes.".format(i,j))
                exit()
            if mapa_ori[i][j] != ' ':
                print("Fail, a parede da posição [{}][{}] foi atravessada.".format(i,j))
                exit()

if mapa[n-1][m-2] != "@":
    print("Solução não encontrada")
else:
    print("Ok")

r.close()
f.close()
temp.close()