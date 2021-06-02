Ref :
https://leetcode.com/discuss/interview-question/823550/amazon-oa-2020-optimize-memory-usage
https://leetcode.com/discuss/interview-question/373202

note : I haven't solved this problem completely. Need to check few edge cases


Give a computer with total K memory space, and an array of foreground tasks and background tasks the computer needs to do. Write an algorithm to find a pair of tasks from each array to maximize the memory usage. Notice the tasks could be done without origin order.

Input
The input to the function/method consists of three arguments :
foregroundTask, an array representing the memory usage of the foreground tasks,
backgroundTask, an array representing the memory usage of the background tasks,
K, the total memory space of the computer.

Output
Return a list of pairs of the task ids.

Examples 1
Input:
foregroundTasks = [1, 7, 2, 4, 5, 6]
backgroundTasks = [3, 1, 2]
K = 6

Output:
[(3, 2), (4, 1), (5,-1)]

Explaination:
Here we have 5 foreground tasks: task 0 uses 1 memeory. task 1 uses 7 memeory. task 2 uses 2 memeory..
And 5 background tasks: task 0 uses 3 memeory. task 1 uses 1 memeory. task 2 uses 2 memeory..
We need to find two tasks with total memory usage sum <= K.
Here we can return the foreground task 3 and background task 2, which total use 6 units of memory.
Or we can return the foreground task 4 and background task 1. Also use total 6 units of memory.
Or we can return the foreground task 5 only without any background task. Also use total 6 units of memory.