#include <iostream>

using namespace std;

class Stack
{
    private:
    static int  counter;
    int tops;
    int *arr;
    int _size;
    public:
    void push(int val)
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
        counter++;
       tops = 0;
       _size = 5;
       arr = new int[_size];
    }
    Stack(int _size)
    {
        counter++;
       tops = 0;
       _size =_size;
       arr = new int[_size];
    }
    void print()
    {
        for(int i = 0; i < tops;i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
     ~Stack()
    {
        delete[] arr;
    }
    static int GetCounter()
    {
        return counter;
    }
    friend void ViewStack(Stack s);
};
void ViewStack(Stack s)
{
    for(int i = 0; i < s.tops;i++)
        {
            cout << s.arr[i] << " ";
        }
        cout << endl;

}


int Stack::counter = 0;

int main()
{
    Stack s(4),s2;
    cout << "Here is Stack one: " ;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    ViewStack(s);


    cout << "Here is Stack two: " ;
    s2.push(5);
    s2.push(6);
    s2.push(7);
    s2.push(8);

    s.pop();
    ViewStack(s2);
    s.peak();
    s2.peak();

    cout << "Here is stack counter: " << Stack::GetCounter();
    return 0;
}
