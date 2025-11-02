#ifndef VEC3_H
#define VEC3_H

#include <math.h>
#include <stdlib.h>
#include <iostream>

class vec3 {
  public:
    vec3() {}

    vec3(double e0, double e1, double e2) {
      _x = e0;
      _y = e1;
      _z = e2;
    }

    inline double x() const { return _x; }
    inline double y() const { return _y; }
    inline double z() const { return _z; }
    inline double r() const { return _x; }
    inline double g() const { return _y; }
    inline double b() const { return _z; }

    void set(double e0, double e1, double e2);

    vec3 &operator+=(const vec3 &v2);
    vec3 &operator-=(const vec3 &v2);
    vec3 &operator*=(const vec3 &v2);
    vec3 &operator*=(const double s);
    vec3 &operator/=(const vec3 &v2);
    vec3 &operator/=(const double s);

    double magnitude() const;
    double magnitude_squared() const;
    void make_unit_vector();

  private:
    double _x;
    double _y;
    double _z;
};

#endif // VEC3_H