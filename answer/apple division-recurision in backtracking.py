def min_difference(n, weights : list) -> int:
    total_weight = sum(weights)
    result = float('inf')

    def possible_groups(idx, sum_group1):
        nonlocal result
        if idx == n:
            sum_group2 = total_weight - sum_group1
            result = min(result, abs(sum_group2 - sum_group1))
            return 
        else:
            x = weights[idx]
            possible_groups(idx + 1, sum_group1 + x)
            possible_groups(idx + 1, sum_group1)

        return 
    
    possible_groups(0, 0)
    return result


n = int(input())
weights = [int(x) for x in input().split()]
print(min_difference(n, weights))