#ifndef CVECTOR_H
#define CVECTOR_H
#include<iostream>
#include<cmath>
#include<iomanip>
#include<stdexcept>
#define epsilon 0.0000000001
#define pi 3.1415926535897932384
using namespace std;
class CVector{
    private:
        int soChieu;
        double* a;
        static int dem;
    public:
        ~CVector();
        CVector();
        CVector(int);
        CVector(int, double*);
        CVector(const CVector&);
        CVector& operator=(const CVector&);
        int GetSoChieu() const;
        double* GetA() const;
        static int GetDem();
        void SetSoChieu(int);
        void SetA(const CVector&);
        double operator[](int) const;
        friend istream& operator>>(istream&, CVector&);
        friend ostream& operator<<(ostream&, const CVector&);
        friend CVector operator+(const CVector&, const CVector&);
        friend CVector operator-(const CVector&, const CVector&);
        friend double operator*(const CVector&, const CVector&);
        friend CVector operator*(const CVector&, double);
        friend CVector operator*(double, const CVector&);
        friend CVector operator/(const CVector&, double);
        friend bool operator==(const CVector&, const CVector&);
        friend bool operator>(const CVector&, const CVector&);
        friend bool operator<(const CVector&, const CVector&);
        friend bool operator>=(const CVector&, const CVector&);
        friend bool operator<=(const CVector&, const CVector&);
        friend bool operator!=(const CVector&, const CVector&);
        CVector operator-() const;
        bool IsZero() const;
        double TichVoHuong(const CVector&) const;
        CVector TichCoHuong(const CVector&) const;
        double GocGiuaHaiVector(const CVector&) const;
        bool KiemTraCungPhuong(const CVector&) const;
        bool KiemTraVuongGoc(const CVector&) const;
        CVector PhepChieuVector(const CVector&) const;
        double DoDaiVecTor() const;
        CVector ChuanHoa() const;
};
#endif