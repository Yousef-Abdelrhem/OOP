#include <iostream>

using namespace std;

class Complex
{
    private:
    int real,img;
    public:
    void setReal(int _real){real=_real;}
    void setImg(int _img){img=_img;}
    int getReal() const {return real;}
    int getImg() const {return img;}
    Complex()
    {
        real=img=0;
    }
    Complex(int _r,int _i)
    {
        real=_r;
        img=_i;
    }

    ~Complex()
    {

    }

    void printComplex()
    {
        cout<<real<<"+"<<img<<"i";
    }

    Complex(const Complex &old)
    {
        real = old.real;
        img = old.img;
    }
    Complex operator+(const Complex &right)
    {
        Complex result(real + right.real,img+ right.img);

        return result;
    }
    Complex operator+=(const Complex &right)
    {
        real += right.real;
        img += right.img;
        return *this;
    }
     Complex operator++()
    {
        real = real+1;
        img = img+1;
        return *this;
    }
    Complex operator+(int num)
    {
        Complex result(real+ num ,img);
        return result;
    }
    int operator>(const Complex &right)
    {

        return real>right.real;
    }

    operator int()
    {
        return real;
    }

    Complex& operator=(const Complex& right)
    {
        real=right.real;
        img=right.img;
        return *this;
    }

};

Complex& operator+(int x,const Complex& right)
{
    Complex result;
    result.setReal(right.getReal()+x);
    result.setImg(right.getImg());
    return result;
}
int main()
{
    /// cpy ctor useless
    Complex c1(1,2);
    cout << "Here is copy constructor :";
    Complex c2(c1);
    ///   c1+c2
    Complex c3 = c1+c2;
    /// c1+=c2
    cout << endl <<"---------------------"<<endl;
    cout << "c1 + c2: ";
    c3.printComplex();
    cout << endl <<"---------------------"<<endl;
    cout << "c1 += c2 : ";
    c1 +=c2;
    c1.printComplex();
    /// ++c1
    cout << endl <<"---------------------"<<endl;
    cout << "++c1 :";
    ++c1;
    c1.printComplex();

    /// c1+10
    cout << endl <<"---------------------"<<endl;
    cout << "c1+10 :";
    c3 = c1+10;
    c3.printComplex();
    ///  c1>c2
    cout << endl <<"---------------------"<<endl;
    int x = c1>c2;
    cout << "c1>c2 :" << x;

    /// (int)c1
    cout << endl <<"---------------------"<<endl;
    cout << "cast int c1: " << (int)c1;
    ///   c1=c2
    cout << endl <<"---------------------"<<endl;
    c2=c1;
    cout << "c1 = c2 :"  ;
    c2.printComplex();
    /// 10+c1
    c1= 10+c3;
    cout << endl <<"---------------------"<<endl;
    c1= 10+c3;
    cout << "c1 = c2 :";
    c1.printComplex();

    return 0;
}



