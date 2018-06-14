#include <iostream>
#include <string>
#include <cstring>
#define THOUSAND 1000
#define SIZE 1000000
#define CHARSIZE 256
using namespace std;

void get2DArray(int arr2D[][THOUSAND], int &row, int &col)
{
  cin >> row >> col;
  // Read the array
  for(int i=0;i<row;++i) 
    for(int j=0;j<col;++j) 
      cin >> arr2D[i][j];
}

void print2DArray(int arr2D[][THOUSAND], int row, int col)
{
  cout << "The array of size " << row << '*' << col << " is: " << endl;
  // Print the array
  for(int i=0;i<row;++i) 
  {
    for(int j=0;j<col;++j) 
      cout << arr2D[i][j] << ' ';
    cout << endl;
  }
}

bool checkPalindrome(char str[])
{
  /* Given a String s, check it its palindrome. Return true if string is
   * palindrome, else return false. Palindrome strings are those, where string
   * s and its reverse is exactly same. */
  int i,j;
  if(str==nullptr) return false;
  // Initialize j to end of str
  for(j=0;str[j]!='\0';j++);
  i=0;--j;
  while(i<j)
    if(str[i++]!=str[j--])
        return false;
  return true;
}

void reverseStringIndexwise(char str[], int i, int j)
{
  if(str==nullptr) return;
  while(i<j)
  {
      char temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      i++;j--;
  }
}

void replaceCharacter(char input[], char c1, char c2)
{
  /* Given an input string S and two characters c1 and c2, you need to replace
   * every occurrence of character c1 with character c2 in the given string.
   * For eg:
   * Input: abacd  a x
   * Output: xbxcd
   ***************************************************************************/
  int i=0;
  if(input==nullptr) return;
  // Initialize j to end of str
  while(input[i] != '\0')
  {
    if(input[i]==c1)
      input[i]=c2;
    ++i;
  }
}

void trimSpaces(char input[])
{
  /* Given an input string S that contains multiple words, you need to remove
   * all the spaces present in the input string. There can be multiple spaces
   * present after any word. 
   * Input: abc def g hi
   * Output: abcdefghi
   ***************************************************************************/
  int i=0,j=0;
  if(input==nullptr) return;
  // Initialize j to end of str
  while(input[i] != '\0')
  {
    if(input[i]==' ')
    {
      ++i;
      continue;
    }
    input[j++]=input[i++];
  }
  input[j]='\0';
}

void printSubstrings(char str[])
{
  /* Given a String S of length n, print all its substrings. Substring of
   * a String S is a part of S (of any length from 1 to n), which contains all
   * consecutive characters from S. For input "xyz", output will be:
   * x
   * xy
   * xyz
   * y
   * yz
   * z
   ***************************************************************************/
  int i,j,k,len;
  if(str==nullptr) return;
  // Calculate len
  for(j=0;str[j]!='\0';j++);
  len = j;

  for(i=0;i<len;++i)
    for(j=len;j>0;--j)
    {
      for(k=i;k<j;k++)
        cout << str[k];
      if(i<j)cout << endl;
    }
}

void reverseEachWord(char input[])
{
  /* Given a string S, reverse each word of a string individually. For eg. if a 
   * string is "abc def", reversed string should be "cba fed". Sample Input :
   * Welcome to Coding Ninjas
   * Sample Output: 
   * emocleW ot gnidoC sajniN */
  int i=0,j=0,start,stop;
  if(input==nullptr) return;
  while(input[i] != '\0')
  {
    if(isspace(input[i]))
    {
      i++;
      continue;
    }
    start = i++;
    while(input[i] !='\0' && !isspace(input[i])) i++;
    stop = i-1;

    // Swap the word which runs from start to stop
    while(start<stop)
    {
      char temp = input[start];
      input[start] = input[stop];
      input[stop] = temp;
      start++;stop--;
    }
  }
}

void columWiseSum()
{
  /* Given a 2D integer array of size M*N, find and print the sum of ith column
   * elements separated by space. */
  int matrix[THOUSAND+1][THOUSAND];
  int m, n;
  cin >> m >> n;
  // Initialize matrix[m] as zero
  for(int j=0;j<n;++j)
      matrix[m][j] = 0;
  // Read the input from console and simpultaneously update sum
  for(int i=0;i<m;++i)
    for(int j=0;j<n;++j)
    {
      cin >> matrix[i][j];
      matrix[m][j] += matrix[i][j];
    }
  // Display the output
  for(int j=0;j<n;++j)
      cout << matrix[m][j] << ' ';
  cout << endl;
}

