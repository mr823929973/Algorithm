#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int a[100005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,t,tmp;
    while( cin >> n >>t)
    {
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            cin >> tmp;   
            a[tmp]++;
        }
        for(int i=1;i<=t;i++)
        {
            cin >> tmp;   
            cout << a[tmp] << ' ' ;
        }
        cout << endl;
    }
}