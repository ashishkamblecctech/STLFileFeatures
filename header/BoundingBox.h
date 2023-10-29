#include "Point.h"
#include <iostream>
#include<vector>
using namespace std;

class BoundingBox
{
    public:
    BoundingBox();
    ~BoundingBox();

    void getData();
    void getMaxData(double x, double y, double z);
    void getMinData(double x, double y, double z);  
    void generateShape();
    void saveData(); 

    private:
    Point pMax; 
    Point pMin;
    vector <Point> points;
    vector <Point> mData;
};