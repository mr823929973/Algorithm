#include<iostream>
using namespace std;
int main()
{
    int t;
    unsigned a;
    unsigned a1;
    unsigned a2;    
    cin >> t;
    while(t--)
    {
        cin >> a;
        a1 = a & 0xffff0000;
        a1 = a1 >> 16;
        a2 = a & 0x0000ffff;
        a2 = a2 << 16;
        a = a1 | a2;
        cout << a << endl;
    }
    return 0;
}