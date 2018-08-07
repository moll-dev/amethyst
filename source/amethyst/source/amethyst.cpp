#include <iostream>
#include <geometry.h>

using namespace std;
using namespace geometry;

int main(){
    cout << "Vector Addition" << endl << endl;

    Vector2f v1 = Vector2f(6.55f, 9.0f);
    Vector2f v2 = Vector2f(4.0f, 1.0f);
    Vector2f v3 = Vector2f(2.0f, 2.0f);

    v1 += Vector2f(4.0f, 4.0f);

    cout << "V1:" << v1 << endl;
    cout << "V2:" << v2 << endl;

    cout << Vector2<int>(20, 40) / 10 << endl;
    cout << Vector2<float>(5.0f, 6.0f) * 10.0f << endl;
    cout << 10.0f * Vector2<float>(5.0f, 6.0f) << endl;

    cout << "DOT PRODUCTS " << Dot(Vector2f(5.0, 5.0), Vector2f(1.0f, 1.0f)) << endl;
    cout << "DOT PRODUCTS " << Dot(Vector2f(1.0, 0.0).Normal(), Vector2f(0.0f, 1.0f).Normal()) << endl;

    cout << "Normal:  " << Normal(Vector3f(1.0f, 0.5f, 0.0f)) << endl;
    cout << "Normal2: " << Vector3f(1.0f, 0.5f, 0.0f).Normal() << endl;
    return 0;
}