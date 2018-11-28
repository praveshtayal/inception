#include <iostream>
using namespace std;

int numberStarPattern()
{
    int n;
    cin >> n;

    for(int i=0;i<n; i++)
    {
        for(int j=0;j<n; j++)
            if(j==n-i-1)
                cout << '*';
            else
                cout << n-j;
        cout << endl;
    }
    return 0;
}

int zeroStarPattern()
{
    int n,i,j;
    cin >> n;

    for(i=0;i<n; i++)
    {
        /* Print 1st Part */
        for(j=0;j<n; j++)
            if(j==i)
                cout << '*';
            else
                cout << '0';
        /* Print * Part */
        cout << '*';
        /* Print 2nd Part */
        for(j=0;j<n; j++)
            if(j==n-i-1)
                cout << '*';
            else
                cout << '0';
        cout << endl;
    }
    return 0;
}

int checkArmstrong()
{
    int n,i,j;
    cin >> n;

    int digits = 0;
    int ncopy = n;
    int result = 0;
    for(i=n;i; i/=10)
        digits++;
    for(i=0;i<digits; i++)
    {
        int digit = n%10;
        n /= 10;
        int exp=1;
        for(j=0;j<digits; j++)
            exp *= digit;
        result += exp;
    }
    if(result==ncopy)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}

int main()
{
    double d = 10.0; cout << d << endl;
    //numberStarPattern();
    //zeroStarPattern();
    //checkArmstrong();
    return 0;
}

