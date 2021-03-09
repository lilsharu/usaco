---
markdown:
    path: "Closing the Farm.md"
export_on_save:
    markdown: true
---

# Closing the Farm

## US Open 2016

### Silver

#### Problem 3

For the Silver version of this Problem, we can solve this quite easily. All we need to do is see if all the barns are in a single Connected Component after we remove a barn. To find this out, we just need to check if every remaining barn can be reached from a root node. If yes, then the barn is connected. Otherwise, it is not.

The first step is finding the root node. We can easily do this by selecting the last node to be removed, as we know that it will always be included in any graph of the farm.

From here, we can do BFS for each removed node to count if the number of barns in the component of the root is the number left in total.

@import "closingTheFarmSilver.cpp"
