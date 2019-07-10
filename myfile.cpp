#include <iostream>
enum{

};

class Matrix {
  public:
    void input_number_matrix(){
      for(size_t i = 0; i<size; ++i){
        for(size_t j = 0; j<size; ++j){
          std::cout <<"Input integer number ["<<i<<"]"<<"["<<j<<"]"<<"element of matrix:\n";
          std::cin >> matrix[i][j];
        }
      }
    }
    void random_input_matrix(){
      for(size_t i = 0; i<size; ++i){
        for(size_t j = 0; j<size; ++j){
          matrix[i][j] = 1 + rand() % 4;
        }
      }
    }
    void show_matrix(){
      for(size_t i = 0; i<size; ++i){
        for(size_t j = 0; j<size; ++j){
          std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<"\n";
      }
    }
    Matrix& operator += (const Matrix &rhl) {
      for(size_t i = 0; i<size; ++i){
        for(size_t j = 0; j<size; ++j){
          matrix[i][j] += rhl.matrix[i][j];
        }      
      }
      return *this;
    }
    Matrix& operator -= (const Matrix &rhl) {
      for(size_t i = 0; i<size; ++i){
        for(size_t j = 0; j<size; ++j){
          matrix[i][j] -= rhl.matrix[i][j];
        }      
      }
      return *this;
    }
    Matrix& operator *= (const Matrix &rhl) {
      for(size_t i = 0; i<size; ++i){
        for(size_t j = 0; j<size; ++j){
          matrix[i][j] *= rhl.matrix[i][j];
        }      
      }
      return *this;
    }
    Matrix& operator /= (const Matrix &rhl) {
      for(size_t i = 0; i<size; ++i){
        for(size_t j = 0; j<size; ++j){
          double_matrix[i][j] *= rhl.matrix[i][j];
        }      
      }
      return *this;
    }

  private:
    static const size_t size = 3;
    int matrix [size][size]{};
    double double_matrix [size][size]{};
    
};

int main(int argc, char const *argv[]) {
  Matrix m;
  Matrix m1;
  size_t input_type = 0;
  std::cout << "Welcom to programm sum, difference, division, multiplication square matrices!\n";
  std::cout << "How do you want to remember the matrix:\n"
            << "1. Manual input\n"
            << "2. Random input\n";
  std::cin >> input_type;
  enum {
    MANUAL_INPUT = 1,
    RANDOM_INPUT
  };
  switch (input_type){
    case MANUAL_INPUT:
      m.input_number_matrix();
      std::cout <<"Element of matrix 1: \n";
      m.show_matrix();

      m1.input_number_matrix();
      std::cout <<"Element of matrix 2: \n";
      m1.show_matrix();
      break;
    case RANDOM_INPUT:
      m.random_input_matrix();
      std::cout <<"Element of matrix 1: \n";
      m.show_matrix();

      m1.random_input_matrix();
      std::cout <<"Element of matrix 2: \n";
      m1.show_matrix();
      break;      

    default:
      std::cout << "Error choise!";
      break;
  }
  size_t input_actions = 0;
  std::cout << "Choise what are going to do: \n" 
            << "1. Sum 1 matrix and 2 matrix \n"
            << "2. Diff 2 matrix and 1 matrix \n"
            << "3. Division 1 matrix and 2 matrix \n"
            << "4. Multiplay 1 matrix and 2 matrix \n";
  std::cin >> input_actions;

  enum{
    SUM = 1,
    DIFF,
    DIV,
    MULTI
  };

  switch (input_actions){
    case SUM:
      m1 += m;
      std::cout <<"Element of matrix 2: \n";
      m1.show_matrix();
      break;

    case DIFF:
      m1 -= m;
      std::cout <<"Element of matrix 2: \n";
      m1.show_matrix();
      break;

    case DIV:
      m1 /= m;
      std::cout <<"Element of matrix 2: \n";
      m1.show_matrix();
      break;
    
    case MULTI:
      m1 *= m;
      std::cout <<"Element of matrix 2: \n";
      m1.show_matrix();
      break;

    default:
      std::cout<<"Error actions!\n";
      break;
  }


  return 0;
}