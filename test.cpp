#include<stack>
#include<queue>
#include<iostream>
using namespace std;
int main()
{
    stack<int> stack;
    queue<int> queue;
    priority_queue<int> heap;
    int array[10]={1,3,5,7,9,2,4,6,8,10};
    int i;
    for(i=0;i<10;i++)
    {
        stack.push(array[i]);
        queue.push(array[i]);
        heap.push(array[i]);
    }
    for(i=0;i<10;i++)
    {
        cout<<stack.top()<<"    "<<queue.front()<<"    "<<heap.top()<<endl;
        stack.pop();
        queue.pop();
        heap.pop();
    }
    return 0;
}