Perfect Shuffle
==============================
see:
http://stackoverflow.com/questions/2352542/how-to-master-in-place-array-modification-algorithms

Problem
-------------------
a1, a2, ...,an,b1,b2,...,bm
==>
a1,b1,a2,b2,......

Solution
-------------------
Firstly, we can assume that m be equal to n for we can change the problem from m
!= n to m = n by moving the extra elements to the end of the array. For example,
a1, a2, a3, b1, b2
->
b1, b2, a3, a1, a2
-> skip the n - m steps of a part in O(N)
b1, b2, a1, a2, a3

### O(nlogn) Inplace
To simplify the problem, we can first assume that m equals n.

### O(n) Inplace

