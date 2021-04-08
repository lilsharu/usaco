[n, l] = map(int, input().strip().split())
vals = sorted([int(v) for v in input().strip().split()], reverse=True)
potential = set(vals)

for v in vals:
    potential.add(v + 1)

potential = list(potential)
potential.sort()


def work(val):
    num = 0
    add = l
    for v in vals:
        if v >= val:
            num += 1
        elif add > 0 and v + 1 >= val:
            num += 1
            add -= 1
        else:
            return False
        if (num >= val):
            return True


lo = 0
hi = len(potential)

ans = -1
while (lo <= hi):
    mid = (lo + hi) // 2
    if work(potential[mid]):
        ans = mid
        lo = mid + 1
    else:
        hi = mid - 1

print(potential[ans])
