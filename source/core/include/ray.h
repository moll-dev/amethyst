#ifndef RAY_H
#define RAY_H

#include "geometry.h"

namespace geometry {
    // TODO: Placeholder for Medium class
    class Medium {

    };

    class Ray {
        public:
            Ray() : tMax(Infinity), medium(nullptr) { }

            Ray(const Point3f &o, const Vector3f &d, float tMax = Infinity,
                float time = 0.0f, const Medium *medium = nullptr)
                : o(o), d(d), tMax(tMax), time(time), medium(medium) { }

            Point3f o;
            Vector3f d;
            mutable float tMax;
            Float time;

            // TODO: implement Medium
            const Medium *medium;
    }; // Class Ray

}; // Namespace geometry
#endif // RAY_H