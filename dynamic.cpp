#include <climits>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

// Brute Force
int countStepsTo1(int n){
    if(n<=1) return 0;
    int subtract = countStepsTo1(n-1);
    int div2 = (n%2==0)?countStepsTo1(n/2):INT_MAX;
    int div3 = (n%3==0)?countStepsTo1(n/3):INT_MAX;
    return 1+min(subtract,min(div2,div3));
}

// Memoiztion
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

    ans[n] = min(min(a,b),c) + 1;
    return ans[n];
}

// Memoiztion
int countStepsTo1Mem(int n){
    int *ans = new int[n+1];

    for (int i=0;i<=n;i++)
        ans[i] = -1;

    int result = countStepsTo1(n, ans);
    delete []ans;
    return result;
}

// Dynamic Programming
int countStepsTo1DP(int n){
    int *ans = new int[n+1];
    ans[0] = ans[1] = 0;     /* Base Cases */
    for (int i=2;i<=n;i++)
    {
        int a = (i%3 == 0) ? ans[i/3]+1: INT_MAX;
        int b = (i%2 == 0) ? ans[i/2]+1: INT_MAX;
        int c = ans[i-1] + 1;
        ans[i] = min(min(a,b),c);
    }

    int result = ans[n];
    delete [] ans;
    return result;
}

// Brute Force
long staircase(int n){
    /* A child is running up a staircase with n steps and can hop either 1 step,
     * 2 steps or 3 steps at a time. Implement a method to count how many
     * possible ways the child can run up to the stairs. You need to return all
     * possible number of ways. */
    if(n<=2) return n;
    if(n==3) return 4;
    return staircase(n-1) + staircase(n-2) + staircase(n-3);
}

// Dynamic Programming
long staircaseDP(int n){
    /* A child is running up a staircase with n steps and can hop either 1 step,
     * 2 steps or 3 steps at a time. Implement a method to count how many
     * possible ways the child can run up to the stairs. You need to return all
     * possible number of ways. */
    if(n<=2) return n;
    long *ans = new long[n+1];
    ans[0] = 0;     /* Base Cases */
    ans[1] = 1;     /* Base Cases */
    ans[2] = 2;     /* Base Cases */
    ans[3] = 4;     /* Base Cases */
    for (int i=4;i<=n;i++)
        ans[i] = ans[i-3] +    ans[i-2] + ans[i-1];

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
            int alternate = 1 +    ans[i-(j*j)];
            if( alternate<ans[i])
                ans[i] = alternate;
        }
    }

    int result = ans[n];
    delete [] ans;
    return result;
}

// Brute Force
int balancedBTs(int h) {
    /* Given an integer h, find the possible number of balanced binary trees of
     * height h. You just need to return the count of possible binary trees which
     * are balanced. This number can be huge, so return output modulus 10^9 + 7. */
#define BIGNUMBER 1000000007
    if(h<=1) return 1;
    long h1 = balancedBTs(h-1);
    long h2 = balancedBTs(h-2);
    // (h1*h1) + 2*(h1*h2)
    long h1Mul = (h1*h1)%BIGNUMBER;
    long h2Mul = (h1*h2)%BIGNUMBER;
    return (h1Mul + ((2*h2Mul)%BIGNUMBER))%BIGNUMBER;
}

// Dynamic Programming
int balancedBTsDP(int h) {
    /* Given an integer h, find the possible number of balanced binary trees of
     * height h. You just need to return the count of possible binary trees which
     * are balanced. This number can be huge, so return output modulus 10^9 + 7. */
#define BIGNUMBER 1000000007
    if(h<=1) return 1;
    long *ans = new long[h+1];
    ans[0] = ans[1] = 1;     /* Base Cases */
    for (int i=2;i<=h;i++)
    {
        long a = (ans[i-1]*ans[i-1]) % BIGNUMBER;
        long b = (2*ans[i-1]*ans[i-2]) % BIGNUMBER;
        ans[i] = (a + b) % BIGNUMBER;
    }

    int result = (int)ans[h];
    delete [] ans;
    return result;
}

