#include <iostream>
#include <geometry.h>

using namespace std;

int main(){
    cout << "Hello, Tom" << endl;
    cout << "Vector 1" << endl;

    geometry::Vector2<float> v = geometry::Vector2<float>(6.0f, 9.0f);
    cout << v << endl;
    return 0;
}