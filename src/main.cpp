#include <iostream>
#include <fstream>

#include "math/vec3.h"
#include "math/vec3ops.h"
#include "core/ray.h"
#include "core/camera.h"

using namespace std;

bool hit_sphere(const vec3& center, double rad, const Ray& r) {
  vec3 oc = r.getOrigin() - center;
  double a = dot(r.getDirection(),r.getDirection());
  double b = 2 * dot(r.getDirection(),oc);
  double c = dot(oc,oc) - rad*rad;
  double discriminant = b*b - 4*a*c;
  return (discriminant > 0);
}

// This function checks what the ray hits
vec3 color(const Ray& r) {

  // Create a sphere at (0,0,-1) with r=0.5
  if (hit_sphere(vec3(0,0,-1), 0.5, r)) {
    return vec3(1,0,0); // Sphere is colored red
  }

  // If nothing is hit, give the gradient background
  vec3 unit_direction = unit_vector(r.getDirection());
  double t = 0.5*(unit_direction.y() + 1);
  return (1-t)*vec3(1,1,1) + t*vec3(0.5,0.7,1.0);
}

int main() {
  // Everything runs from here. After edits, run make, and then ./bin/black_hole_raytracer

  ofstream output_file("../output/image.ppm");
  if (!output_file.is_open()) {
    cout << "Unable to open file!";
    return 0;
  }

  int height = 200;
  int width = 400;
  int backgroundDist = 100;

  // Set up PPM file
  output_file << "P3\n" << width << " " << height << "\n255\n";

  // Set up camera
  Camera cam(120, double(width)/double(height));

  // Write to PPM file
  for (int j = height-1; j >= 0; j--) {
    for (int i = 0; i < width; i++) {
      double u = double(i) / double(width);
      double v = double(j) / double(height);

      Ray r(cam.getOrigin(), cam.getLowerLeft() + u*cam.getHorizontal() + v*cam.getVertical());
      vec3 col = color(r);

      int ir = int(255.99*col.r());
      int ig = int(255.99 * col.g());
      int ib = int(255.99 * col.b());

      output_file << ir << " " << ig << " " << ib << "\n";
    }
  }
}