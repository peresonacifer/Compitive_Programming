def min_difference_recursive(idx, sum_group1, sum_group2, weights, n):
    if idx == n:
        return abs(sum_group1 - sum_group2)
    
    else:
        add_in_group1 = min_difference_recursive(idx + 1, sum_group1 + weights[idx], sum_group2, weights, n)
        add_in_group2 = min_difference_recursive(idx + 1, sum_group1, sum_group2 + weights[idx], weights, n)

    return min(add_in_group1, add_in_group2)


def min_difference(n, weights):
    return min_difference_recursive(0, 0, 0, weights, n)


n = int(input())
weights = [int(x) for x in input().split()]
print(min_difference(n, weights))