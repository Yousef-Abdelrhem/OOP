#include <iostream>

using namespace std;

class Queue
{
private:
    static int  counter;
    int que;
    int top;
    int *arr;
    int _size;
public:
    Queue()
    {
        _size = 5;
        top = 0;
    }
    void enqueue(int val)
    {
        if(top != 5)
            arr[top++] = val;
        else
            cout << "queue is full";
    }
    void dequeue()
    {
        if(top != 0)
        {
            top--;
            shift(); /// 2 3 4 5
        }
        else
        {
                cout << "Throw Erorr queue is empty";
        }
    }
    void shift()
    {

        for(int i = 1; i <= top; i++ )
        {
            /// 1 2 3 4 5 top 4
            arr[i - 1] = arr[i];
        }
    }
    void print()
    {
        for(int i = 0; i < top; i++ )
        {
            cout << arr[i] << " ";
        }

    }
};


int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.dequeue();
    q.dequeue();



    q.print();
    return 0;
}
/// 1 2 3 4 5
/// 2 3 4 5 1
/// 3 4 4 1 6
/// the insert order
