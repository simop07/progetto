#include "sfml.hpp"

int main() {
  std::vector<boid> flock;
  /* int n;
   double s;
   double a;
   double c;
   std::cout << "Insert number of boids" << '\n';
   std::cin >> n;
   std::cout << "Insert parameters s, a and c respectevly" << '\n';
   std::cin >> s >> a >> c;*/
  stats st{1., 10., 2.5, 0.07, 0.01, 0., 100., 100., 0., 5., 50.};
  // stats st{1., 8., s, a, c, 0., 50., 50., 0., 0.5, 10., 100.};
  std::default_random_engine generator;
  std::normal_distribution<double> pos_d(st.u_b / 2., st.u_b * 2.);
  std::normal_distribution<double> vel_d(0., st.v_max);

  predator p{{st.r_b / 4., st.u_b / 4.}, {0., 0.}};

  for (int i = 0; i < 250; ++i) {
    boid b_i{{pos_d(generator), pos_d(generator)},
             {vel_d(generator), vel_d(generator)}};
    flock.push_back(b_i);
  }

  run_simulation(flock, p, st);
}
