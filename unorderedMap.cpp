#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
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
  if(input==nullptr || n<=0) return 0;
  unordered_map<int,int> count;
  int maxElement=input[0];
  count[input[0]] += 1;
  for(int i=1; i<n; i++)
  {
      count[input[i]] += 1;
      if(count[input[i]]>count[maxElement])
        maxElement = input[i];
  }
  return maxElement;
}

void intersection(int input1[], int input2[], int size1, int size2) {
  /* Given two random integer arrays, print their intersection. That is, print
   * all the elements that are present in both the given arrays. Input arrays
   * can contain duplicate elements. */
  if(input1==nullptr || size1<=0) return;
  if(input2==nullptr || size2<=0) return;
  unordered_map<int,int> count;
  for(int i=0; i<size1; i++)
  {
      count[input1[i]] += 1;
  }
  for(int i=0; i<size2 && count.count(input2[i]); i++)
  {
    cout << input2[i] << endl;
    if(count[input2[i]]==1)
      count.erase(input2[i]);
  }
}

int main()
{
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


  /* count returns 0 or 1. That is beacuse unordere_map can only have atmost
   * one value for any key. Thus, the key will either be present or absent in
   * the map. And hence 0 and 1 are only possible answers. */
  if(mymap.count("ghi")) // count returns 0 or 1
    cout << "ghi is present" << endl;

  cout << mymap.size() << endl;
  mymap.erase("ghi"); // erase the <key,value> pair, if present
  
  /* Iterators */
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
  return 0;
}

