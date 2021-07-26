cont = 0
pala = {}
mapa = []

for j in range(10):
    p = input().split()
    pala[p[0]] = p[1:]

for j in range(80):
    mapa.append(input())

for j in pala:
    temp = ""
    
    for i in pala[j]:
        temp_i = i.replace("(","").replace(")","").split(',')
        x = int(temp_i[0])
        y = int(temp_i[1])
        temp += mapa[x][y]
    if(temp != j and j != temp[::-1]):
        print("Erro encontrado! palavra:",j," encontrado: ",temp)
        cont+=1

if cont == 0:
    print("Sucesso!")
else:
    print("Wrong answer! Erros: ", cont)



