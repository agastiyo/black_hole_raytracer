#include <iostream>

#include "schwarzchild_metric.h"

SchwarzchildMetric::SchwarzchildMetric(double mass) {
  M = mass;
}

double SchwarzchildMetric::g(int mu, int nu, double r, double theta) {
  if (mu > 3 || nu > 3) { // not a physical coordinate
    return NULL;
  }

  if (mu != nu) { // metric tensor is diagonal
    return 0;
  }

  if (mu == 0) { return -(1-(2*M)/r); }
  if (mu == 1) { return 1/(1-(2*M)/r); }
  if (mu == 2) { return r*r; }
  if (mu == 3) { return r*r*sin(theta)*sin(theta); }

  return NULL; // should never reach here
}

double SchwarzchildMetric::g_inv(int mu, int nu, double r, double theta) {
  if (mu > 3 || nu > 3) { // not a physical coordinate
    return NULL;
  }

  if (mu != nu) { // inverse metric tensor is diagonal
    return 0;
  }

  if (mu == 0) { return -1/(1-(2*M)/r); }
  if (mu == 1) { return 1-(2*M)/r; }
  if (mu == 2) { return 1/(r*r); }
  if (mu == 3) { return 1/(r*r*sin(theta)*sin(theta)); }

  return NULL; // should never reach here
}

double SchwarzchildMetric::affine(int mu, int nu, int lambda, double r, double theta) {
  if (mu > 3 || nu > 3 || lambda > 3) { // not a physical coordinate
    return NULL;
  }

  // compute the christoffel symbols by hand
  // hard code this once done

  return NULL;
}