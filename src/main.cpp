#include <iostream>
#include <fstream>

#include "classes/vec3.h"

using namespace std;

int main() {
  // Everything runs from here. After edits, run make, and then ./bin/black_hole_raytracer

  ofstream output_file("../output/image.ppm");
  if (!output_file.is_open()) {
    cout << "Unable to open file!";
    return 0;
  }

  // Set up PPM file
  int nx = 200;
  int ny = 200;
  output_file << "P3\n" << nx << " " << ny << "\n255\n";

  // Write to PPM file
  for (int j = ny-1; j >= 0; j--) {
    for (int i = 0; i < nx; i++) {
      vec3 col(double(i) / double(nx), double(j) / double(ny) , 0.2);
      int ir = int(255.99*col.r());
      int ig = int(255.99 * col.g());
      int ib = int(255.99 * col.b());

      output_file << ir << " " << ig << " " << ib << "\n";
    }
  }
}