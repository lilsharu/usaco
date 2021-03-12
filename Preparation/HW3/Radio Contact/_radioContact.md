---
markdown:
    path: "Radio Contact.md"
---
# Radio Contact

## January 2016

### Gold

#### Problem 2

As we are solving for the minimum value for the cost of the entire journey, given the constraints (the maximum value of $N$ and $M$ is $1000$), the most efficient solution would be to try every possible path. To make the path calcuations more efficient, we can find the distances between every possible position combination of Farmer John and Bessie ($O\left(NM\right)$) and then run a BFS, storing the position in the path for both Farmer John and Bessie, was well as the total energy consumed already. Then, we can test all possible movements: Either Bessie Moves, Farmer John Moves, or they both do, as long as either that combination has not already been explored or that the new combinations leads to a cheaper solution.

Here is my C++ Code:

@import "radioContact.cpp"