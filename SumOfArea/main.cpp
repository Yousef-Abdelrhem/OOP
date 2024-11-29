#include <iostream>

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
    virtual double CArea()=0;


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
    double CArea() override
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
    double CArea() override
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
    double CArea() override
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
    double CArea() override
    {
        return 3.14 * dim1 * dim2;
    }
};


double SumAreas(Geoshape **arrParam , int _size)
{
    int sum = 0;
    for(int i = 0; i < _size; i++)
    {
       sum = arrParam[i]->CArea();
    }
    return sum;
}

using namespace std;


int main() {

    Rect r[2] = {Rect (2,4),Rect(6,2)};
    Square sq(2);
    Tri T(4 , 9);
    Circle c(4);

    Geoshape *arr[5] ={&r[0], &r[1], &sq, &T,&c};

    cout << "The Sum of Shapes: "<<SumAreas(arr, 5);
    return 0;
}

///////////////////////////////////////////////////////
////1- Geoshape    Rect,Sq,tri,cir :geoshape
