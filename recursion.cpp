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
    if(n == 1){
        return 1;
    }
    int smallAns = sum(n-1);
    return smallAns + n;
}

int sumArray(int input[], int n) {
    if(n == 1){
        return input[0];
    }
    int smallAns = sumArray(input, n-1);
    return smallAns + input[n-1];
}

bool checkNumber(int input[], int size, int x) {
    if(size == 1){
        return x==input[0];
    }
    bool smallAns = checkNumber(input, size-1, x);
    return smallAns || (x==input[size-1]);

}

int firstIndex(int input[], int size, int x) {
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

int __allIndexes(int input[], int size, int x, int output[]) {
    if(size <= 0){
        return 0;
    }
    if(x==input[size-1])
    {
      output[0] = size-1;
      int smallAns = __allIndexes(input,size-1,x,output+1);
      return 1+smallAns;
    }
    else
    {
      int smallAns = __allIndexes(input,size-1,x,output);
      return smallAns;
    }
}

int allIndexes(int input[], int size, int x, int output[]) {
  int count = __allIndexes(input, size, x, output);
  for(int i=0;i<count/2; i++)
  {
    int temp = output[i];
    output[i] = output[count-1-i];
    output[count-1-i] = temp;
  }
  return count;
}

int multiplyNumbers(int m, int n) {
    if(n == 1){
        return m;
    }
    int smallAns = multiplyNumbers(m,n-1);
    return smallAns + m;
}

int countZeros(int n){
    if(n == 0){
        return 0;
    }
    int smallAns = countZeros(n / 10);
    int r = n%10;
    if(r==0)
      smallAns++;
    return smallAns;
}

double geometricSum(int k){
    if(k == 0){
        return 1;
    }
    double smallAns = geometricSum(k-1);
    return smallAns + 1/pow(2,k);
}

bool RcheckPalindrome(char input[],int size) {
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
    if(n == 0){
        return 0;
    }
    int smallAns = sumOfDigits(n / 10);
    return smallAns + n%10;
}

void replacePi(char input[]) {
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
