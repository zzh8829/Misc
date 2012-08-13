def c(n,m):
    a=1
    b=1
    for i in range(n+1-m,n+1):
        a=a*i
    for j in range(1,m+1):
        b=b*j
    return a/b

ans = c(40,20)
print ans
