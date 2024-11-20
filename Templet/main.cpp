#include <iostream>

using namespace std;
template <class T>

class Stack
{
    private:
    int tops;
    T *arr;
    int _size;
    public:
    void push(T val)
    {
        if(!IsFull())
            arr[tops++] = val;
         else
                cout << "Can't push Throw Error" << endl;
    }
    void pop()
    {
        if(tops != 0)
        {
            arr[tops--]= 0;
        }
    }
    void peak()
    {
         if(tops != 0)
            cout << "The Peak Of the Stack is "<< arr[tops-1]<< endl;
    }
    int IsFull()
    {
        if(tops == _size)
        {
            return 1;
        }
        else
            return 0;
    }

    Stack()
    {
       tops = 0;
       _size = 5;
       arr = new int[_size];
    }
    Stack(int _size)
    {
       tops = 0;
       _size =_size;
       arr = new T[_size];
    }
    void print()
    {
        for(int i = 0; i < tops;i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Stack<int> s(4);

    cout << "the stack is : ";
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    s.print();
    cout << "Trying Pop operation: ";
    s.pop();
    s.print();

    s.peak();

    return 0;
}
