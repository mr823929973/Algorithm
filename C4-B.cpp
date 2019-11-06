#include<iostream>
using namespace std;
int index[15];
int a[15];
void dfs(int num , int n,int m)
{
    int i;
    if(num > m)
    {
        for(i = 1 ; i <= m ; i++)
        cout << a[i] << ' ';
        cout << endl;
         return;
    }
    for(i = 1 ; i <= n ; i++)
    {
        if(index[i] == 0)
        {
            index[i] = 1;
            a[num] = i;
            dfs(num + 1 , n ,m);
            index[i] = 0;
        }
    }
}
int main()
{
    int n,m;
    a[0] = 1;
    int i;
    cin >> n >>m;
    dfs(1,n,m);
    return 0;
}