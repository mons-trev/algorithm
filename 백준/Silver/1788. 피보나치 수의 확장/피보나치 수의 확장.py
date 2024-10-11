m_pos = [0 for _ in range(1000001)]
m_neg = [0 for _ in range(1000001)]

# 아놔 recursion error

m_pos[0]=m_neg[0]=0
m_pos[1]=m_neg[1]=1

def fib_pos(n) :
    for i in range(2, n+1) :
        m_pos[i] = (m_pos[i-2] + m_pos[i-1])%1000000000
    return m_pos[n]

def fib_neg(n) :
    for i in range(2, n+1) :
        tmp = (m_neg[i-2] - m_neg[i-1])

        if tmp < 0 :
            m_neg[i] = -1 * (abs(tmp) % 1000000000)
        else :
            m_neg[i] = tmp % 1000000000
    return m_neg[n]

n = int(input())
if(n>0) :
    print('1')
    print(fib_pos(n))
else :
    ans = fib_neg(-n)
    if ans < 0 :
        print('-1')
    if ans == 0:
        print('0')
    if ans > 0:
        print('1')
    print(abs(ans))
    