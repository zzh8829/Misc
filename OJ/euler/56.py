
def dig(n):
    return sum(map(int, str(n)))

max = 0

for i in range(1,101):
    for j in range(1,101):
        d=dig(i**j)
        if d > max:
            max = d
print max

