# Task

Fortune Telling
Given a collection of n cards. The i-th card (1 ≤ i ≤ n) has a number Ai on its front and a number Bi on its back. At the start, all the cards are facing upwards. He wants to minimize the range of numbers (i.e. the difference between the maximum and minimum values) on the face-up side. He is allowed to flip a maximum of m cards. Flipping a card will transition Bi to the face up side and Ai to the back. Help him find the minimum possible range after using at most m flips.

Input

The first line of the input consists of 2 integers n and m . The next line contains n integers, i-th of which denotes Ai . The next line contains n integers, i-th of which denotes Bi .

Output

Output a single integer, the minimum possible range.


Example 1 :

Input: n = 5, m = 2, A = [1, 2, 17, 16, 9], B = [3, 4, 5, 6, 11]
Output: 8
Explanation: By flipping card 3 and 4, we get the face up numbers {1, 2, 5, 6, 9}. This makes range=9-1=8.


Constraints:
1 <= m <= n
1 <= Ai, Bi <= 107


Reference:

<!-- import java.util.*;

 public class Main {
     static int ans = Integer.MAX_VALUE;
     public static void main(String[] args) {
         int n = 5;
         int m = 2;
         int[] A = new int[]{1, 2, 17, 16, 9};
         int[] B = new int[]{3, 4, 5, 6, 11};
         minRange(n, m, A, B, 0);
         System.out.println(ans);
}
 
 public static void minRange(int n, int m, int[] A, int[] B, int ind) {
         if(m == 0){
             int currMax = -1;
             int currMin = Integer.MAX_VALUE;
             for(int i=0; i<n; i++){
                 currMax = Math.max(A[i], currMax);
                 currMin = Math.min(A[i], currMin);
             }
             int curr = Math.abs(currMax-currMin);
             ans = Math.min(ans, curr);
             return;
         }
         if(ind >= n){
             return;
         }
         minRange(n, m, A, B, ind+1);
         int temp = A[ind];
         A[ind] = B[ind];
         minRange(n, m-1, A, B, ind+1);
         A[ind] = temp;
         return;
     }
 } -->