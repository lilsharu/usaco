---
markdown:
    path: cowAtLarge.md
export_on_save:
    markdown: true
---

# Cow At Large

## January 2018

### Gold

#### Problem 2

We can split this problem into two main parts. Where is the potential place for each farmer to start, and how many of those places are unnecessary.

The first part of the problem is simple. All we need to do is find all the exits, can easily be found by looking for leaves on the "tree" that can be formed by all the paths that Bessie can take. To find this, we can simply find a list of all the leaves by finding each child with only one path.

With all the leaves, or potential exits that Bessie can exploit, there are some that are not necessary if Bessie can be blocked from all of them beforehand. For example, if A is the parent of B and B is the parent of two leaves C and D, only one farmer is needed becuase that farmer can move to B and block the exits to both C and D. With this observation, we can determine that, for any given section of the graph, if a farmer can move to an ancestor node A at or before Bessie, only that exit is needed to block every exit that has A as its ancestor.

With these observations, we can come up with the following solution:

1. BFS from Bessie's starting point, or the root, and find the distances from all other nodes in the tree.
2. If any node in the BFS has no children, add it to the list of exit nodes.
3. Sort all the exit nodes by distance from Bessie (A node closer to Bessie can block out a node farther from it if it shares a common ancestor, so this avoids double counting and extra complexity).
4. For each exit node, find the farthest anscestor visitable (simply take the the floor of the distance divided by 2), add one to the total, and remove all other children (including exit nodes) from consideration.

Here is my implementation of this:

@import "cowAtLarge.cpp"
