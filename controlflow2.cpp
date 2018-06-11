#include <iostream>
using namespace std;

int printPrimes()
{
  static int _primeList[] = {2,3,5,7,11,13,17,19,23,29,31,37};
  int n, i, j, divisor;
  cin >> n;

  static int *primeList = new int[n];
  static int listSize = sizeof(_primeList)/sizeof(int);
  for(i=0; i<listSize; ++i)
    primeList[i] = _primeList[i];
  int maxPrime = primeList[i-1];
  for(int i=maxPrime; i<=n; ++i)
  {
    // Check if i is prime
    for(j=0; j<listSize; ++j)
       if(i%primeList[j]==0)
         break; // not a prime no.
    if(j==listSize)
    {
      // i is prime. Add it to primeList
      primeList[listSize++] = i;
    }
  }
  for(i=0; i<listSize && primeList[i]<=n; ++i)
    cout << primeList[i] << endl;
  return 0;
}

int fib()
{
  // Print the nth fibonnaci number
  int n, i, j, divisor;
  cin >> n;

  int *fib= new int[n+1];
  fib[0]=0;
  fib[1]=1;
  for(i=2;i<=n;++i)
  {
    fib[i] =fib[i-1]+fib[i-2];
  }
  cout << fib[n] <<endl;
  delete [] fib;
  return 0;
}

int fib2()
{
  // Print the nth fibonnaci number
  int n, i;
  cin >> n;

  int a=0, b=1, c;
  for(i=0;i<=n;++i)
  {
    c=a+b;
    a=b;
    b=c;
  }
  cout << a <<endl;
  return 0;
}

int trailingZerosInFact()
{
  int n, result=0, power=5;
  cin >> n;
  while(n>=power)
  {
    result += n/power; //power
    power *= 5;
  }
  cout << result << endl;
  return 0;
}

int countChar()
{
  /* Write a program to count and print the total number of characters
   * (lowercase english alphabets only), digits (0 to 9) and white spaces
   * (single space, tab i.e. '\t' and newline i.e. '\n') entered till '$'.
   * That is, input will be a stream of characters and you need to consider
   * all the characters which are entered till '$'.
   * Print count of characters, count of digits and count of white spaces
   * respectively (separated by space). */
  int lowercase=0, digit=0, whitespace=0;
  char c;
  cin.get(c);
  while(c != '$')
  {
    if ('a'<= c && c <= 'z') lowercase += 1;
    else if ('0'<= c && c <= '9') digit += 1;
    else if (' '== c || c == '\n' || c == '\t') whitespace += 1;
    cin.get(c);
  }
  cout << lowercase << ' ' << digit << ' ' << whitespace << endl;
  return 0;
}

int arrowPattern()
{
  int n, i,j;
  cin >> n;
  for(i=0;i<=n/2;++i)
  {
    for(j=0;j<i;++j)
      cout << ' ';
    for(j=0;j<=i;++j)
      cout << "* ";
    cout << endl;
  }
  for(i-=2;i>=0;--i)
  {
    for(j=0;j<i;++j)
      cout << ' ';
    for(j=0;j<=i;++j)
      cout << "* ";
    cout << endl;
  }
  return 0;
}

int numberPattern()
{
  int n, i,j,k;
  cin >> n;
  for(i=n;i>=1;--i)
  {
    k=i;
    for(j=1;j<=n;++j)
    {
      cout << k;
      if (k<n) k++;
    }
    cout << endl;
  }
  return 0;
}

int sumOrProduct()
{
  int n,c,j,result;
  cin >> n >> c;
  if(c==1)
  {
    result = 0;
    for(j=1;j<=n;++j)
    {
      result += j;
    }
  }
  else if(c==2)
  {
    result = 1;
    for(j=1;j<=n;++j)
    {
      result *= j;
    }
  }
  else
      result = -1;
  cout << result << endl;
  return 0;
}

int termsAP()
{
  int n,j,k,result;
  cin >> n;
  for(j=1,k=1;k<=n;++j)
  {
    result = 3*j + 2;
    if(result%4==0)
      continue;
    cout << result << ' ';
    ++k;
  }
  cout << endl;
  return 0;
}

int squareRoot()
{
  int n,j,result;
  cin >> n;
  for(j=1;j<=n;++j)
  {
    result = j*j;
    if(result>n)
      break;
  }
  cout << j-1 << endl;
  return 0;
}

int reverseDigits()
{
  int n,result=0;
  cin >> n;
  while(n)
  {
    int digit = n%10;
    n /= 10;
    result = result*10 + digit;
  }
  cout << result << endl;
  return 0;
}

int decimalToBinary()
{
  long n,result=0,i=1;
  cin >> n;
  while(n)
  {
    if(n%2)
    {
      result += i;
    }
    n /= 2;
    i *= 10;
  }
  cout << result << endl;
  return 0;
}

int binaryToDecimal()
{
  long n,result=0,i=1;
  cin >> n;
  while(n)
  {
    if(n%10)
    {
      result += i;
    }
    n /= 10;
    i *= 2;
  }
  cout << result << endl;
  return 0;
}

int checkDecreasingIncreasing()
{
  /* You are given S a sequence of n integers i.e. S = s1, s2, ..., sn.
   * Compute if it is possible to split S into two parts : s1, s2, ..., si
   * and si+1, si+2, ….., sn (0 <= i <= n) in such a way that the first 
   * part is strictly decreasing while the second is strictly increasing one
   * That is, in the sequence if numbers are decreasing, they can start 
   * increase at one point. And once number starts increasing, they cannot
   * decrease at any point further.
   * Sequence made up of only increasing numbers or only decreasing numbers
   * is a valid sequence. So in both the cases, print true. 
   * You just need to print true/false. No need to split the sequence. */
  int n,i;
  cin >> n;
  int *a= new int[n];
  // Input the sequence into array
  for(i=0;i<n;++i)
    cin >> a[i];
  // Check for Decreasing
  for(i=0;i<n-1 && a[i]>a[i+1];++i); 
  // Check for increasing
  for(;i<n-1 && a[i]<a[i+1];++i);
  if(i==n-1)
    cout << "true" << endl;
  else
    cout << "false" << endl;
  delete [] a;
  return 0;
}

void controlflow2()
{
  //printPrimes();
  //fib();
  //trailingZerosInFact();
  //countChar();
  //arrowPattern();
  //numberPattern();
  //sumOrProduct();
  //termsAP();
  //squareRoot();
  //reverseDigits();
  //decimalToBinary();
  //binaryToDecimal();
  //checkDecreasingIncreasing();
}
