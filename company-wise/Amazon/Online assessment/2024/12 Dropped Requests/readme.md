# Task


Dropped Requests

On Black Sale Day, non-critical requests for a transaction system are routed through a throttling gateway to ensure that the network is not choked by non-essential requests. The gateway has the following limits:

The number of transactions in any given second cannot exceed 3.
The number of transactions in any given 10 second period cannot exceed 20. A ten-second period includes all requests arriving from time T to T-9 (inclusive of both) for any valid time T.
The number of transactions in any given minute cannot exceed 60. Similar to above, 1 minute is from max(T, T-59) to T.
Any request that exceeds any of the above limits will be dropped by the gateway. Given the times at which different requests arrive sorted ascending, find how many requests will be dropped.

Note : Even if a request is dropped it is still considered for future calculations. Although, if a request is to be dropped due to multiple violations, it is still counted only once.


Function Description

Complete the function droppedRequests in the editor.

droppedRequests has the following parameter(s):

List requestTime : an ordered list of integers that represent the times of various requests

Returns

int : the total number of dropped requests


Example 1 :

Input: requestTime = [1, 1, 1, 1, 2]
Output: 1
Explanation: 1. Request 1 - Not Dropped. 2. Request 1 - Not Dropped. 3. Request 1 - Not Dropped. 4. Request 1 - Dropped. At most 3 requests are allowed in one second. 5. Request 2 - Not Dropped.


Example 2 :

Input: requestTime = [1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7]
Output: 2
Explanation: 1. Request 1 - Not Dropped. 2. Request 1 - Not Dropped. 3. Request 1 - Not Dropped. 4. Request 1 - Dropped. At most 3 requsts are allowed in one second. 5. Request 2 - Not Dropped. 6. Request 2 - Not Dropped. 7. Request 2 - Not Dropped. 8. Request 3 - Not Dropped. 9. Request 3 - Not Dropped. 10. Request 3 - Not Dropped. 11. Request 4 - Not Dropped. 12. Request 4 - Not Dropped. 13. Request 4 - Not Dropped. 14. Request 5 - Not Dropped. 15. Request 5 - Not Dropped. 16. Request 5 - Not Dropped. 17. Request 6 - Not Dropped. 18. Request 6 - Not Dropped. 19. Request 6 - Not Dropped. 20. Request 7 - Not Dropped. The total count of requests in the 10-second period from the first to the seventh second is 21, which exceeds the limit (21 > 20), so 1 request is dropped. 21. Request 7 - Dropped.


Example 3 :

Input: requestTime = [1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 7, 7, 7, 7, 11, 11, 11, 11]
Output: 7
Explanation: 1. Request 1 - Not Dropped. 2. Request 1 - Not Dropped. 3. Request 1 - Not Dropped. 4. Request 1 - Dropped. At most 3 requsts are allowed in one second. 5. No request will be dropped till 6 as all comes at an allowed rate of 3 requests per second and the 10-second clause is also not violated. 6. Request 7 - Not Dropped. The total number of requests has reached 20 now. 7. Request 7 - Dropped. At most 20 requests are allowed in ten seconds. 8. Request 7 - Dropped. At most 20 requests are allowed in ten seconds. 9. Request 7 - Dropped. At most 20 requests are allowed in ten seconds. Note that the 1-second limit is also violated here. 10. Request 11 - Not Dropped. The 10-second window has now become 2 to 11. Hence the total number of requests in this window is 20 now. 11. Request 11 - Dropped. At most 20 requests are allowed in ten seconds. 12. Request 11 - Dropped. At most 20 requests are allowed in ten seconds. 13. Request 11 - Dropped. At most 20 requests are allowed in ten seconds. Also, at most 3 requests are allowed per second. 14. Hence, a total of 7 requests are dropped.


Constraints:
1 ≤ n ≤ 106
1 ≤ requestTime[i] ≤ 109