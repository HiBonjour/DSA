def canPlace(h, l):
    flag = True
    for i in range(h):
        if queens[i] == l or h - i == l - queens[i] or h - i == queens[i] - l:
            flag = False
            break
    return flag


def place(k):
    if k == n:
        global count
        count += 1
        print(count, ':', queens)
    else:
        for i in range(n):
            if canPlace(k, i):
                queens[k] = i
                place(k + 1)


print("Please type the number of your queens")
n = int(input())
queens = [0] * n
count = 0
place(0)
