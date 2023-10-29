#pragma once
class Point{
    public:
    Point(double x, double y, double z);
    Point();
    ~Point();
    
    double getx();
    double gety();
    double getz();

    private:
    double px, py, pz;
};