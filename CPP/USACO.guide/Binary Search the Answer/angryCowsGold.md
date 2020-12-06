Bessie the cow has designed what she thinks will be the next big hit video
game: "Angry Cows". The premise, which she believes is completely original,
is that the player shoots a cow with a slingshot into a one-dimensional scene
consisting of a set of hay bales located at various points on a number line;
the cow lands with sufficient force to detonate the hay bales in close
proximity to her landing site, which in turn might set of a chain reaction
that causes additional hay bales to explode. The goal is to use a single cow
to start a chain reaction that detonates all the hay bales.

There are N hay bales located at distinct integer positions x1,x2,…,xN on the
number line. If a cow is launched with power R landing at position x, this
will causes a blast of "radius R", engulfing all hay bales within the range
x−R…x+R. These hay bales then themselves explode (all simultaneously), each
with a blast radius of R−1. Any not-yet-exploded bales caught in these blasts
then all explode (all simultaneously) with blast radius R−2, and so on.

Please determine the minimum amount of power R with which a single cow may be
launched so that, if it lands at an appropriate location, it will cause
subsequent detonation of every single hay bale in the scene
