#include <iostream>
using namespace std;

int main()
{
  int n = 5;
  int i = 1;
  while( i <= n )
  {
    int j = 1;
    while( j <= n ) // What if we change n to i. No change
    {
      cout << j;
      if(j==i)
      {
        break;
        // return; // What if return instead of break;
      }
      j = j + 1;
    }
    cout << endl;
    i = i + 1;
  }
  cout << "Outside While" << endl;
  return 0;
}

int main()
{
  int n = 5;
  int i = 1;
  while( i <= n )
  {
    i = i+1;
    cout << i << endl;
  }
  cout << "Outside While" << endl;
  return 0;
}

int main()
{
  int n = 5;
  int i = 1;
  while( i <= n )
  {
    i = i+1;
    if(i==4)
      break;  // What if continue
    cout << i << endl;
  }
  cout << "Outside While" << endl;
  return 0;
}

int main()
{
  int n = 5;
  int i = 1;
  while( i <= n )
  {
    if(i==4)
      continue;
    cout << i << endl;
    i = i+1;
  }
  cout << "Outside While" << endl;
  return 0;
}

