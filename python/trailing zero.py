def trailing_zero(n):
    zero_n = 0
    while n >= 5:
        n //= 5
        zero_n += n
    
    return zero_n
n = int(input())
print(trailing_zero(n))  
