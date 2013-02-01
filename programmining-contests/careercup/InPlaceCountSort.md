In-Place Count Sort
====================

Problem
-----------------
From [careercup](http://www.careercup.com/question?id=15303665&utm_source=feedburner&utm_medium=feed&utm_campaign=Feed%3A+Careercup+%28CareerCup%29&utm_content=Google+Reader)
You are given an unsorted integer array of size N. This array contains integer
from range 0 - N (not necessarily distinct and same integer can appear multiple 
time in an array).
You need to find pair of all the elements in array which sum up to N.

First i gave a solution using an extra array of size N to keep count of each
integer in original array and was able to give solution in O(n) Time complexity
and O(n) space complexity.

Then interviewer asked me to decrease space complexity, for which i gave
solution as sorting the given array (in nlogn time) and then find the pairs in
O(n) time, and hence total time complexity was O(nlogn) and space complexity as
O(1).

But interviewer kept pressing for a better time complexity (than O(nlogn)) with
O(1) space complexity.

How is it possible, i could not think of any way.

Solution
-------------------
To decrease the space complexity, we need convert rhe unsorted integer array to 
counter array in-place in O(n) time complexity.
The answer is [In-Place Count Sort](http://en.wikipedia.org/wiki/In-Place_Count_Sort)

But the standard algorithm do not support duplicate numbers in the array. we
improve the algorithm a bit.
<pre><code>
void inPlaceCounterSort(int* array, uint32_t size) {
  for (uint32_t i = 0; i &lt; size; i++) {
    if (array[i] &lt;= 0) continue;
      int current = array[i] - 1;
      array[i] = 0;
      while (array[current] > 0) {
        int tmp = array[current] - 1;
        array[current] = -1;
        current = tmp;
    }
    array[current]--;
  }
  for (uint32_t i = 0; i &lt; size; i++) {
    array[i] = -array[i];
  }
}
</code></pre>
