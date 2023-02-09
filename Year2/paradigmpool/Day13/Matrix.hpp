/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGD13-mael1.becel
** File description:
** Matrix
*/

#ifndef MATRIX_CPP_
    #define MATRIX_CPP_

    #include "Array.hpp"

    template <unsigned int Rows, unsigned int Columns>
    class Matrix {
        public:
            Matrix() {
                for (unsigned int i = 0; i < Rows; i++) {
                    for (unsigned int j = 0; j < Columns; j++) {
                        _matrix[i][j] = 0;
                    }
                }
            };
            ~Matrix() {};
            double &operator ()(unsigned int row, unsigned int col) {return (_matrix[row][col]);};
            double operator ()(unsigned int row, unsigned int col) const {return (_matrix[row][col]);};

            template <unsigned int U, unsigned int UWU>
            Matrix<U, UWU> operator*(const Matrix<U, UWU> &matrix)
            {
                Matrix<U, UWU> result;

                for(unsigned int i = 0; i < Rows; i++) {
                    for(unsigned int j = 0; j < UWU; j++) {
                        result(i, j)=0;
                        for(unsigned int k = 0; k < Columns; k++) {
                            result(i, j) += (*this)(i, k) * matrix(k, j);
                        }
                    }
                }
                return (result);
            }

            template <unsigned int U, unsigned int UWU>
            Matrix<U, UWU> &operator*=(const Matrix<U, UWU> &matrix)
            {
                Matrix<U, UWU> result;

                for (unsigned int i = 0; i < Rows; i++) {
                    for (unsigned int j = 0; j < UWU; j++) {
                        result(i, j)=0;
                        for (unsigned int k = 0; k < Columns; k++) {
                            result(i, j) += (*this)(i, k) * matrix(k, j);
                        }
                    }
                }
                this->_matrix = result;
                return (*this);
            }

        protected:
        private:
            Array<Array<double, Columns>, Rows> _matrix;
    };

    template <unsigned int Rows, unsigned int Columns>
    std::ostream &operator<<(std::ostream &os, const Matrix<Rows, Columns> &matrix)
    {
        os << "[";
        for (unsigned int i = 0; i < Rows; i++) {
            os << "[";
            for (unsigned int j = 0; j < Columns; j++) {
                os << matrix(i, j);
                if (j != Columns - 1)
                    os << ", ";
            }
            os << "]";
            if (i != Rows - 1)
                os << ", ";
        }
        os << "]";
        return os;
    }

#endif /* !MATRIX_CPP_ */
