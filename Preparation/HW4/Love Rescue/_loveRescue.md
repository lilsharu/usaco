---
markdown:
    path: "Love Rescue.md"
---
# Love Rescue

## CodeForces

### Contest ID 939

#### Problem D

The most important observation is that, as long as one letter is connected to another through any possible path, it can be transformed to that letter. In other words, as long as two letters are in the same component, they can be exchanged / swapped. Therefore, all we need to do is use a simple Disjoint Set Union.

We move through each index and, whenever we see a difference, we first check if the two letters are already in the same connected component. If they are, we don't need to worry about them since we can already map it. If not, we just add it to the list of connections and update our DSU with that union.

---

Note: While DSU is quick and easy, DFS should also work since the maximum size of any connected component is only 26

---

Here is my code:

@import "939D.cpp"
