from random import randint as r

f = open("in","w")

n = r(10,110)
m = r(10,110)

arr  = []
posi = [' ', ' ', ' ', '#']

for i in range(n):
    x = []
    for j in range(m):
        x.append(posi[r(0,len(posi)-1)])
    arr.append(x)

arr[0][1] = arr[n-1][m-2] = ' '

f.write(str(n)+" "+str(m)+"\n")
for i in range(n):
    for j in range(m):
        f.write(arr[i][j])
    f.write('\n')

f.close()