---
markdown:
    path: "Magic Parenthesis (CSES 115).md"
---
# [Magic Parenthesis](https://cses.com/115/list)

## CSES BOI 2005

### Day 1

#### Problem B

The first observation should be to notice that each "Magic Parenthesis" acts like a regular closing bracket, but can also be considered multiple of them combined. The next thing to notice is that, if an opening parenthesis is not closed, it will carry on until the end of the line.

When counting parenthesis in code, an important technique is to do a "prefix sum" of sorts, where each opening parenthesis is a +1 and each closing parenthesis is a -1. If the total at the end of the line is 0, then you have closed everything. Now, with these together, the problem becomes simple.

If we treat each "Magic Parenthesis" as a regular parenthesis, we can reach the end of the line and see how many extra opening parenthesis we have that have not already been closed. This extra number can just be dedicated to the very last magic parenthesis, leaving all others with a value of 1. With that, we will have made sure that we closed all of the parentheses and have a net of zero.

Here is my implementation:

@import "magicParenthesis.cpp"
