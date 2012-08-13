def zc(n):
    return pow(n,n,10**10)

m=0
for i in range(1,1001):
    m+=zc(i)

print m%(10**10)
