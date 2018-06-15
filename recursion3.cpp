#include<iostream>
#include <unordered_map>
#include<cmath>
#include<string>
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

void printSArray(string a[], int size)
{
  /* This function is for non null terminated strings */
    cout << "The Array of size " << size << " is ";
    for(int i=0;i<size;i++) cout << a[i] << ' ';
    cout << endl;
}

bool checkBB(char input[]);
bool checkA(char input[])
{
  /* Each 'a' is followed by nothing or an 'a' or "bb" */
  if(input[0]=='\0') return true;
  if(input[0]=='a') return checkA(input+1);
  if(input[0]=='b')
  {
    if(input[1]=='\0') return false;
    if(input[1]=='b') return checkBB(input+2);
  }
  return false;
}

bool checkBB(char input[])
{
  /* Each "bb" is followed by nothing or an 'a' */
  if(input[0]=='\0') return true;
  if(input[0]=='a') return checkA(input+1);
  return false;
}

bool checkAB(char input[])
{
  /* Suppose you have a string made up of only 'a' and 'b'. Write a recursive
   * function that checks if the string was generated using the following
   * rules:
   * a. The string begins with an 'a'
   * b. Each 'a' is followed by nothing or an 'a' or "bb"
   * c. Each "bb" is followed by nothing or an 'a' */
  if(input[0]!='a') return false;
  return checkA(input+1);
}

int staircase(int n)
{
  /* A child is running up a staircase with N steps, and can hop either 1 step,
   * 2 steps or 3 steps at a time. Implement a method to count how many
   * possible ways the child can run up to the stairs. You need to return
   * number of possible ways W. */
  if(n<3) return n;
  if(n==3) return 4;
  return staircase(n-1)+staircase(n-2)+staircase(n-3);
}

int binarySearchIndex(int arr[], int start, int end, int val)
{
  /* Given an integer sorted array (sorted in increasing order) and an element
   * x, find the x in given array using binary search. Return the index of x.
   * Return -1 if x is not present in the given array. Note : If given array
   * size is even, take first mid.*/
  if(start>end) return -1;
  int mid=(start+end)/2;
  if(val == arr[mid])
      return mid;
  else if(val>arr[mid])
      return binarySearchIndex(arr,mid+1,end,val);
  else
      return binarySearchIndex(arr,start,mid-1,val);
}

int binarySearch(int arr[], int n, int val)
{
  return binarySearchIndex(arr,0,n-1,val);
}

int subset(int input[], int n, int output[][20]) {
  /* Given an integer array (of length n), find and return all the subsets of
   * input array. Subsets are of length varying from 0 to n, that contain
   * elements of the array. But the order of elements should remain same as in
   * the input array. The order of subsets are not important. */
  if(n<=0)
  {
    output[0][0] = 0;
    return 1;
  }

  int i, j, withoutInclusion = subset(input,n-1,output);
  /* output has withoutInclusion entries */
  for(i=0; i<withoutInclusion; i++)
  {
    output[withoutInclusion+i][0] = output[i][0] + 1;
    for(j=1; j<=output[i][0]; j++)
      output[withoutInclusion+i][j] = output[i][j];
    output[withoutInclusion+i][j] = input[n-1];
  }
  return 2*withoutInclusion;
}

void printSubsetsOfArrayHelper(int input[], int num, string str) {
    if(num==0)
    {
        if(str.length()){
          str = str.substr(1);
        }
        cout <<str <<endl;
        return;
    }

    printSubsetsOfArrayHelper(input+1,num-1,str + " " + to_string(input[0]));
    printSubsetsOfArrayHelper(input+1,num-1,str);
}
void printSubsetsOfArray(int input[], int size) {
  /* Given an integer array (of length n), find and return all the subsets of
   * input array. Subsets are of length varying from 0 to n, that contain
   * elements of the array. But the order of elements should remain same as in
   * the input array. Note : The order of subsets are not important. For input
   * array of size 3 with elements 15 20 12 is:
   * 12
   * 20
   * 20 12
   * 15
   * 15 12
   * 15 20
   * 15 20 12
   ****************************************************************************/
  printSubsetsOfArrayHelper(input, size, "");
}

