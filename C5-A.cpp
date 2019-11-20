#include<iostream>
using namespace std;
int x[55];
int y[55];
int r[55];
int incircle(int x0,int y0,int i)
{
    if((x0-x[i])*(x0-x[i])+(y0-y[i])*(y0-y[i]) < r[i] * r[i]) return 1;
    else return 0;
}
int main()
{
    int T,n,i,x1,y1,x2,y2,cnt;
    cin >> T;
    while (T--)
    {
        cnt = 0;
        cin >>n;
        for(i=1;i<=n;i++)
            cin>>x[i];
        for(i=1;i<=n;i++)
            cin>>y[i];
        for(i=1;i<=n;i++)
            cin>>r[i];
        cin>>x1>>y1>>x2>>y2;
        for(i=1;i<=n;i++)
        {
            if(incircle(x1,y1,i)^incircle(x2,y2,i)==1) cnt++; 
        }
        cout << cnt << endl;
    }
    return 0;
}