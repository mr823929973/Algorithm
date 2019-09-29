#include<iostream>
using namespace std;
#define MAXSIZE 1000005
int a[MAXSIZE];
int diff[MAXSIZE];
int main()
{
    int n , k , i;
    cin >> n >> k;
    int x , y;
    for(i = 0 ; i < k ; i++)
    {
        cin >> x >> y;
        diff[x]++;
        diff[x + y]--; 
    }
    int max = 0;
    for(i = 1 ; i <= n ; i++)
    {
        a[i] = a[i - 1] + diff[i];
        if(a[i] > max) max = a[i];
    }
    cout << max;
    return 0;
}