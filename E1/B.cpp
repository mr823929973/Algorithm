#include<iostream>
using namespace std;
int a[1000001];
int sum[1000001];
int main()
{
    int n , k;
    cin >> n >> k;
    int i;
    int big;
    for(i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    big = sum[k] - sum[0];
    for(i = k ; i <= n ; i++)
    {
        if(sum[i] - sum[i-k] > big)
            big = sum[i] - sum[i-k];
    }
    cout << big;
    return 0;
}