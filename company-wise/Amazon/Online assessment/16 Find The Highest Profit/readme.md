Ref :
https://algo.monster/problems/find_the_highest_profit

An e-commerce company imports a type of fitness band from China and sell them in the US for a higher price. The company source the product from multiple suppliers, each with their own inventory. The suppliers raise the price of their product when inventory decreases due to scarcity. More specifically, the profit that the e-commerce company makes on each product sold is equal to the number of products left from the supplier.

Given a list of integers representing the number of products each supplier has and an integer representing the number of products sold, find the maximum profit the company can make.

Examples
Example 1:
Input:
inventories = [6, 4] order = 4

Output: 19
Explanation:
There are two suppliers, with inventory of 4 and 6 respectively. A total of 4 items are ordered. We can make maximum profit by

selling 1 item from the first supplier for 6
selling 1 item from the first supplier for 5
selling 1 item from the first supplier for 4, which brings down the inventory of the first supplier to 3
selling 1 item from the second supplier for 4
The maximum profit is 6 + 5 + 4 + 4 = 19.

Example 2:
Input:
inventories = [10, 10]

order = 5

Output: 46
Explanation:
The maximum profit we can generate is by

selling 1 item for a profit of 10 from the first supplier
selling 1 item for a profit of 10 from the second supplier
selling 1 item for a profit of 9 from the first supplier
selling 1 item for a profit of 9 from the second supplier
selling 1 item for a profit of 8 from the first or second supplier
The maximum profit is 10 + 10 + 9 + 9 + 8 = 46.