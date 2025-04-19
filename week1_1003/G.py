xy = []
for _ in range(3):
    xy.append([int(x) for x in input().split()])

result = []
x =0
for i in range(2):
    for j in range(2):
        x += (xy[i][j] - xy[i+1][j])**2
    result.append(x)
    x = 0
result.append((xy[0][0] - xy[2][0])**2 + (xy[0][1] - xy[2][1])**2)
result.sort()
if (result[0] + result[1]) == result[2]:
    print("Wow! It is a right triangle!", end = "")
else:
    print("Sad:( It isn't a right triangle.", end = "")
