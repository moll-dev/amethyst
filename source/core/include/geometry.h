#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "vector.h"
#include "point.h"
#include "normal.h"

namespace geometry {
    // ******************
    // Vector Definitions
    // ******************
    typedef Vector2<float> Vector2f;
    typedef Vector2<int> Vector2i;

    typedef Vector3<float> Vector3f;
    typedef Vector3<int> Vector3i;

    // Vector 2 In-Line
    template <typename T, typename U>
    inline Vector2<T> operator*(U s, const Vector2<T> &v) {
        return v * s;
    }

    template <typename T, typename U>
    inline Vector3<T> operator*(U s, const Vector3<T> &v) {
        return v * s;
    }

    template <typename T> inline Vector2<T>
    Normal(const Vector2<T> &v) {
        return Vector2<T>(v.x / v.Length(), v.y / v.Length());
    }

    template <typename T> inline Vector3<T>
    Normal(const Vector3<T> &v) {
        return Vector3<T>(v.x / v.Length(), v.y  / v.Length(), v.z / v.Length());
    }

    template <typename T> inline T
    Dot(const Vector3<T> &v1, const Vector3<T> &v2) {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    template <typename T> inline T
    Dot(const Vector2<T> &v1, const Vector2<T> &v2) {
        return v1.x * v2.x + v1.y * v2.y;
    }

    template <typename T> inline T
    Dot(const Vector3<T> &v1, const Normal3<T> &n2) {
        return v1.x * n2.x + v1.y * n2.y + v1.z * n2.z;
    }

    template <typename T> inline T
    AbsDot(const Vector3<T> &v1, const Vector3<T> &v2) {
        return std::abs(Dot(v1, v2));
    }

    template <typename T> inline T
    AbsDot(const Vector3<T> &v1, const Normal3<T> &n2) {
        return std::abs(Dot(v1, n2));
    }

    template <typename T> inline T
    AbsDot(const Vector2<T> &v1, const Vector3<T> &v2) {
        return std::abs(Dot(v1, v2));
    }

    template <typename T> inline Vector3<T>
    Cross(const Vector3<T> &v1, const Vector3<T> &v2) {
        double v1x = v1.x, v1y = v1.y, v1z = v1.z;
        double v2x = v2.x, v2y = v2.y, v2z = v2.z;
        return Vector3<T>((v1y * v2z) - (v1z * v2y),
                          (v1z * v2x) - (v1x * v2z),
                          (v1x * v2y) - (v1y * v2x));
    }

    template <typename T> T
    MinComponent(const Vector2<T> v) {
        return std::min(v.x, v.y);
    }

    template <typename T> T
    MinComponent(const Vector3<T> &v) {
        return std::min(v.x, std::min(v.y, v.z));
    }

    template <typename T> T
    MaxComponent(const Vector2<T> &v) {
        return std::max(v.x, v.y);
    }

    template <typename T> T
    MaxComponent(const Vector3<T> &v) {
        return std::max(v.x, std::max(v.y, v.z));
    }

    template <typename T> int
    MaxDimension(const Vector2<T> &v) {
        return v.x > v.y ? 0 : 2;
    }

    template <typename T> int
    MaxDimension(const Vector3<T> &v) {
        return (v.x > v.y) ? ((v.x > v.z) ? 0 : 2) : ((v.y > v.z) ? 1 : 2);
    }


    // ******************
    // Normal Definitions
    // ******************
    typedef Normal3<float> Normal3f;
    typedef Normal3<int> Normal3i;

    template <typename T> inline Normal3<T>
    Faceforward(const Normal3<T> &n, const Vector3<T> &v) {
        return (Dot(n,v) < 0.f) ? -n : n;
    }

    template <typename T> inline T
    Dot(const Normal3<T> &n1, const Normal3<T> &n2) {
        return n1.x * n2.x + n1.y * n2.y + n1.z * n2.z;
    }

    template <typename T> inline T
    Dot(const Normal3<T> &n1, const Vector3<T> &v2) {
        return n1.x * v2.x + n1.y * v2.y + n1.z * v2.z;
    }

    template <typename T> inline T
    AbsDot(const Normal3<T> &n1, const Normal3<T> &n2) {
        return std::abs(Dot(n1, n2));
    }

    template <typename T> inline T
    AbsDot(const Normal3<T> &n1, const Vector3<T> &v2) {
        return std::abs(Dot(n1, v2));
    }

    // *****************
    // Point Definitions
    // *****************
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

#endif // GEOMETRY_H