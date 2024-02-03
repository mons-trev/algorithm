

def bt(idx) :
    if (idx >= n) :
        global ans
        ans=ans+1
        return
    for i in range(0,n):
        if (vcol[i] or vld[(idx-i)+15] or vrd[idx+i]) : continue
        else : 
            vcol[i] = True
            vld[idx - i + 15] = True
            vrd[idx + i]=True
            bt(idx + 1)
            vcol[i] = False
            vld[idx - i+15] = False
            vrd[idx + i] = False


n=int(input());

vcol = [False]*16
vrd = [False]*31
vld = [False]*31
ans = 0

bt(0)
print(ans)