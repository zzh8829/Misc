fib=[1,1]

for i in range(2,20002):
    fib.append(fib[i-1]+fib[i-2])
    if len(str(fib[i]))>=1000:
        print i+1
        break
