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
  int j;
  if(input==nullptr) return;
  for(j=0;input[j]!='\0';j++)
    if('A' <= input[j] && input[j] <= 'Z')
      input[j] = input[j] - 'A' + 'a';
}

void ReverseString(char arr[], int size)
{
  for(int i=0;i<size/2;++i)
  {
    char temp = arr[i];
    arr[i] = arr[size-i-1];
    arr[size-i-1] = temp;
  }
}

void rotateStringByNChars(char input[], int n)
{
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
