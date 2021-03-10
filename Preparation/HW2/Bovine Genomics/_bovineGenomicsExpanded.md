---
markdown:
    path: "Bovine Genomics.md"
---

# Bovine Genomics

## US Open 2017

### Gold

#### Problem 1

For this problem, all you need is a Brute Force algorithm with Hashing, which will run in time. Hashing will reduce the time for comparisons, and therefore reduce the time limit for finding if an substring is already present.

The idea behind the Brute Force is to found every combination of substrings for the spotted cows (shorter than the current minimum, becasue anything larger is suboptimal) and added them to a set after hashing. Then take the same substring from all the of the plain cows and checked if they exist in the set after hashing. If it does not exist, then you can reduce the shortest length to the length of the current substring and continue.

I have not solved it with Hashing at the moment.
