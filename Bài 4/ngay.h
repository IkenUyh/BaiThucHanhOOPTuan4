#ifndef CDATE_H
#define CDATE_H
#include<iostream>
#include<ctime>
#include<cmath>
#include<iomanip>
using namespace std;
class CDate{
    private:
        int ngay, thang, nam;
        int static dem;
    public:
        ~CDate();
        CDate();
        CDate(int);
        CDate(int, int);
        CDate(int, int, int);
        CDate(const CDate&);
        CDate& operator=(const CDate&);
        int GetNgay() const;
        int GetThang() const;
        int GetNam() const;
        static int GetDem();
        void SetNgay(int);
        void SetThang(int);
        void SetNam(int);
        void SetNgayThangNam(int, int, int);
        friend istream& operator>>(istream&, CDate&);
        friend ostream& operator<<(ostream&, const CDate&);
        friend CDate operator+(const CDate&, const CDate&);
        friend CDate operator+(CDate, int);
        friend CDate operator+(int, const CDate&);
        friend int operator-(const CDate&, const CDate&);
        friend CDate operator-(CDate, int);
        friend CDate operator-(int, const CDate&);
        friend CDate operator++(CDate&);
        friend CDate operator++(CDate&, int);
        friend CDate operator--(CDate&);
        friend CDate operator--(CDate&, int);
        int NgayToSoNgay() const;
        void SoNgayToNgay(int);
        void ThoiGianHienTai();
        double LaiSuatNganHang(double, double) const;
        bool KiemTraHopLe() const;
};
#endif