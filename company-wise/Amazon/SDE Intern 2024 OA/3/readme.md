Amazon prime video has movies in the category 'comedy' or 'drama'. Determine the earliest time you can finish at least one movie from each category. The release schedule and duration of the movies are provided.

- You can start watching a movie at the time it is released or later.
- If you begin a mvoie at time t, it ends at time t + duration.
- If a movie ends at time t + duration, the second movie can start at that time, t + duration, or later.
- The movies can be watched in any order.

Example:

comedyRelease Time = [1,4]
comedyDuration = [3,2]
dramaReleastTime = [5,2]
dramaDuration = [2,2]

Duration and release times are aligned by index.

Two of the best ways to finish watching one movie from each category at the earliest time are as follows:

- start watching comedy movie1 at time t = 1 and until t = 1 + 3 = 4. then, watch the drama movie2 from time t = 4 to t = 4 + 2 = 6.
- Start watching drama movie2  at time t = 2 and until t = 2 + 2 = 4. then, watch the comedy movie2 from time t = 4 to t = 4 + 2 = 6
The earliest finish time and also the answer is 6.

Examples that are sub-optimal include:

- start watching a comedy movie2 at time t = 4 and until t = 4 + 2 = 6. Then, watch the drama movie1 from time t = 6 to t = 6 + 2 = 8.
- Start watching a comedy movie1 at time t = 1 and until t = 1 + 3 = 4. then, watch the drama movie1 from time t = 5 to t = 5 + 2 = 7.