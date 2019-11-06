#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=2510;
const int INF = 0x3f3f3f3f;
int edge[maxn][maxn];
int dis[maxn]={0};
bool visit[maxn]={0};
int n,m,s,t,i,mins;
int Dijkstra(int s,int t)
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=edge[s][i];
    }
     visit[s]=true;
    dis[s]=0;
    for(int i=1;i<n;i++)
    {
        int minl=INF;
        int k=0;
        for(int j=1;j<=n;j++)
        {
            if(!visit[j]&&dis[j]<minl)
            {
                minl=dis[j];
                k=j;
            }
        }
        if(k==0)
        {
            break;
        }
        visit[k]=true;
        for(int j=1;j<=n;j++)
        {
            if(dis[k]+edge[k][j]<dis[j])
            {
                dis[j]=dis[k]+edge[k][j];
            }
        }
    }
    return dis[t];
}
int main()
{
    cin>>n>>m>>s>>t;
    memset(edge,INF,sizeof(edge));
    int a,b,val;
    for(i=0;i<m;i++)
    {
        cin>>a>>b>>val;
        edge[a][b]=val;
        edge[b][a]=val;
    }
    mins=Dijkstra(s,t);
    cout<<mins;
    return 0;
}