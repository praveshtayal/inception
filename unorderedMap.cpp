#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <string>
#define MILLION 1000000
using namespace std;

vector<int> removeDuplicates(int arr[], int size)
{
  vector<int> output;
  unordered_map<int,bool> seen;
  for(int i=0; i<size; i++)
    if(!seen.count(arr[i]))
    {
      seen[arr[i]] = true;
      output.push_back(arr[i]);
    }
  return output;
}

int highestFrequency(int *input, int n){
  /* You are given with an array of integers that contain numbers in random
   * order. Write a program to find and return the number which occurs maximum
   * times in the given input. If more than one element occurs same number of
   * times in the input, return the element which is present in the input
   * first. */
  if(n<=0 || input==nullptr) return 0;
  unordered_map<int,int> mymap;
  int maxElement = input[0];
  ++mymap[input[0]];
  for(int i=1; i<n; i++)
    if(++mymap[input[i]]>mymap[maxElement])
      maxElement = input[i];
  return maxElement;
}

void intersection(int input1[], int input2[], int size1, int size2) {
  /* Given two random integer arrays, print their intersection. That is, print
   * all the elements that are present in both the given arrays. Input arrays
   * can contain duplicate elements. */
  if(input1==nullptr || size1<=0) return;
  if(input2==nullptr || size2<=0) return;
  unordered_map<int,int> myMap;
  for(int i=0; i<size1; i++)
      myMap[input1[i]]++;

  for(int i=0; i<size2; i++)
    if(myMap.count(input2[i]))
    {
      cout << input2[i] << endl;
      if(myMap[input2[i]]==1)
        myMap.erase(input2[i]);
      else
        myMap[input2[i]]--;
    }
}

void PairSum(int *input, int n) {
  /* Given a random integer array A of size N. Find and print the pair of
   * elements in the array which sum to 0. Array A can contain duplicate
   * elements. While printing a pair, print the smaller element first. That is,
   * if a valid pair is (6, -6) print "-6 6". There is no constraint that out
   * of 5 pairs which have to be printed in 1st line. You can print pairs in
   * any order, just be careful about the order of elements in a pair. */
  if(input==nullptr || n<=0) return;
  unordered_map<int,int> myMap;
  for(int i=0; i<n; i++)
  {
    int inverse = -input[i];
    if(myMap.count(inverse))
    {
      int count = myMap[inverse];  // print count times
      if(inverse>0) inverse *= -1; // inverse is negative
      for(int j=0; j<count; j++)
        cout << inverse << ' ' << -inverse << endl;
    }
    myMap[input[i]]++;
  }
}

/* This function removes the elements if pairs are formed. That is if there are
 * 3 negative numbers and 2 positive numbers, only 2 pairs are printed  */
void PairSum2(int *input, int n) {
  /* Given a random integer array A of size N. Find and print the pair of
   * elements in the array which sum to 0. Array A can contain duplicate
   * elements. While printing a pair, print the smaller element first. That is,
   * if a valid pair is (6, -6) print "-6 6". There is no constraint that out
   * of 5 pairs which have to be printed in 1st line. You can print pairs in
   * any order, just be careful about the order of elements in a pair. */
  if(input==nullptr || n<=0) return;
  unordered_map<int,int> myMap;
  for(int i=0; i<n; i++)
  {
    int inverse = -input[i];
    if(myMap.count(inverse))
    {
      if(inverse<0) cout << inverse << ' ' << -inverse << endl;
      else cout << -inverse << ' ' << inverse << endl;
      myMap.erase(inverse);
    }
    else
      myMap[input[i]] = 1;
  }
}

char* uniqueChar(char *str){
  /* Given a string, you need to remove all the duplicates. That means, the
   * output string should contain each character only once. The respective
   * order of characters should remain same. For eg:
   * input: ababacd
   * output: abcd */
  if(str==nullptr) return str;
  unordered_map<char,int> myMap;
  int i, j;
  for(i=j=0; str[i]!='\0'; i++)
  {
    if(myMap.count(str[i])) continue;
    myMap[str[i]] = 1;
    str[j++] = str[i];
  }
  str[j]='\0';
  return str;
}

