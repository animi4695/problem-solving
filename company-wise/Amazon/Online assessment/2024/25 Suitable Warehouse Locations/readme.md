# Task

Ref - https://leetcode.com/discuss/interview-question/5158290/Amazon-OA

The world is represented by a number line from -109 to 109. There are n delivery centers, the ith one at location center[i]. A location x is called a suitable location for a warehouse if it is possible to bring all the products to that point by traveling a distance of no more than d. At any one time, products can be brought from one delivery center and placed at point x. Given the positions of n delivery centers, calculate the number of suitable locations in the world. That is, calculate the number of points x on the number line (-109 ≤ x ≤ 109) where the travel distance required to bring all the products to that point is less than or equal to d.

Note: The distance between point x and center[i] is |x - center[i]|, their absolute difference.


Example 1:

Input: center = [-2, 1, 0], d = 8

Output: 3

Explanation:
Initially, delivery centers locate at -2, 1 and 0:
chart-trips
The various locations along with the distance traveled to bring all treasures at that point are -
Locate the warehouse at x = -3: First bring products from center[0] = -2 covering a distance of |-3 - (-2)| = 1 to reach the center and |-3 - (-2)| = 1 to return. Similarly we bring products from centers 1 and 2 to point -3 for total distance of 1 + 1 + 4 + 4 + 3 + 3 = 16 which is > d. This is not a suitable location.
chart-trips
Locate the warehouse at x = 0, total distance traveled is 2 * |0 - (-2)| + 2 * |0 - 1| + 2 * |0 - 0| = 6 ≤ d. This is a suitable location.
chart-trips
Locate the warehouse at x = -1, total distance traveled is 2 * |-1 - (-2)| + 2 * |-1 - 1| + 2 * |-1 - 0| = 8 ≤ d. This is a suitable location.
chart-trips
Locate the warehouse at x = 1, total distance traveled is 2 * |1 - (-2)| + 2 * |1 - 1| + 2 * |1 - 0| = 8 ≤ d. This is a suitable location.
chart-trips
The only suitable location are {-1, 0, 1}. So return 3.

Example 2:

Input: center = [2, 0, 3, -4], d = 22

Output: 5

Explanation:
There are 5 suitable locations i.e {-1, 0, 1, 2, 3}.

Place a warehouse at x = -1, total distance traveled is 2 * |-1 - 2| + 2 * |-1 - 0| + 2 * |-1 - 3| + 2 * |-1 - (-4)| = 22 ≤ d.
x = 0, total distance traveled is 2 * |0 - 2| + 2 * |0 - 0| + 2 * |0 - 3| + 2 * |0 - (-4)| = 18 ≤ d.
x = 1, total distance traveled is 2 * |1 - 2| + 2 * |1 - 0| + 2 * |1 - 3| + 2 * |1 - (-4)| = 18 ≤ d.
x = 2, total distance traveled is 2 * |2 - 2| + 2 * |2 - 0| + 2 * |2 - 3| + 2 * |2 - (-4)| = 18 ≤ d.
x = 3, total distance traveled is 2 * |3 - 2| + 2 * |3 - 0| + 2 * |3 - 3| + 2 * |3 - (-4)| = 22 ≤ d.

Example 3:

Input: center = [-3, 2, 2], d = 8

Output: 0

Explanation:
It can be shown that there are no suitable locations. For example, if a warehouse is placed at x = 2, then total distance traveled is 2 * |2 - (-3)| + 2 * |2 - 2| + 2 * |2 - 2| = 10 > d.


Function Description
Complete the function suitableLocations in the editor below.
suitableLocations has the following parameters:
int center[n]: the positions of delivery centers
long d: the maximum total travel distance for a suitable location


Returns
int: the number of suitable locations.


Constraints
1 ≤ n ≤ 105
-109 ≤ packageweight[i] ≤ 109
0 ≤ d ≤ 105