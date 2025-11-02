#include <iostream>
#include <fstream>

#include "classes/vec3.h"
#include "classes/vec3ops.h"
#include "classes/ray.h"

using namespace std;

vec3 color(const Ray& r) {
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

  // Define the lower left corner to start traversal of the screen
  vec3 lower_left_corner(-width/200,-height/200,-backgroundDist/100);

  vec3 horizontal(width/100,0,0); // Width of screen
  vec3 vertical(0,height/100,0); // Height of screen
  vec3 origin(0,0,0);

  // Set up PPM file
  output_file << "P3\n" << width << " " << height << "\n255\n";

  // Write to PPM file
  for (int j = height-1; j >= 0; j--) {
    for (int i = 0; i < width; i++) {
      double u = double(i) / double(width);
      double v = double(j) / double(height);

      Ray r(origin, lower_left_corner + u*horizontal + v*vertical);
      vec3 col = color(r);

      int ir = int(255.99*col.r());
      int ig = int(255.99 * col.g());
      int ib = int(255.99 * col.b());

      output_file << ir << " " << ig << " " << ib << "\n";
    }
  }
}