vector<int> longestSubsequence(int *arr, int n){
  /* Longest Consecutive Subsequence: You are given with an array of integers
   * that contain numbers in random order. Write a program to find the longest
   * possible sub sequence of consecutive numbers using the numbers from given
   * array. 
   * You need to return the output array which contains consecutive elements.
   * Order of elements in the output is not important.
   * If two arrays are of equal length return the array whose index of smallest
   * element comes first. For input array of size 13:
   * input: 2 12 9 16 10 5 3 20 25 11 1 8 6 
   * output: 8 9 10 11 12 */
  vector<int> result;
  if(arr==nullptr || n<=0) return result;
  unordered_map<int, int> myMap; // Stores Values and their index
  // We move backwards beacuse we want to store the first index of duplicate
  // elements. If we move forward, we need to check if element is already
  // present
  for(int i=n-1; i>=0; i++)
    myMap[arr[i]] = i;
  unordered_map<int, int>::iterator it=myMap.begin();
  int maxSize = 1, first, last, maxFirst, maxLast;
  maxFirst=maxLast=first=last=it->first;
  while(!myMap.empty())
  {
    // Try to maximise the current sequence.
    
    // Search for first-1 and add it if it exist
  }

  // Create the result vector with values from maxFirst to maxLast
  for(int i=maxFirst; i<=maxLast; i++)
    result.push_back(i);
  return result;
}

vector<int> longestSubsequence10(int *arr, int n){
  /* Longest Consecutive Subsequence: You are given with an array of integers
   * that contain numbers in random order. Write a program to find the longest
   * possible sub sequence of consecutive numbers using the numbers from given
   * array. 
   * You need to return the output array which contains consecutive elements.
   * Order of elements in the output is not important.
   * If two arrays are of equal length return the array whose index of smallest
   * element comes first. For input array of size 13:
   * input: 2 12 9 16 10 5 3 20 25 11 1 8 6 
   * output: 8 9 10 11 12 */
  vector<int> result;
  if(arr==nullptr || n<=0) return result;
  map<int, int> myMap;
  // We move backwards beacuse we want to store the first index of duplicate
  // elements. If we move forward, we need to check if element is already
  // present
  for(int i=n-1; i>=0; i++)
    myMap[arr[i]] = i;
  map<int, int>::iterator it=myMap.begin();
  int maxSize = 0, first, last, maxFirst, maxLast;
  maxFirst=maxLast=first=last=it->first;
  // loop starts from second index
  for(it++; it!=myMap.end(); it++)
  {
    if(it->first==last+1)
    {
      last = last+1;
      if(last-first>maxSize)
      {
        maxFirst = first;
        maxLast = last;
        maxSize = last-first;
      }
    }
    else
      first = last = it->first;
  }
  for(int i=maxFirst; i<=maxLast; i++)
    result.push_back(i);
  return result;
}

/* This approach uses unordered_map */
vector<int> longestSubsequence2(int *arr, int n){
  /* Longest Consecutive Subsequence: You are given with an array of integers
   * that contain numbers in random order. Write a program to find the longest
   * possible sub sequence of consecutive numbers using the numbers from given
   * array. 
   * You need to return the output array which contains consecutive elements.
   * Order of elements in the output is not important.
   * If two arrays are of equal length return the array whose index of smallest
   * element comes first. For input array of size 13:
   * input: 2 12 9 16 10 5 3 20 25 11 1 8 6 
   * output: 8 9 10 11 12 */
  vector<int> result;
  if(arr==nullptr || n<=0) return result;
  int maxSize = 0;
  pair<int, int> p, max;
  max.first = max.second = arr[0];
  unordered_map<int, pair<int,int> > myMap;
  for(int i=1; i<n; i++)
  {
    if(myMap.count(arr[i])) continue;  // ignore duplicate elements
    p.first = p.second = arr[i];
    if(myMap.count(arr[i]-1) && myMap.count(arr[i]+1))
    {
      p.first = myMap[arr[i]-1].first;
      p.second = myMap[arr[i]+1].second;
      myMap[arr[i]-1] = myMap[arr[i]] = myMap[arr[i]+1] = p;
    }
    else if(myMap.count(arr[i]-1)) 
    {
      p.first = myMap[arr[i]-1].first;
      p.second = arr[i];
      myMap[arr[i]-1] = myMap[arr[i]] = p;
    }
    else if(myMap.count(arr[i]+1)) 
    {
      p.first = arr[i];
      p.second = myMap[arr[i]+1].second;
      myMap[arr[i]] = myMap[arr[i]+1] = p;
    }
    else
      myMap[arr[i]] = p;
    if(p.second-p.first>maxSize)
    {
      max = p;
      maxSize = p.second-p.first;
    }
  }
  for(int i=0; i<=maxSize; i++)
    result.push_back(p.first+i);
  return result;
}

