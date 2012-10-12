x=int(raw_input())
n=int(raw_input())
m=[99999 for i in range(x+1)]
m[0] = 0
for i in range(n):
    t = int(raw_input())
    for j in range(t,x+1):
        if m[j-t]+1 < m[j]:
            m[j]=m[j-t]+1
print m[x]
