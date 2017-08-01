## [070. Climbing Stairs](https://leetcode.com/problems/minimum-path-sum/description/)
### 题目要求：
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
### 我的解法：
斐波那契数列
```c
    int climbStairs(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        int a=1,b=2,c;
        while(n>=3){
            c=a+b;
            a=b;
            b=c;
            --n;
        }
        return c;
    }
```
