#include <iostream>
using namespace std;

bool chooseElements(int *input, int size, int sum) {
  if(size<=0) return 0==sum;
  if(size==1) return input[0]==sum;
  return chooseElements(input+1, size-1, sum-input[0])
    || chooseElements(input+1, size-1, sum);
}

bool splitArray(int *input, int size) {
  int sum3=0, sum5=0, sumOther=0;
#define FIFTY 50
  int other[FIFTY], sizeOther=0;
  for(int i=0; i<size; i++)
    if(input[i]%5==0)
      sum5 += input[i];
    else if(input[i]%3==0)
      sum3 += input[i];
    else {
      sumOther += input[i];
      other[sizeOther++] = input[i];
    }
  int sumTotal = sum3 + sum5 + sumOther;
  if(sumTotal%2 != 0) return false;
  int sumSet = sumTotal/2;
  int diff3 = sumSet - sum3;
  int diff5 = sumSet - sum5;
  int diff = min(diff3, diff5);
  return chooseElements(other, sizeOther, diff);
}

int main()
{
  int n, arr[FIFTY];
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> arr[i];
  cout << splitArray(arr, n) << endl;
}

