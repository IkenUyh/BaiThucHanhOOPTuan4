#include"ngay.h"
int CDate::dem=0;
bool NamNhuan(int n){
    return (n%4==0&&n%100!=0)||(n%400==0);
}
int SoNgayTrongThang(int thang, int nam){
    int nThang[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(thang==2&&NamNhuan(nam)) return 29;
    return nThang[thang];
}
bool CDate::KiemTraHopLe() const{
    return nam>=1&&thang>=1&&thang<=12&&ngay>=1&&ngay<=SoNgayTrongThang(thang, nam);
}
int CDate::NgayToSoNgay() const{
    int res=0;
    for(int i=1; i<nam; i++) res+=NamNhuan(i)?366:365;
    for(int i=1; i<thang; i++) res+=SoNgayTrongThang(i, nam);
    res+=ngay;
    return res;
}
void CDate::SoNgayToNgay(int songay){
    int nam=1;
    while(songay>(NamNhuan(nam)?366:365)){
        songay-=NamNhuan(nam)?366:365;
        nam++;
    }
    int thang=1;
    while(songay>SoNgayTrongThang(thang, nam)){
        songay-=SoNgayTrongThang(thang, nam);
        thang++;
    }
    int ngay=songay;
    this->ngay=ngay; this->thang=thang; this->nam=nam;
}
void CDate::ThoiGianHienTai(){
    time_t now=time(0);
    tm* ltm=localtime(&now);
    ngay=ltm->tm_mday;
    thang=ltm->tm_mon+1;
    nam=ltm->tm_year+1900;
}
CDate::~CDate(){
    --dem;
}
CDate::CDate():ngay(30), thang(4), nam(1975){
    //ngay=30; thang=4; nam=1975;
    ++dem;
}
CDate::CDate(int ngay):ngay(ngay), thang(4), nam(1975){
    //this->ngay=ngay; thang=4; nam=1975;
    if(ngay<1||ngay>SoNgayTrongThang(thang, nam)) 
    this->ngay=30;
    ++dem;
}
CDate::CDate(int ngay, int thang):ngay(ngay), thang(thang), nam(1975){
    //this->ngay=ngay; this->thang=thang; nam=1975;
    if(ngay<1||ngay>SoNgayTrongThang(thang, nam))
    this->ngay=30;
    if(thang<1||thang>12) this->thang=4;
    ++dem;
}
CDate::CDate(int ngay, int thang, int nam):ngay(ngay), thang(thang), nam(nam){
    //this->ngay=ngay; this->thang=thang; this->nam=nam;
    if(ngay<1||ngay>SoNgayTrongThang(thang, nam))
    this->ngay=30;
    if(thang<1||thang>12) this->thang=4;
    if(nam<1) this->nam=1975;

    ++dem;
}
CDate::CDate(const CDate& d){
    this->ngay=d.ngay;
    this->thang=d.thang;
    this->nam=d.nam;
    if(ngay<1||ngay>SoNgayTrongThang(thang, nam))
    this->ngay=30;
    if(thang<1||thang>12) this->thang=4;
    if(nam<1) this->nam=1975;
    ++dem;
}
CDate& CDate::operator=(const CDate& d){
    this->ngay=d.ngay;
    this->thang=d.thang;
    this->nam=d.nam;
    if(ngay<1||ngay>SoNgayTrongThang(thang, nam))
    this->ngay=30;
    if(thang<1||thang>12) this->thang=4;
    if(nam<1) this->nam=1975;
    return *this;
}
int CDate::GetNgay() const{
    return this->ngay;
}
int CDate::GetThang() const{
    return this->thang;
}
int CDate::GetNam() const{
    return this->nam;
}
int CDate::GetDem(){
    return dem;
}
void CDate::SetNgay(int ngay){
    this->ngay=ngay;
    while(!KiemTraHopLe()){
        cout<<"Ngay ban nhap khong hop le!";
        cout<<"Moi ban nhap lai: "; cin>>this->ngay;
    }
}
void CDate::SetThang(int thang){
    this->thang=thang;
    while(!KiemTraHopLe()){
        cout<<"Thang ban nhap khong hop le!";
        cout<<"MOi ban nhap lai: "; cin>>this->thang;
    }
}
void CDate::SetNam(int nam){
    this->nam=nam;
    while(!KiemTraHopLe()){
        cout<<"Nam ban nhap khong hop le!";
        cout<<"Moi ban nhap lai: "; cin>>this->nam;
    }
}
void CDate::SetNgayThangNam(int ngay, int thang, int nam){
    this->ngay=ngay; this->thang=thang; this->nam=nam;
    while(!KiemTraHopLe()){
        cout<<"Ngay thang nam ban nhap ";
        cout<<"khong hop le! Moi ban nhap lai: "<<endl;
        cout<<"Nhap ngay: "; cin>>this->ngay;
        cout<<"Nhap thang: "; cin>>this->thang;
        cout<<"Nhap nam: "; cin>>this->nam;
    }
}
istream& operator>>(istream& in, CDate& d){
    do{
        cout<<"Nhap ngay: "; in>>d.ngay;
        cout<<"Nhap thang: "; in>>d.thang;
        cout<<"Nhap nam: "; in>>d.nam;
        if(d.nam<1||d.thang<1||d.thang>12||d.ngay<1
        ||d.ngay>SoNgayTrongThang(d.thang, d.nam))
        cout<<"Ngay thang nam khong hop le! Moi ban nhap lai: "<<endl;
        
    }while(d.nam<1||d.thang<1||d.thang>12||
    d.ngay<1||d.ngay>SoNgayTrongThang(d.thang, d.nam));
    return in;
}
ostream& operator<<(ostream& out, const CDate& d){
    out<<d.ngay<<"/"<<d.thang<<"/"<<d.nam<<endl;
    return out;
}
CDate operator+(const CDate& d1, const CDate& d2){
    int songay1=d1.NgayToSoNgay();
    int songay2=d2.NgayToSoNgay();
    CDate ans;
    ans.SoNgayToNgay(songay1+songay2-1);
    return ans;
}
CDate operator+(CDate d, int songay){
    int tongngay=d.NgayToSoNgay()+songay;
    CDate ans;
    ans.SoNgayToNgay(tongngay);
    return ans;
}
CDate operator+(int songay, const CDate& d){
    return d+songay;
}
int operator-(const CDate& d1, const CDate& d2){
    return abs(d1.NgayToSoNgay()-d2.NgayToSoNgay());
}
CDate operator-(CDate d, int songay){
    int tongngay=d.NgayToSoNgay()-songay;
    CDate ans;
    ans.SoNgayToNgay(tongngay);
    return ans;
}
CDate operator-(int songay, const CDate& d){
    int tongngay=songay-d.NgayToSoNgay();
    CDate ans;
    ans.SoNgayToNgay(abs(tongngay));
    return ans;
}
CDate operator++(CDate& d){
    int songay=d.NgayToSoNgay()+1;
    d.SoNgayToNgay(songay);
    return d;
}
CDate operator++(CDate& d, int){
    CDate temp=d;
    int songay=d.NgayToSoNgay()+1;
    d.SoNgayToNgay(songay);
    return temp;
}
CDate operator--(CDate& d){
    int songay=d.NgayToSoNgay()-1;
    d.SoNgayToNgay(songay);
    return d;
}
CDate operator--(CDate& d, int){
    CDate temp=d;
    int songay=d.NgayToSoNgay()-1;
    d.SoNgayToNgay(songay);
    return temp;
}
double CDate::LaiSuatNganHang(double tiengoc, double laisuat) const{
    CDate ngayhientai;
    ngayhientai.ThoiGianHienTai();
    CDate khoangcach=ngayhientai-(*this);
    int songay=khoangcach.NgayToSoNgay();
    if(songay<=0) return 0;
    double tienlai=tiengoc*(laisuat/100)
    *(static_cast<double>(songay)/365);
    return tienlai;
}