#include"time.h"
int CTime::dem=0;
bool CTime::KiemTraHopLe(){
    return gio>=0&&gio<24&&phut>=0&&phut<60&&giay>=0&&giay<60;
}
void gotoxy(int x, int y){
    printf("\033[%d;%dH", y + 1, x + 1); 
}
void clearScreen(){
    printf("\033[2J");
}
void displayClock() {
    CTime t;
    while(true){
        t.ThoiGianHienTai();
        clearScreen();
        gotoxy(60, 0); 
        cout<<t<<"  ";
        cout.flush();
        sleep(1); 
    }
}
CTime::~CTime(){
    --dem;
}
CTime::CTime():gio(0), phut(0), giay(0){
    //gio=phut=giay=0;
    ++dem;
}
CTime::CTime(int giay):gio(0), phut(0), giay(giay){
    //gio=phut=0; this->giay=giay;
    if(giay<0||giay>=60) this->giay=0;
    ++dem;
}
CTime::CTime(int phut, int giay):gio(0), phut(phut), giay(giay){
    //gio=0; this->phut=phut; this->giay=giay;
    if(phut<0||phut>=60) this->phut=0;
    if(giay<0||giay>=60) this->giay=0;
    ++dem;
}
CTime::CTime(int gio, int phut, int giay):gio(gio), phut(phut), giay(giay){
    //this->gio=gio; this->phut=phut; this->giay=giay;
    if(gio<0||gio>=24) this->gio=0;
    if(phut<0||phut>=60) this->phut=0;
    if(giay<0||giay>=60) this->giay=0;
    ++dem;
}
CTime::CTime(const CTime& tg){
    this->gio=tg.gio;
    this->phut=tg.phut;
    this->giay=tg.giay;
    if(gio<0||gio>=24) this->gio=0;
    if(phut<0||phut>=60) this->phut=0;
    if(giay<0||giay>=60) this->giay=0;
    ++dem;
}
CTime& CTime::operator=(const CTime& tg){
    this->gio=tg.gio; 
    this->phut=tg.phut;
    this->giay=tg.giay;
    if(gio<0||gio>=24) this->gio=0;
    if(phut<0||phut>=60) this->phut=0;
    if(giay<0||giay>=60) this->giay=0;
    return *this;
}
int CTime::GetGio() const{
    return this->gio;
}
int CTime::GetPhut() const{
    return this->phut;
}
int CTime::GetGiay() const{
    return this->giay;
}
int CTime::GetDem(){
    return dem;
}
void CTime::SetGio(int gio){
    this->gio=gio;
    while(!KiemTraHopLe()){
        cout<<"Gio ban nhap khong hop le!";
        cout<<"Moi ban nhap lai: "; cin>>this->gio;
    }
}
void CTime::SetPhut(int phut){
    this->phut=phut;
    while(!KiemTraHopLe()){
        cout<<"Phut ban nhap khong hop le!";
        cout<<"Moi ban nhap lai: "; cin>>this->phut;
    }
}
void CTime::SetGiay(int giay){
    this->giay=giay;
    while(!KiemTraHopLe()){
        cout<<"Giay ban nhap khong hop le!";
        cout<<"Moi ban nhap lai: "; cin>>this->giay;
    }
}
void CTime::SetGioPhutGiay(int gio, int phut, int giay){
    this->gio=gio; this->phut=phut; this->giay=giay;
    while(!KiemTraHopLe()){
        cout<<"Thoi gian ban nhap khong hop le!";
        cout<<"Moi ban nhap lai"<<endl; 
        cout<<"Nhap gio: "; cin>>this->gio;
        cout<<"Nhap phut: "; cin>>this->phut;
        cout<<"Nhap giay: "; cin>>this->giay;
    }
}
istream& operator>>(istream& in, CTime& tg){
    cout<<"Nhap gio: "; in>>tg.gio;
    while(tg.gio<0||tg.gio>=24){
        cout<<"Gio ban nhap khong hop le!";
        cout<<"Moi ban nhap lai: "; in>>tg.gio;
    }
    cout<<"Nhap phut: "; in>>tg.phut;
    while(tg.phut<0||tg.phut>=60){
        cout<<"Phut ban nhap khong hop le!";
        cout<<"Moi ban nhap lai: "; in>>tg.phut;
    }
    cout<<"Nhap giay: "; in>>tg.giay;
    while(tg.giay<0||tg.giay>=60){
        cout<<"Giay ban nhap khong hop le!";
        cout<<"Moi ban nhap lai: "; in>>tg.giay;
    }
    return in;
}
ostream& operator<<(ostream& out, const CTime& tg){
    out<<(tg.gio<10?"0":"")<<tg.gio<<":";
    out<<(tg.phut<10?"0":"")<<tg.phut<<":";
    out<<(tg.giay<10?"0":"")<<tg.giay;
    return out;
}
CTime operator+(const CTime& tg1, const CTime& tg2){
    CTime res;
    res.giay=tg1.giay+tg2.giay;
    res.phut=tg1.phut+tg2.phut;
    res.gio=tg1.gio+tg2.gio;
    while(res.giay>59){
        res.giay-=60;
        res.phut++;
    }
    while(res.phut>59){
        res.phut-=60;
        res.gio++;
    }
    if(res.gio>23){
        res.gio%=24;
    }
    return res;
}
CTime operator+(CTime tg, int giay){
    tg.giay+=giay;
    while(tg.giay>59){
        tg.giay-=60;
        tg.phut++;
        if(tg.phut>59){
            tg.phut=0;
            tg.gio++;
            if(tg.gio>=24) tg.gio=0;
        }
    }
    return tg;
}
CTime operator+(int giay,const CTime& tg){
    return tg+giay;
}
CTime operator-(const CTime& tg1, const CTime& tg2){
    CTime res;
    int tonggiay1=tg1.gio*3600+tg1.phut*60+tg1.giay;
    int tonggiay2=tg2.gio*3600+tg2.phut*60+tg2.giay;
    int hieugiay=tonggiay1-tonggiay2;
    if(hieugiay<0) hieugiay+=24*3600;
    res.gio=hieugiay/3600;
    hieugiay%=3600;
    res.phut=hieugiay/60;
    res.giay=hieugiay%60;
    return res;
}
CTime operator-(CTime tg, int giay){
    int tonggiay=tg.gio*3600+tg.phut*60+tg.giay;
    tonggiay-=giay;
    if(tonggiay<0) tonggiay+=24*3600;
    tg.gio=tonggiay/3600;
    tonggiay%=3600;
    tg.phut=tonggiay/60;
    tg.giay=tonggiay%60;
    return tg;
}
CTime operator-(int giay,const CTime& tg){
    CTime kq(0, 0, giay);
    return kq-tg;
}
CTime operator++(CTime& tg){
    if(tg.giay<59) tg.giay++;
    else{
        tg.giay=0;
        if(tg.phut==59){
            tg.phut=0;
            if(tg.gio==23) tg.gio=0;
            else tg.gio++;
        }
        else tg.phut++;
    }
    return tg;
}
CTime operator++(CTime& tg, int){
    CTime temp=tg;
    if(tg.giay<59) tg.giay++;
    else{
        tg.giay=0;
        if(tg.phut==59){
            tg.phut=0;
            if(tg.gio==23) tg.gio=0;
            else tg.gio++;
        }
        else tg.phut++;
    }
    return temp;
}
CTime operator--(CTime& tg){
    if(!tg.gio&&!tg.phut&&!tg.giay){
        cout<<"Khong the giam xuong duoi";
        return tg;
    }
    if(tg.giay>0) tg.giay--;
    else{
        tg.giay=59;
        if(tg.phut==0){
            tg.phut=59;
            tg.gio--;
        }
        else tg.phut--;
    }
    return tg;
}
CTime operator--(CTime& tg, int){
    CTime temp=tg;
    if(!tg.gio&&!tg.phut&&!tg.giay){
        cout<<"Khong the giam xuong duoi";
        return temp;
    }
    if(tg.giay>0) tg.giay--;
    else{
        tg.giay=59;
        if(tg.phut==0){
            tg.phut=59;
            tg.gio--;
        }
        else tg.phut--;
    }
    return temp;
}
void CTime::ThoiGianHienTai(){
    time_t now=time(0);
    tm* ltm=localtime(&now);
    gio=ltm->tm_hour;
    phut=ltm->tm_min;
    giay=ltm->tm_sec;
}
