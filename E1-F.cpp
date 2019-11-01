#include<iostream>
using namespace std;
int main()
{
    int n,i,f0=1,f1=1;
    unsigned long long currentFib;
    while(cin>>n)
    {
        currentFib=1;
        f0=1;f1=1;
        for(i = 1 ; i < n - 1 ; i++)
        {
            currentFib = f0 + f1;
            f0 = f1;
            f1 = currentFib;
        }
        cout<<currentFib<<endl;       
    }
    return 0;
}