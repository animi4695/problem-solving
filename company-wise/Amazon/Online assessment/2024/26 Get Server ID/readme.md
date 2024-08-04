# Task

The developers of Amazon are working on a prototype for a simple load-balancing algorithm. There are num_servers servers numbered from 0 to num_servers - 1 and the initial number of requests assigned to each server is 0.

In the i-th second, a request comes from IP hash of requests[i], and it must be assigned to the server with the minimum number of requests amongst the first requests[i] servers. For example, if requests[i] = 4, the request must be assigned to the server with the minimum number of requests amongst the servers with id [0, 1, 2, 3]. If there are multiple servers with the same minimum number of requests, choose the one with the minimum id. When a request is assigned to a server, its number of requests increases by 1.

Given num_servers and the array requests, for each request, find the id of the server it is assigned to.

constraints
1 ≤ num_servers ≤ 10^5
0 ≤ requests[i] < num_servers

Function Description

Complete the function getServerId in the editor.

getServerId takes the following arguments:

int num_servers: the number of servers
int requests[n]: the sizes of the requests
Returns

int[n]: the ids of the servers each request is assigned to


Input:  num_servers = 5, requests = [4, 0, 2, 2]
Output: [0, 0, 1, 2] 
Explanation:
        After the first request, the number of requests is [1, 0, 0, 0, 0]. After the second request, the number of requests is [2, 0, 0, 0, 0]. After the third request, the number of requests is [2, 1, 0, 0, 0]. After the fourth request, the number of requests is [2, 1, 1, 0, 0].


Input:  num_servers = 5, requests = [0, 1, 2, 3]
Output: [0, 1, 2, 3]
Explanation:
        Each request is assigned to the first index with the number of requests equal to 0.