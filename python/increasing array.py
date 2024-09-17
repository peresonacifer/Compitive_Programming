# def increasing_array(n:int, s:list):
#     t=0
#     for i in range(1, n):
#        while s[i-1] > s[i]:
#             s[i] += 1
#             t += 1
#     print(t)
# n = int(input())
# s = [int(x) for x in input().split()]
# increasing_array(n, s)


def increasing_array(n:int, s:list):
    move=0
    for i in range(1, n):
       if s[i-1] > s[i]:
            move += (s[i-1] - s[i])    
            s[i] =  s[i-1]
    print(move)
n = int(input())
s = [int(x) for x in input().split()]
increasing_array(n, s)