---
# title: "Loan Repayment"
author: Shourya Bansal
date: March 9, 2021
output: pdf_document
markdown:
    path: "Loan Repayment.md"
---
# Loan Repayment

## January 2020

### Silver

#### Problem 2

The first observation is to notice the bounds of $N$, which can be as large as $10^{12}$. With N being this large, our algorithm can't be proportional to $N$, so it must use something like $\log{N}$ or $\sqrt{N}$. The following solution is something along the lines of $\sqrt{N}\log{N}$.

The first step of this problem is quite simple: we will simply [Binary Search](https://usaco.guide/silver/binary-search?lang=cpp) on a function for $X$. The tricky part comes when trying to see if $X$ will work.

To find if any $X$ works requires a bit of math. A naive approach would be to keep calculating $Y$ until you have paid off $N$ or reached time $K$, but that can become proportional $N$, which we previously noticed would not work.

You must first notice the significance of the floor function; what this allows is to have a continuous portion where Farmer John will be paying back the same amount of money. Therefore, if we can find out how long each value of $Y$ needs to be paid for, we can significantly shorten the calculation time. To find that out, we can use the following proof.

$$
\text{Let } G = \text{The Amount Already Given} \\
\text{Let } N = \text{The Total Amount Owed} \\
\text{Let } X = \text{A Constant Value} \\
\text{Let } Y = \left\lfloor\frac{N - G}{X}\right\rfloor
$$

These are values that we were already given to us, but we need to find a few of our own values. Namely

$$G_{max} = \text {The most that can be given until } Y \text{changes}$$

To find $G_{max}$, we can remove the floor from our equation, since finding the maximum $G$ by definition will be removing the floor (as there will be no remainder to truncate). If we solve for $G_{max}$ using our equation of Y, we can get that

$$G_{max} = N - XY$$

Now that we have solved for the maximum that can be given, we just need to calculate how many times we can give $Y$ before reaching the maximum, which is simply how far we are from the maximum right now divided by Y, or:

$$\text{Let } T \text { be the number of iterations} = \left\lfloor\frac{G_{max} - G_{cur}}{Y}\right\rfloor + 1$$

Note: We need to add one to include the $Y$ currently.

Now, we can simply use $T$ to update all the values:

$$
G = G_{cur} + YT\\
T_{total} = T_{total_0} + T
$$

If our total $T$ when we have paid off the loan is more than $K$, we know that $X$ is too large.

Here is my implementation of this solution:

@import "loanRepayment.cpp"