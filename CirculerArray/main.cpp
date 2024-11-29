#include <iostream>

using namespace std;

class CirularQueue
{
private :
    int Size;
    int front;
    int rear;
    int *arr;
public:
    CirularQueue()
    {
        front = rear = -1;
        Size = 5;
        arr = new int [Size];
    }
    void enqueue(int val)
    {
        rear = (rear  + 1) % Size;
        arr[rear] = val; // 0 1 2 3
    }
    void dequeue()
    {
        front = (front  + 1) % Size;
        arr[front] = 0;
    }
    bool isEmpty()
    {
        if(rear == -1)
            return 1;
        else
            return 0;
    }
    void print()
    {
        if(isEmpty())
        {

            cout << "The Queue is Empty" << endl;
        }
        else
        {
            for(int i = 0; i < Size; i++)
            cout << arr[i] <<" ";

        cout << endl << "Front: " << front << " Rear: " << rear;

        }
    }
};

int main()
{
    CirularQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(6);
    q.enqueue(7);


    q.print();
    return 0;
}


    /// dequeue ( front++)

///2- Draw abajora via picture class
////and make shape class includes color




