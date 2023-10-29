#include "../header/Point.h"

double Point::getx(){
    return px;
}

double Point::gety(){
    return py;
}

double Point::getz(){
    return pz;
}

 Point::Point(double x, double y, double z){
    px = x;
    py = y;
    pz = z;
 }

Point::Point(){}

Point::~Point(){}
