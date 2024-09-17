# def number_spiral(a, b):
#     c = max(a, b)
#     l = [x for x in range(c**2, c**2-(2*c-1), -1)]
#     if c%2 == 1:
#         if a>b:
#             print(l[-b])
#         else:
#             print(l[a-1])
#     else:
#         if a>b:
#             print(l[b-1])
#         else: 
#             print(l[-a])

#     return None

# t = int(input())
# s=[]
# while t != 0:
#     s += [int(x) for x in input().split()]
#     t -= 1

# while s:
#     number_spiral(s[0], s[1])
#     del s[0], s[0]
def number_spiral(y, x):
    if y >= x:
        if y % 2 == 1:
            return y**2 - 2*(y-1) + x - 1  # 行數奇數，從下往上
        else:
            return y**2 - x + 1  # 行數偶數，從上往下
    else:
        if x % 2 == 1:
            return x**2 - y + 1 # 列數奇數，從左往右
        else:
            return x**2 - 2*(x-1) + y - 1 # 列數偶數，從右往左

# 讀取輸入
t = int(input())
results = []
for _ in range(t):
    y, x = map(int, input().split())
    results.append(number_spiral(y, x))

# 輸出結果
print("\n".join(map(str, results)))
