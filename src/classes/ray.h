#ifndef RAY_H
#define RAY_H

#include <math.h>
#include <stdlib.h>
#include <iostream>

#include "vec3.h"

// Right now the rays are straight lines.
// pos = dir*t + origin
// This is the geodesic in a flat spacetime.

// Writing this for a black hole later, the equation will be different.
// The geodesic will be calculated using the metric function.

class Ray {
  public:
    Ray() {}

    Ray(vec3 _origin, vec3 _direction);

    vec3 getOrigin() const;
    vec3 getDirection() const;
    vec3 point_at_parameter(double t) const;

  private:
    vec3 origin;
    vec3 direction;
};

#endif // RAY_H