#include "camera.h"
#include "math/vec3ops.h"

Camera::Camera(double vfov, double aspect) {
  double theta = vfov*M_PI/180;
  double half_height = tan(theta/2);
  double half_width = aspect*half_height;

  lower_left_corner = vec3(-half_width,-half_height,-1);
  horizontal = vec3(2*half_width,0,0);
  vertical = vec3(0,2*half_height,0);
  origin = vec3(0,0,0);
}

Ray Camera::getRay(double u, double v) {
  return Ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
}