m = [0 for _ in range(100000)]

n = int(input())
m[0] = 0
m[1] = 1
for i in range(2, n+1) :
    m[i] = m[i-2] + m[i-1]

print(m[n])