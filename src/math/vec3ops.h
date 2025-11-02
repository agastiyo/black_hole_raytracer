#ifndef VEC3OPS_H
#define VEC3OPS_H

#include <iostream>

#include "vec3.h"

// Stream operators
std::istream& operator>>(std::istream &is, vec3 &vec);
std::ostream& operator<<(std::ostream &os, vec3 &vec);

// Arithmetic operators
vec3 operator+(const vec3 &v1, const vec3 &v2);
vec3 operator-(const vec3 &v1, const vec3 &v2);
vec3 operator*(const vec3 &v1, const vec3 &v2);
vec3 operator*(double t, const vec3 &v);
vec3 operator*(const vec3 &v, double t);
vec3 operator/(const vec3 &v1, const vec3 &v2);
vec3 operator/(const vec3 &v, double t);

// Vector operations
double dot(const vec3 &v1, const vec3 &v2);
vec3 cross(const vec3 &v1, const vec3 &v2);
vec3 unit_vector(vec3 v);

#endif // VEC3OPS_H