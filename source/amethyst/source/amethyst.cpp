#include <iostream>
#include <geometry.h>

using namespace std;
using geometry::Vector2;

int main(){
    cout << "Vector Addition" << endl;

    Vector2<float> v1 = Vector2<float>(6.55f, 9.0f);
    Vector2<float> v2 = Vector2<float>(4.0f, 1.0f);
    Vector2<float> v3 = Vector2<float>(2.0f, 2.0f);

    v1 += Vector2<float>(4.0f, 4.0f);

    cout << "V1:" << v1 << endl;
    cout << "V2:" << v2 << endl;

    //cout << v1 + v2 << endl;
    cout << Vector2<int>(20, 40) / 10 << endl;
    cout << 10.0f * Vector2<float>(5.0f, 6.0f) << endl;

    return 0;
}