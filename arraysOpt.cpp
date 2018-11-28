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

void printSArray(string a[], int size)
{
    cout << "The Array of size " << size << " is ";
    for(int i=0;i<size;i++) cout << a[i] << ' ';
    cout << endl;
}

int FindUnique(int arr[], int size){
    /* Given an integer array of size 2N + 1. In this given array, N numbers are
     * present twice and one number is present only once in the array. You need
     * to find and return that number which is unique in the array. */ 
    int result = 0;
    for (int i=0;i<size;++i)
        result ^= arr[i];
    return result;
}

int MissingNumber(int arr[], int size){
    /* Given an array of integers of size n which contains numbers from 0 to
     * n - 2. Each number is present at least once. That is, if n = 5, numbers
     * from 0 to 3 is present in the given array at least once and one number is
     * present twice. You need to find and return that duplicate number present
     * in the array. Assume, duplicate number is always present in the array. */
    int result = 0;
    for (int i=0;i<=size-2;++i)
    {
        result ^= i;
        result ^= arr[i];
    }
    return result^arr[size-1];
}

void mergeSort(int input[], int size){
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

void intersection(int input1[], int input2[], int size1, int size2) {
    /* Given two random integer arrays, print their intersection. That is, print
     * all the elements that are present in both the given arrays. Input arrays
     * can contain duplicate elements. 
     * Print intersection elements in different lines */
    /* Solution: Here we will sort the two arrays and then print their
     * intersection. Also, we will copy the elements before making the changes as
     * we should not alter the given array */
    int i, j;
    mergeSort(input1,size1);
    mergeSort(input2,size2);
    i=0, j=0;
    while(i<size1 && j<size2)
    {
        if(input1[i]==input2[j])
        {
            cout << input1[i] << endl;
            i++;
            j++;
        }
        else if(input1[i]<input2[j])
        {
            i++;
        }
        else
            j++;
    }
}

void intersection2(int input1[], int input2[], int size1, int size2) {
    /* Given two random integer arrays, print their intersection. That is, print
     * all the elements that are present in both the given arrays. Input arrays
     * can contain duplicate elements. 
     * Print intersection elements in different lines */


    /* Solution: Here we will sort the two arrays and then print their
     * intersection. Also, we will copy the elements before making the changes as
     * we should not alter the given array */
    int i, j;
    int *input3=new int[size1];
    int *input4=new int[size2];

    for(j=0;j<size1;++j)
        input3[j] = input1[j];
    for(j=0;j<size2;++j)
        input4[j] = input2[j];

    mergeSort(input3,size1);
    mergeSort(input4,size2);
    i=0, j=0;
    while(i<size1 && j<size2)
    {
        if(input3[i]==input4[j])
        {
            cout << input3[i] << endl;
            i++;
            j++;
        }
        else if(input3[i]<input4[j])
        {
            i++;
        }
        else
            j++;
    }
    delete [] input3;
    delete [] input4;
}

void pairSum(int input[], int size, int x) {
    /* Given a random integer array A and a number x. Find and print the pair of
     * elements in the array which sum to x. Array A can contain duplicate
     * elements. While printing a pair, print the smaller element first. That is,
     * if a valid pair is (6, 5) print "5 6". There is no constraint that out of
     * 5 pairs which have to be printed in 1st line. You can print pairs in any
     * order, just be careful about the order of elements in a pair. */
#define HUNDRED 100
    int elements[HUNDRED+1] = {0};
    if(x<1 || HUNDRED<x) return;
    for(int i=0;i<size;++i)
        if(0<=input[i] && input[i]<=HUNDRED)
            elements[input[i]]++;
    for(int i=0;i<=x/2;++i)
    {
        int product;
        if(i==x-i)
            product = elements[i]*(elements[i]-1)/2;
        else
            product = elements[i]*elements[x-i];
        for(int j=0;j<product;j++)
            cout << i << ' ' << x-i << endl;
    }
}

void pairSum2(int input[], int size, int x) {
    /* Here we do not assume any constraint on integer numbers present in the
     * array. Thus, we use another approach */
    /* Given a random integer array A and a number x. Find and print the pair of
     * elements in the array which sum to x. Array A can contain duplicate
     * elements. While printing a pair, print the smaller element first. That is,
     * if a valid pair is (6, 5) print "5 6". There is no constraint that out of
     * 5 pairs which have to be printed in 1st line. You can print pairs in any
     * order, just be careful about the order of elements in a pair. */
    mergeSort(input,size);
    int start=0, end=size-1;
    while(start<end){
        if(input[start]+input[end]==x)
        {
            int product;
            if(input[start]==input[end])
            {
                int count=end-start+1;
                product = count*(count-1)/2;
                start = end; // To ensure that while loop exits
            }
            else
            {
                int startCount=1, endCount=1;
                while(start+1<end && input[start+1]==input[start]) {
                    startCount++;
                    start++;
                }
                while(start<end-1 && input[end-1]==input[end]) {
                    endCount++;
                    end--;
                }
                product = startCount*endCount;
            }
            for(int j=0;j<product;j++)
                cout << input[start] << ' ' << input[end] << endl;
            start++;
            end--;
        }
        else if(input[start]+input[end]<x)
            start++;
        else
            end--;
    }
}

void SortZeroesAndOne(int arr[], int n)
{
    /* You are given an integer array A that contains only integers 0 and 1.
     * Write a function to sort this array. Find a solution which scans the array
     * only once. Don't use extra array. */
    int i, j, k;
    i=0;j=n-1;
    while(i<j)
    {
        while(arr[i]==0 && i<n) i++;
        while(arr[j]==1 && j>i) j--;
        if(i<j)
        {
            k=arr[i];
            arr[i] = arr[j];
            arr[j] = k;
        }
    }
}

void FindTriplet(int arr[], int size, int x)
{
    /* Given a random integer array A and a number x. Find and print the triplet
     * of elements in the array which sum to x. Array A can contain duplicate
     * elements. While printing a triplet, print the smaller element first. That
     * is, if a valid triplet is (1, 6, 5) print "1 5 6". There is no constraint
     * that out of
     * 5 triplet which have to be printed in 1st line. You can print in any
     * order, just be careful about the order of elements in a triplet. */
#define HUNDRED 100
    int elements[HUNDRED+1] = {0};
    if(x<1 || HUNDRED<x) return;
    for(int i=0;i<size;++i)
        if(0<=arr[i] && arr[i]<=HUNDRED)
            elements[arr[i]]++;
    for(int i=0;i<=x/2;++i)
    {
        int product;
        if(i==x-i)
            product = elements[i]*(elements[i]-1)/2;
        else
            product = elements[i]*elements[x-i];
        for(int j=0;j<product;j++)
            cout << i << ' ' << x-i << endl;
    }
}

void FindTriplet2(int arr[], int size, int x) {
    /* Here we do not assume any constraint on integer numbers present in the
     * array. Thus, we use another approach */
    mergeSort(arr,size);
    for(int i=0; i<size-2; i++) // element at index i, i+1 and i+2 are valid
    {
        int start=i+1, end=size-1;
        while(start<end){
            if(arr[i]+arr[start]+arr[end]==x)
            {
                int product;
                if(arr[start]==arr[end])
                {
                    int count=end-start+1;
                    product = count*(count-1)/2;
                    start = end; // To ensure that while loop exits
                }
                else
                {
                    int startCount=1, endCount=1;
                    while(start+1<end && arr[start+1]==arr[start]) {
                        startCount++;
                        start++;
                    }
                    while(start<end-1 && arr[end-1]==arr[end]) {
                        endCount++;
                        end--;
                    }
                    product = startCount*endCount;
                }
                for(int j=0;j<product;j++)
                    cout << arr[i] << ' ' << arr[start] << ' ' << arr[end] << endl;
                start++;
                end--;
            }
            else if(arr[i]+arr[start]+arr[end]<x)
                start++;
            else
                end--;
        }
    }
}

int main()
{
    int n;
    int arr[THOUSAND];
    int output[THOUSAND];
    //n=getArray(arr,THOUSAND);
    //printArray(output,n);
    return 0;
}
