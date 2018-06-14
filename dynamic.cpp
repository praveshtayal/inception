#include <climits>
#include <cmath>
#include <iostream>

inline int min(int a, int b, int c=INT_MAX)
{
  int min2 = (a<b?a:b);
  return (min2<c?min2:c);
}

int countStepsTo1(int n, int *ans){
  /* Given a positive integer n, find the minimum number of steps s, that takes
   * n to 1. You can perform any one of the following 3 steps. 
   * 1.) Subtract 1 from it. (n= n - ­1) ,
   * 2.) If its divisible by 2, divide by 2.( if n%2==0, then n= n/2 ) ,
   * 3.) If its divisible by 3, divide by 3. (if n%3 == 0, then n = n / 3 ).*/
  if (n<=1) return 0;
  
  /* Return the saved answer, if available */
  if (ans[n] != -1) return ans[n];
  
  int a=INT_MAX, b=INT_MAX, c;
  if(n%3 == 0) a = countStepsTo1(n/3,ans);
  if(n%2 == 0) b = countStepsTo1(n/2,ans);
  c = countStepsTo1(n-1,ans);
  
  ans[n] = min(a,b,c) + 1;
  return ans[n];
}

int countStepsTo1(int n){
  int *ans = new int[n+1];
  
  for (int i=0;i<=n;i++)
      ans[i] = -1;
  
  return countStepsTo1(n, ans);
}

int countStepsTo1_MIN(int n){
  int *ans = new int[n+1];
  int a, b, c;

  ans[0] = ans[1] = 0;   /* Base Cases */
  for (int i=2;i<=n;i++)
  {
      a = INT_MAX;
      b = INT_MAX;
      if(i%3 == 0) a = ans[i/3]+1;
      if(i%2 == 0) b = ans[i/2]+1;
      c = ans[i-1] + 1;

      ans[i] = min(a,b,c);
  }

  return ans[n];
}

