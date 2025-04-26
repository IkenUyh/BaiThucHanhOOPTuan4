#ifndef CTIME_H
#define CTIME_H
#include<iostream>
#include<unistd.h>
#include<ctime>
using namespace std;
class CTime{
    private:
        int gio, phut, giay;
        static int dem;
    public:
        ~CTime();
        CTime();
        CTime(int);
        CTime(int, int);
        CTime(int, int, int);
        CTime(const CTime&);
        CTime& operator=(const CTime&);
        int GetGio() const;
        int GetPhut() const;
        int GetGiay() const;
        static int GetDem();
        void SetGio(int);
        void SetPhut(int);
        void SetGiay(int);
        void SetGioPhutGiay(int, int, int);
        friend istream& operator>>(istream&, CTime&);
        friend ostream& operator<<(ostream&, const CTime&);
        friend CTime operator+(const CTime&, const CTime&);
        friend CTime operator+(CTime, int);
        friend CTime operator+(int, const CTime&);
        friend CTime operator-(const CTime&, const CTime&);
        friend CTime operator-(CTime, int);
        friend CTime operator-(int, const CTime&);
        friend CTime operator++(CTime&);
        friend CTime operator++(CTime&, int);
        friend CTime operator--(CTime&);
        friend CTime operator--(CTime&, int);
        void ThoiGianHienTai();
        bool KiemTraHopLe();
};
#endif