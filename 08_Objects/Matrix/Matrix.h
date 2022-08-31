#pragma once

class Matrix
{
public:
    Matrix();
    Matrix(const double &A, const double &B, const double &C, const double &D);
    ~Matrix() = default;

    void print_matrix() const;

    double get_A() const;
    double get_B() const;
    double get_C() const;
    double get_D() const;

    void set_A(const double &new_A);
    void set_B(const double &new_B);
    void set_C(const double &new_C);
    void set_D(const double &new_D);

private:
    double m_A;
    double m_B;
    double m_C;
    double m_D;
};