int subsetSumToK(int input[], int n, int output[][50], int k) {
  /* Given an array A of size n and an integer K, return all subsets of A which
   * sum to K. Subsets are of length varying from 0 to n, that contain elements
   * of the array. But the order of elements should remain same as in the input
   * array. The order of subsets are not important.
   * You need to save all the subsets in the given 2D output array. And return
   * the number of subsets(i.e. number of rows filled in output) from the given
   * function. In ith row of output array, 1st column contains length of the
   * ith subset. And from 1st column actual subset follows. For eg. Input : {1,
   * 3, 4, 2} and K = 5, then output array should contain 
   * {{2, 1, 4},	// Length of this subset is 2
   * {2, 3, 2}}	// Length of this subset is 2
   ****************************************************************************/
  if(n<=0 || input==nullptr || output==nullptr) return 0;
  if(n==1)
  {
    if(input[0]==k)
    {
      output[0][0] = 1;
      output[0][1] = k;
      return 1;
    }
    return 0;
  }

  int count1 = subsetSumToK(input,n-1,output, k);
  int i, j, count2 = subsetSumToK(input,n-1,output+count1, k-input[n-1]);
  for(i=0; i<count2; i++)
  {
    output[count1+i][0] += 1;
    int index = output[count1+i][0];
    output[count1+i][index] = input[n-1];
  }
  int count3 = 0;
  if(k==input[n-1])
  {
    output[count1+count2][0] = 1;
    output[count1+count2][1] = k;
    count3 = 1;
  }
  return count1+count2+count3;
}

void printSubsetSumToKHelper(int input[], int n, int k, int out[], int outSize) {
  if(n<=0 || input==nullptr || out==nullptr) return;
  if(n==1)
  {
    if(input[0]==k)
    {
      for(int i=0; i<outSize; i++) cout << out[i] << ' ';
      cout << k << ' ';
      cout << endl;
    }
    return;
  }

  if(k==input[n-1])
  {
    for(int i=0; i<outSize; i++) cout << out[i] << ' ';
    cout << k << ' ';
    cout << endl;
  }
  printSubsetSumToKHelper(input,n-1,k,out,outSize);
  out[outSize++] = input[n-1];
  printSubsetSumToKHelper(input,n-1,k-input[n-1],out,outSize);
}

void printSubsetSumToK(int input[], int n, int k) {
  /* Given an array A of size n and an integer K, print all subsets of A which
   * sum to K. Subsets are of length varying from 0 to n, that contain elements
   * of the array. But the order of elements should remain same as in the input
   * array. The order of subsets are not important.
   * You need to save all the subsets in the given 2D output array. And return
   * the number of subsets(i.e. number of rows filled in output) from the given
   * function. In ith row of output array, 1st column contains length of the
   * ith subset. And from 1st column actual subset follows. For eg. Input : {1,
   * 3, 4, 2} and K = 5, then output array should contain 
   * {{2, 1, 4},	// Length of this subset is 2
   * {2, 3, 2}}	// Length of this subset is 2
   ****************************************************************************/
  int out[THOUSAND];
  printSubsetSumToKHelper(input,n,k,out,0);
}

void initMap(unordered_map<string,string>& map)
{
  map["1"] = "a"; map["2"] = "b"; map["3"] = "c"; map["4"] = "d";
  map["5"] = "e"; map["6"] = "f"; map["7"] = "g"; map["8"] = "h";
  map["9"] = "i"; map["10"] = "j"; map["11"] = "k"; map["12"] = "l";
  map["13"] = "m"; map["14"] = "n"; map["15"] = "o"; map["16"] = "p";
  map["17"] = "q"; map["18"] = "r"; map["19"] = "s"; map["20"] = "t";
  map["21"] = "u"; map["22"] = "v"; map["23"] = "w"; map["24"] = "x";
  map["25"] = "y"; map["26"] = "z";
  /*
  unordered_map<string,string> map({{"1","a"}, {"2","b"},{"3","c"},{"4","d"},
      {"5","e"},{"6","f"},{"7","g"},{"8","h"},{"9","i"},{"10","j"},{"11","k"},
      {"12","l"},{"13","m"},{"14","n"},""15","o"},{"15","p"},{"17","q"},
      {"18","r"},{"19","s"},{"20","t"},""21","u"},{"22","v"},{"23","w"},
      {"24","x"},{"25","y"},{"26","z"}});
      */
}

