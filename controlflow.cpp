#include<iostream>
#include<cmath>
using namespace std;

int averageMarks(){

 /*  Write a program to input name (as a single character) and marks of
  *  three tests of a student (all integers). Then calculate and print the 
  *  name and average (integer) of all test marks.
  *  All the test marks are integers and calculate average also as integer.
  *  That is, you need to print the integer part of average only, neglect 
  *  the decimal part. */
  char name;
  long a,b,c;
  
  cin >> name;
  cin >> a >> b >> c;
  cout << name << "\n";
  cout << (a+b+c)/3 << "\n";
  return 0;
}  

int averageBest2Marks(){

 /*  Write a program to input name (as a single character) and marks of
  *  three tests of a student (all integers). Then calculate and print the 
  *  name and average (integer) of best 2 test marks.
  *  All the test marks are integers and calculate average also as integer.
  *  That is, you need to print the integer part of average only, neglect 
  *  the decimal part. */
  char name;
  long a,b,c;
  
  cin >> name;
  cin >> a >> b >> c;
  cout << name << " ";
  if(a<b && a<c)
      cout << (b+c)/2 << "\n";
  else if(b<a && b<c)
      cout << (a+c)/2 << "\n";
  else
      cout << (a+b)/2 << "\n";
  return 0;
}  

int characterCase() {
  /* Write a program to determine whether the entered character is in 
   * uppercase or lowercase, or is an invalid character.  Print
   * 1 for uppercase
   * 0 for lowercase 
   * -1 for any other character (special characters or others) */
  char c;
  int out = -1;
  cin >> c;
  if ('a'<= c && c <= 'z') out =  0;
  else if ('A'<= c && c <= 'Z') out = 1;
  cout << out << endl;
  return 0;
}

int sumEvenNumbers()
{
  int n;
  cin >> n;
  int sum = 0;
  for (int i=2; i<=n; i+=2)
    sum += i;
  cout << sum;
  return 0;
}

int fahrToCel()
{
  /* Given three values - Start Fahrenheit Value (S), End Fahrenheit value (E)
   * and Step Size (W), you need to convert all Fahrenheit values from Start to
   * End at the gap of W, into their corresponding Celsius values and print the
   * table. */
  int start, end, step;
  cin >> start >> end >> step;
  for(int fahr=start; fahr<=end; fahr+=step)
      cout << fahr << '\t' << int((fahr-32)*5.0/9.0) << endl;
  return 0;
}

int numberPatternC1()
{
  long n;
  cin >> n;

  for(int i=0;i<n; i++)
  {
      for(int j=0;j<=i; j++)
          cout << i+j+1;
      cout << endl;
  }
  return 0;
}

int numberPatternC2()
{
  long n;
  cin >> n;

  for(int i=0;i<n; i++)
  {
      for(int j=1;j<n-i; j++)
          cout << ' ';
      for(int j=0;j<=i; j++)
          cout << i+j+1;
      cout << endl;
  }
  return 0;
}

int starPattern()
{
  long n;
  cin >> n;

  for(int i=0;i<n; i++)
  {
      for(int j=1;j<n-i; j++)
          cout << ' ';
      for(int j=1;j<=2*i+1; j++)
          cout << '*';
      cout << endl;
  }
  return 0;
}

int trianglePattern()
{
  long n;
  cin >> n;
  int j;

  for(int i=0;i<n; i++)
  {
      for(j=1;j<n-i; j++)
          cout << ' ';
      for(j=0;j<=i; j++)
          cout << i+j+1;
      for(--j;j>0; --j)
          cout << i+j;
      cout << endl;
  }
  return 0;
}

