#include <iostream>
#define SIZE 1000000
using namespace std;

int getArray(int arr[], int size)
{
  cout << "Please enter the size of array: ";
  cin >> size;
  cout << "Please enter the elements of array: ";
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

int BinarySearch(int arr[], int n, int val)
{
  /* Given a sorted integer array (in ascending order) and an element x. You
   * need to search this element x in the given input array using binary
   * search. Return the index of element in the input. Return -1 if x is not
   * present in the input array. */
  int front=0,back=n-1,mid;
  // Note that this check is redundant and will be taken care in the loop.
  if(val < arr[front] || arr[back] < val)
    return -1;
  while(front<=back)
  {
    mid=(front+back)/2;
    if(val == arr[mid])
      return mid;
    else if(val>arr[mid])
      front = mid+1;
    else
      back = mid-1;
  }
  return -1;
}

void BubbleSort(int arr[], int n)
{
  /* Given a random integer array. Sort this array using bubble sort. */
  for(int i=0;i<n;++i)
    for(int j=0;j<n-i-1;++j)
      if(arr[j]>arr[j+1])
      {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
}

void SelectionSort(int arr[], int n)
{
  /* Given a random integer array. Sort this array using selection sort. */
  int min;
  for(int i=0;i<n-1;++i)
  {
    min=i;
    for(int j=i+1;j<n;++j)
      if(arr[j]<arr[min])
        min = j;
    int temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }
}

void InsertionSort(int arr[], int n)
{
  /* Given a random integer array. Sort this array using insertion sort. */
  for(int i=1;i<n;++i)
  {
    for(int j=i;j>0;--j)
      if(arr[j-1]>arr[j])
      {
        int temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
      }
  }
}

void merge(int arr1[], int size1, int arr2[], int size2, int ans[])
{
  /* Given two sorted arrays of Size M and N respectively, merge them into
   * a third array such that the third array is also sorted. */
    // We could have raised exception
    if(size1 == 0 || size2 == 0 || arr1 == nullptr || arr2 == nullptr) return;

    int sizeM = size1+size2;
    int *a1 = arr1;
    int *a2 = arr2;
    int i=0;
    while (i<sizeM && a1<arr1+size1 && a2<arr2+size2)
    {
        if(*a1<=*a2)
            ans[i++] = *a1++;
        else
            ans[i++] = *a2++;
    }

    if(a1 == arr1+size1) // arr1 is merged
        a1 = a2;
    while(i<sizeM)
        ans[i++] = *a1++;
}

long maxPathSum(int ar1[], int ar2[], int m, int n)
{
  /* Given 2 sorted arrays (in increasing order), find a path through the
   * intersections that produces maximum sum and return the maximum sum. That
   * is, we can switch from one array to another array only at common
   * elements. If no intersection element is present, we need to take sum of
   * all elements from the array with greater sum. */
    long max=0, suma=0, sumb=0;
    int i=0, j=0;
    while(i<m && j<n)
    {
        if(ar1[i]==ar2[j])
        {
            max += suma>sumb ? suma : sumb;
            max += ar1[i];
            i++;
            j++;
            suma = sumb = 0;
        }
        else if(ar1[i]<ar2[j])
        {
            suma += ar1[i++];
        }
        else
            sumb += ar2[j++];
    }
    while (i<m)
        suma += ar1[i++];
    while (j<n)
        sumb += ar2[j++];
    max += suma>sumb? suma:sumb;
    return max;
}

int equilibrium(int arr[], int n) {
  /* Find and return the equilibrium index of an array. Equilibrium index of an
   * array is an index i such that the sum of elements at indices less than
   * i is equal to the sum of elements at indices greater than i. Element at
   * index i is not included in either part. If more than one equilibrium index
   * is present, you need to return the first one. And return -1 if no
   * equilibrium index is present.*/
    int f = 0;
    int b = n-1;

    if (n<3) return -1;
    int sizef = arr[f];
    int sizeb = arr[b];
    while (b>2)
        sizeb += arr[--b];
    /* Here f=0, b=2 */
    int eq = 1;
    for(eq=1; eq<n-2; eq++)
    {
        if (sizef == sizeb) return eq;
        sizef += arr[eq];
        sizeb -= arr[eq+1];
    }

    return -1;
}

void PushZeroesEnd(int arr[], int n)
{
  /* Given a random integer array, push all the zeros that are present to end
   * of the array. The respective order of other elements should remain same.
   * Change in the input array itself. You don't need to return or print
   * elements. Don't use extra array. */
    int i, j;
    for ( i=j=0; i<n; i++)
    {
        if (arr[i] == 0) continue;
        arr[j++] = arr[i];
    }
    for ( ; j<n; j++)
        arr[j] = 0;
}

void Reverse(int arr[], int size)
{
  for(int i=0;i<size/2;++i)
  {
    int temp = arr[i];
    arr[i] = arr[size-i-1];
    arr[size-i-1] = temp;
  }
}

void Rotate(int arr[], int d, int size)
{
  /* Given a random integer array of size n, write a function that rotates the
   * given array by d elements (towards left). Change in the input array
   * itself. You don't need to return or print elements. */
  d %= size;
  Reverse(arr,size);
  Reverse(arr,size-d);
  Reverse(arr+size-d,d);
}

int FindSecondLargest(int arr[], int n)
{
  /* Given a random integer array of size n, find and return the second largest
   * element present in the array. If n <= 1 or all elements are same in the
   * array, return -2147483648 i.e. -2^31. */
  if(n <=1 ) return -2147483648;
  int largest=arr[0], secondLargest=arr[1];
  if(largest<secondLargest)
  {
    largest=arr[1];
    secondLargest=arr[0];
  }
  for(int i=2; i<n; ++i)
  {
    if(arr[i]>secondLargest)
    {
      cout << "arr[i], largest, secondLargest are" <<
        arr[i] << " " << largest << ' ' << secondLargest << endl;
      if(arr[i]>largest)
      {
        secondLargest = largest;
        largest = arr[i];
      }
      else
        secondLargest = arr[i];
    }
  }
  return secondLargest;
}

int FindSecondLargest2(int arr[], int n)
{
  /* This is where secondLargest can not be equal to largest */
  /* Given a random integer array of size n, find and return the second largest
   * element present in the array. If n <= 1 or all elements are same in the
   * array, return -2147483648 i.e. -2^31. */
  if(n <=1 ) return -2147483648;
  int largest=INT_MIN+1, secondLargest=INT_MIN;
  for(int i=0; i<n; ++i)
  {
    if(arr[i]>secondLargest)
    {
      if(arr[i]>largest)
      {
        secondLargest = largest;
        largest = arr[i];
      }
      else if(arr[i] != largest)
        secondLargest = arr[i];
    }
  }
  return secondLargest;
}

int FindSortedArrayRotation(int arr[], int n)
{
  /* Given an integer array, which is sorted (in increasing order) and has been
   * rotated by some number k in clockwise direction. Find and return the k.*/
  for(int i=1; i<n; ++i)
    if(arr[i-1]>arr[i])
      return i;
    
  return 0;
}

void sort012(int arr[], int n)
{
  /* You are given an integer array containing only 0s, 1s and 2s. Write
   * a solution to sort this array using one scan only. */
  int i,j,count[3];
  // Initialize count[i] to 0
  for(i=0; i<3; ++i)
    count[i]=0;
  //Scan the input array
  for(i=0; i<n; ++i)
    count[arr[i]]++;
  //Update the array
  for(i=0,j=0; j<count[0]; ++j)
    arr[i++] = 0;
  for(j=0; j<count[1]; ++j)
    arr[i++] = 1;
  for(j=0; j<count[2]; ++j)
    arr[i++] = 2;
}

void sumOfTwoArrays(int input1[], int size1, int input2[], int size2,
    int output[])
{
  /* Two random integer arrays are given A1 and A2, in which numbers from 0 to
   * 9 are present at every index (i.e. single digit integer is present at
   * every index of both given arrays). You need to find sum of both the input
   * arrays (like we add two integers) and put the result in another array i.e.
   * output array (output arrays should also contain only single digits at
   * every index). The size A1 & A2 can be different. Note : Output array size
   * should be 1 more than the size of bigger array and place 0 at the 0th
   * index if there is no carry. No need to print the elements of output
   * array. */
  int i1,i2,i3,sum,carry=0;
  int size3=(size1>size2?size1:size2)+1;
  for(i1=size1-1, i2=size2-1, i3=size3-1; i3>=0; --i3)
  {
    sum = 0;
    if(i1>=0) sum += input1[i1--];
    if(i2>=0) sum += input2[i2--];
    sum += carry;
    carry = sum/10;
    output[i3] = sum%10; 
  }
}

void arrays2()
{
  int n,val;
  int arr[SIZE];
  n=getArray(arr,SIZE);
  //cin >> val; cout << BinarySearch(arr,n,val) <<endl;
  //BubbleSort(arr,n);
  cout << FindSecondLargest2(arr, n) <<endl;
  //printArray(arr,n);
}
