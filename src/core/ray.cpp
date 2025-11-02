#include "ray.h"
#include "vec3ops.h"

Ray::Ray(vec3 _origin, vec3 _direction) {
  origin = _origin;
  direction = _direction;
}

vec3 Ray::getOrigin() const { 
  return origin; 
}

vec3 Ray::getDirection() const { 
  return direction; 
}

vec3 Ray::point_at_parameter(double t) const {
  return origin + (t*direction);
}