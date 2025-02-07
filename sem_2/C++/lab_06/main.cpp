#include <iostream>
#include <vector.hpp>
#include <type_traits>


using namespace std;

template <typename T, typename std::enable_if_t<
    is_arithmetic_v<T> && 
    !is_same_v<T, char> && 
    !is_same_v<T, bool>, int> = 0>
class Matrix {
private:
    Vector<Vector<T>> matrix; 
    size_t m;
    size_t n;

    Matrix<T> minor (int row, int col) {
        Matrix<T> res(n - 1, m - 1, 0);
        size_t m_count = 0;
        size_t n_count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == row || j == col) continue;
                res[m_count][n_count] = matrix[i][j];
                n_count++;
            }
            if (i != row) m_count++;
            n_count = 0;
        }
        return res;
    }
public:
    Matrix() {
        m = 0;
        n = 0;
    }

    Matrix(size_t m_size, size_t n_size, T el = T()) {
        Vector<Vector<T>> matr(m_size, Vector<T>(n_size, el));
        matrix = matr;
        m = m_size;
        n = n_size;
    }

    Matrix(const Matrix& other) {
        matrix = other.matrix;
        m = other.m;
        n = other.n;
    }


    T det () {
        if ((m != n) || (m == 0 && n == 0)) {
            throw out_of_range("Matrix is not square");
        }
        if (m == 1) {
            return matrix[0][0];
        }
        if (m == 2) {
            return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
        }
        T res = T();

        for (int i = 0; i < m; i++) {
            res += pow(-1, i) * matrix[0][i] * this->minor(0, i).det();
        }

        return res;

        
    }

    Vector<T>& operator[](size_t i) {
        return matrix[i];
    }

    Matrix& operator=(const Matrix& other) {
        if (this == &other)
            return *this;

        matrix = other.matrix;
        m = other.m;
        n = other.n;
        
        return *this;
    }

    Matrix& operator++() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j]++;
            }
        }
        return *this;
    }

    Matrix operator+(const Matrix& other) const {
    if (m != other.m && n != other.n) {
        throw out_of_range("Different dimentions");
    }   
    Matrix<T> res(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }     
    return res;
    }

    Matrix& operator+=(const Matrix& other)  {
        *this = *this + other;
        return *this;           
    }

    Matrix operator*(const Matrix& other) const {
        if (n != other.m) {
            throw out_of_range("Incorrect dimentions");
        }   
        Matrix<T> res(m, other.n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < other.n; j++) {
                T a = T();
                for (int k = 0; k < n; k++) {
                    a += matrix[i][k] * other.matrix[k][j];
                }
                res[i][j] = a;
            }
        }

        return res;
    }

    Matrix& operator*=(const Matrix& other) {
        *this = *this * other;
        return *this;   
    }

    friend ostream& operator<<(ostream& out, const Matrix& matr) {
        for (int i = 0; i < matr.m; i++) {
            for (int j = 0; j < matr.n; j++) {
                out << matr.matrix[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }

    friend istream& operator>>(istream& in, Matrix& matr) {
        for (int i = 0; i < matr.m; i++) {
            for (int j = 0; j < matr.n; j++) {
                in >> matr.matrix[i][j];
            }
        }
        return in;
    }
};

int main() {
    Matrix<int> A(2, 2, 1);
    Matrix<int> B(2, 2, 2);

    cout << "Matrix A:\n" << A << endl;
    cout << "Matrix B:\n" << B << endl;

    Matrix<int> C = A + B;
    cout << "A + B:\n" << C << endl;

    Matrix<int> D = A * B;
    cout << "A * B:\n" << D << endl;

    cout << "Determinant of A: " << A.det() << endl;

    return 0;
}
