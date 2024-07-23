# Task

Maximum User Traffic

In order to ensure a hassle-free user experience during the festive season, Amazon maintains logs of the days when its users use the Amazon Shopping app.

The user traffic of a day is said to be the maximum number of users logged into the application during that day. If a user uses the application from day login[i] to day logout[i] , it increases the traffic of each day from login[i] to logout[i] (both inclusive) by 1. That is, if login[i] = 4 and logout[i] = 6, then this user increases the traffic of days 4, 5 and 6 by 1.

Given the login and logout day data of n users, find the number of days on which the user traffic is maximum.

Note that all logins take place before all logouts on a single day.


Function Description

Complete the function maximumUserTraffic in the editor below.

maximumUserTraffic has the following parameter(s):

int login[n] : an array of integers with login[i] denoting the login day of i ^th user.
int logout[n] : an array of integers with logout[i] denoting the logout day of i ^th user.

Returns

int : the number of days having maximum user traffic


Example 1 :

Input: login = [1, 2, 3], logout = [10, 8, 4]
Output: 2
Explanation: The max user traffic is 3, which occurs on 2 days: day 3 and day 4. The answer is 2.


Constraints:
1 ≤ n ≤ 10^5
0 ≤ login[i], logout[i] ≤ 10^5
login[i] ≤ logout[i]