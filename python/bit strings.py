# n = int(input())
# result = 2
# t = 1 
# while 2**t < n:
#     result *= result
#     t += 1

# result *= 2**(n - 2**(t - 1))
mod = 10**9 + 7
# print(result % mod)

n = int(input())
print(2**n % mod)