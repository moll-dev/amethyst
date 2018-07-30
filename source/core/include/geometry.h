#include <assert.h>
#include <math.h>
#include <iostream>

namespace geometry {
    template <typename T> class Vector2 {
    public:
        Vector2();
        Vector2(T x, T y);
        bool HasNaNs();
        friend std::ostream& operator<<(std::ostream& s, const Vector2& v);
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