for _ in range(int(input())):
    n = int(input())
    s = [None] * n
    for i in range(n):
        s[i] = input()

    se = set(s)

    res = [None] * n
    for i in range(n):
        x = s[i]
        for j in range(1, len(x)):
            one, two = x[:j], x[j:]
            if one in se and two in se:
                res[i] = True
                break

    print("".join(["1" if x else "0" for x in res]))
