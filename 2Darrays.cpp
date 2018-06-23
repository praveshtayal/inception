#include<iostream>
using namespace std;

int main()
{
  int m = 4, n = 5;
  int *p = new int[m*n];
  //int (*arr2D)[n] = ((int [n])p);
  for(int i=0; i<m; i++)
  {
    for(int j=0; j<n; j++)
      cout << (&p[(i*n)+j] - &p[0]) << ' ';
    cout << endl;
  }
}

