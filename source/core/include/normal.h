#ifndef NORMAL_H
#define NORMAL_H

#include <assert.h>
#include <math.h>
#include <iostream>
#include "geometry.h"

namespace geometry {
    template <typename T> class Normal3 {
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
}

#endif // NORMAL_H