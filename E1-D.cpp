#include<iostream>
using namespace std;
int index[15];
int a[15];
void dfs(int num , int n)
{
    int i;
    if(num > 1)
    {
        for(i = 1 ; i < num ; i++)
        cout << a[i] << ' ';
        cout << endl;
        if(num > n) return;
    }
    for(i = a[num-1] ; i <= n ; i++)
    {
        if(index[i] == 0)
        {
            index[i] = 1;
            a[num] = i;
            dfs(num + 1 , n);
            index[i] = 0;
        }
    }
}
int main()
{
    int n;
    a[0] = 1;
    cin >> n;
    dfs(1 , n);
    return 0;
}