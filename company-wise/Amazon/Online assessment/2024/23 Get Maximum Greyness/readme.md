# Task

Get Maximum Greyness
INTERN
Several satellites provide observational black and white images which are stored in data centers at Amazon Web Services (AWS).

A black and white image is composed of pixels and is represented as an n x m grid of cells. Each cell has a value of 0 or 1 , where 0 represents a white pixel and 1 represents a black pixel. The grayness of a cell (i, j) is affected by the pixel values in the ith row and the jth column. More formally, the grayness of the cell (i, j) is the difference between the number of black pixels in the i th row and the jth column and the number of white pixels in the ith row and the th column.

Find the maximum grayness among all the cells of the grid.

Note : The value of cell (i, j) is counted both in the ith row and in the jth column.


Function Description

Complete the function getMaximumGreyness in the editor.

GetMaximumGreyness has the following parameter:

string pixels[n] : a grid of pixels, where the i th string consists of m characters and represents the i th row of pixels.

Returns

int : the max greyness of the grid of pixels.

Example 1 :

Input: pixels = ["1010", "0101", "1010"]
Output: 1
Explanation: The n x m = 3 x 4 grid of pixels looks like this:
1 0 1 0
0 1 0 1
1 0 1 0
The grayness of each cell is:
1 -1 1 -1
1 -1 1 -1
1 -1 1 -1
The maximum achievable grayness is 1.


Example 2 :

Input: pixels = ["011", "101", "001"]
Output: 4
Explanation:
The 3 x 3 grid of pixels looks like this:
0 1 1
1 0 1
0 0 1
The grayness of each cell is:
0 0 4
0 0 4
-2 -2 2
The maximum achievable grayness is 4.


Example 3 :

Input: pixels = ["101", "001", "110"]
Output: 2
Explanation:
The 3 x 3 grid of pixels looks like this:
1 0 1
0 0 1
1 1 0
The greyness of the cell (1, 1) is calculated as the image above.
The greyness of each cell is:
2 0 2
0 -2 0
2 0 2
The maximum achievable greyness is 2.


Constraints:
1 ≤ n, m ≤ 1000
pixels[i][j] = '0' or '1' for all 0 ≤ i < n and 0 ≤ j < m