#ifndef POINT_H
#define POINT_H

#include <assert.h>
#include <math.h>
#include <iostream>
#include "geometry.h"

namespace geometry {
    template <typename T> class Point3 {
        public:
            Point3() {
                x = y = z = 0;
            }

            Point3(T x, T y, T z) {
                this->x = x;
                this->y = y;
                this->z = z;
                assert(!HasNaNs());
            }

            bool HasNaNs() {
                return isnan(x) || isnan(y) || isnan(z);
            }

            template <typename U> explicit Point3(const Point3<U> &p): x((T)p.x), y((T)p.y), z((T)p.z) {
                assert(!HasNaNs());
            }

            template <typename U> explicit operator Vector3<U>() const {
                return Vector3<U>(x, y, z);
            }

            Point3<T> operator+(const Vector3<T> &v) {
                return Point3<T>(x + v.x, y + v.y, z + v.z);
            }

            Point3<T> &operator+=(const Vector3<T> &v) {
                x += v.x; y += v.y; z += v.z;
                return *this;
            }

            Vector3<T> operator-(const Point3<T> &p) const {
                return Vector3<T>(x - p.x, y - p.y, z - p.z);
            }

            Point3<T> operator-(const Vector3<T> &v) const {
                return Point3<T>(x - v.x, y - v.y, z - v.z);
                return *this;
            }

            Point3<T> &operator-=(const Vector3<T> &v) {
                x - v.x; y - v.y; z - v.z;
                return *this;
            }
            
            Point3<T> operator*(T s) const {
                return Point3(s * x, s * y, s * z);
            }

            Point3<T> &operator*=(T s) {
                x *= s; y *= s; z *= s;
                return *this;
            }

            friend std::ostream& operator<<(std::ostream& s, const Point3 &p) {
                s << "Point3<" << p.x << "," << p.y << "," << p.z << ">";
                return s;
            }

            T x, y, z;
    };

    template <typename T> class Point2 {
        public:
            Point2() {
                x = y = 0;
            }

            Point2(T x, T y) {
                this->x = x;
                this->y = y;
                assert(!HasNaNs());
            }

            bool HasNaNs() {
                return isnan(x) || isnan(y);
            }

            explicit Point2(const Point3<T> &p) : x(p.x), y(p.y) {
                assert(!HasNaNs());
            }

            Point2<T> operator+(const Vector2<T> &v) {
                return Point2<T>(x + v.x, y + v.y);
            }

            Point2<T> &operator+=(const Vector2<T> &v) {
                x += v.x; y += v.y;
                return *this;
            }

            Vector2<T> operator-(const Point2<T> &p) const {
                return Vector2<T>(x - p.x, y - p.y);
            }

            Point2<T> operator-(const Vector2<T> &v) const {
                return Point2(x - v.x, y - v.y);
            }

            Point2<T> &operator-=(const Vector2<T> &v) {
                x - v.x; y - v.y;
                return *this;
            }

            Point2<T> operator*(T s) const {
                return Point2(s * x, s * y);
            }

            Point2<T> &operator*=(T s) {
                x *= s; y *= s;
                return *this;
            }

            friend std::ostream& operator<<(std::ostream& s, const Point2 &p) {
                s << "Point2<" << p.x << "," << p.y << ">";
                return s;
            }

            T x, y;
    };   

    typedef Point2<float> Point2f;
    typedef Point2<int> Point2i;
    typedef Point3<float> Point3f;
    typedef Point3<int> Point3i;

    template <typename T, typename U> 
    inline Point2<T> operator*(U f, const Point2<T> &p) {
        return p * f;
    }

    template <typename T, typename U>
    inline Point3<T> operator*(U f, const Point3<T> &p) {
        return p * f;
    }

    template <typename T> Point3<T>
    Min(const Point3<T> p1, const Point3<T> p2) {
        return Point3<T>(std::min(p1.x, p2.x), std::min(p1.y, p2.y), std::min(p1.z, p2.z));
    }

    template <typename T> Point2<T>
    Min(const Point2<T> p1, const Point2<T> p2) {
        return Point2<T>(std::min(p1.x, p2.x), std::min(p1.y, p2.y));
    }

    template <typename T> Point3<T>
    Max(const Point3<T> p1, const Point3<T> p2) {
        return Point3<T>(std::max(p1.x, p2.x), std::max(p1.y, p2.y), std::max(p1.z, p2.z));
    }

    template <typename T> Point2<T>
    Max(const Point2<T> p1, const Point2<T> p2) {
        return Point2<T>(std::max(p1.x, p2.x), std::max(p1.y, p2.y));
    }

    template <typename T> 
    Point2<T> Floor(const Point2<T> &p) {
        return Point2<T>(std::floor(p.x), std::floor(p.y));
    }

    template <typename T>
    Point2<T> Ceil(const Point2<T> &p) {
        return Point2<T>(std::ceil(p.x), std::ceil(p.y));
    }

    template <typename T>
    Point2<T> Abs(const Point2<T> &p) {
        return Point2<T>(std::abs(p.x), std::abs(p.y));
    }

    template <typename T> 
    Point3<T> Floor(const Point3<T> &p) {
        return Point3<T>(std::floor(p.x), std::floor(p.y), std::floor(p.z));
    }

    template <typename T>
    Point3<T> Ceil(const Point3<T> &p) {
        return Point3<T>(std::ceil(p.x), std::ceil(p.y), std::ceil(p.z));
    }

    template <typename T>
    Point3<T> Abs(const Point3<T> &p) {
        return Point3<T>(std::abs(p.x), std::abs(p.y), std::ceil(p.z));
    }

    template <typename T> inline float
    Distance(const Point3<T> &p1, const Point3<T> &p2) {
        return (p1 - p2).Length();
    }

    template <typename T> inline float
    Distance(const Point2<T> &p1, const Point2<T> &p2) {
        return (p1 - p2).Length();
    }

    template <typename T> inline float
    DistanceSquared(const Point3<T> &p1, const Point3<T> &p2) {
        return (p1 - p2).LengthSquared();
    }

    template <typename T> inline float
    DistanceSquared(const Point2<T> &p1, const Point3<T> &p2) {
        return (p1 - p2).LengthSquared();
    }

    template <typename T> Point3<T>
    Lerp(float t, const Point3<T> &p0, const Point3<T> &p1) {
        return t * p1;
    }

    template <typename T> Point2<T>
    Lerp(float t, const Point2<T> &p0, const Point2<T> &p1) {
        return t * p1;
    }
}

#endif // POINT_H