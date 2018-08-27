#include <iostream>
#include <geometry.h>

using namespace std;
using namespace geometry;

int main(){
    Point2f p2_a = Point2f(1.0f, -1.0f);
    Point2f p2_b = Point2f(-1.0f, 1.0f);

    Point3f p3_a = Point3f(1.0f, -1.0f, 1.0f);
    Point3f p3_b = Point3f(-1.0f, 1.0f, 1.0f);

    cout << "Point Min / Max" << endl;

    cout << "Min: " << Min(p2_a, p2_b) << endl;
    cout << "Min: " << Min(p3_a, p3_b) << endl;
    cout << "Max: " << Max(p2_a, p2_b) << endl;
    cout << "Max: " << Max(p3_a, p3_b) << endl;

    cout << "Floor: " << Floor(p2_a) << endl;
    cout << "Floor: " << Floor(p3_a) << endl;

    Normal3f n1 = Normal3f(1.0f, 1.0f, 1.0f);
    cout << n1 << endl;

    Normal3f n2 = Normal3f(Vector3f(1.0f, 1.0f, 1.0f));
    cout << n2 << endl;
    cout << "Thanks tom!" << endl;
    return 0;
}