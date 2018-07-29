#include<iostream>
using namespace std;

template <typename T1, typename T2>
class Pair {
  public:
  Pair(T1 _x=0, T2 _y=0)
  {
    x = _x;
    y = _y;
  }

  T1 getX() const
  {
    return x;
  }

  T2 getY() const
  {
    return y;
  }

  void setX(T1 _x)
  {
    x = _x;
  }

  void setY(T2 _y)
  {
    y = _y;
  }

  /*
  void print() const
  {
    cout << x << ' ' << y << endl;
  }
  */
  private:
    T1 x;
    T2 y;
};

template<typename T1, typename T2>
istream& operator>>(istream& cin,Pair<T1, T2> &p)
{
  T1 x; T2 y;
  cin >> x >> y;
  p.setX(x);
  p.setY(y);
  return cin;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& cout,const Pair<T1, T2>& p)
{
  cout << p.getX() << ' ' << p.getY();
  return cout;
}

int main()
{
  Pair<int, int> p1(0, 5);
  cin >> p1;
  cout << p1 << endl;
  p1.setX(11);
  p1.setY(22);
  Pair<float, float> p2(5.2, 7.4);
  cout << p2 << endl;
  Pair<char, char> p3('X', 'Y');
  cout << p3 << endl;
  Pair<int, float> p5(89, 98.98);
  cout << p5 << endl;

  Pair< Pair<int, float>, char> p6( Pair<int,float>(1, 10.1), 'a');
  cout << p6 << endl;
  cin >> p6;
  cout << p6 << endl;
}
