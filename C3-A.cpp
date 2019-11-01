#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 501
#define max 0x3f3f3f3f
int p[N][N]={};
int f[N][N]={};
int dp[N][N]={};
int main()
{
    int m,n,i,j,k;
    int ans;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(dp,max,4*501*501);
        ans=max;
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=m;j++)
                scanf("%d",&p[i][j]);
                dp[1][i]=p[i][1];
            }
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%d",&f[i][j]);      
        for(i=2;i<=m;i++)
            for(j=1;j<=n;j++)
                for(k=1;k<=n;k++)
                {
                    dp[i][j]=min(dp[i-1][k]+p[j][i]+f[k][j],dp[i][j]);
                }
        for(i=1;i<=n;i++)  
        ans=min(ans,dp[m][i]);
        printf("%d\n",ans);      
    }
    return 0;
}