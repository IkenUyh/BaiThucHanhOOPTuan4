#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>
using namespace std;
class CMatrix{
    private:
        int sd, sc;
        int **p;
        static int dem;
    public:
        ~CMatrix();
        CMatrix();
        CMatrix(int);
        CMatrix(int, int);
        CMatrix(int, int, int**);
        CMatrix(const CMatrix&);
        CMatrix& operator=(const CMatrix&);
        int GetSoDong() const;
        int GetSoCot() const;
        int** GetP() const;
        static int GetDem();
        void SetSoDong(int);
        void SetSoCot(int);
        void SetP(const CMatrix&);
        friend istream& operator>>(istream& in, CMatrix&);
        friend ostream& operator<<(ostream& out, const CMatrix&);
        friend CMatrix operator+(const CMatrix&, const CMatrix&);
        friend CMatrix operator+(CMatrix, double);
        friend CMatrix operator+(double, const CMatrix&);
        friend CMatrix operator-(const CMatrix&, const CMatrix&);
        friend CMatrix operator-(CMatrix, double);
        friend CMatrix operator-(double, const CMatrix&);
        friend CMatrix operator*(const CMatrix&, const CMatrix&);
        friend CMatrix operator*(const CMatrix&, int* v);
        friend CMatrix operator*(int* v, const CMatrix&);
        friend CMatrix operator*(CMatrix, double);
        friend CMatrix operator*(double, const CMatrix&);
        friend CMatrix operator/(CMatrix, double);
        friend bool operator==(const CMatrix&, const CMatrix&);
        friend bool operator>(const CMatrix&, const CMatrix&);
        friend bool operator<(const CMatrix&, const CMatrix&);
        friend bool operator>=(const CMatrix&, const CMatrix&);
        friend bool operator<=(const CMatrix&, const CMatrix&);
        friend bool operator!=(const CMatrix&, const CMatrix&);
        friend CMatrix& operator+=(CMatrix&, const CMatrix&);
        friend CMatrix& operator-=(CMatrix&, const CMatrix&);
        friend CMatrix& operator*=(CMatrix&, const CMatrix&);
        friend CMatrix& operator*=(CMatrix&, double);
        friend CMatrix& operator*=(CMatrix&, int* v);
        void PhatSinh();
        CMatrix ChuyenVi() const;
        int TinhDinhThuc() const;
        CMatrix MaTranNghichDao() const;
        int& operator()(int, int); 
        int operator()(int, int) const;
};
#endif