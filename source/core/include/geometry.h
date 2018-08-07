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

            float Length() const {
                return std::sqrt((x * x + y * y));
            }

            Vector2<T> Normal() const {
                return Vector2<T>(x / Length(), y / Length());
            }

            Vector2<T> operator+(const Vector2& v) const {
                return Vector2(x+v.x, y+v.y);
            }

            Vector2<T>& operator+=(const Vector2& v) {
                x += v.x; y += v.y;
                return *this;
            }

            Vector2<T> operator-(const Vector2& v) const {
                return Vector2(x-v.x, y-v.y);
            }

            Vector2<T> operator-() const {
                return Vector2<T>(-x, -y);
            }

            Vector2<T>& operator-=(const Vector2& v) {
                x -= v.x; y -= v.y;
                return *this;
            }

            Vector2<T> operator*(T s) const {
                return Vector2<T>(s*x, s*y);
            }

            Vector2<T>& operator*=(T s) {
                x *= s; y *= s;
                return *this;
            }

            Vector2<T> operator/(T f) const {
                assert(f != 0);
                float inv = (float)1 / f;
                return Vector2(x * inv, y * inv);
            }

            Vector2<T>& operator/=(T f) {
                assert(f != 0);
                float inv = (float)1 / f;
                x *= inv; y *= inv;
                return *this;
            }

            friend std::ostream& operator<<(std::ostream& s, const Vector2& v) {
                s << "Vector2<" << v.x << "," << v.y << ">";
                return s;
            }

            // Public Vector2 Data
            T x, y;
    };

    typedef Vector2<float> Vector2f;
    typedef Vector2<int> Vector2i;


    template <typename T> class Vector3 {
    public:
            Vector3() {
                x = y = z = 0;
            }

            Vector3(T x, T y, T z) {
                this->x = x;
                this->y = y;
                this->z = z;
                assert(!HasNaNs());
            }

            bool HasNaNs() {
                return isnan(x) || isnan(y) || isnan(z);
            }

            float Length() const {
                return std::sqrt(x * x + y * y + z * z);
            }

            Vector3<T> Normal() const {
                return Vector3<T>(x / Length(), y / Length(), z / Length());
            }

            Vector3<T> operator+(const Vector3& v) const {
                return Vector3(x + v.x, y + v.y, z + v.z);
            }

            Vector3<T>& operator+=(const Vector3& v) {
                x += v.x; y += v.y; z += v.z;
                return *this;
            }

            Vector3<T> operator-(const Vector3& v) const {
                return Vector3(x - v.x, y - v.y, z - v.z);
            }

            Vector3<T> operator-() const {
                return Vector3<T>(-x, -y, -z);
            }

            Vector3<T>& operator-=(const Vector3& v) {
                x -= v.x; y -= v.y; z -= v.z;
                return *this;
            }

            Vector3<T> operator*(T s) const {
                return Vector3<T>(s * x, s * y, s * z);
            }

            Vector3<T>& operator*=(T s) {
                x *= s; y *= s; z *= s;
                return *this;
            }

            Vector3<T> operator/(T f) const {
                assert(f != 0);
                float inv = (float)1 / f;
                return Vector3(x * inv, y * inv, z * inv);
            }

            Vector3<T>& operator/=(T f) {
                assert(f != 0);
                float inv = (float)1 / f;
                x *= inv; y *= inv; z *= inv;
                return *this;
            }

            friend std::ostream& operator<<(std::ostream& s, const Vector3& v) {
                s << "Vector3<" << v.x << "," << v.y << "," << v.z << ">";
                return s;
            }

            // Public Vector2 Data
            T x, y, z;
    };

    typedef Vector3<float> Vector3f;
    typedef Vector3<int> Vector3i;

    // Vector 2 In-Line
    template <typename T> inline Vector2<T>
    operator*(T s, const Vector2<T> &v) {
        return v * s;
    }

    template <typename T> inline T
    Dot(const Vector2<T> &v1, const Vector2<T> &v2) {
        return v1.x * v2.x + v1.y * v2.y;
    }

    template <typename T> inline Vector2<T>
    Normal(const Vector2<T> &v) {
        return Vector2<T>(v.x / v.Length(), v.y / v.Length());
    }

    // Vector 3 In-Line
    template <typename T> inline Vector3<T>
    operator*(T s, const Vector3<T> &v) {
        return v * s;
    }

    template <typename T> inline T
    Dot(const Vector3<T> &v1, const Vector3<T> &v2) {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v1.z;
    }   

    template <typename T> inline Vector3<T>
    Normal(const Vector3<T> &v) {
        return Vector3<T>(v.x / v.Length(), v.y  / v.Length(), v.z / v.Length());
    }
    
    // // Inlined functions
    // template <typename T>
    // inline Vector2<T> operator*(T s, const Vector2<T> &v) {
    //     return v * s;
    // }

}