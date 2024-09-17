def gray_code (n):
    l_1 = ["00", "01", "11", "10"]
    l_2 = ["0", "1"]
    temp = []
    l_3 = l_1.copy()
    if n % 2 :
        if n == 1:
            return l_2
        else:
            m = (n - 1) // 2
            for i in range(2):
                for j in range(4):
                    temp.append(l_2[i] + l_3[j]) 
                l_3 = l_3[::-1]                    
            l_3 = temp
            temp = []
            while m - 1:
                for i in range(4):
                    for j in range(len(l_3)):
                        temp.append(l_1[i] + l_3[j]) 
                    l_3 = l_3[::-1]
                l_3 = temp
                temp = []
                m -= 1
            return l_3            


    else:
        m = n // 2 
        if m > 1:
            while m - 1:
                for i in range(4):
                    for j in range(len(l_3)):
                        temp.append(l_1[i] + l_3[j]) 
                    l_3 = l_3[::-1]
                l_3 = temp
                temp = []
                m -= 1
            return l_3
        
        else:
            return l_1



n = int(input())
print("\n".join(gray_code(n)))