int minCostPath(int **input, int m, int n) {
    /* Given an integer matrix of size m*n, you need to find out the value of
     * minimum cost to reach from the cell (0, 0) to (m-1, n-1). 
     * From a cell (i, j), you can move in three directions : (i+1, j), (i, j+1)
     * and (i+1, j+1).
     * Cost of a path is defined as the sum of values of each cell through which
     * path passes. */
    /* Solution: we will calculate minCostPath for each cell dynamically */
    for(int j=1; j<n; j++)
        input[0][j] += input[0][j-1];
    for(int i=1; i<m; i++)
        input[i][0] += input[i-1][0];
    for(int i=1; i<m; i++)
        for(int j=1; j<n; j++)
            input[i][j] += min(min(input[i-1][j],input[i][j-1]),input[i-1][j-1]);

    return input[m-1][n-1];
}

int lcsBF(string s1, string s2){
    /* Given 2 strings of S1 and S2 with lengths m and n respectively, find the
     * length of longest common subsequence.*
     * A subsequence of a string S whose length is n, is a string containing
     * characters in same relative order as they are present in S, but not
     * necessarily contiguous. Subsequences contain all the strings of length
     * varying from 0 to n. E.g. subsequences of string "abc" are
     * - "",a,b,c,ab,bc,ac,abc. */
    if(s1.length()==0 || s2.length()==0) return 0;
    // both strings have atleast one character
    int a = s1[0]==s2[0] ? lcsBF(s1.substr(1), s2.substr(1)) : INT_MIN;
    int b=lcsBF(s1.substr(1), s2);
    int c=lcsBF(s1, s2.substr(1));

    return max(a+1, max(b, c));
}

int lcsMZ(string s1, string s2, int** result){
    int m = s1.length(), n = s2.length();
    if(m==0 || n==0) return 0;
    if(result[m-1][n-1]!=-1) return result[m-1][n-1];
    int a = s1[0]==s2[0] ? lcsMZ(s1.substr(1), s2.substr(1), result) :
        INT_MIN;
    int b=lcsMZ(s1.substr(1), s2, result);
    int c=lcsMZ(s1, s2.substr(1), result);

    result[m-1][n-1] = max(a+1, max(b, c));
    return result[m-1][n-1];
}

int lcsMZ(string s1, string s2){
    /* Given 2 strings of S1 and S2 with lengths m and n respectively, find the
     * length of longest common subsequence.*
     * A subsequence of a string S whose length is n, is a string containing
     * characters in same relative order as they are present in S, but not
     * necessarily contiguous. Subsequences contain all the strings of length
     * varying from 0 to n. E.g. subsequences of string "abc" are
     * - "",a,b,c,ab,bc,ac,abc. */
    if(s1.length()==0 || s2.length()==0) return 0;
    // both strings have atleast one character
    // Initialize result (2D Array of size m*n) to -1
    int m = s1.length(), n = s2.length();
    int **result = new int*[m];
    for(int i=0; i<m; i++)
    {
        result[i] = new int[n];
        for(int j=0; j<n; j++)
            result[i][j] = -1;
    }
    int ans = lcsMZ(s1, s2, result);
    for(int i=0; i<m; i++)
    {
        delete [] result[i];
    }
    delete [] result;
    return ans;
}

int lcsDP(string s1, string s2){
    /* Given 2 strings of S1 and S2 with lengths m and n respectively, find the
     * length of longest common subsequence.*
     * A subsequence of a string S whose length is n, is a string containing
     * characters in same relative order as they are present in S, but not
     * necessarily contiguous. Subsequences contain all the strings of length
     * varying from 0 to n. E.g. subsequences of string "abc" are
     * - "",a,b,c,ab,bc,ac,abc. */
    if(s1.length()==0 || s2.length()==0) return 0;
    // both strings have atleast one character
    // Initialize result (2D Array of size m*n) to -1
    int m = s1.length(), n = s2.length();
    int **result = new int*[m];
    for(int i=0; i<m; i++)
    {
        result[i] = new int[n];
    }
    // Fill in the first row
    for(int j=0; j<n; j++)
        result[0][j] = (s1[m-1]==s2[n-1-j])? 1:0;
    // Fill in the first column
    for(int i=1; i<m; i++)
        result[i][0] = (s1[m-1-i]==s2[n-1])? 1:0;

    for(int i=1; i<m; i++)
        for(int j=1; j<n; j++)
        {
            int a = s1[m-1-i]==s2[n-1-j] ? result[i-1][j-1] : INT_MIN;
            int b = result[i-1][j];
            int c = result[i][j-1];
            result[i][j] =    max(a+1, max(b, c));
        }
    int ans = result[m-1][n-1];
    for(int i=0; i<m; i++)
    {
        delete [] result[i];
    }
    delete [] result;
    return ans;
}

