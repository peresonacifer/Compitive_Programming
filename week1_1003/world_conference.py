
def fuc(n, l):
    result = []
    s = set()
    for i in range(n):
        if i == n - 1 :
            if (l[i] != l[i - 1] and l[i] != l[0]):
                if l[i] in s and l[i] not in result:
                    result.append(l[i])
        else:
            if (l[i] != l[i - 1] and l[i] != l[i + 1]):
                if l[i] in s and l[i] not in result:
                    result.append(l[i])
            else:
                if (l[i] != l[i - 1] and l[i] in s) and l[i] not in result:
                    result.append(l[i])
                    j = i
                    while (l[j] == l[j + 1]):
                        if(j + 1 == n - 1 and l[j + 1] == l[0]):
                            result.remove(l[i])
                            break
                        if j + 1 < n - 1: j += 1
        s.add(l[i])

    if len(result) == 0:
        print("Yes")
    else:
        result.sort()
        print("No")
        print(*result)



n = int(input())
l = [int(x) for x in input().split()]
fuc(n, l)