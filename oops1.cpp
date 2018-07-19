#include <iostream>
#include <vector>
using namespace std;

class Fraction {
  public:
    Fraction(int numerator=0, int denominator=1);
    int numerator() const;
    int denominator() const;
    
    Fraction & operator +=(const Fraction& f);
    Fraction & operator *=(const Fraction& f);

    //ostream& operator <<(ostream& cout);
    friend istream& operator>>(istream& cin, Fraction& f);
  private:
    int _numerator, _denominator;
    void reduce();
};

Fraction::Fraction(int numerator, int denominator)
  : _numerator(numerator), _denominator(denominator)
{
  //cout << "Constructor Called" << endl;
  reduce();
}

int Fraction::numerator() const {
  return this->_numerator;
}

int Fraction::denominator() const {
  return this->_denominator;
}

int gcd(int a, int b)
{
  int minimum = min(a,b);
  int ans = 1;
  for(int i=2; i<=minimum; i++)
  {
    if((a%i)==0 && (b%i)==0)
      ans = i;
  }
  return ans;
}

void Fraction::reduce() {
  int _gcd = gcd(_numerator, _denominator);
  _numerator /= _gcd;
  _denominator /= _gcd;
}

Fraction& Fraction::operator +=(const Fraction &f)
{
  _numerator = _numerator*f._denominator + f._numerator * _denominator;
  _denominator = _denominator * f._denominator;
  reduce();
  return *this;
}

Fraction& Fraction::operator *=(const Fraction &f)
{
  _numerator *= f._numerator;
  _denominator *= f._denominator;
  reduce();
  return *this;
}

ostream& operator<<(ostream& cout, const Fraction & f)
{
  cout << f.numerator() << '/' << f.denominator();
  return cout;
}

istream& operator>>(istream& cin, Fraction& f)
{
  int a, b;
  cin >> f._numerator >> f._denominator;
  f.reduce();
  //cin >> a >> b;
  //f = Fraction(a,b);
  return cin;
}

class ComplexNumbers
{
  public:
    ComplexNumbers(int r=0, int i=0);
    void plus(const ComplexNumbers &c);
    void multiply(const ComplexNumbers &c);
    void print() const;
  private:
  int re,im;
};

ComplexNumbers::ComplexNumbers(int r, int i)
  :re(r),im(i)
{
  /*
  this->re = r;
  this->im = i;
  */
}
void ComplexNumbers::plus(const ComplexNumbers &c)
{
  re += c.re;
  im += c.im;
}

void ComplexNumbers::multiply(const ComplexNumbers &c)
{
  int real = re*c.re - im*c.im;
  im = re*c.im + im*c.re;
  re = real;
}

void ComplexNumbers::print() const
{
  std::cout << re << " + i" << im << std::endl;
}

class Polynomial {
  public:
    void setCoefficient(int degree, int coeff)
    {
      int i=getCoefficientIndex(degree);
      // Here we should insert degree and coeff at index i
      pair<int,int> x(degree,coeff);
      if(i<p.size())
      {
        if(p[i].first==degree)
        {
          // We already have a term of this degree
          if(coeff==0)
          {
            p.erase(p.begin()+i);
            return;
          }
          p[i].second = coeff;
          return;
        }
        if(coeff!=0) p.insert(p.begin()+i, x);
        return;
      }
      if(coeff!=0) p.push_back(x);
    }

    Polynomial& add(const Polynomial& b)
    {
      for(int i=0; i<b.p.size(); i++)
      {
        int degree = b.p[i].first;
        int coeff=getCoefficient(degree);
        coeff += b.p[i].second;
        setCoefficient(degree, coeff);
      }
      return (*this);
    }

    Polynomial& subtract(const Polynomial& b)
    {
      for(int i=0; i<b.p.size(); i++)
      {
        int degree = b.p[i].first;
        int coeff=getCoefficient(degree) ;
        coeff -= b.p[i].second;
        setCoefficient(degree, coeff);
      }
      return (*this);
    }

    Polynomial& multiply(const Polynomial& b)
    {
      vector< pair<int,int> > old = p;
      p.clear(); // p is now empty
      for(int i=0; i<b.p.size(); i++)
      {
        int degreeB = b.p[i].first;
        int coeffB = b.p[i].second;
        //int coeff=getCoefficient(degree) ;
        for(int j=0; j<old.size(); j++)
        {
          int degreeA = old[j].first;
          int coeffA = old[j].second;
          Polynomial temp;
          temp.setCoefficient(degreeA+degreeB, coeffA*coeffB);
          add(temp);
        }
      }
      return (*this);
    }

    int getCoefficient(int degree) const
    {
      int index=getCoefficientIndex(degree);
      if(index<p.size() && p[index].first == degree)
        return p[index].second;
      return 0;
    }

    void print() const
    {
      for(int i=0; i<p.size(); i++)
        cout << p[i].second << 'x' << p[i].first << ' ';
      cout << endl;
    }

  private:
    vector< pair<int, int> > p;
    int getCoefficientIndex(int degree) const
    {
      int i=0;
      for(; i<p.size(); i++)
        if(p[i].first >= degree)
          return i;
      return i;
    }
};

int main()
{
  /* Fraction Usage
  Fraction f, f1;
  cout << f << ' ' << f1 << endl;
  cin >> f >> f1;
  cout << f << ' ' << f1 << endl;
  f += f1;
  cout << f << ' ' << f1 << endl;
  f1 *= f;
  cout << f << ' ' << f1 << endl;
  */

  /*
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    */
  Polynomial a, b;
  a.setCoefficient(1,5);
  a.setCoefficient(5,25);
  a.setCoefficient(3,9);
  a.print();

  b.setCoefficient(1,5);
  b.print();

  a.multiply(b);
  a.print();
    return 0;
}
