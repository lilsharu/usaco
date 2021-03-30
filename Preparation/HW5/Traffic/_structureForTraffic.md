# Data Structure

I used two data structures: A Sum Tree and a Weighted Tree. For the Sum Tree, I simply used the sum of all the children and itself recursively with a DFS (Since it is the sum of all the children, you need to keep setting each node as the root).

After doing that, I needed to make a weighted tree for the congestion. To do this, we start similarly, but keep the sum of only the children and add on the total underneath. This is because, when moving upwards, you are adding the total of the values underneath to the current distance-indexed value.
