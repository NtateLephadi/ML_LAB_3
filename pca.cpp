#include "pca.h"

pca::pca(){}

pca::~pca(){}

void pca::set_january(){
  std::ifstream afile("january.txt", std::ios::in);
  if (afile.is_open()) {
    std::string line;
    while (std::getline(afile, line)) {
      this->january.push_back(std::stod(line));
    }
    afile.close();
  }
  else {
    std::cerr << "Unable to open file\n";
  }
}

void pca::set_july(){
  /* code */
  std::ifstream afile("july.txt", std::ios::in);
  if (afile.is_open()) {
    std::string line;
    while (std::getline(afile, line)) {
      this->july.push_back(std::stod(line));
    }
    afile.close();
  }
  else {
    std::cerr << "Unable to open file\n";
  }
}

void pca::to_string(){

  std::cout << "january" << '\n';

  for (size_t i = 0; i < this->january.size(); i++) {
    /* code */
    std::cout << this->january[i] << '\n';
  }

  std::cout << "july" << '\n';

  for (size_t i = 0; i < this->july.size(); i++) {
    /* code */
    std::cout << this->july[i] << '\n';
  }
}