void printPairs(int *input, int n, int k) {
  /* You are given with an array of integers and an integer K. Write a program
   * to find and print all pairs which have difference K. Best solution takes
   * O(n) time. And take difference as absolute. */
  if(input==nullptr || n<=0) return;
  if(k<0) k *= -1; // k is positive
  unordered_map<int,int> myMap;
  for(int i=0; i<n; i++)
  {
    int solutionBig = input[i] + k;
    int solutionSmall = input[i] - k;
    if(myMap.count(solutionBig))
    {
      int count = myMap[solutionBig];  // print count times
      for(int j=0; j<count; j++)
        cout << input[i] << ' ' << solutionBig << endl;
    }
    if(k && myMap.count(solutionSmall))
    {
      int count = myMap[solutionSmall];  // print count times
      for(int j=0; j<count; j++)
        cout << solutionSmall << ' ' << input[i] << endl;
    }
    myMap[input[i]]++;
  }
}

int lengthOfLongestSubsetWithZeroSum(int* arr, int size){
  /* Given an array consisting of positive and negative integers, find the
   * length of the longest continuous subset whose sum is zero. You have to
   * return the length of longest subset. For eg for input array of size 10:
   * input: 95 -97 -387 -435 -5 -70 897 127 23 284
   * output: 6 */
  /* Solution uses the fact that if sum of x consecutive number is zero, then
   * their sum starting from index 0 will be same */
  if(arr==nullptr || size<=0) return 0;
  //int startIndex=-1, endIndex=-1;
  int maxLength=0;
  vector<int> sum;
  unordered_map<int, int> m; // stores sum and index
  sum.push_back(arr[0]); 
  m[arr[0]] = 0;
  if(arr[0]==0)
  {
    maxLength = 1;
    //startIndex = endIndex = 0;
  }
  for(int i=1; i<size; i++)
  {
    sum.push_back(sum[i-1]+arr[i]);
    if(sum[i]==0)
    {
      //start = 0;
      //endIndex = i;
      maxLength = i+1;
    }
    else if(m.count(sum[i]))
    {
      if(i-m[sum[i]]>maxLength)
        maxLength = i-m[sum[i]];
        //startIndex = m[sum[i]];
        //endIndex = i;
    }
    else
      m[sum[i]] = i;
  }
  return maxLength;
}

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
  for(int i=0;i<size;++i)
    cout << arr[i] << endl;
}

int main()
{
  int a1[MILLION], a2[MILLION];
  int s1, s2;
  s1 = getArray(a1,MILLION);
  //vector<int> v = longestSubsequence(a1,s1);
  //for(int i=0; i<v.size();i++) cout << v[i] << ' '; cout<<endl;
  //PairSum(a1,s1);
  s2 = getArray(a2,MILLION);
  intersection(a1, a2, s1, s2);
  /*
  unordered_map<string,int> mymap;
  // Insert using insert function
  pair<string,int> p("abc",1);
  mymap.insert(p);

  // Insert using []
  mymap["def"] = 2;

  // We can access using index as well as at. Note that if we access using
  // index for a value which was not present, it inserts that value and returns
  // the default value for this key.
  try {
    cout << mymap.at("ghi") << endl; // throws exception
  } catch (exception &e)
  {
    cout << "Exception Caught: " << e.what() << endl;
  }
  cout << mymap["ghi"] << endl; // insert the key with default value
  */


  /* count returns 0 or 1. That is beacuse unordere_map can only have atmost
   * one value for any key. Thus, the key will either be present or absent in
   * the map. And hence 0 and 1 are only possible answers. */
  /*
  if(mymap.count("ghi")) // count returns 0 or 1
    cout << "ghi is present" << endl;

  cout << mymap.size() << endl;
  mymap.erase("ghi"); // erase the <key,value> pair, if present
  
  // Iterators
  unordered_map<string,int>::iterator it;
  mymap.clear(); // erase everything from map. The size is now 0.
  mymap["abc"] = 2;
  mymap["abc1"] = 21;
  mymap["abc2"] = 22;
  mymap["abc3"] = 23;
  mymap["abc4"] = 24;
  mymap["abc5"] = 25;
  mymap["abc6"] = 26;
  for(it=mymap.begin(); it!=mymap.end(); it++)
  {
    cout << it->first << ' ' << it->second << endl;
  }

  int arr[] = {1,3,2,4,3,2,1,4,3,2,3,4,3,2,1,6,4,5,3,2,7,2,3,8,8,1,2,3};
  vector<int> uniqueVector = removeDuplicates(arr, sizeof(arr)/sizeof(int));
  for(int i=0; i<uniqueVector.size(); i++)
    cout << uniqueVector[i] << ' ';
  cout << endl;
  */
  return 0;
}