void findLargest(int arr[][1000], int row, int col)
{
  /* Largest Row or Column: Given an NxM 2D array, you need to find out which
   * row or column has largest sum (sum of its elements) overall amongst all
   * rows and columns. 
   * Note : If there are more than one rows/columns with maximum sum consider
   * the row/column that comes first. And if ith row and jth column has same
   * sum (which is largest), consider the ith row as answer. */
  long rowSum[THOUSAND] = { 0 };
  long colSum[THOUSAND] = { 0 };
  for(int i=0;i<row;++i)
    for(int j=0;j<col;++j)
    {
      rowSum[i] += arr[i][j];
      colSum[j] += arr[i][j];
    }
  bool flagRow = 1;
  long maxIndex=0, maxSum=rowSum[0];
  for(int i=1;i<row;++i)
    if(rowSum[i]>maxSum)
    {
      maxIndex=i;
      maxSum=rowSum[i];

    }
  for(int j=0;j<col;++j)
    if(colSum[j]>maxSum)
    {
      flagRow = 0;
      maxIndex=j;
      maxSum=colSum[j];
    }

  // Display the output
  if(flagRow)
      cout << "row ";
  else
      cout << "column ";
  cout << maxIndex << ' ' << maxSum << endl;
}

void wavePrint(int input[][1000], int row, int col)
{
  /* Given a two dimensional n*m array, print the array in a sine wave order.
   * i.e. print the first column top to bottom, next column bottom to top and
   * so on. For eg for input array of size 3*4:
   * 1  2  3  4
   * 5  6  7  8 
   * 9 10 11 12
   * Output: 1 5 9 10 6 2 3 7 11 12 8 4
   ***************************************************************************/
  int i=0,j=0;
  for(j=0;j<col;++j)
    if(j%2==0)
      for(i=0;i<row;++i)
        cout << input[i][j] << ' ';
    else
      for(i=row-1;i>=0;--i)
        cout << input[i][j] << ' ';
  cout << endl;
}

void spiralPrint(int input[][1000], int row, int col)
{
  /* Given an N*M 2D array, print it in spiral form. That is, first you need to
   * print the 1st row, then last column, then last row and then first column
   * and so on. For eg for 4*4 matrix :
   * 1 2 3 4
   * 5 6 7 8
   * 9 10 11 12
   * 13 14 15 16
   * Output: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 
   ***************************************************************************/
  enum dir {front, down, back, up} direction = front;
  int dimensionFront = col;
  int dimensionDown = row-1;
  int i=0,j=0;
  int count = row*col;
  while(count>0)
  {
    switch(direction)
    {
      case front:
        for(int k=0; k<dimensionFront; k++)
        {
          cout << input[i][j++] << ' ';
        }
        count -= dimensionFront;
        if(dimensionFront)
        {
          dimensionFront--;
          j--; i++;
        }
        break;
      case down:
        for(int k=0; k<dimensionDown; k++)
        {
          cout << input[i++][j] << ' ';
        }
        count -= dimensionDown;
        if(dimensionDown)
        {
          dimensionDown--;
          i--; j--;
        }
        break;
      case back:
        for(int k=dimensionFront; k>0; k--)
        {
          cout << input[i][j--] << ' ';
        }
        count -= dimensionFront;
        if(dimensionFront)
        {
          dimensionFront--;
          j++; i--;
        }
        break;
      case up:
        for(int k=dimensionDown; k>0; k--)
        {
          cout << input[i--][j] << ' ';
        }
        count -= dimensionDown;
        if(dimensionDown)
        {
          dimensionDown--;
          i++; j++;
        }
        break;
    }
    direction = (enum dir)((direction+1)%4);
  }
  cout << endl;
}

bool isPermutation(char input1[], char input2[])
{
  /* Given two strings, check if they are permutations of each other. Return
   * true or false. Permutation means - length of both the strings should same
   * and should contain same set of characters. Order of characters doesn't
   * matter. Note : Input strings contain only lowercase english alphabets. */
  int chars[CHARSIZE] = {0};
  int i=0;

  for(i=0; input1[i]!='\0';i++)
    chars[input1[i]]++;
  for(i=0; input2[i]!='\0';i++)
    chars[input2[i]]--;
  for(i=0;i<CHARSIZE;i++)
    if(chars[i] != 0)
      return false;
  return true;
}

void reverseStringWordWise(char input[]) {
  /* Reverse the given string word wise. That is, the last word in given string
   * should come at 1st place, last second word at 2nd place and so on. 
   * Individual words should remain as it is. Sample Input:
   * Welcome to Coding Ninjas
   * Sample Output:
   * Ninjas Coding to Welcome */
  int len = strlen(input);
  reverseStringIndexwise(input, 0, len-1);
  reverseEachWord(input);
}

