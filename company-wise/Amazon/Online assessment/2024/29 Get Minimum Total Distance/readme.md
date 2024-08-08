# Task

Amazon has recently established n distribution centers in a new location. They want to set up 2 warehouses to serve these distribution centers. Note that the centers and warehouses are all built along a straight line. A distribution center has its demands met by the warehouse that is closest to it. A logistics team wants to choose the location of the warehouses such that the sum of the distances of the distribution centers to their closest warehouses is minimized.

Given an array dist_centers, that represent the positions of the distribution centers, return the minimum sum of distances to their closest warehouses if the warehouses are positioned optimally.

Function Description

Complete the function getMinTotalDistance in the editor.

getMinTotalDistance has the following parameter:

int dist_centers[n]: the locations of the distribution centers
Returns

int: the minimum sum of distances

Example 1:

Input:  dist_centers = [1, 2, 3]
Output: 1 
Explanation:

One optimal solution is to position the 2 warehouses at x1 = 1 and x2 = 2.

The minimum sum of the distances between distribution centers and the warehouses closest to them is 0 + 0 + 1 = 1.