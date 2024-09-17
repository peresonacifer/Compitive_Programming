t = 0
result = []
def fuc_hanoi(n, a, c, b):
    global t , result
    if n == 1:
        t += 1
        result.extend([a, c])
    else:
        fuc_hanoi(n-1, a, b, c)
        t += 1
        result.extend([a, c])
        fuc_hanoi(n-1, b, c, a)
    

n = int(input())
fuc_hanoi(n, 1, 3, 2)
print(t)
for i in range(0,len(result),2):
    print(result[i], result[i+1])