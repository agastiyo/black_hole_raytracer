#include "vec3.h"

void vec3::set(double e0, double e1, double e2)
{
  _x = e0;
  _y = e1;
  _z = e2;
}

void vec3::make_unit_vector() {
  double mag = magnitude();
  _x = _x / mag;
  _y = _y / mag;
  _z = _z / mag;
}

double vec3::magnitude() const {
  return sqrt(magnitude_squared());
}

double vec3::magnitude_squared() const {
  return _x*_x + _y*_y + _z*_z;
}

vec3& vec3::operator+=(const vec3 &v) {
  _x += v._x;
  _y += v._y;
  _z += v._z;
  return *this;
}

vec3& vec3::operator-=(const vec3 &v) {
  _x -= v._x;
  _y -= v._y;
  _z -= v._z;
  return *this;
}

vec3& vec3::operator*=(const vec3 &v) {
  _x *= v._x;
  _y *= v._y;
  _z *= v._z;
  return *this;
}

vec3& vec3::operator*=(const double t) {
  _x *= t;
  _y *= t;
  _z *= t;
  return *this;
}

vec3& vec3::operator/=(const vec3 &v) {
  _x /= v._x;
  _y /= v._y;
  _z /= v._z;
  return *this;
}

vec3& vec3::operator/=(const double t) {
  _x /= t;
  _y /= t;
  _z /= t;
  return *this;
}