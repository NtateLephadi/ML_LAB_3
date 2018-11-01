#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>

#ifndef PCA_H
#define PCA_H

class pca{
private:
  std::vector<double> january, july;
public:
  pca();
  ~pca();
  void set_january();
  void set_july();
  void to_string();
};

#endif
