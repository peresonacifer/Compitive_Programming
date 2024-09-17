def two_knight(k):
    result = []
    for i in range(1, k+1):
        if i == 1:
            result.append(0)    
        elif i == 2:
            result.append(combination(i**2))
        else:
            #兩個騎士的可能位置
            possible = combination(i**2) 
            
            x = (i-2)**2  #此時棋盤的九宮格數
            knight_attack = 2*4*x   #騎士對撞
            repeatition = (i-3)*(i-2)*2*2 #重複算的
            ans = possible - (knight_attack - repeatition)    
            result.append(ans)

    return result



def combination (k):  
    if k >= 2:
        result = k*(k-1)//2
        return result
    else:
        return None


n = int(input())
print("\n".join(map(str, two_knight(n))))