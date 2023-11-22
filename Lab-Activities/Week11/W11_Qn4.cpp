#include<iostream>
#include<cmath>
using namespace std;

class Rectangle
{
    protected:
        double length,width;

    public:
        Rectangle(double l=1.0, double  w=1.0)
        {
            length=l;
            width=w;
        }
        double area()
        {
            return length*width;
        }
};

class Box : public Rectangle
{
    protected:
        double height;
    
    public: 
        Box(double l=1.0, double w=1.0, double h=1.0): Rectangle(1,w), height(h){}
        
        double volume()
        {
            return height*Rectangle::area();
        }
        
        double area()
        {
            return 2*((length*width)+(length*height)+(width*height));
        }
};

int main()
{
    Rectangle r1,r2(3,4);
    Box b1, b2(3,4,5);

    cout<<"The area of rectangle 1 is "<<r1.area()<<endl;
    cout<<"The area of rectangle 2 is "<<r2.area()<<endl;

    cout<<"The volume of Box 1 is "<<b1.volume()<<endl;
    cout<<"The volume of Box 2 is "<<b2.volume()<<endl;
    
    cout<<"The area of Box 1 is "<<b1.area()<<endl;
    cout<<"The area of Box 2 is "<<b2.volume()<<endl;
}