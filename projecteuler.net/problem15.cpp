/*
Lattice Paths-Problem 15

Starting in the top left corner of a 2x2 grid, and only being able to move to the right and down, 
there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20x20 grid?
*/

/*I would start to say a few things: 

1 we need to require that we can pass again on the same point of a lattice, otherwise we would 
have infinite paths. An idea for a future exercise could be that we can pass only a certain number
k of times on each node, and then count those paths. Much complicated, we could maybe see it as a
multidimensional lattice somehow

2 to solve, as always, we should start from examples: 3x3 grids, 4x4 etc... if we do it well we could 
just write a program to help us, but we wouldn't need to build a class ad an object grid, path etc...
we could be more elegant and less computationally expensive.
*/

#include<iostream>
