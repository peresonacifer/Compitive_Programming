def fuc(s, ind_0, idx_1, idx_2):
    
    while idx_1 != ind_0:
        rep = set()
        rep.add(s[idx_1])
        while idx_2 <= len(s) - 1:  
            
            if s[idx_2] in rep:
                idx_2 += 1
                continue
            else:
                rep.add(s[idx_2]) 
                s.insert(idx_1, s.pop(idx_2))
                result[0] += 1
                result.append(''.join(s))
                fuc(s, idx_1, len(s) - 2, len(s) - 1 )
                s.insert(idx_2, s.pop(idx_1))
                idx_2 += 1
        idx_1 -= 1
        idx_2 = idx_1 + 1
    return




result = [1]
s = list(input())
s.sort()
result.append(''.join(s))
fuc(s, -1, len(s) - 2, len(s) - 1)
print("\n".join(map(str, result)))