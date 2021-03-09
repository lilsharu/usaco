---
markdown:
    path: "Milk Pails.md"
---

# Milk Pails

## February 2016

### Silver

#### Problem 3

The first thing we can notice on this problem is the very low bounds. We are given a total of 4 variables, three of which have a maximum of $100$, and one which has a maximum of $200$. With this in mind, we can see that, even if we brute force every combination, we should still be able to pass without a timeout error, giving us a maximum of $2\cdot10^8$ operations.

However, if you look at the problem more closely, one of these values $\left(M\right)$ is fixed and the other is just a constraint, so trying every possible combination of the remaining two values $\left(X, Y\right)$ should run in more than enough time $\left(10^4\right)$.

Starting with no milk in either container, we can either fill each container, empty each container, or pour the contents of one container to another. If we try out every combination of those (skipping duplicates and cases which are above the maximum time alloted), we can store the minimum difference until now and update it when we can improve it.

Here is my implementation of this solution:

@import "milkPails.cpp"