#include<iostream>
#include<algorithm>
#include<cstring>
int dp[30005]={};
int c[505];
int va[505];
int main()
{
	int n,v,i,j;
    while(std::cin>>n>>v)
    {
      	for(i=1;i<=n;i++)
			std::cin>>c[i]>>va[i];
		for(i=1;i<=n;i++)
			for(j=v;j>=0;j--)
			{
				if(j-c[i]>=0)
				dp[j]=std::max(dp[j],dp[j-c[i]]+va[i]);
			}
		std::cout<<dp[v]<<'\n';
		memset(dp,0,4*30005);
    }
	return 0;
}