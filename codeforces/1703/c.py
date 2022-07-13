for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().strip().split()]
    d = []
    for _ in range(n):
        _, di = input().strip().split()
        d.append(sum([1 if x == "U" else -1 for x in di]))

    # print(n, a, d)

    res = []
    for i in range(n):
        res.append((a[i] - d[i]) % 10)

    print(" ".join([str(x) for x in res]))
