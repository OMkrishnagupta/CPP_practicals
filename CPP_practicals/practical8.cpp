#include <iostream>
using namespace std;

class Matrix {
    int arr[10][10];
    int row, col;

public:
    Matrix() {
        row = col = 0;
    }

    void getMatrix() {
        cout << "Enter the number of rows and columns of the matrix: ";
        cin >> row >> col;

        cout << "Enter the elements of the matrix:\n";
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> arr[i][j];
            }
        }
    }

    void displayMatrix() {
        cout << "The matrix is:\n";
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    void addMatrix(Matrix m1, Matrix m2) {
        if (m1.row != m2.row || m1.col != m2.col) {
            throw "Matrices are incompatible!";
        }

        row = m1.row;
        col = m1.col;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                arr[i][j] = m1.arr[i][j] + m2.arr[i][j];
            }
        }
    }

    void multiplyMatrix(Matrix m1, Matrix m2) {
        if (m1.col != m2.row) {
            throw "Matrices are incompatible!";
        }

        row = m1.row;
        col = m2.col;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                arr[i][j] = 0;
                for (int k = 0; k < m1.col; k++) {
                    arr[i][j] += m1.arr[i][k] * m2.arr[k][j];
                }
            }
        }
    }

    void transposeMatrix(Matrix m) {
        row = m.col;
        col = m.row;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                arr[i][j] = m.arr[j][i];
            }
        }
    }
};

int main() {
    Matrix mat1, mat2, mat3;
    int choice;

    while (true) {
        cout << "\n\nMenu\n";
        cout << "----\n";
        cout << "1. Add two matrices\n";
        cout << "2. Multiply two matrices\n";
        cout << "3. Transpose a matrix\n";
        cout << "4. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                try {
                    mat1.getMatrix();
                    mat2.getMatrix();
                    mat3.addMatrix(mat1, mat2);
                    mat3.displayMatrix();
                } catch(const char* msg) {
                    cerr << msg << endl;
                }
                break;

            case 2:
                try {
                    mat1.getMatrix();
                    mat2.getMatrix();
                    mat3.multiplyMatrix(mat1, mat2);
                    mat3.displayMatrix();
                } catch(const char* msg) {
                    cerr << msg << endl;
                }
                break;

            case 3:
                try {
                    mat1.getMatrix();
                    mat3.transposeMatrix(mat1);
                    mat3.displayMatrix();
                } catch(const char* msg) {
                    cerr << msg << endl;
                }
                break;

            case 4:
                exit(0);

            default:
                cout << "Invalid choice!\n";
                break;
        }
    }

    return 0;
}

