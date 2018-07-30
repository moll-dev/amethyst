#include <geometry.h>

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
        // Public Vector2 Data

        friend std::ostream& operator<<(std::ostream& s, const Vector2& v) {
            s << "Vector2<" << v.x << "," << v.y << ">";
            return s;
        }
        T x, y;
};

template <typename T> class Vector3 {
    public:

        // Public Vector3 Data
        T x, y, z;
};