# def two_sets(n):
#     sequence_1 = set()
#     sequence_2 = set()
#     mid = (1 + n) // 2
#     if n % 2 == 0:
#         pairs = 2*mid + 1 
#         if n % 4 :
#             print("NO")
#         else:
#             for i in range(1, n//2 + 1):
#                 if i <= n // 4 :
#                     sequence_1.update({i, pairs - i})
#                 else:
#                     sequence_2.update({i, pairs - i})

#             print("YES")
#             print(len(sequence_1))
#             print(*sequence_1)
#             print(len(sequence_2))
#             print(*sequence_2)

#     else:
#         pairs = 2*mid
#         if ((n - 1) // 2) % 2 :  
#             print("NO")
#         else:  
#             for i in range(1, n // 2 + 1):
#                 if (pairs - i) - i == mid:
#                     sequence_1.update({i, mid})
#                     sequence_2.update({pairs - i})
#                     continue
#                 if i <= n // 4 :
#                     sequence_1.update({i, pairs - i})
#                 else:
#                     sequence_2.update({i, pairs - i})
#             print("YES")
#             print(len(sequence_1))
#             print(*sequence_1)
#             print(len(sequence_2))
#             print(*sequence_2)

# n = int(input())
# two_sets(n)



n = int(input())
if (n * (n + 1) // 2) % 2:
    print("NO")
else:
    print("YES")
    s1, s2 = [], []
    if n % 4 == 0:
        for i in range(1, n//2 + 1):
            if i % 2 == 0:
                s1.append(i)
                s1.append(n + 1 - i)
            else:
                s2.append(i)
                s2.append(n + 1 - i)
    else:
        s1 = [1, 2]
        s2 = [3]
        for i in range(4, n+1):
            if (i - 3) % 4 < 2:
                s1.append(i)
            else:
                s2.append(i)
    print(len(s1))
    print(*s1)
    print(len(s2))
    print(*s2)
