# Multithreading
## Problem
You have been asked by the student council to monitor the use of washing
machines in OBH. You have to report the events of the day in the format provided
by the council with some statistics. In your conclusion line, you have to report if
more washing machines are needed or not. More washing machines are needed if
at least 25% of the students who came to the machines returned without getting
their clothes washed.
### During the entire day:
• N students will come to get their clothes washed
• There are M functioning washing machines
• The time at which the i-th student comes is T_i seconds after the execution of
the program
• The time taken to wash the i-th student's clothes is W_i seconds
• The patience of the i-th student is P_i seconds, after which he leaves without
getting his clothes washed
Statistics-
• Number of students who left without washing. Integer between 0 and N
• Total number of seconds wasted. Seconds wasted by a student
= Time at which he starts washing/leaves without washing - time of arrival
Given appropriate inputs, simulate the events using multi-threading. Avoid
deadlocks and busy waiting. Instead, use semaphores and mutex locks to
implement the problem. You are required to write your algorithm, followed by
implementational details in your report.
### Input format-
The first line contains 2 integers N and M.
The next N lines contain 3 integers T_i, W_i and P_i, the i-th line corresponding to
the detail's of the i-th student
Output format-
A relevant line has to be printed in the given color for the following events, with the
time at which it occurs:
Event Colour
- A student arrives to get their clothes washed (White)
- A student gets an empty washing machine to wash his clothes (Green)
- A student leaves after his washing is complete (Yellow)
- A student leaves without getting his clothes washed (Red)
  A single integer stating the number of students who came but could not wash their
  clothes.
  A single integer stating the total number of seconds wasted by all students
  waiting.
  A final line saying "Yes" if more washing machines are needed, or "No" if they are
  not needed. (in White)
  Example 1-
  Input-
  5 2
  6 3 5
  3 4 3
  6 5 2
  2 9 6
  8 5 2
  Output-
  2: Student 4 arrives
  2: Student 4 starts washing
  3: Student 2 arrives
  3: Student 2 starts washing
  6: Student 1 arrives
  6: Student 3 arrives
  7: Student 2 leaves after washing
  7: Student 1 starts washing
  8: Student 5 arrives
  8: Student 3 leaves without washing
  9: Student 1 leaves after washing
  9: Student 5 starts washing
  10: Student 5 leaves after washing
  11: Student 4 leaves after washing
  1
  4
  No
  ### Explanation-
  Time wasted by the students waiting:
  Student 1 = 1 second (7-6)
  Student 2 = 0 seconds (3-3)
  Student 3 = 2 second (8-6)
  Student 4 = 0 seconds (2-2)
  Student 5 = 1 second (9-8)
  Total = 4 seconds
  Number of students who left without washing = 1 (Student 3)
  Percentage of students left without washing = 20% which is less than 25%
  Therefore, no washing machines needed
  Example 2-
  Input:
  2 1
  2 5 1
  1 2 4
  2 4 2
  Output-
  1: Student 2 arrives
  1: Student 2 starts washing
  2: Student 1 arrives
  2: Student 3 arrives
  3: Student 2 leaves after washing
  3: Student 1 starts washing
  4: Student 3 leaves without washing
  7: Student 1 leaves after washing
  1
  3
  Yes
  ### Points to Ponder-
- If there are multiple students waiting, then the student who arrived first will use
  the machine first (FCFS)
- If there are multiple students arriving at the same time, the one with the lower
  index will go first
- If a student arrives at time t_i and has patience p_i, he can use the machine at
  time (t_i + p_i) if it gets empty at that second
- If a student arrives at time t_i and has patience p_i, he will leave at time (t_i + p_i)
  if there are no machines empty at that second

# Approach for the problem
To solve the given problem I have first used the concept of multithreading. I have first
created n numbers of threads which represent the number of students. And now to handle
situation of different arrival time I decided to use sleep() fuction to sleep the thread 
till it's arrival time, and after that the thread gets activated. 
I used semaphore of value m i.e. total number of washing machine which are available so 
that only m number of students and use the washing machine at a given time at max. Now to
handle the problem of timing, I used to function to store the value of start time by calling
it and subtract it from current time when needed to get the time lapse. By this way I solved 
the problem of total time wasted time wasted also. I have used sem_timedwait() function to 
implement the functionality of timeout. And incase of semaphore not locking I used else 
statement to also calculate the number of students left.