int editDistanceBF(string s1, string s2){
    /* Given two strings s and t of lengths m and n respectively, find the Edit
     * Distance between the strings. Edit Distance of two strings is minimum
     * number of steps required to make one string equal to other. In order to do
     * so you can perform following three operations only :*
     * 1. Delete a character
     * 2. Replace a character with another one
     * 3. Insert a character */
    // return max(s1.length(),s2.length()) - lcsDP(s1,s2);
    if(s1.length()==0) return s2.length();
    if(s2.length()==0) return s1.length();

    // both strings have atleast one character
    if(s1[0]==s2[0]) return editDistanceBF(s1.substr(1), s2.substr(1));
    int a=editDistanceBF(s1.substr(1), s2);  //Insert Operation
    int b=editDistanceBF(s1, s2.substr(1));  //Delete Operation
    int c=editDistanceBF(s1.substr(1), s2.substr(1)); //Replace Operation

    return min(min(a, b), c)+1;
}

int editDistanceDP(string s1, string s2){
    /* Given two strings s and t of lengths m and n respectively, find the Edit
     * Distance between the strings. Edit Distance of two strings is minimum
     * number of steps required to make one string equal to other. In order to do
     * so you can perform following three operations only :*
     * 1. Delete a character
     * 2. Replace a character with another one
     * 3. Insert a character */
    // return max(s1.length(),s2.length()) - lcsDP(s1,s2);
    if(s1.length()==0) return s2.length();
    if(s2.length()==0) return s1.length();

    // both strings have atleast one character
    // Initialize result (2D Array of size m*n) to -1
    int m = s1.length(), n = s2.length();
    int **result = new int*[m];
    for(int i=0; i<m; i++)
    {
        result[i] = new int[n];
    }
    bool found;
    // Fill in the first row
    for(int j=0, found=false; j<n; j++)
    {
        if(s1[m-1]==s2[n-1-j]) found = true;
        result[0][j] = found? j:j+1;
    }
    // Fill in the first column
    for(int i=1, found=false; i<m; i++)
    {
        if(s1[m-1-i]==s2[n-1]) found = true;
        result[i][0] = found? i:i+1;
    }

    for(int i=1; i<m; i++)
        for(int j=1; j<n; j++)
        {
            if(s1[m-1-i]==s2[n-1-j]) result[i][j] = result[i-1][j-1];
            else
            {
                int a = result[i-1][j];
                int b = result[i][j-1];
                int c = result[i-1][j-1];
                result[i][j] = min(min(a, b), c) + 1;
            }
        }
    int ans = result[m-1][n-1];
    for(int i=0; i<m; i++)
        delete [] result[i];
    delete [] result;
    return ans;
}

int knapsack(int* weights, int* values, int n, int maxWeight){
    /* A thief robbing a store and can carry a maximal weight of W into his
     * knapsack. There are N items and ith item weigh wi and is value vi. What is
     * the maximum value V, that thief can take ?*/
    if(weights==nullptr || values==nullptr || n<=0 || maxWeight<=0) return 0;
    if(n==1) // Base Case
    {
        if(weights[0]<=maxWeight) return values[0];
        return 0;
    }
    if(weights[0]>maxWeight) // 0 item cannot be included
        return knapsack(weights+1, values+1, n-1, maxWeight);
    // 0 item can be included
    int included = knapsack(weights+1, values+1, n-1, maxWeight-weights[0]);
    int notincluded = knapsack(weights+1, values+1, n-1, maxWeight);
    return max(included+values[0], notincluded);
}

