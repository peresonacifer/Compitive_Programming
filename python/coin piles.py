# def coin_piles(a, b):
#     if a == 0 and b == 0:
#         return "YES"
#     elif (a + b) % 3 or a == 0 or b == 0:
#         return "NO" 
#     else:
#         if max(a, b) / min(a, b) > 2:
#             return "NO"
#         else:
#             return "YES"


# n = int(input())
# result = []
# for _ in range(n):
#     a, b = map(int, input().split())
#     result.append(coin_piles(a, b))

# print("\n".join(result))


def coin_piles(a, b):
    # 檢查兩個條件
    if (a + b) % 3 == 0 and min(a, b) * 2 >= max(a, b):
        return "YES"
    return "NO"

n = int(input())
result = []
for _ in range(n):
    a, b = map(int, input().split())
    result.append(coin_piles(a, b))

print("\n".join(result))


# import sys

# # 使用 sys.stdin 和 sys.stdout 進行更快的輸入輸出
# input = sys.stdin.read
# output = sys.stdout.write

# def can_empty_piles(a, b):
#     # 檢查條件
#     if (a + b) % 3 == 0 and min(a, b) * 2 >= max(a, b):
#         return "YES"
#     return "NO"

# # 讀取所有輸入
# data = input().splitlines()
# t = int(data[0])  # 第一行是測試數量
# results = []

# # 處理每組測試數據
# for i in range(1, t + 1):
#     a, b = map(int, data[i].split())
#     results.append(can_empty_piles(a, b))

# # 一次性輸出所有結果
# output("\n".join(results) + "\n")

