import sys

list = sys.stdin.readline().strip().split()

list[0]=list[0][::-1]
list[1]=list[1][::-1]

if((int)(list[0])>(int)(list[1])) :
    print(list[0])
else :
    print(list[1])
