N = int(input())
for _ in range(N):
    num = input().strip()
    if len(num) != 4 or not num.isdigit():
        print("Failure Input")
    else:
        if num[0] == '0':
            print("Failure Input")
            continue
        freq = {}
        for d in num:
            freq[d] = freq.get(d, 0) + 1
        if len(freq) == 3:
            counts = sorted(freq.values())
            if counts == [1, 1, 2]:
                print("Yes")
            else:
                print("No")
        else:
            print("No")