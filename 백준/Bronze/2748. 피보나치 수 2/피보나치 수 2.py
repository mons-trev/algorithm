m = [-1 for _ in range(91)]

def fibo(n) :
    if(n==0) :
        return 0
    if(n==1) :
        return 1
    if(m[n]!=-1) :
        return m[n]
    m[n]=fibo(n-1) + fibo(n-2)
    return m[n]

n = int(input())

print(fibo(n))
