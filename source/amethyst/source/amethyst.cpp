#include <iostream>
#include <geometry.h>
#include <point.h>
#include <normal.h>
#include <vector.h>
#include <ray.h>

using namespace std;
using namespace geometry;

int main(){
    cout << "Hello Tom!" << endl;

    Ray r1 = Ray(Point3f(0.0f, 0.0f, 0.0f), Vector3f(1, 2, 3));
    Ray r2 = Ray();

    Ray r3 = RayDifferential(r1);

    cout << r1 << endl;
    cout << r2 << endl;
    cout << r1(1.0) << endl;
    cout << r3 << endl;
    RayDifferential r4 = r3;
    r4.ScaleDifferentials(2.0f);
    cout << r4 << endl;

    return 0;
}