int totalSalary() {
	/* Write a program to calculate the total salary of a person. The user has to 
   * enter the basic salary (an integer) and the grade (an uppercase character),
   * and depending upon which the total salary is calculated as -
   * totalSalary = basic + hra + da + allow – pf
   * where :
   * hra   = 20% of basic
   * da    = 50% of basic
   * allow = 1700 if grade = ‘A’
   * allow = 1500 if grade = ‘B’
   * allow = 1300 if grade = ‘C' or any other character
   * pf    = 11% of basic.
   * Round off the total salary and then print the integral part only. */
  int basic;
  char grade;
  int allow = 1300;

  cin >> basic >> grade;
  if(grade=='A') allow = 1700;
  else if (grade == 'B') allow = 1500;

  cout << (int)round(1.59*basic + allow);
  return 0;
}

int quadraticRoots() {
	// Write your code here
  long a,b,c;
  cin >> a >> b >> c;

  int discriminant = (b*b) - 4*a*c;
  if (discriminant < 0)
  {
    cout << "-1" << endl;
    return 0;
  }
  else if (discriminant == 0)
  {
    cout << "0" << endl;
  }
  else
  {
    cout << "1" << endl;
  }

  discriminant = sqrt(discriminant);
  cout << (int)round((-b+discriminant)/(2.0*a)) << ' ';
  cout << (int)round((-b-discriminant)/(2.0*a)) << endl;
  return 0;
}

int sumEvenOddDigits()
{
  /* Prints the sum of even places and out places. Note that units digit will
   * be odd place in odd digit numbers and even place in even digit number */
  long n;
  cin >> n;

  int odd, even, digit, flag;
  odd = even = digit = flag = 0;
  while(n)
  {
    digit = n%10;
    n /= 10;
    if(flag)
    {
      flag = 0;
      even += digit;
    }
    else
    {
      flag = 1;
      odd += digit;
    }
  }
  if(flag)
      cout << even << ' ' << odd << endl;
  else
      cout << odd << ' ' << even << endl;
  return 0;
}

int sumEvenOddDigits2()
{
  /* Write a program to input an integer N and print the sum of all its even
   * digits and sum of all its odd digits separately.
   * Digits means numbers not the places. That is, if the given integer is
   * "13245", even digits are 2 & 4 and odd digits are 1, 3 & 5.
   * Print first even sum and then odd sum separated by space */

  long n;
  cin >> n;

  int odd, even, digit;
  odd = even = 0;
  while(n)
  {
    digit = n%10;
    n /= 10;
    if(digit%2==0)
    {
      even += digit;
    }
    else
    {
      odd += digit;
    }
  }
  cout << even << ' ' << odd << endl;
  return 0;
}

int power()
{
  long base, n, result;
  cin >> base >> n;

  result = 1;
  for(int i=0;i<n; i++)
    result *= base;
  cout << result << endl;
  return 0;
}

int numberPattern1()
{
  long n;
  cin >> n;

  for(int i=0;i<n; i++)
  {
      for(int j=0;j<=i; j++)
          cout << '1';
      cout << endl;
  }
  return 0;
}

int numberPattern2()
{
  long n;
  cin >> n;

  cout << '1' << endl;
  for(int i=1;i<n; i++)
  {
      for(int j=0;j<=i; j++)
        if(j==0 || j==i)
          cout << i;
        else
          cout << '0';
      cout << endl;
  }
  return 0;
}

int numberPattern3()
{
  long n;
  cin >> n;

  for(int i=0;i<n; i++)
  {
      for(int j=0;j<=i; j++)
        if(j==0 || j==i)
          cout << '1';
        else
          cout << '2';
      cout << endl;
  }
  return 0;
}

int numberPattern4()
{
  long n;
  cin >> n;

  for(int i=0;i<n; i++)
  {
      for(int j=1;j<=n-i; j++)
          cout << j;
      cout << endl;
  }
  return 0;
}

void controlflow()
{
  //quadraticRoots();
  //sumEvenOddDigits2();
  //power();
  //numberPattern1();
  //numberPattern2();
  //numberPattern3();
  //numberPattern4();
  //fahrToCel();
  //numberPatternC1();
  //numberPatternC2();
  //starPattern();
  //trianglePattern();
}
