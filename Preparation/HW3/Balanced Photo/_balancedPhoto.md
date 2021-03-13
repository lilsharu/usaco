---
output: pdf_document
markdown:
    path: "Balanced Photo.md"
---
# Balanced Photo

## January 2017

### Gold

#### Problem 1

---

The basic idea behind this problem is that we need to find the number of elements larger than cow $i$ to the right and to the left of the cow. We could easily brute force this and solve it in $N^2$ time by looking at each cow once. However, this will not be fast enough as the limit of $N$ is $100,000$, so we need to think of something a little more clever.

A tool that we can use is the `lower_bound` function, which allows us to find the first element greater than the current value in a sorted array, and in turn find the number of elements greater than the value we are looking for. So this solves part of our efficiency problem. But the question remains, how do we find this for both the left and the right sides? We can have an array that we keep sorted which stores the cows on the left. These cows will remain in our right array, so we simply need to subtract the number of cows that fit the criteria in the left array from the right array, giving us the two values. Then, if the condition is met, we can increment it. If it is not met, we can decrement it.

Here is an outline of the process followed:

1. Read in all values in two arrays. We will sort one of them and not the other.
2. Sort one of the arrays (to allow us to do `lower_bound` and `upper_bound` queries)
3. Loop through each element
   1. Find the `upper_bound` on the left array and use that to determine the number of elements that are greater than it
   2. Find the `upper_bound` on the right array and subtract the value from the left array to avoid double-counting.
   3. Check if the maximum of the two values is more than twice the minimum of the two values and increment if that is the case.
   4. Insert the current value into the correct position in the left array, making sure it remains sorted

Here is my code:

@import "balancedPhoto.cpp"
