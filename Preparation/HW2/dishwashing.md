# Dishwashing

## February 2019 Gold

### Problem 2

The first observation that needs to be made is that each plate needs to be
placed on the first stack whose bottom is greater than it, or the next empty
stack.

Then, the next think you need to observe is that you can't place an plate on any
other plate whose value is less than its own value, so any time you encounter
smaller plate on the pile that you need to place the current plate on, you will
need to move first clean it down the pile until you can add another plate.

Now, to check if the next element can be added, you just need to make sure you
didn't need to remove a plate with a greater value to place any previous
element. If you did, you can't place the plate, so you can stop checking
further.

Therefore, all you need to do is maintain a list of all the different stacks of
plates and also the cleaned plate. If you can add a plate, simulate adding it by
removing all other necessary plates and cleaning them. If you can't remove a
plate, or add a different one, you know that you have reached your limit.

Here is my implementation:

@import "dishwashing.cpp" {cmd="cpp"}
