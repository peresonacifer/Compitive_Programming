def min_difference(n, weights) -> int:
    diffence_weights = set()
    for i in range(n // 2 + 1):
        if i == 0:
            diffence_weights.add(sum(weights))
        else:
            diffence_weights = diffence_weights | num_sum(i, weights, weights.copy())

    return min(diffence_weights)


def num_sum(n, weights : list, group2 : list, group1_sum = 0) -> set :
    result = set()
    temp = group1_sum
    if n == 0:
        result.add(abs(sum(group2) - temp))
        return result
    

    else:
        
        for i in range(len(weights) - (n - 1)):
            temp += weights[i]
            remain = weights[i + 1 : ]
            group2.remove(weights[i])
            result = result | num_sum(n - 1, remain, group2 = group2, group1_sum = temp)
            group2.append(weights[i])
            temp = group1_sum

    return result

n = int(input())
weights = [int(x) for x in input().split()]
print(min_difference(n, weights))