Matrix Multiplication Performance Analysis

![image](https://github.com/user-attachments/assets/06aa5db0-d16c-4ec4-8313-7ff7f328adef)

As can be seen in the figure, execution times for main thread performing matrix multiplication on entire 1000x1000, main thread performing matrix multiplication on two 500x1000 one after the other, single thread(not main thread) performing matrix multiplication on entire 1000x1000 will be almost same(around 5.5 - 5.6 sec) as there is no parellelism involved.

If we are using two threads(not including main thread) and executing matrix multiplication on 500x1000 matrices in parellel, the execution time is going to be significantly reduced. It was 2.6 sec for this scenario. This was almost twice as fast as the scenario with no multithreading.

But as we increase the number of threads, the performance jump(speed up) just won't be as much as the amount of parellelisable code won't change. This was observed in four threads scenario. In this scenario, each thread works on only 250x1000 matrix multiplication and all four run in parellel. Execution time was around 1.7 sec, which is better than two threads scenario but not as significant as the jump from no multithreading to using two threads. 
According to Amdahl's law,
Speed up = 1/(1 - X + X/N) where X = % of code parellelisable, N = Number parellel executions.
Amdahl's law shows that the speed up decreases as you increase parellelisable cores and not change the amount of parellelisable code.  
