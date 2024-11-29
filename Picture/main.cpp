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

class ISMLine: Shape
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
    void DrawLine()
    {
        line(start.GetX(),start.GetY(),end.GetX(),end.GetY());
    }
};

class ISMRect: Shape
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
    void DrawRect()
    {
        setcolor(mycolor);
        rectangle(ul.GetX(),ul.GetY(),lr.GetX(),lr.GetY());
    }
};

class ISMTri :Shape
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
   void DrawTri()
   {
        setcolor(mycolor);
        line(p1.GetX(),p1.GetY(),p2.GetX(),p2.GetY());
        line(p1.GetX(),p1.GetY(),p3.GetX(),p3.GetY());
        line(p3.GetX(),p3.GetY(),p2.GetX(),p2.GetY());
    }

};

class ISMCir: Shape
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
    void DrawCircle()
    {
        setcolor(mycolor);
        circle(center.GetX(),center.GetY(),radius);
    }
};

class Picture
{
protected:
    ISMLine * lptr;
    ISMRect * rptr;
    ISMCir * cptr;
    ISMTri * tptr;
    int lsize;
    int rsize;
    int csize;
    int tsize;
public:
    void SetLines(ISMLine * _lptr, int Size)
    {
        lptr = _lptr;
        lsize = Size;
    }
    void SetRect(ISMRect * _rptr, int Size)
    {
        rptr = _rptr;
        rsize = Size;
    }
    void SetCircle(ISMCir * _cptr, int Size)
    {
        cptr = _cptr;
        csize = Size;
    }
    void SetTri(ISMTri * _tptr, int Size)
    {
        tptr = _tptr;
        tsize = Size;
    }

    Picture()
    {
        lsize=rsize=csize=tsize=0;
    }
void Excute()
{
        for(int i = 0; i < lsize; i++)
            lptr[i].DrawLine();
         for(int i = 0; i < csize; i++)
            cptr[i].DrawCircle();
         for(int i = 0; i < rsize; i++)
            rptr[i].DrawRect();
         for(int i = 0; i < tsize; i++)
            tptr[i].DrawTri();
}

};
using namespace std;

int main() {
    initgraph();

    ISMLine larr[2] = {ISMLine(200, 350, 300, 370, 8),ISMLine(100, 200, 100,270, 8)};
    ISMCir head(250, 150, 95, 8);
    ISMRect rarr[2]={ISMRect(240, 198, 260, 350, 8), ISMRect(200, 350, 300, 370, 8)};

    Picture p;
    p.SetLines(larr,2);
    p.SetRect(rarr,2);
    p.SetCircle(&head,1);

    p.Excute();

    return 0;
}

///////////////////////////////////////////////////////
////
///Composition
///class Point
///class ISMLine
///class ISMRect
///class ISMTri
///class ISMCir
