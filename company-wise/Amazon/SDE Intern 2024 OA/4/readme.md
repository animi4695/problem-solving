The machine learning enthusiasts at Amazon are working on a data interpolation model to increase the size of the data set for better learning.

In one such model, there are 26 different classification possible and the ith data point is annotated to belong to the data[i] class where data is a string of lowercase english letters. However, for some data points, data[i] is equal to '?' representing that the corresponding data point classification is missing and needs to be replaced with some lowercase English letter.

The cost of any index of the string of data is defined as the number of indices before it that also have the same classification result.

For example,
- for the string 'hello' the costs are [0, 0, 0 ,1, 0] correspondign to each index.
- for the string 'abc' the costs are [0,0,0] corresponding to each index.
- For the string 'aaccbbc' the costs are [0,1,0,1,0,1,2] corresponding to each index because before the last c character, there are 2 more c characters.

The task is to replace all the characters '?' so that the sum of the indices cost is minimum.

Given the string data, interpolate the data such that total cost of all indices is minimized. If there are multiple ways to get minimum cost, print the lexicographically smallest possible string that satisfies the goal.

Note: A string p is lexicographically smaller that string  q, if p is a prefix of q, is not equal to q, or there exists i, such that p_i < q_i and for all j < i it is satisfied that p_j = q_j. Note that while comparing p_j and q_j we consider their ASCII values, i.e. '[' and ']' are greater than any uppercase english letters. For example, "ABC" is lexicographically smaller than "BCD" and "ABCDE" but larger than "AAC" and "AACDE".

Example:

Given the string data = "abcd?"

Some of the possible replacements are:

abcda = 1 (cost)
abcdd = 1 (cost)
abcde = 0 (cost)
abcdz = 0 (cost)

The strings "abcda", "abcdb", "abcdc" and "abcdd" cost 1 because the last element has a duplicate character. We can see that the minimum cost possible is 0. Since there can be multiple possible strings with 0 cost, we choose the lexicographically smaller one i.e abcde.

