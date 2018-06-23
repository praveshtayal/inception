#include <climits>
#include <cmath>
#include <iostream>
using namespace std;

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
  
  int result = countStepsTo1(n, ans);
  delete []ans;
  return result;
}

int countStepsTo1_MIN(int n){
  int *ans = new int[n+1];
  ans[0] = ans[1] = 0;   /* Base Cases */
  for (int i=2;i<=n;i++)
  {
      int a = (i%3 == 0) ? ans[i/3]+1: INT_MAX;
      int b = (i%2 == 0) ? ans[i/2]+1: INT_MAX;
      int c = ans[i-1] + 1;
      ans[i] = min(a,b,c);
  }

  int result = ans[n];
  delete [] ans;
  return result;
}

long staircase(int n){
  /* A child is running up a staircase with n steps and can hop either 1 step,
   * 2 steps or 3 steps at a time. Implement a method to count how many
   * possible ways the child can run up to the stairs. You need to return all
   * possible number of ways. */
  if(n<=2) return n;
  long *ans = new long[n+1];
  ans[0] = 1;   /* Base Cases */
  ans[1] = 1;   /* Base Cases */
  ans[2] = 2;   /* Base Cases */
  for (int i=3;i<=n;i++)
      ans[i] = ans[i-3] +  ans[i-2] + ans[i-1];

  long result = ans[n];
  delete [] ans;
  return result;
}

int minCount(int n){
  /* Given an integer N, find and return the count of minimum numbers, sum of
   * whose squares is equal to N. That is, if N is 4, then we can represent it
   * as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the
   * minimum count of numbers required. */
  if(n<0) n *= -1; // -5 will have same value as 5 assuming we add iota
  int s = sqrt(n);
  if(s*s==n) return 1; // perfect square
  int *ans = new int[n+1];
  for (int i=0;i<=n;i++)
  {
    s = sqrt(i);
    if(s*s==i)
    {
      ans[i] = 1;
      continue;
    }
    ans[i] = 1 + ans[i-1];
    for (int j=2;j<s;j++)
    {
      int alternate = 1 +  ans[i-(j*j)];
      if( alternate<ans[i])
        ans[i] = alternate;
    }
  }

  int result = ans[n];
  delete [] ans;
  return result;
}

int balancedBTs(int h) {
  /* Given an integer h, find the possible number of balanced binary trees of
   * height h. You just need to return the count of possible binary trees which
   * are balanced. This number can be huge, so return output modulus 10^9 + 7.
   * */
#define BIGNUMBER 1000000007
  if(h<=1) return 1;
  int *ans = new int[h+1];
  ans[0] = ans[1] = 1;   /* Base Cases */
  for (int i=2;i<=h;i++)
    ans[i] = (ans[i-1]*ans[i-1] + 2*ans[i-1]*ans[i-2]) % BIGNUMBER;

  int result = ans[h];
  delete [] ans;
  return result;
}

int balancedBTs2(int h) {
  /* Given an integer h, find the possible number of balanced binary trees of
   * height h. You just need to return the count of possible binary trees which
   * are balanced. This number can be huge, so return output modulus 10^9 + 7.
   * */
  return 0;
}

int main()
{
  balancedBTs(10);
  return 0;
}
