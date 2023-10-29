#include "../header/Point.h"
#include "../header/BoundingBox.h"
#include <fstream>
#include <sstream>

BoundingBox::BoundingBox():pMax(0,0,0), pMin(0,0,0){}

BoundingBox ::~BoundingBox(){}

void BoundingBox::getData(){
    std::ifstream dataFile;
    dataFile.open("../stlFile/Solid_Model.stl");//Getting data from stl file

    std::string line;

    std::ofstream dataF;
    dataF.open("../txt/Output.txt");//Plotting points in 'Output.txt' file

    double xMax, yMax, zMax;
    double xMin, yMin, zMin;
    int count = 0;
    int mainCount = 0;

    while(std::getline(dataFile, line))
    {
        if(line.find("vertex") != std::string::npos){
            std::istringstream iss(line);
            std::string token;
            double x, y, z;
            iss>>token>>x>>y>>z;

            Point point(x,y,z);
            points.push_back(point);

            double x1, y1, z1;

            if(count == 0){
                //Assigning initial value for getting min and max value
                x1=x;
                y1=y;
                z1=z;
            }

            dataF<<x<<" "<<y<<" "<<z<<endl;
            count++;

            if(count == 3){
                //Printing 1st line again after every 3 lines for printing figure on gnuplot
                count = 0;
                dataF<<x1<<" "<<y1<<" "<<z1<<endl;
            }
            
             //if loops for getting pMax and pMin of x, y and z co-ordinates
            if(mainCount == 0){
                mainCount = 1;
                xMax = xMin = x;
                yMax = yMin = y;
                zMax = zMin = z;
            }

            if(x > xMax){
                xMax = x;
            }

            if(x < xMin){
                xMin = x;
            }

            if(y > yMax){
                yMax = y;
            }

            if(y < yMin){
                yMin = y;
            }

            if(z > zMax){
                zMax = z;
            }

            if(z < zMin){
                zMin = z;
            }
        }
    }

    getMaxData(xMax, yMax, zMax);
    getMinData(xMin, yMin, zMin);

    dataFile.close();//Closing ifstream object of reading lines from '.stl' file
    dataF.close();//Closing ofstream object of writing points in '.txt' file
}

void BoundingBox::getMaxData(double x, double y, double z){
    pMax = Point(x, y, z);
}

void BoundingBox::getMinData(double x, double y, double z){
    pMin = Point(x, y, z);
}

void BoundingBox:: generateShape(){
    //Getting 8 points of the BoundingBox
    mData.push_back(Point(pMin.getx(),pMin.gety(),pMin.getz()));
    mData.push_back(Point(pMax.getx(),pMin.gety(),pMin.getz()));
    mData.push_back(Point(pMax.getx(),pMax.gety(),pMin.getz()));
    mData.push_back(Point(pMin.getx(),pMax.gety(),pMin.getz()));

    mData.push_back(Point(pMin.getx(),pMin.gety(),pMax.getz()));
    mData.push_back(Point(pMax.getx(),pMin.gety(),pMax.getz()));
    mData.push_back(Point(pMax.getx(),pMax.gety(),pMax.getz()));
    mData.push_back(Point(pMin.getx(),pMax.gety(),pMax.getz()));
}

void BoundingBox:: saveData(){
    std::ofstream dataFile;
    dataFile.open("../txt/Bounding_Box.txt");//

    //Steps for drawing BoundingBox on gnuplot-> Total 16 points
    dataFile << mData[0].getx() <<" "<< mData[0].gety() <<" "<<mData[0].getz()<<std::endl;
    dataFile << mData[1].getx() <<" "<< mData[1].gety() <<" "<<mData[1].getz()<<std::endl;
    dataFile << mData[2].getx() <<" "<< mData[2].gety() <<" "<<mData[2].getz()<<std::endl;
    dataFile << mData[3].getx() <<" "<< mData[3].gety() <<" "<<mData[3].getz()<<std::endl;
    dataFile << mData[0].getx() <<" "<< mData[0].gety() <<" "<<mData[0].getz()<<std::endl;

    dataFile << mData[4].getx() <<" "<< mData[4].gety() <<" "<<mData[4].getz()<<std::endl;
    dataFile << mData[5].getx() <<" "<< mData[5].gety() <<" "<<mData[5].getz()<<std::endl;
    dataFile << mData[6].getx() <<" "<< mData[6].gety() <<" "<<mData[6].getz()<<std::endl;
    dataFile << mData[7].getx() <<" "<< mData[7].gety() <<" "<<mData[7].getz()<<std::endl;
    dataFile << mData[4].getx() <<" "<< mData[4].gety() <<" "<<mData[4].getz()<<std::endl;

    dataFile << mData[7].getx() <<" "<< mData[7].gety() <<" "<<mData[7].getz()<<std::endl;
    dataFile << mData[3].getx() <<" "<< mData[3].gety() <<" "<<mData[3].getz()<<std::endl;
    dataFile << mData[2].getx() <<" "<< mData[2].gety() <<" "<<mData[2].getz()<<std::endl;
    dataFile << mData[6].getx() <<" "<< mData[6].gety() <<" "<<mData[6].getz()<<std::endl;
    dataFile << mData[5].getx() <<" "<< mData[5].gety() <<" "<<mData[5].getz()<<std::endl;
    dataFile << mData[1].getx() <<" "<< mData[1].gety() <<" "<<mData[1].getz()<<std::endl;

    dataFile.close();
}
