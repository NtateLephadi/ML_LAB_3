#include "pca.h"

int main(int argc, char const *argv[]) {
  /* code */
  pca p;
  p.set_january();
  p.set_july();
  p.minus_mean();
  p.set_covariance_matrix();
  p.set_eigen();
  return 0;
}
