n = int(input())

memo = [-1 for i in range(501)]
memo[0] = 0
memo[1] = 1
def factorial(n) :
    if n<=2 :
        memo[n]=n
        return memo[n]
    if memo[n] != -1 :
        return memo[n]
    memo[n]=n*factorial(n-1)
    return n*factorial(n-1)
    
    
ans = factorial(n)
ansnum = 0

while(ans != 0 and ans%10==0) :
    ansnum+=1
    ans//=10
print(ansnum)