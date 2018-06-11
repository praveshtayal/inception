#include<iostream>
using namespace std;
int main()
{
  /* Increment check */
  int a = 10;
  int b = 20;
  int c = ++a + ++b;
  char ch = 'a';

  cout << (void*)&ch << endl;
  
  /******************
  //int arr[2][3] = { {1,2}, {3,4}, {5,6}};  Incorrect
  int arr[2][3] = { {1,2}, {3,4,6} };  // Correct
  //int arr[2][3] = { 1,2,3, 3,4,6,7 };  // Correct
  for (int i=0; i<2; i++)
    for (int j=0; j<3; j++)
      cout << arr[i][j] << ' ' ;
  cout << endl;
  *****************/
  return 0;
}
