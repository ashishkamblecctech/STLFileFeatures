#include<iostream>
#include "../header/Point.h"
#include "../header/BoundingBox.h"

int main()  
{
    BoundingBox cu;
    cu.getData(); //Reads data from '.stl' file and perform related operations
    cu.generateShape(); //Storing points of Bounding-Box in mData
    cu.saveData(); //Writing data into '.txt' file for gnuplot application
}

