#include<cstdio>
#include<algorithm>
int num[100005];
int dp[100005];
int max(int a ,int b)
{
    if(a>=b) return a;
    else return b;
}
int main()
{
    int n,tmp,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&tmp);
        num[tmp]+=1;
    }
    dp[1]=num[1];
    for(i=2;i<=100000;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+num[i]*i);
    }
    printf("%d",dp[100000]);
    return 0;
}