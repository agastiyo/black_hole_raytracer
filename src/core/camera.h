#ifndef CAMERAH
#define CAMERAH

#include "ray.h"

// This Camera is fixed at the origin right now, could add functionality to make it modular later

class Camera {
  public:
    Camera(double vfov, double aspect);

    Ray getRay(double u, double v);

    inline vec3 getOrigin() { return origin; }
    inline vec3 getLowerLeft() { return lower_left_corner; }
    inline vec3 getHorizontal() { return horizontal; }
    inline vec3 getVertical() {return vertical; }

  private:
    vec3 origin;
    vec3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;
};

#endif