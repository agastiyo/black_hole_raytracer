#include "four_momentum.h"

FourMomentum::FourMomentum() {
  kt = 0;
  kr = 0;
  ktheta = 0;
  kphi = 0;
}

FourMomentum::FourMomentum(double _kt, double _kr, double _ktheta, double _kphi) {
  kt = _kt;
  kr = _kr;
  ktheta = _ktheta;
  kphi = _kphi;
}

FourMomentum FourMomentum::fromRay(const vec3 &dir, const vec3 &camPos, const SchwarzchildMetric &g) {
  

  return FourMomentum();
}