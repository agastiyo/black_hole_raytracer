#include <iostream>

#include "vec3ops.h"

std::istream& operator>>(std::istream &is, vec3 &vec)
{
  double x, y, z;
  is >> x >> y >> z;
  vec.set(x, y, z);
  return is;
}

std::ostream& operator<<(std::ostream &os, vec3 &vec) {
  os << vec.x() << " " << vec.y() << " " << vec.z();
  return os;
}

vec3 operator+(const vec3 &v1, const vec3 &v2) {
  return vec3(v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z());
}

vec3 operator-(const vec3 &v1, const vec3 &v2) {
  return vec3(v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z());
}

vec3 operator*(const vec3 &v1, const vec3 &v2) {
  return vec3(v1.x() * v2.x(), v1.y() * v2.y(), v1.z() * v2.z());
}

vec3 operator*(double t, const vec3 &v) {
  return vec3(t * v.x(), t * v.y(), t * v.z());
}

vec3 operator*(const vec3 &v, double t) {
  return vec3(t * v.x(), t * v.y(), t * v.z());
}

vec3 operator/(const vec3 &v1, const vec3 &v2) {
  return vec3(v1.x() / v2.x(), v1.y() / v2.y(), v1.z() / v2.z());
}

vec3 operator/(const vec3 &v, double t) {
  return vec3(v.x() / t, v.y() / t, v.z() / t);
}

double dot(const vec3 &v1, const vec3 &v2) {
  return v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z();
}

vec3 cross(const vec3 &v1, const vec3 &v2) {
  return vec3((v1.y() * v2.z() - v1.z() * v2.y()),
              -(v1.x() * v2.z() - v1.z() * v2.x()),
              (v1.x() * v2.y() - v1.y() * v2.x()));
}

vec3 unit_vector(vec3 v) {
  return v / v.magnitude();
}