// Brute Force
int getMaxMoney(int arr[], int n){
    /* A thief wants to loot houses. He knows the amount of money in each house.
     * He cannot loot two consecutive houses. Find the maximum amount of money he
     * can loot.*/
    if(arr==nullptr || n<=0) return 0;
    if(n==1) return arr[0]; // Base Case
    int dontchoose0 = getMaxMoney(arr+1, n-1);
    int choose0 = getMaxMoney(arr+2, n-2);
    return max(arr[0]+choose0, dontchoose0);
}

// Memoization
int getMaxMoney(int arr[], int n, int *ans){
    /* A thief wants to loot houses. He knows the amount of money in each house.
     * He cannot loot two consecutive houses. Find the maximum amount of money he
     * can loot.*/
    if(arr==nullptr || n<=0) return 0;
    if(n==1)
    {
        return arr[0]; // Base Case
    }
    if(ans[n]!=-1) return ans[n];
    int dontchoose0 = getMaxMoney(arr+1, n-1, ans);
    int choose0 = getMaxMoney(arr+2, n-2, ans);
    ans[n] =    max(arr[0]+choose0, dontchoose0);
    return ans[n];
}

int getMaxMoneyMem(int arr[], int n){
    /* A thief wants to loot houses. He knows the amount of money in each house.
     * He cannot loot two consecutive houses. Find the maximum amount of money he
     * can loot.*/
    int *ans = new int[n+1];
    for (int i=0;i<=n;i++)
        ans[i] = -1;
    int result = getMaxMoney(arr, n, ans);
    delete [] ans;
    return result;
}

int getMaxMoneyDP(int arr[], int n){
    /* A thief wants to loot houses. He knows the amount of money in each house.
     * He cannot loot two consecutive houses. Find the maximum amount of money he
     * can loot.*/
    if(arr==nullptr || n<=0) return 0;
    if(n==1) return arr[0];
    int *ans = new int[n+1];
    ans[0]=arr[0];
    ans[1]=max(arr[0], arr[1]);
    for (int i=2;i<=n;i++)
        ans[i] = max(ans[i-2]+arr[i], ans[i-1]);
    int result = ans[n];
    delete [] ans;
    return result;
}

/*
   int lis(int arr[], int n) {
   if(arr==nullptr || n<=0) return 0;
   if(n==1) return 1;
   if(
   }
   */
int lisDP(int arr[], int n) {
    /* Given an array with N elements, you need to find the length of the longest
     * subsequence of a given sequence such that all elements of the subsequence
     * are sorted in strictly increasing order.*/
    if(arr==nullptr || n<=0) return 0;
    if(n==1) return 1;
    int *ans = new int[n+1];
    // ans[i] represents longest subsequence length if n=i && i is included
    ans[0]=1;
    int max=1;
    for (int i=1;i<=n;i++)
    {
        ans[i] = 1;
        for (int j=0;j<i;j++)
            if(arr[i]>arr[j])
                if(ans[i]<ans[j]+1)
                {
                    ans[i]=ans[j]+1;
                    if(ans[i]>max) max=ans[i];
                }
    }
    //copy(ans, &ans[n], ostream_iterator<int>(cout, " "));
    delete [] ans;
    return max;
    /* Note the complexity for this code is n square. We can optimize it further
     * using ordered maps to nlogn. */
}

int vectorSum(int *arr, int size, int sum) {
    /* How many ways can elements of array arr add to sum. */
    if(size<=0) return 0;
    if(size==1) {
        if(arr[0]==sum) return 1;
        return 0;
    }
    int ans=0;
    // Can the last element of array be included
    if(arr[size-1]==sum) return 1+vectorSum(arr, size-1, sum);
    if(arr[size-1]<sum) return vectorSum(arr, size-1, sum-arr[size-1])+
        vectorSum(arr, size-1, sum);
    return vectorSum(arr, size-1, sum);
}

