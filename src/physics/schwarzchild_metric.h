// We are working in the coordinate system (t,r,theta,phi) or (0,1,2,3) with signature (-,+,+,+) and assuming G = 1 and c = 1

class SchwarzchildMetric {
  public:
    SchwarzchildMetric(double mass);

    double g(int mu, int nu, double r, double theta);
    double g_inv(int mu, int nu, double r, double theta);
    double dg(int mu, int nu, double r, double theta, int a);
    double affine(int mu, int nu, int lambda, double r, double theta);

    inline double delta(double r) { return r*r - 2*M*r; }

    inline double event_horizon_radius() { return 2*M; }

  private: 
    double M; // mass
};