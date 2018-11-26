#include <iostream>
using namespace std;

// Give a C++ code fragment, that, given an n x n matrix M of type float,
//  replaces M with its transpose. Try to do this without the use of
//  a temporary matrix.
void transpose(float** M, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      float tmp = M[i][j];
      M[i][j] = M[j][i];
      M[j][i] = tmp;
    }
  }
}

void printMatrix(float** M, int n) {
  for (int i = 0; i < n; i++)
    cout << " -";
  cout << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == 0)
	cout << "|";
      cout << M[i][j];
      if (j == (n-1))
	cout << "|";
      else
	cout << " ";
    }
    cout << endl;
  }
  for (int i = 0; i < n; i++)
    cout << " -";
  cout << endl;
}

int main() {
  int DIM = 3;
  float **M = new float* [DIM];
  for (int i = 0; i < DIM; i++)
    M[i] = new float[DIM];
  int n = 1;
  for (int i = 0; i < DIM; i++)
    for (int j = 0; j < DIM; j++)
      M[i][j] = n++;
  cout << "Before transpose, M:\n";
  printMatrix(M, DIM);
  transpose(M, DIM);
  cout << "After transpose, M:\n";
  printMatrix(M, DIM);
  for (int i = 0; i < DIM; i++)
    delete[] M[i];
  delete[] M;
  return 0;
}
