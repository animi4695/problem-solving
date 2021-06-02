Ref : https://leetcode.com/discuss/interview-question/868371/amazon-oa-critical-connections

Question:
Amazon wants to pilot hardware replacements in data center AMZN525, to increase the reliability of the network. AMZN525 has a "connected" network of data servers i.e. every server can communicate with the rest of the network. The data servers are connected by point-to-point cables to establish "critical" or "non-critical" connections. A connection is considered "critical" if its removal results in a disconnected network of servers. Amazon wants to significantly increase the reliability of its Data Centers by replacing the critical connections with far more reliable cables.

Write a method that returns critical connections in AMZN525.

Input:
The input to the method consists of three arguments -
numOfServers an integer representing number of servers in the data center;
numOfConnections an integer representing number of connections between the servers;
connections a list of pairs of integers representing the connections between the two servers.

Output
Return a list of pairs of integers representing the critical connections. If there are no critical connectionr, return a list with an empty pair - not just an empty list.

Constraints
0 <= numOfServers <= 10^5
0 <= numOfConnections <= 10^5
1 <= connections[i][j] <= numOfServers
0 <= i <= numOfConnections
0 <= j <2

Example
Input:
numOfServers=5
numOfConnections=5
connections=[[1,2],[1,3],[3,4],[1,4],[4,5]]

Output:
[[1,2],[4,5]]