int findString(char S[], char T[])
{
  /* Given two strings S and T, write a function to find if T is present as
   * a substring inside S or not. If yes, return the starting index otherwise
   * return -1. */
  int j;
  if(S==nullptr || T==nullptr || S[0]=='\0' || T[0]=='\0') return -1;
  for(j=0;S[j]!='\0';j++)
    if(S[j] == T[0])
    {
      int k;
      for(k=1;S[j+k]!='\0' && T[k]!='\0';k++)
        if(S[j+k]!=T[k])
          break;
      if(T[k]=='\0') 
        return j;
    }
  return -1;
}

void convertStringToLowerCase(char input[])
{
  /* Write a function that converts a given string to lower case. */
  int j;
  if(input==nullptr) return;
  for(j=0;input[j]!='\0';j++)
    if('A' <= input[j] && input[j] <= 'Z')
      input[j] = input[j] - 'A' + 'a';
}

void ReverseString(char arr[], int size)
{
  /* We have given size because we do not assume null terminated string */
  for(int i=0;i<size/2;++i)
  {
    char temp = arr[i];
    arr[i] = arr[size-i-1];
    arr[size-i-1] = temp;
  }
}

void rotateStringByNChars(char input[], int n)
{
  /* Given a string and an integer n, shift and rotate the given string by
   * n characters in right. */
  int size=0;
  if(input==nullptr) return;
  while(input[size]!='\0') size++;
  n %= size;
  ReverseString(input,size);
  ReverseString(input,n);
  ReverseString(input+n,size-n);
}

void removeAllOccurrencesOfChar(char input[], char c)
{
  /* Given a string and a character x. Write a function to remove all
   * occurrences of x character from the given string. */
    int i, j=0;
    if(input==nullptr) return;
    for(i=0; input[i]!='\0'; i++)
    {
        if (input[i] == c) continue;
        input[j++] = input[i];
    }
    input[j] = '\0';
}

void removeConsecutiveDuplicates(char input[])
{
  /* Given a string, remove all the consecutive duplicates that are present in
   * the given string. That means, if 'aaa' is present in the string then it
   * should become 'a' in the output string. */
    int i, j=0;
    if(input==nullptr || input[0]=='\0') return;
    input[j++] = input[0];
    for(i=1; input[i]!='\0'; i++)
    {
        if(input[i] == input[i-1]) continue;
        input[j++] = input[i];
    }
    input[j] = '\0';
}

char highestOccurringChar(char input[])
{
  /* Given a string, find and return the highest occurring character present in
   * the given string. If there are 2 characters in the input string with same
   * frequency, return the character which comes first. Assume all the
   * characters in the given string are lowercase. */
  int chars[CHARSIZE] = {0};
  int maxIndex=0;

  for(int i=0; input[i]!='\0';i++)
  {
    chars[input[i]]++;
    if(chars[input[i]] > chars[maxIndex])
      maxIndex = input[i];
  }
  return (char)maxIndex;
}

void stringCompression(char input[])
{
  /* Write a program to do basic string compression. For a character which is
   * consecutively repeated more than once, replace consecutive duplicate
   * occurrences with the count of repetitions. For e.g. if a String has 'x'
   * repeated 5 times, replace this "xxxxx" with "x5". Note : Consecutive count
   * of every character in input string is less than equal to 9.*/
    int i, j=0, count;
    if(input==nullptr || input[0]=='\0') return;
    input[j++] = input[0];
    for(i=1; input[i]!='\0'; i++)
    {
        if(input[i] == input[i-1])
        {
          for(count=1; input[i]==input[i+count]; count++);
          input[j++] = count+1+'0';
          i += count-1;
        }
        else
          input[j++] = input[i];
    }
    input[j] = '\0';
}

int chararrays()
{
  int n,val;
  char str[SIZE];
  int row = THOUSAND; int col = THOUSAND;
  int arr2D[THOUSAND][THOUSAND];
  //cin >> str; printSubstrings(str);
  //cin.getline(str,SIZE); reverseEachWord(str); cout << str << endl;
  cin.getline(str,SIZE); reverseStringWordWise(str); cout << str << endl;
  //get2DArray(arr2D, row, col);
  //print2DArray(arr2D, row, col);
  //spiralPrint(arr2D, row, col);
  // cin.getline(str,SIZE); stringCompression(str); cout << str << endl;
  return 0;
}
