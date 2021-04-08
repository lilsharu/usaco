[n, l] = map(int, input().strip().split())
vals = sorted([int(v) for v in input().strip().split()], reverse=True)

ogl = l

h = vals[0]
num = 0

# One Case Missing: The Highest H stems from a certain x + 1
for paper in vals:
    if paper >= h:
        num += 1
    elif paper + int(bool(l)) >= h:
        num += 1
    else:
        l = ogl
        h = paper
        num += 1
    if num >= h:
        break

# Inefficient, can be improved
if (l > 0):
    for i in range(n):
        l -= 1
        vals[i] += 1
        halt = vals[0]
        for paper in vals:
            if paper >= halt:
                num += 1
            elif paper + int(bool(l)) >= halt:
                num += 1
            else:
                l = ogl
                halt = paper
                num += 1
            if num >= h:
                break
    vals[i] -= 1

print(h)
