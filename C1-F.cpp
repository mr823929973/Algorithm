#include<iostream>
using namespace std;
int main()
{
    int n,i;
    long long a[51];
    a[1] = 1 ;
    a[2] = 2 ;
    a[3] = 4 ;
    a[4] = 7 ;   
    a[5] = 13 ;
    for(i = 6 ; i <= 50 ; i++)
    {
        a[i] = a[i - 4] + a[i - 5] + a[i - 2] + a[i - 1];
    }
    while(cin >> n)
        cout << a[n] << endl;
}