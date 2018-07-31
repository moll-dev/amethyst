#include <assert.h>
#include <math.h>
#include <iostream>

namespace geometry {
    template <typename T> class Vector2 {
        public:
            Vector2() {
                x = y = 0;
            }

            Vector2(T x, T y) {
                this->x = x;
                this->y = y;
                assert(!HasNaNs());
            }

            bool HasNaNs() {
                return isnan(x) || isnan(y);
            }

            Vector2<T> operator+(const Vector2& v) {
                return Vector2(x+v.x, y+v.y);
            }

            Vector2<T>& operator+=(const Vector2& v) {
                x += v.x; y += v.y;
                return *this;
            }

            Vector2<T> operator-(const Vector2& v) {
                return Vector2(x-v.x, y-v.y);
            }

            Vector2<T>& operator-=(const Vector2& v) {
                x -= v.x; y -= v.y;
                return *this;
            }

            Vector2<T> operator*(T s) {
                return Vector2(s*x, s*y);
            }

            Vector2<T>& operator*=(T s) {
                x *= s; y *= s;
                return *this;
            }

            friend std::ostream& operator<<(std::ostream& s, const Vector2& v) {
                s << "Vector2<" << v.x << "," << v.y << ">";
                return s;
            }

            // Public Vector2 Data
            T x, y;
    };

    template <typename T> class Vector3 {
    public:
        // Public Vector3 Data
        T x, y, z;
    };

    typedef Vector2<float> Vector2f;
    typedef Vector2<int> Vector2i;
    typedef Vector3<float> Vector3f;
    typedef Vector3<int> Vector3i;
}