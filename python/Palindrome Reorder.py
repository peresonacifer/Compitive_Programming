# def palindrome_reorder(s : str):
#     x = set(s)
#     y = tuple(s)
#     result = tuple()
#     old_n = 0
#     mid_c = tuple()
#     for i in x:
#         z = y.count(i)
#         if len(y) % 2:
#             if z % 2:
#                 old_n += 1
#                 if old_n > 1:
#                     return "NO SOLUTION"
#                 result += tuple(i)*((z-1)//2)
#                 mid_c = tuple(i)
#             else:
#                 result += tuple(i)*(z//2)
            
#         else:
#             if z % 2:
#                 return "NO SOLUTION"
#             else:
#                 result += tuple(i)*(z//2)
#     result_2 = result[::-1]
#     result += mid_c
#     result += result_2
    
#     return result


# str1 = input() 
# print("".join(palindrome_reorder(str1)))
def palindrome_reorder(s : str):
    x = set(s)
    y = list(s)
    result = []
    old_n = 0
    mid_c = [""]
    for i in x:
        z = y.count(i)
        if len(y) % 2:
            if z % 2:
                old_n += 1
                if old_n > 1:
                    return "NO SOLUTION"
                result += i*((z-1)//2)
                mid_c = i
            else:
                result += i*(z//2)
            
        else:
            if z % 2:
                return "NO SOLUTION"
            else:
                result += i*(z//2)
    result_2 = result[::-1]
    result += mid_c
    result += result_2
    
    return result


str1 = input() 
print("".join(palindrome_reorder(str1)))