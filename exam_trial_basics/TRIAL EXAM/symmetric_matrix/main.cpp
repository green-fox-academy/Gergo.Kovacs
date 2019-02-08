#include <iostream>
int const max = 100;

bool isSymmetric(int matrix[][max], int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
            return true;
        }
    }
}
int main()
{

    int matrix[][max] = {{1, 0, 1,}, {0, 2, 2,}, {1, 2, 5}};

    if (isSymmetric(matrix, 3)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}