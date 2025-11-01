#include <iostream>

#include "vec3.h"

// Functions to print the vector

inline std::istream& operator>>(std::istream &is, vec3 &vec) {
  double x, y, z;
  is >> x >> y >> z;
  vec.set(x,y,z);
  return is;
}

inline std::ostream &operator<<(std::ostream &os, vec3 &vec)
{
  os << vec.x() << " " << vec.y() << " " << vec.z();
  return os;
}

// Operator Overloads

inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
  return vec3(v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z());
}

inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
  return vec3(v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z());
}

inline vec3 operator*(const vec3 &v1, const vec3 &v2) {
  return vec3(v1.x() * v2.x(), v1.y() * v2.y(), v1.z() * v2.z());
}

inline vec3 operator*(double t, const vec3 &v) {
  return vec3(t * v.x(), t * v.y(), t * v.z());
}

inline vec3 operator*(const vec3 &v, double t) {
  return vec3(t * v.x(), t * v.y(), t * v.z());
}

inline vec3 operator/(const vec3 &v1, const vec3 &v2) {
  return vec3(v1.x() / v2.x(), v1.y() / v2.y(), v1.z() / v2.z());
}

inline vec3 operator/(const vec3 &v, double t) {
  return vec3(v.x() / t, v.y() / t, v.z() / t);
}

inline double dot(const vec3 &v1, const vec3 &v2) {
  return v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z();
}

inline vec3 cross(const vec3 &v1, const vec3 &v2) {
  return vec3((v1.y() * v2.z() - v1.z() * v2.y()),
              -(v1.x() * v2.z() - v1.z() * v2.x()),
              (v1.x() * v2.y() - v1.y() * v2.x()));
}

// Class Function Implementation

inline void vec3::set(double e0, double e1, double e2)
{
  _x = e0;
  _y = e1;
  _z = e2;
}

inline void vec3::make_unit_vector() {
  _x = _x / magnitude();
  _y = _y / magnitude();
  _z = _z / magnitude();
}

inline double vec3::magnitude() const {
  return sqrt(magnitude_squared());
}

inline double vec3::magnitude_squared() const {
  return _x*_x + _y*_y + _z*_z;
}

inline vec3 &vec3::operator+=(const vec3 &v)
{
  _x += v._x;
  _y += v._y;
  _z += v._z;
  return *this;
}

inline vec3 &vec3::operator-=(const vec3 &v)
{
  _x -= v._x;
  _y -= v._y;
  _z -= v._z;
  return *this;
}

inline vec3& vec3::operator*=(const vec3 &v) {
  _x *= v._x;
  _y *= v._y;
  _z *= v._z;
  return *this;
}

inline vec3 &vec3::operator*=(const double t)
{
  _x *= t;
  _y *= t;
  _z *= t;
  return *this;
}

inline vec3 &vec3::operator/=(const vec3 &v)
{
  _x /= v._x;
  _y /= v._y;
  _z /= v._z;
  return *this;
}

inline vec3 &vec3::operator/=(const double t)
{
  _x /= t;
  _y /= t;
  _z /= t;
  return *this;
}

// Misc funcs

inline vec3 unit_vector(vec3 v) {
  return v / v.magnitude();
}