int allWays(int x, int n) {
    /* Given two integers a and b. You need to find and return the count of
     * possible ways in which we can represent the number a as the sum of unique
     * integers raise to the power b. For eg. if a = 10 and b = 2, only way to
     * represent 10 as: 10 = 1^2 + 3^2.
     * Hence, answer is 1. */
    vector<int> p;
    // p[i] represents i^n
    p.push_back(1);
    for (int i=2, j=pow(i,n);j<=x;j=pow(++i,n))
        p.push_back(j);
    return vectorSum(&p[0], p.size(), x);
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value){
    /* You are given an infinite supply of coins of each of denominations
     * D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number
     * of ways W, in which you can make change for Value V using coins of
     * denominations D. Note : Return 0, if change isn't possible. */
    if(denominations==nullptr || numDenominations<=0) return 0;
    int last = denominations[numDenominations-1];
    if(last==value)
        return 1+countWaysToMakeChange(denominations, numDenominations-1, value);
    if(last<value)
        return countWaysToMakeChange(denominations, numDenominations, value-last)
            + countWaysToMakeChange(denominations, numDenominations-1, value);
    return countWaysToMakeChange(denominations, numDenominations-1, value);
}

int countWaysToMakeChange1(int denominations[], int numDenominations, int value){
    /* You are given an infinite supply of coins of each of denominations
     * D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number
     * of ways W, in which you can make change for Value V using coins of
     * denominations D. Note : Return 0, if change isn't possible. */
    if(denominations==nullptr || numDenominations<=0) return 0;
    int count = countWaysToMakeChange(denominations, numDenominations-1, value);
    int last = denominations[numDenominations-1];
    if(last>value) return count;
    else if(last==value) return count+1;
    else return count + countWaysToMakeChange(denominations, numDenominations, value-last);
}

int countWaysToMakeChangeDP(int denominations[], int numDenominations, int value){
    /* You are given an infinite supply of coins of each of denominations
     * D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number
     * of ways W, in which you can make change for Value V using coins of
     * denominations D. Note : Return 0, if change isn't possible. */
    if(denominations==nullptr || numDenominations<=0) return 0;
    // Allocate memory for 2D array
    int **result = new int*[numDenominations];
    for(int i=0; i<numDenominations; i++)
        result[i] = new int[value+1];

    // Update result array
    for(int i=0; i<numDenominations; i++)
        for(int j=0; j<=value; j++)
        {
            result[i][j] = 0;
        }

    // Save ans and Release memory for 2D array
    int ans = result[numDenominations-1][value];
    for(int i=0; i<numDenominations; i++)
        delete [] result[i];
    delete [] result;
    return ans;
}

int mcm(int* p, int n){
    /* Given a chain of matrices A1, A2, A3,.....An, you have to figure out the
     * most efficient way to multiply these matrices i.e. determine where to
     * place parentheses to minimise the number of multiplications.
     * You will be given an array p[] of size n + 1. Dimension of matrix Ai is
     * p[i - 1]*p[i]. You need to find minimum number of multiplications needed
     * to multiply the chain.*/
    if(p==nullptr || n<3) return 0; // Invalid input
    // Matrix of size (n-2)*(n-2)
    int size = n-2;
    // result[i][j] represent matrix starting from i and ending at j+2
    int **result = new int*[size];
    for(int i=0; i<size; i++)
        result[i] = new int[size];
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++) {
            if(i>j) result[i][j] = INT_MAX;
            else if(i==j) result[i][j] = p[i]*p[i+1]*p[i+2];
            else {
                result[i][j] = result[i][j-1] + p[i]*p[j+1]*p[j+2];
                    // Here i<j
                    for(int k=i; k+2<j; k++) {
                        int operations = p[i]*p[i+1]*p[i+2];
                        result[i][j] = p[i]*p[i+1]*p[i+2];
                    }
            }
        }

    for(int i=0; i<size; i++)
        delete [] result[i];
    delete [] result;


    if(n==3) return p[0]*p[1]*p[2]; // Base Case, only 1 possibility

    // If we do first matrix multiplication (A1*A2)*..An
    int opt1 = p[0]*p[1]*p[2]; 
    swap<int>(p[0],p[1]); // We need to save p[1] and pass p[0]
    opt1 += mcm(p+1, n-1);
    swap<int>(p[0],p[1]); // Reverse the swap

    // If we do matrix multiplication A1*(A2*..An)
    int opt2 = mcm(p+1,n-1);
    opt2 += p[0]*p[1]*p[n-1];
    return min(opt1, opt2);
}

