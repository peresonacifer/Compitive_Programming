def my_sort(digits, n, s):
    times = 0
    while (digits < n):
        for i in range(digits, 0, -1):
            if s[i] < s[i - 1]:
                s[i], s[i - 1] = s[i - 1], s[i]
                times += 1
            else: break
        digits += 1
    
    return times

n = int(input())
s = [int(x) for x in input().split()]
print(my_sort(1, n, s))