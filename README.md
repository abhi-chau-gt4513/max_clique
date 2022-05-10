# Max Clique

## Background

In the world of algorithms, we deal with problems that cannot be solved using the computational resources we currently have, yet. More accurately, we do not know whether they can be solved efficiently. All of our problems are Search problems, in which there is an input, a candidate solution, and a criteria dependent on the problem to see if the candidate is indeed a valid solution. This presents these classes:
1. NP: This stands for Nondeterministic Polynomial, which means that the Computation time it takes for the algorithm to validate a solution for that particular search problem is Polynomial (i.e. n^d, where n is a positive integer representing the input size and d is a nonnegative integer).
2. P: This is a subclass of NP where the problem can also be solved in Polynomial Time.

There are certain problems that are the hardest to solve, in which all other problems that exist in the world of algorithms and beyond are reducable to them. In other words, if a Polynomial solution is found for any one of these hardest problems, that would mean all those problems can be solved in Polynomial Time, which is a huge deal in the world of Computer Science, and beyond, perhaps.

The Max-Clique problem, which is what this repo is about, happens to be one of these problems.

This repo is there for the purposes of general exploration and research, and it gives a bit of perspective as to how one would think about finding ways to solve hard problems, as well as validating these solutions without extending beyond the use of resources such as memory and computational power.

For more information, check out these sites:
1) https://en.wikipedia.org/wiki/NP-completeness
2) https://classroom.udacity.com/courses/ud401
3) https://www.youtube.com/watch?v=0sQ37m3whP4
