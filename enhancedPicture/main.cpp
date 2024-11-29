#include <iostream>
#include "graphics.h"

class Shape
{
protected:
    int mycolor;
public:
    void SetColor(int x){ mycolor = x;}
    int GetColor(){return mycolor;}
    Shape()
    {
        mycolor = 0;
    }
    Shape(int _x)
    {
        mycolor = _x;
    }
    virtual void Draw()=0;
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
    ~Point(){}
};

class ISMLine: public Shape
{
    private:
    Point start;
    Point end;
    public:

    void SetStart(int _x, int _y)
    {
     start.SetX(_x);
     start.SetY(_y);
    }
    Point GetStart(){return start;}
    void SetEnd(int _x, int _y)
    {
     end.SetX(_x);
     end.SetY(_y);
    }
    Point GetEnd(){return end;}

    ISMLine()
    {
     start.SetX(0);
     start.SetY(0);
     end.SetX(0);
     end.SetY(0);
     SetColor(5);
    }

    ISMLine(int _x, int _y, int _x2,int _y2,int color)
    :start(_x,_y),end(_x2,_y2),Shape(color)
    {
    }
    ISMLine(const ISMLine &old)
    {
     start = old.start;
     end = old.end;
    }
    ~ISMLine()
    {
    }
    void Draw() override
    {
        line(start.GetX(),start.GetY(),end.GetX(),end.GetY());
    }
};

class ISMRect: public Shape
{
    Point ul;
    Point lr;
    public:
    void SetUL(Point _ul){ul=_ul;}
    Point GetUL(){return ul;}
    void SetLR(Point _lr){lr=_lr;}
    Point GetLR(){return lr;}
    void SetMyColor(int _color){ SetColor(_color);}
    ISMRect()
    {
    }
    ISMRect(int x1,int y1,int x2,int y2,int _color)
    :ul(x1,y1),lr(x2,y2),Shape(_color)
    {
    }
    ~ISMRect()
    {
    }
    void Draw() override
    {
        setcolor(mycolor);
        rectangle(ul.GetX(),ul.GetY(),lr.GetX(),lr.GetY());
    }
};

class ISMTri :public Shape
{
private:
    Point p1;
    Point p2;
    Point p3;
public:
   ISMTri(){}

   ISMTri(int x1,int y1,int x2,int y2,int x3,int y3,int _color)
   :p1(x1,y1), p2(x2,y2), p3(x3,y3),Shape(_color)
   {
   }
   ISMTri(const ISMTri& old){}
   ~ISMTri(){}
   void Draw() override
   {
        setcolor(mycolor);
        line(p1.GetX(),p1.GetY(),p2.GetX(),p2.GetY());
        line(p1.GetX(),p1.GetY(),p3.GetX(),p3.GetY());
        line(p3.GetX(),p3.GetY(),p2.GetX(),p2.GetY());
    }

};

class ISMCir: public Shape
{
private:
    Point center;
    int radius;
public:
     void SetCenter(Point _center){center=_center;}
    Point GetCenter(){return center;}
    void SetRadius(int _radius){radius=_radius;}
    int GetRadius(){return radius;}
    void SetMyColor(int _color){mycolor=_color;}

    ISMCir(){}
    ISMCir(int x,int y,int _radius,int _color)
    :center(x,y),Shape(_color)
    {
        radius = _radius;
        mycolor = _color;
    }
    void Draw() override
    {
        setcolor(mycolor);
        circle(center.GetX(),center.GetY(),radius);
    }
};

class Picture
{
private:
    Shape ** sptr;
    int Size;
public:
    Picture()
    {
        sptr = NULL;
        Size = 0;
    }
    void SetPicture(Shape ** _Shapes, int _Size)
    {
        sptr = _Shapes;
        Size = _Size;
    }

void Excute()
{
    for(int i = 0; i < Size; i++ )
    {
        sptr[i]->Draw();
    }
}

};
using namespace std;

int main() {
    initgraph();

    ISMLine larr[2] = {ISMLine(200, 350, 300, 370, 8),ISMLine(100, 200, 100,270, 8)};
    ISMCir head(250, 150, 95, 8);
    ISMRect rarr[2]={ISMRect(240, 198, 260, 350, 8), ISMRect(200, 350, 300, 370, 8)};
    ISMTri button(200, 150, 250, 150, 225, 100, 5);

    Shape *shapes[6] = {larr,&larr[1], &head,&rarr[0],&rarr[1],&button};

    Picture p;

    p.SetPicture(shapes , 6);

    p.Excute();

    return 0;
}

///////////////////////////////////////////////////////
