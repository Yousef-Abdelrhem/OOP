#include <iostream>
#include <stdexcept>
using namespace std;

class Stack
{
private:
    int tops;
    int *arr;
    int _size;

public:
    // Default constructor
    Stack() : tops(0), _size(5)
    {
        arr = new int[_size];
    }

    // Parameterized constructor
    Stack(int size) : tops(0), _size(size)
    {
        arr = new int[_size];
    }

    // Copy constructor
    Stack(const Stack& old) : tops(old.tops), _size(old._size)
    {
        arr = new int[_size];
        for(int i = 0; i < tops; i++)
        {
            arr[i] = old.arr[i];
        }
    }

    // Assignment operator
    Stack& operator=(const Stack& right)
    {
        if (this != &right)
        {
            delete[] arr;
            tops = right.tops;
            _size = right._size;
            arr = new int[_size];
            for(int i = 0; i < tops; i++)
            {
                arr[i] = right.arr[i];
            }
        }
        return *this;
    }

    // Destructor
    ~Stack()
    {
        delete[] arr;
    }

    // Push method
    void push(int val)
    {
        if(!IsFull())
            arr[tops++] = val;
        else
            throw std::runtime_error("Stack is full");
    }

    // Pop method
    void pop()
    {
        if(tops > 0)
            tops--;
        else
            throw std::runtime_error("Stack is empty");
    }

    // Peak method
    int peak() const
    {
        if(tops > 0)
            return arr[tops-1];
        throw std::runtime_error("Stack is empty");
    }

    // Is Full method
    bool IsFull() const
    {
        return tops == _size;
    }

    // Print method
    void print() const
    {
        for(int i = tops - 1; i >= 0; i--)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    // Reverse method
    void Reverse()
    {
        Stack s(*this);
        tops = 0;
        while(s.tops > 0)
        {
            push(s.peak());
            s.pop();
        }
    }

    // Addition operator
    Stack operator+(const Stack &right) const
    {
        Stack result(this->tops + right.tops);

        // Copy elements from the first stack
        for (int i = 0; i < this->tops; i++) {
            result.push(this->arr[i]);
        }

        // Copy elements from the second stack
        for (int i = 0; i < right.tops; i++) {
            result.push(right.arr[i]);
        }

        return result;
    }

    // Equality operator
    bool operator==(const Stack& right) const
    {
        if(tops != right.tops)
            return false;

        for(int i = 0; i < tops; i++)
        {
            if(arr[i] != right.arr[i])
                return false;
        }
        return true;
    }
};



int main()
{
    Stack s(4),s4;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    /// copy contr
    cout << "Here a Copy constructor from Stack one: " ;
    Stack s2(s);
    s2.print();
    /// opreator =
    cout << "operator = on s3: " ;
    Stack s3;
    s3=s;
    s3.print();
    /// Stack reverseStack()
    cout << "Reverse Stack: " ;
    s.Reverse();
    s.print();

    cout << "Can be solved using freq arry or Sets " << "endl" << "Stack == Stack 2: ";
   // bool flag =(s==s4);
    //cout << (flag) << endl;
    cout << (s==s2) << endl;

    cout << "Stack + operator : ";
    s4= s+s2;
    s4.print();


    return 0;
}





