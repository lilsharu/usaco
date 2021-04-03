n = int(input())

ans = list()

for x in range(2, int(n ** 0.5 + 0.5)):
    if n % x == 0:
        print(x, end='')
        print(int(n / x), end='')
        break
