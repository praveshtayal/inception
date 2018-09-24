#include<iostream>
#include<cmath>
#define THOUSAND 1000
using namespace std;

int getArray(int arr[], int size)
{
  cin >> size;
  // Read the array
  for(int j=0;j<size;++j) 
    cin >> arr[j];
  return size;
}

void printArray(int arr[], int size)
{
  // Print Array
  cout << "The array of size " << size << " is: " << endl;
  for(int i=0;i<size;++i)
    cout << arr[i] << ' ';
  cout << endl;
}

void print(int n){
  /* Given the code to print number from 1 to n in increasing order
   * recursively. But it contains few bugs, that you need to rectify such that
   * all the test cases should pass.*/
    if(n == 1){
        cout << n << " ";
      return;
    }
    print(n - 1);
    cout << n << " ";
}

int count(int n){
  /* return the number of digits present in a number recursively */
    if(n == 0){
        return 0;
    }
    int smallAns = count(n / 10);
    return smallAns + 1;
}

int power(int x, int n) {
  /* find x to the power n (i.e. x^n) */
    if(n == 0){
        return 1;
    }
    int smallAns = power(x,n-1);
    return smallAns * x;
}

int sum(int n) {
  /* Given an integer n, find and return the sum of numbers from 1 to n using
   * recursion.*/
    if(n == 1){
        return 1;
    }
    int smallAns = sum(n-1);
    return smallAns + n;
}

int sumArray(int input[], int n) {
  /* Given an array of length N, you need to find and return the sum of all
   * elements of the array.*/
    if(n == 1){
        return input[0];
    }
    int smallAns = sumArray(input, n-1);
    return smallAns + input[n-1];
}

bool checkNumber(int input[], int size, int x) {
  /* Given an array of length N and an integer x, you need to find if x is
   * present in the array or not. Return true or false.*/
    if(size == 1){
        return x==input[0];
    }
    bool smallAns = checkNumber(input, size-1, x);
    return smallAns || (x==input[size-1]);

}

int firstIndex(int input[], int size, int x) {
  /* Given an array of length N and an integer x, you need to find and return
   * the first index of integer x present in the array. Return -1 if it is not
   * present in the array. First index means, the index of first occurrence of
   * x in the input array. Do this recursively. Indexing in the array starts
   * from 0. */
    if(size <= 0){
        return -1;
    }
    if(x==input[0]) return 0;
    int smallAns = firstIndex(input+1, size-1, x);
    if(smallAns == -1)
      return -1;
    else
      return smallAns+1;
}

int lastIndex(int input[], int size, int x) {
  /* Given an array of length N and an integer x, you need to find and return
   * the last index of integer x present in the array. Return -1 if it is not
   * present in the array. Last index means - if x is present multiple times in
   * the array, return the index at which x comes last in the array. */
    if(size <= 0){
        return -1;
    }
    if(x==input[size-1]) return size-1;
    int smallAns = lastIndex(input, size-1, x);
    if(smallAns == -1)
      return -1;
    else
      return smallAns;
}

int allIndexes(int input[], int size, int x, int output[]) {
  /* Given an array of length N and an integer x, you need to find all the
   * indexes where x is present in the input array. Save all the indexes in an
   * array (in increasing order). Do this recursively. Indexing in the array
   * starts from 0.*/
    if(size <= 0) return 0;
    int smallAns = allIndexes(input,size-1,x,output);
    if(x==input[size-1])
      output[smallAns++] = size-1;
    return smallAns;
}

int multiplyNumbers(int m, int n) {
  /* Given two integers m & n, calculate and return their multiplication using
   * recursion. You can only use subtraction and addition for your calculation.
   * No other operators are allowed.*/
    if(m==0 || n==0) return 0;
    if(n>0)
    {
      int smallAns = multiplyNumbers(m,n-1);
      return smallAns + m;
    }
    else
    {
      int smallAns = multiplyNumbers(m,n+1);
      return smallAns - m;
    }
}

int countZeros(int n){
  /* Given an integer n, count and return the number of zeros that are present
   * in the given integer using recursion.*/
  if(n<0) n *= -1;  // Make n positive
  if(n<10)
  {
    if(n == 0) return 1;
    return 0;
  }
  int smallAns = countZeros(n / 10);
  if(n%10==0)
    smallAns++;
  return smallAns;
}

double geometricSum(int k){
  /* Given k, find the geometric sum i.e. 1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k)*/
    if(k == 0){
        return 1;
    }
    double smallAns = geometricSum(k-1);
    return smallAns + 1/pow(2,k);
}

