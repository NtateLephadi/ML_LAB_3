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

  std::cout << "covariance matrix" << '\n';

  for (size_t i = 0; i < this->covariance_matrix.size(); i++) {
    /* code */
    for (size_t j = 0; j < this->covariance_matrix[i].size(); j++) {
      /* code */
      std::cout << this->covariance_matrix[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

void pca::minus_mean() {
  /* code */
  double sum = std::accumulate(
    this->january.begin(),
    this->january.end(),
    0
  );

  double mean = sum / this->january.size();
  for (size_t i = 0; i < this->january.size(); i++) {
    /* code */
    this->january[i]=mean-this->january[i];
  }

  sum = std::accumulate(
    this->july.begin(),
    this->july.end(),
    0
  );

  mean = sum / this->july.size();
  for (size_t i = 0; i < this->july.size(); i++) {
    /* code */
    this->july[i]=mean-this->july[i];
  }
}

double pca::covariance(std::vector<double> v, std::vector<double> y){
  double product = 0;

  for (size_t i = 0; i < v.size(); i++) {
    /* code */
    product+=v[i]*y[i];
  }
  return (product)/63;
}

void pca::set_covariance_matrix() {
  /* code */
  std::vector<double> v;
  v.push_back(
    covariance(
      this->january,
      this->january
    )
  );

  v.push_back(
    covariance(
      this->january,
      this->july
    )
  );

  this->covariance_matrix.push_back(v);

  v.clear();

  v.push_back(
    covariance(
      this->july,
      this->january
    )
  );

  v.push_back(
    covariance(
      this->july,
      this->july
    )
  );

  this->covariance_matrix.push_back(v);
}

void pca::set_eigen(){
  Matrix2f A;
  A <<
  this->covariance_matrix[0][0],
  this->covariance_matrix[0][1],
  this->covariance_matrix[1][0],
  this->covariance_matrix[1][1];
  std::cout << "Here is the matrix A:\n" << A << std::endl;
  SelfAdjointEigenSolver<Matrix2f> eigensolver(A);
  if (eigensolver.info() != Success) abort();
  std::cout << "The eigenvalues of A are:\n" << eigensolver.eigenvalues() << std::endl;
  std::cout << "Here's a matrix whose columns are eigenvectors of A \n"
  << "corresponding to these eigenvalues:\n"
  << eigensolver.eigenvectors() << std::endl;  
}
