# Task

Find Largest Set of Onion
FULLTIME
You are shopping online for some bags of onion. Each listing displays the number of onions that the bag contains. You want to buy a perfect set of onion bags from the entire search results list, onionBags . A perfect set of onion bags, perfect , is defined as:

The set contains at least two bags of onion.
When the onion bags in the set perfect are sorted in increasing order by count, it satisfies the condition perfect[i] * perfect[i] = perfect[i+1] for all 1 ≤ i < n . Here n is the size of the set and perfect[i] is the number of onion in bag i .
Find the largest possible set perfect and return an integer, the size of that set. If no such set is possible, then return -1 . It is guaranteed that all elements in onionBags are distinct.


Example 1 :

Input: onionBags = [3, 9, 4, 2, 16]
Output: 3
Explanation: The following are the perfect sets:

Set perfect = [3, 9]. The size of this set is 2.
Set perfect = [4, 2]. The size of this set is 2.
Set perfect = [4, 16]. The size of this set is 2.
Set perfect = [4, 2, 16]. The size of this set is 3.
The size of the largest set is 3. The image below illustrates the correct ordering of the purchased onion bags by count.