bool RcheckPalindrome(char input[],int size) {
  /* Check if a given String S is palindrome or not (using recursion). Return
   * true or false.*/
    if(size <= 1){
        return true;
    }
    if(input[0]!=input[size-1]) return false;
    return RcheckPalindrome(input+1,size-2);
}

bool checkPalindrome(char input[]) {
  int size;
  if(input==nullptr) return false;
  for(size=0;input[size]!='\0';size++);
  return RcheckPalindrome(input,size);
}

int sumOfDigits(int n){
  /* Write a recursive function that returns the sum of the digits of a given
   * integer. */
    if(n == 0){
        return 0;
    }
    int smallAns = sumOfDigits(n / 10);
    return smallAns + n%10;
}

void replacePi(char input[]) {
  /* Given a string, compute recursively a new string where all appearances of
   * "pi" have been replaced by "3.14".*/
    if(input[0] == '\0')
        return;
    else if(input[0]!='p')
      replacePi(input+1);
    else if(input[1]=='\0')
      return;
    else if(input[1]=='i')
    {
      int size;
      // Calculate Size
      for(size=2;input[size]!='\0';size++);
      for(int i=size+2;i>=4;i--)
        input[i] = input[i-2];
      input[0] = '3';
      input[1] = '.';
      input[2] = '1';
      input[3] = '4';
      replacePi(input+4);
    }
    else
      replacePi(input+1);
}

void removeX(char input[]) {
  /* Given a string, compute recursively a new string where all 'x' chars have
   * been removed.*/
    if(input[0] == '\0')
        return;
    else if(input[0]!='x')
      removeX(input+1);
    else
    {
      int i;
      for(i=0;input[i]!='\0';i++)
        input[i] = input[i+1];
      input[i] = '\0';
      removeX(input);
    }
}

int stringToNumberNonRecuresive(char input[])
{
  /* Write a recursive function to convert a given string into the number it
   * represents. That is input will be a numeric string that contains only
   * numbers, you need to convert the string into corresponding integer and
   * return the answer.*/
  int i, number=0;
  for(i=0;input[i]!='\0';i++)
  {
    int digit = input[i]-'0';
    number = (number*10) + digit;
  }
  return number;
}

int stringToNumber(char input[])
{
  /* Write a recursive function to convert a given string into the number it
   * represents. That is input will be a numeric string that contains only
   * numbers, you need to convert the string into corresponding integer and
   * return the answer.*/
    if(input[0] == '\0')
      return 0;
    int smallAns = stringToNumber(input+1);
    int power=1;
    for(int i=1;input[i]!='\0';i++)
      power *= 10;
    int digit = input[0]-'0';
    return digit*power + smallAns;
}

void pairStar(char input[])
{
  /* Given a string, compute recursively a new string where identical chars
   * that are adjacent in the original string are separated from each other by
   * a "*".*/
    if(input[0] == '\0')
      return;
    pairStar(input+1);
    if(input[0]==input[1])
    {
      int size;
      // Calculate Size
      for(size=2;input[size]!='\0';size++);
      for(int i=size+1;i>=2;i--)
        input[i] = input[i-1];
      input[1] = '*';
    }
}

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
  /* Tower of Hanoi is a mathematical puzzle where we have three rods and
   * n disks. The objective of the puzzle is to move all disks from source rod
   * to destination rod using third rod (say auxiliary). The rules are:
   * 1) Only one disk can be moved at a time.
   * 2) A disk can be moved only if it is on the top of a rod.
   * 3) No disk can be placed on the top of a smaller disk.
   * Print the steps required to move n disks from source rod to destination
   * rod. Source Rod is named as 'a', auxiliary rod as 'b' and destination rod
   * as 'c'.*/
    if(n == 0) return;
    if(n == 1)
    {
      cout << source << ' ' << destination << endl;
      return;
    }
    towerOfHanoi(n-1,source,destination,auxiliary);
    cout << source << ' ' << destination << endl;
    towerOfHanoi(n-1,auxiliary,source,destination);
}

int recursion()
{
  int n,x,val;
  /*
  int arr[THOUSAND];
  int output[THOUSAND];
  n=getArray(arr,THOUSAND);
  cin >> x;
  int count = allIndexes(arr, n, x, output);
  printArray(output,count);
  */
  cin >> x; cout << geometricSum(x) << endl;
  return 0;
}

