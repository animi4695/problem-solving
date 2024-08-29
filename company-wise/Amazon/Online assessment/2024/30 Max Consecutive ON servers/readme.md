# Task

Amazon has a cluster of n servers. Some are in the OFF state while others are ON. The developers responsible for maintaining the servers have access to a special operation to change the states. In one operation, they can choose a contiguous sequence of servers and flip their states, i.e., ON to OFF and vice versa. Due to operational constraints, this operation can be performed on the cluster a maximum of k times.

Given a binary string server_states, of length n, where '1' represents ON, '0' represents OFF, and an integer k, find the maximum possible number of consecutive ON servers after at most k operations.

Function Description

Complete the function getMaxConsecutiveON in the editor.

getMaxConsecutiveON has the following parameters:

String server_states: states of the servers, '1' represents ON state, '0' represents OFF
int k: the maximum number of operations that can be performed
Returns

int: the maximum number of consecutive ON servers after a maximum of k operations

Example 1:

Input:  server_states = "00010", k = 1
Output: 4 8
Explanation:

      It is optimal to apply the special operations on consecutive indices (0-based indexing) as follows:

      Flip indices [0..2] giving states = "11110"

      After 1 operation, there are a maximum of 4 consecutive ON servers.
      
Example 2:

Input:  server_states = "1001", k = 2
Output: 4 
Explanation:

The indices [1...2] can be chosen and flipped in on operation as follows:
Thus in one operation, the maximum num of consecutive ON server is 3. It is optimal to stop after 1 operation.
      
Example 3:

Input:  server_states = "11101010110011", k = 2
Output: 8 
Explanation:

It is optimal to apply the special operations on consecutive indices (0-based indexing) as follows:

-> Flip indices [7...9] given states = "11101011000011"

-> Flip indices [8...11] given states = "1110101111111"

After 2 operations, a maximum of 8 consecutive ON servers can be obtained.
      
Constraints:
1 ≤ n ≤ 2 * 105
1 ≤ k ≤ 2 * 105
server_states contains only 0s and 1s