Several processes are scheduled for execution on an AWS Server.

On one server, n processes are scheduled where the ith process is assigned a priority of *priority[i]*. The processes are placed sequentially in a queue and are numbered 1,2,3....n. The server schedules the processes per the following algorithm:

1. It finds the maximum priority shared by at least 2 processes. Let that be denoted by p.
2. Otherwise, select the two of the processes with the lowest indexes and priority p, call them *process1* and *process2*.
3. The server executes process1 and removes it from the queue.
4. To avoid starvation, it reduces the priority of process2 to floow(p/2).
5. Start again from step 1.

Given the initial priority of the processes, find the final priority of the processes which remain after the algorithm terminates.

Note that relative the arrangment of remaining processes in the queue remains the same, only their priorities change.

Example

The number  of processes n = 6, priorities, *prority = [6,6,6,1,2,2].*

The scheduler works as follows:
- p = 6 at indices 1,2 and 3. The indices used are process1 = 1, process2 = 2. Remove process1 and update the priority of process 2 to floow(6/2) = 3.
- p = 2 and process1 = 4, process2 = 5. So, update the priority = floor(2/2) = 1 of process2 and remove process1. Current set of process priorities, priority = [3,6,1,1].
- p = 1 and process1 = 3, process2 = 4. So, update the priority = floor(1/2) = 0 of process2 and remove process1. Current set of process priorities, priority = [3,6,0].
- There are no more matching process priorities so the algorithm ends.
The final priorities of the remaining processes are priority = [3,6,0].

i/p:

4
4
4
2
1

o/p :

0