#include<iostream>
using namespace std;

int main()
{
  int m = 4, n = 5;
  int *p = new int[m*n];
  for(int i=0; i<m; i++)
  {
    for(int j=0; j<n; j++)
      cout << (&p[(i*n)+j] - &p[0]) << ' ';
    cout << endl;
  }
}

