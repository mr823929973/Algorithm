#include<iostream>
using namespace std;
#define swap(x, y)\
	x = x ^ y;\
	y = x ^ y;\
	x = x ^ y;
int cnt = 0 ;
int a[55];
int u[10] , v[10];
void dfs(int k)
{
    if(k == 0) 
    {
        cnt ++;
        return;
    }
    if(a[v[k - 1]-1] > a[u[k - 1]-1])
    {
        dfs(k - 1);
        swap(a[v[k - 1]-1], a[u[k - 1]-1])
        dfs(k - 1);
        swap(a[v[k - 1]-1], a[u[k - 1]-1])
    }
    else return;
}
void st(int n, int s)
{
    int i , j ,k ,l;
    if(s == 0)
    {
        cnt = n + (n - 2) * (n - 1) ;
        return ;
    }
    for(i = 1 ; i <= n ; i++)
    {
        if(i == 1)
        {
            for(j = 0 ; j < n ; j++)
            {
                a[j] = 1;
                for(k = 0 ,l = 2; k < n;k++)
                {
                    if(k == j) continue;
                    a[k] = l;
                    l++;
                }
                dfs(s);
            }
        }
        else
        {
            for(j = 0 ; j < n ; j++)
            {
                if(j + 2 == i  || j + 1 == i ) continue;
                a[j] = i;
                for(k = 0 , l = 1 ; k < n ; k++)
                {   
                    if(k == j) continue;
                    if(l == i) l++;
                    a[k] = l;
                    l++;
                }
                dfs(s);
            }
        }
    }    
}
int main()
{
    int t;
    cin >> t;
    int n,k,i;
    while(t--)
    {
        cin >> n >> k;
        for(i = 0 ; i < k ; i++)
        {
            cin >> u[i] >> v[i] ;
        }
        st(n,k);
        cout << cnt << endl ;
        cnt = 0 ;
    }
    return 0;
}