int getCodes(string input, string output[10000]) {
  /* You are given the input text and output string array. Find all possible
   * codes and store in the output string array. Don’t print the codes. Also,
   * return the number of codes return to the output string. You do not need to
   * print anything. */
  /* TODO: map is initialized each time which can be optimized using flag */
  unordered_map<string,string> map;
  initMap(map);
  int len = input.length(), count, sum=0;
  if(len==1)
  {
    output[sum++] = map[input];
    return sum;
  }
  else if(len==2 && map.count(input))
    output[sum++] = map[input];

  /* Print possiblities after removing 1 character */
  count = getCodes(input.substr(1), output+sum);
  for(int j=0; j<count; j++)
    output[sum+j] = map[input.substr(0,1)] + output[sum+j];
  sum += count;

  /* Print possiblities after removing 2 character */
  if(len>2 && map.count(input.substr(0,2)))
  {
    count = getCodes(input.substr(2), output+sum);
    for(int j=0; j<count; j++)
      output[sum+j] = map[input.substr(0,2)] + output[sum+j];
    sum += count;
  }
  return sum;
}

void printAllPossibleCodesHelper(string input, string output,
    unordered_map<string,string>& map) {
  int len = input.length();
  if(len==1)
  {
    cout << output << map[input] << endl;
    return;
  }
  else if(len==2 && map.count(input))
  {
    cout << output << map[input] << endl;
    printAllPossibleCodesHelper(input.substr(1),
      output + map[input.substr(0,1)], map);
    return;
  }
  /* Print possiblities after removing 1 character */
  printAllPossibleCodesHelper(input.substr(1),
      output + map[input.substr(0,1)], map);

  /* Print possiblities after removing 2 character */
  if(map.count(input.substr(0,2)))
    printAllPossibleCodesHelper(input.substr(2),
      output + map[input.substr(0,2)], map);
}

void printAllPossibleCodes(string input) {
  /* Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given
   * a numeric string S. Write a program to print the list of all possible
   * codes that can be generated from the given string. The order of codes are
   * not important. Just print them in different lines. For eg for 1123 print
   * aabc
   * kbc
   * alc
   * aaw
   * kw
   ****************************************************************************/
  unordered_map<string,string> map;
  initMap(map);
  printAllPossibleCodesHelper(input, "",map);
}

int returnPermutations(string input, string output[]){
  /* Given a string, find and return all the possible permutations of the input
   * string. The order of permutations are not important. Just return them in
   * different lines. For eg for input abc, return no of permutaions
   * abc
   * acb
   * bac
   * bca
   * cab
   * cba
   ****************************************************************************/
  int len = input.length();
  if(len==0) return 0;
  if(len==1)
  {
    output[0] = input;
    return 1;
  }
  int count, sum=0;
  for(int i=0; i<len; i++)
  {
    count = returnPermutations(input.substr(0,i)+input.substr(i+1),output+sum);
    for(int j=0; j<count; j++)
      output[sum+j] = input.substr(i,1) + output[sum+j];
    sum += count;
  }
  return sum;
}

void printPermutationsHelper(string input, string output){
  int len = input.length();
  if(len==1)
  {
    cout << output << input << endl;
    return;
  }
  for(int i=0; i<len; i++)
    printPermutationsHelper(input.substr(0,i) + input.substr(i+1),
        output + input.substr(i,1));
}

void printPermutations(string input){
  /* Given a string, find and print all the possible permutations of the input
   * string. The order of permutations are not important. Just print them in
   * different lines. For eg for input abc, print
   * abc
   * acb
   * bac
   * bca
   * cab
   * cba
   ****************************************************************************/
  /* Solution: Print all string starting with a , then b, then c and so on */
  if(input.length()==0) return;
  printPermutationsHelper(input,"");
}

//int recursion3()
int main()
{
  int n;
  int arr[THOUSAND];
  int output[THOUSAND];
  n=getArray(arr,THOUSAND);
  //printArray(output,n);
  int sum, count, out[THOUSAND][50]; cin>>sum;
  //count = subsetSumToK(arr,n,out,sum); cout<<count<<endl;
  printSubsetSumToK(arr,n,sum); 
  //string in; cin >> in; printPermutations(in);
  //string in; cin >> in; printAllPossibleCodes(in);
  //string in, out[10000]; cin >> in; int count = getCodes(in, out);
  //for(int j=0; j<count; j++) cout << out[j] << endl;
  return 0;
}
