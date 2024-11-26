#include <iostream>
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

class ISMLine
{
    private:
    Point start;
    Point end;
    int myColor;
    public:

    ISMLine()
    {

    }
    ISMLine(int _x, int _y, int _x2,int _y2)
    {
     start.SetX(_x);
     start.SetY(_y);
     end.SetX(_x);
     end.SetY(_y);

    }

};
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
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
