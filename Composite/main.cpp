#include <iostream>

using namespace std;
class complex
{
private :
    int real;
    int img;
public:
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
        if(img > 1) cout << real << " + " << img << "i" << endl;
        else if(img == 1) cout << real << " + " << "i" << endl;
        else if(img == -1) cout << real << " - " << "i" << endl;
        else if(img < -1) cout << real << " - " << -(img) << "i" << endl;
        }
        /// if img > 0 and real 0 print img
        else if(real == 0)
        {
        if(img > 1) cout << img << "i" << endl;
        else if(img == 1) cout << "i" << endl;
        else if(img == -1) cout << " - " << "i" << endl;
        else if(img < -1) cout << img << "i" << endl;
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
};

complex AddComplex(const complex &left,const complex &right)
{
        complex sum;
        sum.SetReal(left.GetReal() + right.GetReal());
        sum.SetImg(left.GetImg() + right.GetImg());
        return sum;

}

int main()
{
complex c1,c2,c3,c4;

c1.SetReal(2);
c2.SetReal(-5);

c1.SetImg(-4);
c2.SetImg(4);

c3 = c1.Add(c2);
cout << "Sum using Add fun inside class : ";
c3.Print();

cout << "\n" <<"Sum using Add Fun OutSideClass class : ";
c4 = AddComplex(c1,c2);
c4.Print();

return 0;
}


/// class complex has valus
///setters

///getters
///print
///print
///Addmember
