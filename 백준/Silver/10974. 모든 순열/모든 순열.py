n = int(input())

a = []

def rec(n, a, b) :
    if (n==b) :
        for i in a :
            print(i, end = ' ')
        print()
    for i in range(1, n+1) :
        if i not in a:
            a.append(i)
            rec(n, a, b+1)
            a.pop()
     
rec(n, a, 0)