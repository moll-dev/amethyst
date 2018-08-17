#include <iostream>
#include <geometry.h>
#include <point.h>

using namespace std;

int main(){
    cout << "Vector Addition" << endl << endl;
    geometry::Point2f pt1 = geometry::Point2f(1.0f, 1.0f);
    geometry::Point3f pt2 = geometry::Point3f(3.0f, 2.0f, 2.0f);

    cout << pt1 << endl;
    cout << pt2 << endl;
    return 0;
}