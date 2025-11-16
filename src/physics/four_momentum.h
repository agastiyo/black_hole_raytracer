#include "math/vec3.h"
#include "schwarzchild_metric.h"

class FourMomentum {
  public:
    FourMomentum();
    FourMomentum(double _kt, double _kr, double _ktheta, double _kphi);

    FourMomentum fromRay(const vec3& dir, const vec3& camPos, const SchwarzchildMetric& g);

  private:
    double kt;
    double kr;
    double ktheta;
    double kphi;
};