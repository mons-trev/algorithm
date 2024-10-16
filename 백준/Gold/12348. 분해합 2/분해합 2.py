n = int(input())

def decomsum(n) :
    
    tmp=n
    num = 1

    while(tmp//10) : # 최대 18번
        num+=1
        tmp=tmp//10
    
    for i in range(n-num*9, n-num+1) : # 최대 18*9 = 162번
        
        tmpans=i
        tmp2= i
        while(tmp2) :
            tmpans+=(tmp2%10)
            tmp2=tmp2//10
            if(tmpans > n) :
                break
        if(tmpans==n) :
            return i
    
    return 0
    
print(decomsum(n))