f, e = map(int, input().split())
era = [0 for i in range(0, e+1)]
def find(f,e) :

    for i in range(2,e+1) :
        if(era[i]==1) : 
            continue
        if i>=f :
            print(i)
        for j in range(i**2, e+1, i) :
            era[j]=1
            
find(f,e)