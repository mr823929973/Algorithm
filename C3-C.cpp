#include <iostream>
#include <cstdio>
using namespace std;

#define N 350
#define MAXVALUE 0x3f3f3f3f
int m[N+1][N+1]={0};
int s[N+1][N+1]={0};
int p[N+1] = {};
int n;
void matrix_chain_order(int *p,int len,int m[N+1][N+1],int s[N+1][N+1]);
void print_optimal_parents(int s[N+1][N+1],int i,int j);

int main()
{
    int i;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n+1;i++) scanf("%d",&p[i]);
        matrix_chain_order(p,n+1,m,s);
        printf("%d\n",m[1][n]);
        print_optimal_parents(s,1,n);
        printf("\n");
    }
    return 0;
}

void matrix_chain_order(int *p,int len,int m[N+1][N+1],int s[N+1][N+1])
{
    int i,j,k,t;
    for(i=0;i<=n;++i)
        m[i][i] = 0;
    for(t=2;t<=n;t++) 
    {
        for(i=1;i<=n-t+1;i++)  
        {
            j=i+t-1;
            m[i][j] = MAXVALUE;  
            for(k=j-1;k>=i;k--)   
            {
                int temp = m[i][k]+m[k+1][j] + p[i-1]*p[k]*p[j];
                if(temp < m[i][j])
                {
                    m[i][j] = temp;   
                    s[i][j] = k;     
                }
            }
        }
    }
}

//s中存放着括号当前的位置
void print_optimal_parents(int s[N+1][N+1],int i,int j)
{
    if( i == j)
        cout<<"A"<<i;
    else
    {
        cout<<"(";
        print_optimal_parents(s,i,s[i][j]);
        print_optimal_parents(s,s[i][j]+1,j);
        cout<<")";
    }

}