string solve(int n, int x, int y)
{
    /* Coin Tower: Whis and Beerus are playing a new game today . They form
     * a tower of N coins and make a move in alternate turns . Beerus being the
     * God plays first . In one move player can remove 1 or X or Y coins from the
     * tower . The person to make the last move wins the Game . Can you find out
     * who wins the game ?
     * Output will be A string containing the name of the winner like “Whis” or
     * “Beerus” (without quotes)
     * Constraints: 1<=n<=10^6, 2<=x<=y<=50 */
    return 0;
}

class MaxSquareWithAllZeros {
    private:
        int **arr, row, col;
    public:
        MaxSquareWithAllZeros(int** _arr, int _row, int _col)
            : arr(_arr), row(_row), col(_col)
        {
        }

        int findMatrix(int i, int j)
        {
            if(i==row || j==col){
                return 0;
            }
            int op1 = findMatrix(i+1, j);
            int op2 = findMatrix(i, j+1);
            int maximum = max(op1, op2);

            if(min(row-i, col-j)<maximum)
                return maximum;

            for(int p=0; p<=maximum; p++)
                for(int q=0; q<=maximum; q++)
                    if(arr[i+p][j+q]==1)
                        return maximum;
            return maximum+1;
        }
};
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    /* Given a n*m matrix which contains only 0s and 1s, find out the size of
     * maximum square sub-matrix with all 0s. You need to return the size of
     * square with all 0s. */
    int **storage;
    storage = new int*[row+1];
    for(int i=0; i<=row; i++)
    {
        storage[i] = new int[col+1];
        for(int j=0; j<=col; j++)
            storage[i][j] = 0;
    }
    for(int i=row-1; i>=0; i--)
        for(int j=col-1; j>=0; j--)
        {
            int maximum = storage[i][j] = max(storage[i+1][j], storage[i][j+1]);

            if(min(row-i, col-j)<=maximum)
                continue;

            bool foundOne = false;
            for(int p=0; p<=maximum; p++)
                for(int q=0; q<=maximum; q++)
                    if(arr[i+p][j+q]==1){
                        foundOne = true;
                        p = q = maximum+1;
                    }
            if(foundOne==false)
                storage[i][j] += 1;
        }
    int ans = storage[0][0];
    for(int i=0; i<=row; i++)
        delete [] storage[i];
    delete [] storage;
    return ans;
}

int solve(string S,string V)
{
    /* Gary has two string S and V. Now Gary wants to know the length shortest
     * subsequence in S such that it is not a subsequence in V. Note: input data
     * will be such so there will always be a solution.*/
    return 0;
}

int getArray(int arr[], int size)
{
    cin >> size;
    // Read the array
    for(int j=0;j<size;++j) 
        cin >> arr[j];
    return size;
}


int main()
{
    //balancedBTs(10);
    //cout << lcsMZ("adebc", "dcadb") << endl;
    //cout << editDistanceBF("adebc", "dcadb") << endl;
    //cout << editDistanceDP("adebc", "dcadb") << endl;
    //int n, arr[1000000];
    //n = getArray(arr,1000000);
    //copy(arr, &arr[n-1], istream_iterator<int>(cin, " "));
    //cout << lisDP(arr, n) << endl; 
    //copy(arr, &arr[n], ostream_iterator<int>(cout, " "));
    int m, n, **arr;
    cin >> m >> n;
    arr = new int*[m];
    for(int i=0; i<m; i++)
    {
        arr[i] = new int[n];
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    }
    int maximum = findMaxSquareWithAllZeros(arr, m, n);
    cout << maximum << endl;

    return 0;
}
