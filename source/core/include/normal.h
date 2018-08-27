#ifndef NORMAL_H
#define NORMAL_H

#include <assert.h>
#include <math.h>
#include <iostream>
#include "geometry.h"

namespace geometry {
    template <typename T> 
    class Normal3 {
        public:
            Normal3() {
                x = y = z = 0;
            }

            Normal3(T x, T y, T z) {
                this->x = x;
                this->y = y;
                this->z = z;
                assert(!HasNaNs());
            }

            explicit Normal3<T>(const Vector3<T> &v): x(v.x), y(v.y), z(v.z) {
                assert(!v.HasNaNs());    
            }

            bool HasNaNs() const {
                return isnan(x) || isnan(y) || isnan(z);
            }

            friend std::ostream& operator<<(std::ostream& s, const Normal3 &n) {
                s << "Normal3<" << n.x << "," << n.y << "," << n.z << ">";
                return s;
            }

            T x, y, z;

           
    };

    typedef Normal3<float> Normal3f;
    typedef Normal3<int> Normal3i;

    template <typename T> inline Normal3<T>
    Faceforward(const Normal3<T> &n, const Vector3<T> &v) {
        return (Dot(n,v) < 0.f) ? -n : n;
    }

    template <typename T> inline T
    Dot(const Normal3<T> &n1, const Vector3<T> &v2) {
        return n1.x * v2.x + n1.y * v2.y + n1.z * v2.z;
    } 

    template <typename T> inline T
    Dot(const Vector3<T> &v1, const Normal3<T> &n2) {
        return v1.x * n2.x + v1.y * n2.y + v1.z * n2.z;
    } 
}

#endif // NORMAL_H