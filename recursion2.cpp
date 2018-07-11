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
  // cout << "The array of size " << size << " is: " << endl;
  for(int i=0;i<size;++i)
    cout << arr[i] << ' ';
  cout << endl;
}

void printSArray(string a[], int size)
{
  /* This function is for non null terminated strings */
    cout << "The Array of size " << size << " is ";
    for(int i=0;i<size;i++) cout << a[i] << ' ';
    cout << endl;
}

void mergeSort(int input[], int size){
  /* Sort an array A using Merge Sort. Change in the input array itself. So no
   * need to return or print anything. */
  int result[THOUSAND];
  if(size <= 1)
    return;
  int size1 = size/2;
  int size2 = size-size1;
  mergeSort(input,size1);
  mergeSort(input+size1,size2);
  int i=0, j=size1,k=0, temp;
  while(i<size1 && j<size)
  {
    if(input[i]<input[j])
      result[k++] = input[i++];
    else
      result[k++] = input[j++];
  }
  while(i<size1)
      result[k++] = input[i++];
  while(j<size)
      result[k++] = input[j++];
  for(i=0;i<size;i++)
    input[i]=result[i];
}

void swap(int input[], int i, int j)
{
  int temp = input[i];
  input[i]= input[j];
  input[j] = temp;
}

void quickSort(int input[], int size) {
  if(input==nullptr || size<=1) return;
  // size is atleast 2. 
  // Count no of elements smaller than input[0]
  int count=0;
  for(int i=1; i<size; i++)
    if(input[i]<input[0])
      count++;
  // count may be zero as well
  swap(input, 0, count);
  int left=0, right=size-1;
  while(left<count && right>count)
  {
    while(input[left]<input[count]) left++;
    while(input[right]>=input[count]) right--;
    if(left<right)
      swap(input, left++, right--);
  }
  quickSort(input, count);
  quickSort(input+count+1, size-count-1);
}

void replaceCharacter(char input[], char c1, char c2)
{
  /* Given an input string S and two characters c1 and c2, you need to replace
   * every occurrence of character c1 with character c2 in the given string.*/
  if(input[0]=='\0') return;
  if(input[0]==c1)
    input[0] = c2;
  replaceCharacter(input+1,c1,c2);
}

void removeConsecutiveDuplicates(char *input) {
  /* Given a string S, remove consecutive duplicates from it recursively. */
  if(input[0]=='\0') return;
  removeConsecutiveDuplicates(input+1);
  if(input[0]==input[1])
  {
    int i;
    for(i=0;input[i]!='\0';i++)
      input[i] = input[i+1];
    input[i-1]='\0';
  }
}

int keypad(int num, string output[]){
  /* Given an integer n, using phone keypad find out all the possible strings
   * that can be made using digits of input n. Return empty string for numbers
   * 0 and 1 */
  static string options[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs",
    "tuv", "wxyz"};
    if (num==0)
    {
        output[0] = "";
        return 1;
    }

    int small = num/10;
    int remainder = num%10;
    int count = keypad(small, output);

    int optionslen = options[remainder].length();
    for (int i = 0; i< optionslen-1; i++)
        for (int j=0; j<count; j++)
            output[((i+1)*count)+j] = output[j];
    int k=0;
    for (int i = 0; i< optionslen; i++)
        for (int j=0; j<count; j++)
        {
            output[k] = output[k] + options[remainder][i];
            k++;
        }
    return k;
}

void printKeypadHelper(int num, string str) {
  /* Given an integer n, using phone keypad find out and print all the possible 
   * strings that can be made using digits of input n. */
  static string options[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs",
    "tuv", "wxyz"};
    if (num==0)
    {
        cout <<str <<endl;
        return;
    }

    int small = num/10;
    int remainder = num%10;
    int optionslen = options[remainder].length();
    for (int i = 0; i< optionslen; i++)
      printKeypadHelper(small, options[remainder][i] + str);
}
void printKeypad(int number) {
  printKeypadHelper(number,"");
}

int main()
{
  int n,x,val;
  int arr[THOUSAND];
  int output[THOUSAND];
  n=getArray(arr,THOUSAND);
  //mergeSort(arr,n);
  quickSort(arr,n);
  printArray(arr,n);

  /*
    string out[1000];
    int number;
    cout << "Please input the number for keypad: ";
    cin >> number;
    n = keypad(number, out);
    printSArray(out,n);
  */
  return 0;
}
