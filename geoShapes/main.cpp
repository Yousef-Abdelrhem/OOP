#include <iostream>
#include "graphics.h"

class Geoshape
{
protected:
    double dim1;
    double dim2;
public:
    void SetDim1(double _dim1){dim1 =_dim1;}
    double GetDim1(){return dim2;}
    void SetDim2(double _dim2){dim2 =_dim2;}
    double GetDim2(){return dim2;}

    Geoshape()
    {
        dim1 = dim2 = 0;
    }
    Geopshape(double _dim)
    {
        dim1=dim2=_dim;
    }
    Geoshape(double _dim1, double _dim2)
    {
        dim1 = _dim1;
        dim2 = _dim2;
    }
};


class Point{
private:
    int x;
    int y;

public:
    Point()
    {
            x = y = 0;
    }
    Point(int _x, int _y)
    {
        x =_x;
        y = _y;
    }
    void SetX(int _x){ x =_x;}
    int GetX(){return x;}
    void SetY(int _y){ y =_y;}
    int GetY(){return y;}

    Point(const Point &old)
    {
        x = old.x;
        y = old.y;
    }
    ~Point()
    {
    }
};


class Rect: public Geoshape
{
    public:
    Rect()
    {
    }

    Rect(double _dim1,double _dim2)
    :Geoshape(_dim1,_dim2)
    {

    }
    ~Rect()
    {
    }
    double CArea()
    {
        return dim1 * dim2;
    }
};


class Square: public Geoshape
{
public:
    Square()
    {
    }
    Square(double _dim)
    :Geoshape(_dim,_dim)
    {
    }
    double CArea()
    {
        return dim1 * dim2;
    }

    void SetDim1(double _dim1)
    {dim1=dim2=_dim1;}
    void SetDim2(double _dim2)
    {dim2=dim1=_dim2;}

};

class Tri : public Geoshape
{
protected:

public:
    Tri()
    {}
    Tri(int _height,int  _base)
    :Geoshape(_height, _base)
    {
    }
    double CArea()
    {
        return 0.5 * dim1 * dim2;
    }
};

class Circle : public Geoshape
{
protected:

public:
    Circle()
    {}
    Circle(int _radius)
    :Geoshape(_radius, _radius)
    {
    }
    double CArea()
    {
        return 3.14 * dim1 * dim2;
    }
};



using namespace std;


int main() {
    initgraph();
    Rect r(2,4);
    cout << "The Area of Rectangle is : "<< r.CArea();
    cout << endl << "^---------------------------------^"<< endl;
    Square sq(2);
    cout << "The Area of Square is : "<< sq.CArea();
    cout << endl << "^---------------------------------^"<< endl;
    Tri T(4 , 9);
    cout << "The Area of Triangle is : "<< T.CArea();

    cout << endl << "^---------------------------------^"<< endl;
    Circle c(4);
    cout << "The Area of Circle is : "<< c.CArea();
    cout << endl << "^---------------------------------^"<< endl;

    return 0;
}

///////////////////////////////////////////////////////
////1- Geoshape    Rect,Sq,tri,cir :geoshape
