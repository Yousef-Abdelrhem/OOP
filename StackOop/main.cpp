#include <iostream>

using namespace std;

class Stack
{
    private:
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
            arr[--tops]= 0;
        }
    }
    int peak()
    {
         if(tops != 0)
             return arr[tops-1];
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
       arr = new int[_size];
    }
    void print()
    {
        for(int i = tops - 1; i >= 0 ;i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
     ~Stack()
    {
        delete[] arr;
    }

    Stack(const Stack& old)
    {
        this->tops = old.tops;
        _size = old._size;
        arr = new int[_size];
        for(int i = 0; i < tops; i++)
        {
            arr[i] = old.arr[i];
        }
    }

    Stack& operator=(const Stack& right)
    {
        delete [] arr;
        tops = right.tops;
        _size = right._size;
        arr = new int[_size];
        for(int i = 0; i < tops; i++)
        {
            arr[i] = right.arr[i];
        }
      return *this;
    }



    void Reverse()
    {
        Stack s;
        s=*this;

        for(int i = 0; i < tops; i++)
        {
            arr[i] = s.peak();
            s.pop();
        }
    }

    bool operator==(const Stack& right)
    {
     if((_size != right._size) || (tops != right.tops))
        return false;

     int Max = -1;

     for(int i = 0; i < tops; i++)
        Max= max(Max,arr[i]);

     int freq[Max + 1]={0};

     for(int i = 0; i < tops; i++)
     freq[arr[i]]++;

     for(int i = 0; i < tops; i++)
     {
       if(freq[right.arr[i]] == 0)
       return false;
       else
           freq[right.arr[i]]--;
     }
     return true;
    }

   Stack operator+(const Stack &right) const
    {
        Stack result(this->tops + right.tops);

        for (int i = 0; i < this->tops; i++) {
            result.push(this->arr[i]);
        }

        for (int i = 0; i < right.tops; i++) {
            result.push(right.arr[i]);
        }

        return result;
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

    cout << (s==s2) << endl;

    cout << "Stack + operator : ";
    s4= s+s2;
    s4.print();


    return 0;
}

//2- Stack
    //cpy ctor  MUST
    //= operator MUST
    //Stack reverseStack()
    //==
    //+
