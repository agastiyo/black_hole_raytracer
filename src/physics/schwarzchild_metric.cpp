#include <iostream>

#include "schwarzchild_metric.h"

SchwarzchildMetric::SchwarzchildMetric(double mass) {
  M = mass;
}

// g_{\mu\nu}
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

// g^{\mu\nu}
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

// \pdd_a g_{\mu\nu}
double SchwarzchildMetric::dg(int mu, int nu, double r, double theta, int a) {
  if (mu > 3 || nu > 3) { // not a physical coordinate
    return NULL;
  }

  if (mu != nu) { // metric tensor is diagonal
    return 0;
  }

  if (mu == 0) {
    if (a == 1) { return 1-(2*M)/(r*r); }
    return 0;
  }

  if (mu == 1) {
    if (a == 1) { return -(2*M)/((r-2*M)*(r-2*M)); }
    return 0;
  }

  if (mu == 2) {
    if (a == 1) { return 2*r; }
    return 0;
  }

  if (mu == 3) {
    if (a == 1) { return 2*r*sin(theta)*sin(theta); }
    if (a == 2) { return r*r*2*cos(theta)*sin(theta); }
    return 0;
  }

  return NULL; // should never reach here
}

// \Gamma_{\mu\mu}^\lambda
double SchwarzchildMetric::affine(int mu, int nu, int lambda, double r, double theta) {
  if (mu > 3 || nu > 3 || lambda > 3) { // not a physical coordinate
    return NULL;
  }

  // using the christoffel symbol equation

  double res = 0;

  for (int d = 0; d <= 3; d++) {
    res += g_inv(lambda,d,r,theta) * (dg(d,nu,r,theta,mu) + dg(mu,d,r,theta,nu) - dg(mu,nu,r,theta,d));
  }

  return 0.5 * res;
}