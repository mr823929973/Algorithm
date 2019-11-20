#include<iostream>
using namespace std;
int dp[200][2];
int main()
{
    int n,i;
    while(cin >> n)
    {
        n=n/3;
        dp[1][1]=1;
        dp[1][0]=1;
        for(i=2;i<=n;i++)
        {
            dp[i][1]=(2*dp[i-1][0]+dp[i-1][1])%1000007;
            dp[i][0]=dp[i-1][1];
        }
        cout << dp[n][1] << endl;
    }
}