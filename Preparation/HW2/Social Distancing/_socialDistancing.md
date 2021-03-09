---
markdown:
    path: "Social Distancing.md"
---

# Social Distancing

## US Open 2020

### Silver

#### Problem 1

To solve this problem, the first thing to notice is that, if gap $x$ is not possible, then all gaps $g > x$ won't work either. With this observation in mind, we can classify a function to check if a value works as monotonic, which allows us to use the strategy of Binary Search on the Answer to Solve efficiently. We use a binary increment to find the heighest value that works, slowly decreasing the size of the jumps we are taking as we approach the limit of the answer.

To check if a gap is possible, we need to place each cow the closest it can be, which means a minimum of distance $x$, or the start of the next patch of grass if $x$ is outside any graphs. So we can check if, after going through all the cows, or reaching the end of the path, if we have any cows remaining. If we do, then we can't have a gap that size. If we do not, then a gap that size works and we can look for gaps larger.

Here is my implementation:

@import "socialDistancing.cpp"