#include"vector.h"
int CVector::dem=0;
CVector::~CVector(){
    --dem;
    if(a!=nullptr){
        delete[] a;
        a=nullptr;
        soChieu=0;
    }
}
CVector::CVector(){
    soChieu=0;
    a=new double[1]{0};
    ++dem;
}
CVector::CVector(int soChieu){
    if(soChieu<0){
        cout<<"So chieu phai lon hon 0";
        this->soChieu=0;
        a=new double[1]{0};
    }
    else{
        this->soChieu=soChieu;
        a=new double[this->soChieu]{0};
    }
    ++dem;
}
CVector::CVector(int soChieu, double* arr){
    if(soChieu<0){
        cout<<"So chieu phai lon hon 0";
        this->soChieu=0;
        a=new double[1]{0};
    }
    else{
        this->soChieu=soChieu;
        a=new double[soChieu]{0};
        if(arr!=nullptr)
            for(int i=0; i<soChieu; i++)
                a[i]=arr[i]; 
    }
    ++dem;
}
CVector::CVector(const CVector& arr){
    soChieu=arr.soChieu;
    a=new double[soChieu];
    for(int i=0; i<soChieu; i++) a[i]=arr.a[i];
    ++dem;
}
CVector& CVector::operator=(const CVector& arr){
    if(soChieu!=arr.soChieu){
        delete[] a;
        soChieu=arr.soChieu;
        a=new double[soChieu];
    }
    for(int i=0; i<soChieu; i++) a[i]=arr.a[i];
    return *this;
}
int CVector::GetSoChieu() const{
    return this->soChieu;
}
double* CVector::GetA() const{
    return this->a;
}
int CVector::GetDem(){
    return dem;
}
void CVector::SetSoChieu(int soChieu){
    if(soChieu<0){
        cout<<"So chieu phai lon hon 0";
        return;
    }
    delete[] a;
    this->soChieu=soChieu;
    a=new double[this->soChieu]{0};
}
void CVector::SetA(const CVector& arr){
    if(soChieu!=arr.soChieu){
        delete[] a;
        soChieu=arr.soChieu;
        a=new double[soChieu];
    }
    for(int i=0; i<soChieu; i++) a[i]=arr.a[i];
}
double CVector::operator[](int chiSo) const{
    if(chiSo<0||chiSo>=soChieu){
        cout<<"Chi so nam ngoai pham vi";
        return 0;
    }
    return a[chiSo];
}
istream& operator>>(istream& in, CVector& vec){
    int soChieu;
    cout<<"Nhap so chieu: ";
    in>>soChieu;
    while(soChieu<0){
        cout<<"So chieu khong duoc am!";
        cout<<"Moi ban nhap lai"; in>>soChieu;
    }
    vec.SetSoChieu(soChieu);
    for(int i=0;i<soChieu;i++){
        cout<<"Nhap diem "<<i+1<<": ";
        in>>vec.a[i];
    }
    return in;
}
ostream& operator<<(ostream& out, const CVector& vec){
    out<<"(";
    for(int i=0;i<vec.soChieu;i++){
        out<<vec.a[i];
        if(i<vec.soChieu-1)out<<", ";
    }
    out<<")";
    return out;
}
CVector operator+(const CVector& vec1, const CVector& vec2){
    if(vec1.soChieu!=vec2.soChieu){
        cout<<"Khong cung so chieu";
        return CVector();
    }
    CVector res(vec1.soChieu);
    for(int i=0;i<vec1.soChieu;i++)
        res.a[i]=vec1.a[i]+vec2.a[i];
    return res;
}
CVector operator-(const CVector& vec1, const CVector& vec2){
    if(vec1.soChieu!=vec2.soChieu){
        cout<<"Khong cung so chieu";
        return CVector();
    }
    CVector res(vec1.soChieu);
    for(int i=0;i<vec1.soChieu;i++)
        res.a[i]=vec1.a[i]-vec2.a[i];
    return res;
}
double operator*(const CVector& vec1, const CVector& vec2){
    if(vec1.soChieu!=vec2.soChieu){
        cout<<"Khong cung so chieu";
        return 0;
    }
    double tich=0;
    for(int i=0;i<vec1.soChieu;i++) 
        tich+=vec1.a[i]*vec2.a[i];
    return tich;
}
CVector operator*(const CVector& vec, double so){
     CVector res(vec.soChieu);
    for(int i=0;i<vec.soChieu;i++) 
        res.a[i]=vec.a[i]*so;
    return res;
}
CVector operator*(double so, const CVector& vec){
    return vec*so;
}
CVector operator/(const CVector& vec, double so){
    if(abs(so)<epsilon){
        cout<<"Khong chia duoc cho 0";
        return CVector();
    }
    CVector res(vec.soChieu);
    for(int i=0;i<vec.soChieu;i++) res.a[i]=vec.a[i]/so;
    return res;
}
bool operator==(const CVector& vec1, const CVector& vec2){
    if(vec1.soChieu!=vec2.soChieu) return false;
    for(int i=0;i<vec1.soChieu;i++)
        if(abs(vec1.a[i]-vec2.a[i])>epsilon) return false;
    return true;
}
bool operator>(const CVector& vec1, const CVector& vec2){
    return vec1.DoDaiVecTor()>vec2.DoDaiVecTor();
}
bool operator<(const CVector& vec1, const CVector& vec2){
    return vec1.DoDaiVecTor()<vec2.DoDaiVecTor();
}
bool operator>=(const CVector& vec1, const CVector& vec2){
    return vec1.DoDaiVecTor()>=vec2.DoDaiVecTor();
}
bool operator<=(const CVector& vec1, const CVector& vec2){
    return vec1.DoDaiVecTor()<=vec2.DoDaiVecTor();
}
bool operator!=(const CVector& vec1, const CVector& vec2){
    return !(vec1==vec2);
}
CVector CVector::operator-() const{
    CVector res(soChieu);
    for(int i=0;i<soChieu;i++)
        res.a[i]=-a[i];
    return res;
}
bool CVector::IsZero() const{
    for(int i=0;i<soChieu;i++)
        if(abs(a[i])>epsilon)
            return false;
    return true;
}
double CVector::TichVoHuong(const CVector& other) const{
    if(soChieu!=other.soChieu){
        cout<<"Khong cung so chieu";
        return 0;
    }
    double tich=0;
    for(int i=0;i<soChieu;i++) tich+=a[i]*other.a[i];
    return tich;
}
CVector CVector::TichCoHuong(const CVector& v) const{
    if(soChieu!=3||v.soChieu!=3){
        cout<<"Tich co huong chi ap dung cho vector 3 chieu!";
        return CVector();
    }
    CVector res(3);
    res.a[0]=a[1]*v.a[2]-a[2]*v.a[1];
    res.a[1]=a[2]*v.a[0]-a[0]*v.a[2];
    res.a[2]=a[0]*v.a[1]-a[1]*v.a[0];
    return res;
}
double CVector::GocGiuaHaiVector(const CVector& other) const{
    if(soChieu!=other.soChieu){
        cout<<"Khong cung so chieu";
        return 0;
    }
    double tichVoHuong=TichVoHuong(other);
    double doDai1=DoDaiVecTor();
    double doDai2=other.DoDaiVecTor();
    if(doDai1<epsilon||doDai2<epsilon){
        cout<<"Vector khong duoc la vector 0";
        return 0;
    }
    double cosGoc=tichVoHuong/(doDai1*doDai2);
    if(cosGoc>1) cosGoc=1;
    if(cosGoc<-1) cosGoc=-1;
    return acos(cosGoc);
}
bool CVector::KiemTraCungPhuong(const CVector& other) const{
    if(soChieu!=other.soChieu){
        cout<<"Khong cung so chieu";
        return false;
    }
    if(IsZero()||other.IsZero())return true;
    double doDai1=DoDaiVecTor();
    double doDai2=other.DoDaiVecTor();
    double tichVoHuong=TichVoHuong(other);
    return abs(abs(tichVoHuong)-doDai1*doDai2)<epsilon;
}
bool CVector::KiemTraVuongGoc(const CVector& other) const{
    if(soChieu!=other.soChieu){
        cout<<"Khong cung so chieu";
        return false;
    }
    return abs(TichVoHuong(other))<epsilon;
}
CVector CVector::PhepChieuVector(const CVector& other) const{
    if(soChieu!=other.soChieu){
        cout<<"Khong cung so chieu";
        return CVector();
    }
    double doDai=other.TichVoHuong(other);
    if(doDai<epsilon){
        cout<<"Vector chieu len khong duoc la 0";
        return CVector();
    }
    double heSo=TichVoHuong(other)/doDai;
    CVector res(soChieu);
    for(int i=0;i<soChieu;i++)res.a[i]=heSo*other.a[i];
    return res;
}
double CVector::DoDaiVecTor() const{
    double sum=0;
    for(int i=0;i<soChieu;i++) sum+=a[i]*a[i];
    return sqrt(sum);
}
CVector CVector::ChuanHoa() const{
    double doDai=DoDaiVecTor();
    if(doDai<epsilon){
        cout<<"Vector khong duoc la vector 0";
        return CVector();
    }
    CVector res(soChieu);
    for(int i=0;i<soChieu;i++)
        res.a[i]=a[i]/doDai;
    return res;
}