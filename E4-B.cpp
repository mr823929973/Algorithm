#include<iostream>
#include<stack>
using namespace std;
bool isW(string);
int main()
{
    int T;
    string x;
    cin >> T;
    while(T--)
    {
        cin >> x;
        if(isW(x)) cout << "Yes" <<endl;
        else cout << "No" <<endl;
    }
    return 0;
}
bool isW(string x)
{
    if(x=="") return true;
    stack<char> p;
    int flag=0;
    int pos;
    for(int i=0;i<x.length();i++)
    {
        if (x[i] == '(') 
        {
			p.push(1);
		}
        else 
        {
			if(!p.empty())
				p.pop();
			else 
            {
				return false;
			}
			if(p.empty())
            {
				flag++;
				if (flag == 1) 
                {
					pos = i;
				}
                else if(flag > 2)
                    return false;
			}
		}
	}
	if(flag == 1)
    {
		string x1 = x.substr(1, x.length()-2);
		return isW(x1);
	}
    else if(flag == 2)
    {
		string x1 = x.substr(1, pos-1);
		string x2 = x.substr(pos+2, x.length()-pos-3);
		return isW(x1) && isW(x2);
	}
    else
    {
		return false;
	}
}
