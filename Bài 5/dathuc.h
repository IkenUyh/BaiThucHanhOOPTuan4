#ifndef CDATHUC_H
#define CDATHUC_H
#include<iostream>
#include<cmath>
using namespace std;
class cDaThuc{
    private:
        int n; 
        double* heSo;
        static int dem;
    public:
        ~cDaThuc();
        cDaThuc();
        cDaThuc(int);
        cDaThuc(int, double*);
        cDaThuc(const cDaThuc&);
        cDaThuc& operator=(const cDaThuc&);
        int GetN() const;
        double* GetHeSo() const;
        static int GetDem();
        void SetN(int);
        void SetHeSo(const cDaThuc&);
        friend istream& operator>>(istream& in, cDaThuc&);
        friend ostream& operator<<(ostream& out, const cDaThuc&);
        friend cDaThuc operator+(const cDaThuc&, const cDaThuc&);
        friend cDaThuc operator-(const cDaThuc&, const cDaThuc&);
        friend cDaThuc operator*(const cDaThuc&, const cDaThuc&);
        friend cDaThuc operator/(const cDaThuc&, const cDaThuc&);
        friend cDaThuc operator%(const cDaThuc&, const cDaThuc&);
        friend bool operator==(const cDaThuc&, const cDaThuc&);
        friend bool operator>(const cDaThuc&, const cDaThuc&);
        friend bool operator<(const cDaThuc&, const cDaThuc&);
        friend bool operator>=(const cDaThuc&, const cDaThuc&);
        friend bool operator<=(const cDaThuc&, const cDaThuc&);
        friend bool operator!=(const cDaThuc&, const cDaThuc&);
        cDaThuc DaoHam() const;
        cDaThuc TichPhan() const;
        void ToiGian();
        double TinhGiaTri(double) const;
};
#endif