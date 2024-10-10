n = int(input())

m = [0 for _ in range(46)]

def fibo(now) :
    if(now <= 1) :
         m[now] = now
         return now
    if m[now] != 0 :
        return m[now]
    else :
        m[now] = fibo(now-1)+fibo(now-2)
    return m[now]
    
print(fibo(n))