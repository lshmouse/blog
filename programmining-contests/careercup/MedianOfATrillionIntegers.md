median of a trillion integers
==============================
Problem
-------------------------
See: http://matpalm.com/median/question.html

How would you find the median of a trillion integers spread across a thousand
machines?  what is a median? informally the median of a list of elements is the "middle" element after the
list is sorted.
eg for a sorted list with 11 elements [1 1 2 3 3 4 5 5 5 6 9]
the median of this list is the value in the "middle" with 5 elements on either
side ie. the value 4.

doing some back of envelope calculations we see that a trillion (1012) ints
would consume, at 4 bytes per int, 4x10^12 bytes = 4x10^9 kb = 4x10^6 mb = 4x10^3 gb. 
Spread over 1,000 machines thats 4gb worth of ints per machine. 

Solution
-------------------------


