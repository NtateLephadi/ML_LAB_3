#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <functional>   // std::minus
#include <numeric>      // std::accumulate
#include "Eigen/Dense"

#ifndef PCA_H
#define PCA_H

using namespace Eigen;

class pca{
private:
  std::vector<double> january, july;
  std::vector<std::vector<double>> covariance_matrix;
public:
  pca();
  ~pca();
  void set_january();
  void set_july();
  void to_string();
  void minus_mean();
  double covariance(std::vector<double>, std::vector<double>);
  void set_covariance_matrix();
  void set_eigen();
};

#endif
