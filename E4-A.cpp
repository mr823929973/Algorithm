#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
const int inf=1000005;
char s1[inf],s2[inf];
int main()
{
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
    int T,n,i;
    int s10,s11,s20,s21,c10,c01;
    cin >> T;
    while(T--)
    {
        s10=s11=s20=s21=0;
        c01=c10=0;
        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));
        scanf("%s%s",s1,s2);
        n=strlen(s1);
        n--;
        for(i=0;i<n;i++)
        {
            if(s1[i]=='0') 
            {
                s10++;
                if(s2[i]=='0') s20++;
                else
                {
                    c01++;
                    s21++;
                }
            }
            else
            {
                s11++;
                if(s2[i]=='1') s21++;
                else
                {
                    c10++;
                    s20++;
                }
            }
        }
        if((s11==0&&s21!=0)||(s10==0&&s20!=0))
        {
            cout<<"-1"<<endl;
        }
        else cout<<min(c10,c01)+abs(c10-c01)<<endl;
    }
    return 0;
}