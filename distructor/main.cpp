#include <iostream>

int constructors = 0;
int distructors = 0;

using namespace std;
class complex
{

private :
    int real;
    int img;
public:
    complex()
    {
        constructors++;
        cout<< "constructor "<< constructors <<" \n";
    }
    complex(int _img)
    {
        constructors++;

        cout<< "constructor "<< constructors <<" \n";
    }
    complex(int real, int img)
    {
        constructors++;

        cout<< "constructor "<< constructors <<" \n";
    }
     complex(bool flag)
    {
        constructors++;

    }
    void SetReal(int _real)
    {
        real = _real;
    }

    int GetReal() const
    {
        return real;
    }

    void SetImg(int _img)
    {
        img = _img;
    }

    int GetImg() const
    {
        return img;
    }

    void Print()
    {
        /// real is not 0 and img not
        if(real != 0 && img != 0)
        {
            if(img > 1)
                cout << real << " + " << img << "i" << endl;
            else if(img == 1)
                cout << real << " + " << "i" << endl;
            else if(img == -1)
                cout << real << " - " << "i" << endl;
            else if(img < -1)
                cout << real << " - " << -(img) << "i" << endl;
        }
        /// if img > 0 and real 0 print img
        else if(real == 0)
        {
            if(img > 1)
                cout << img << "i" << endl;
            else if(img == 1)
                cout << "i" << endl;
            else if(img == -1)
                cout << " - " << "i" << endl;
            else if(img < -1)
                cout << img << "i" << endl;
        }
        /// real num and img 0
        else if(img == 0)
        {
            cout << real << endl;
        }

    }
    complex Add(const complex &right)
    {
        complex sum;
        sum.real= real + right.real;
        sum.img = img + right.img;
        return sum;

    }
    ~complex()
    {
        distructors++;
    }
};

complex AddComplex(complex left,complex right)
{
    complex sum(false);
    sum.SetReal(left.GetReal() + right.GetReal());
    sum.SetImg(left.GetImg() + right.GetImg());
    return sum;

}

int main()
{

    complex c1,c2(1),c3(1,2);
    int real,img;
    cout << "Enter two nums : " ;
    cin >> real >> img;
    c1.SetReal(real);
    c2.SetReal(real);

    c1.SetImg(img);
    c2.SetImg(img);

    c3 = c1.Add(c2);

    cout << "Sum using Add fun inside class : ";
    c3.Print();

    cout << "\n" <<"Sum using Add Fun OutSideClass class : ";
    c3 = AddComplex(c1,c2);
    c3.Print();

    cout << "\n" << "count " <<constructors <<" of constructors " << "against destructors " << distructors;
    return 0;
}
