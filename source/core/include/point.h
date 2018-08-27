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
}

#endif // POINT_H