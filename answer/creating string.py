def permute(s):
    # 基本情况：如果字符串长度为1，则返回该字符作为唯一排列
    if len(s) == 1:
        return [s]
    
    # 存储所有排列
    permutations = []
    
    # 遍历字符串中的每一个字符
    for i in range(len(s)):
        # 当前字符
        char = s[i]
        # 剩余部分字符串
        remaining = s[:i] + s[i+1:]
        # 递归获取剩余字符串的排列
        for p in permute(remaining):
            permutations.append(char + p)
    
    return permutations

# 主程序
s = input().strip()  # 读取输入字符串

# 获取所有排列
all_permutations = permute(s)

# 去重并排序
unique_permutations = sorted(set(all_permutations))

# 输出结果
print(len(unique_permutations))
for p in unique_permutations:
    print(p)
