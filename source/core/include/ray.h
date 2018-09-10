#ifndef RAY_H
#define RAY_H

#include <ostream>
#include "geometry.h"

namespace geometry {
    // TODO: Placeholder for Medium class
    class Medium {

    };

    class Ray {
        public:
            Ray() : tMax(Infinity), time(0.0f), medium(nullptr) {}

            Ray(const Point3f &o, const Vector3f &d, float tMax = Infinity, float time = 0.0f, const Medium *medium = nullptr)
            : o(o), d(d), tMax(tMax), time(time), medium(medium) {}


            // TODO: implement Medium
            Point3f o;
            Vector3f d;
            mutable float tMax;
            float time;
            const Medium *medium;

            Point3f operator()(float t) {
                return o + d * t;
            }

            friend std::ostream& operator<<(std::ostream& s, const Ray &r) {
                s << "Ray<" << r.o << "," << r.d << ">";
                return s;
            } 
    }; // Class Ray

    class RayDifferential : public Ray {
        public:
            RayDifferential() { hasDifferentials = false; }
        
            RayDifferential(const Point3f &o, const Vector3f &d, float tMax = Infinity, float time = 0.0f, const Medium *medium = nullptr)
            : Ray(o, d, tMax, time, medium) {
                hasDifferentials = false;
            }

            RayDifferential(Ray &ray) : Ray(ray) {
                hasDifferentials = false;
            }

            ScaleDifferentials(float s) {
                rxOrigin = o + (rxOrigin - o) * s;
                ryOrigin = o + (ryOrigin - o) * s;
                rxDirection = d + (rxDirection - d) * s;
                ryDirection = d + (ryDirection - d) * s;
            }

            bool hasDifferentials;
            Point3f rxOrigin, ryOrigin;
            Vector3f rxDirection, ryDirection;
    }; // Class RayDifferential

}; // Namespace geometry
#endif // RAY_H