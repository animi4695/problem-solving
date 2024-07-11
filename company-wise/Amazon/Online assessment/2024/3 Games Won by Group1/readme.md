# Task

There is a tournament of pair games where two teams of two players each compete against one another.

There are two groups group1 and group2 of size n each. The skill levels of the i^th players of the groups are group1[i] and group2[i]. For each pair of indices, (i, j) (0 ≤ i < j < n), the pair of players (group1[i], group1[j]) compete in the pair game with (group2[i], group2[j]).

The winner of the game is group1 if group1[i] + group1[j] > group2[i] + group2[j], and vice-versa.

Given group1, and group2, find the number of games group1 will win. Since the answer can be large, report it modulo 10^9 + 7.


Input: n = 3, group1 = [1, 2, 3], group2 = [3, 2, 1]
Output: 1
Explanation: As shown on the iamge above, group1 wins one match so the answer is 1.


Constraints:
2 <= n <= 105
1 <= group1[i], group2[i] <= 109
