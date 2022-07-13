for _ in range(int(input())):
    n = int(input())
    s = input()
    u = set(s)

    res = len(u) * 2 + (len(s) - len(u))

    print(res)
