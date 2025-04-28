#include"dathuc.h"
int cDaThuc::dem=0;
cDaThuc::~cDaThuc(){
    --dem;
    if(heSo!=nullptr){
        delete[] heSo;
        heSo=nullptr;
        n=0;
    }
}
cDaThuc::cDaThuc(){
    n=0;
    heSo=new double[1]{0};
    ++dem;
}
cDaThuc::cDaThuc(int n){
    if(n<0){
        this->n=0;
        heSo=new double[1]{0};
    }
    else{
        this->n=n;
        heSo=new double[this->n+1]{0};
    }
    ++dem;
}
cDaThuc::cDaThuc(int n, double* hs){
    this->n=n;
    heSo=new double[this->n+1];
    for(int i=0; i<=n; i++) heSo[i]=hs[i];
    ++dem;
}
cDaThuc::cDaThuc(const cDaThuc& dt){
    n=dt.n;
    heSo=new double[n+1];
    for(int i=0; i<=n; i++) heSo[i]=dt.heSo[i];
    ++dem;
}
int cDaThuc::GetN() const{
    return this->n;
}
double* cDaThuc::GetHeSo() const{
    return this->heSo;
}
int cDaThuc::GetDem(){
    return dem;
}
void cDaThuc::SetN(int n){
    delete[] heSo;
    this->n=n;
    heSo=new double[this->n+1]{0};
}
void cDaThuc::SetHeSo(const cDaThuc& dt){
    if(n!=dt.n){
        delete[] heSo;
        n=dt.n;
        heSo=new double[n+1];
    }
    for(int i=0; i<=n; i++) heSo[i]=dt.heSo[i];
}
cDaThuc& cDaThuc::operator=(const cDaThuc& dt){
    if(n!=dt.n){
        delete[] heSo;
        n=dt.n;
        heSo=new double[n+1];
    }
    for(int i=0; i<=n; i++) heSo[i]=dt.heSo[i];
    return *this;
}
istream& operator>>(istream& in, cDaThuc& dt){
    cout<<"Nhap bac cua da thuc: "; in>>dt.n;
    delete[] dt.heSo;
    dt.heSo=new double[dt.n+1];
    for(int i=dt.n; i>=0; i--){
        cout<<"Nhap he so a"<<i<<": ";
        in>>dt.heSo[i];
    }
    return in;
}
ostream& operator<<(ostream& out, const cDaThuc& dt){
    out<<"P(x) = ";
    bool fi=true;
    for(int i=dt.n; i>=0; i--){
        if(dt.heSo[i]){
            if(!fi&&dt.heSo[i]>0) out<<" + ";
            if(dt.heSo[i]<0) out<<" - ";
            if(abs(dt.heSo[i])!=1||i==0) out<<abs(dt.heSo[i]);
            if(i>0) out<<"x";
            if(i>1) out<<"^"<<i;
            fi=false;
        }
    }
    if(fi) out<<"0";
    out<<endl;
    return out;
}
cDaThuc operator+(const cDaThuc& dt1, const cDaThuc& dt2){
    int BacMax=max(dt1.n, dt2.n);
    cDaThuc sum(BacMax);
    for(int i=0; i<=BacMax; i++){
        double hs1=(i<=dt1.n)?dt1.heSo[i]:0;
        double hs2=(i<=dt2.n)?dt2.heSo[i]:0;
        sum.heSo[i]=hs1+hs2;
    }
    return sum;
}
cDaThuc operator-(const cDaThuc& dt1, const cDaThuc& dt2){
    int BacMax=max(dt1.n, dt2.n);
    cDaThuc tru(BacMax);
    for(int i=0; i<=BacMax; i++){
        double hs1=(i<=dt1.n)?dt1.heSo[i]:0;
        double hs2=(i<=dt2.n)?dt2.heSo[i]:0;
        tru.heSo[i]=hs1-hs2;
    }
    return tru;
}
cDaThuc operator*(const cDaThuc& dt1, const cDaThuc& dt2){
    int n=dt1.n+dt2.n;
    cDaThuc res(n);
    for(int i=0; i<=n; i++) res.heSo[i]=0;
    for(int i=0; i<=dt1.n; i++){
        for(int j=0; j<=dt2.n; j++){
            res.heSo[i+j]+=dt1.heSo[i]*dt2.heSo[j];
        }
    }
    return res;
}
cDaThuc operator/(const cDaThuc& dt1, const cDaThuc& dt2){
    bool check=true;
    for(int i=0; i<=dt2.n; i++){
        if(dt2.heSo[i]){
            check=false;
            break;
        }
    }
    if(check){
        cout<<"Loi! Khong the chia cho da thuc 0"<<endl;
        return cDaThuc();
    }
    if(dt1.n<dt2.n) return cDaThuc();
    cDaThuc dividend=dt1;
    int n=dt1.n-dt2.n;
    cDaThuc res(n);
    for(int i=n; i>=0; i--){
        double heso=dividend.heSo[i+dt2.n]/dt2.heSo[dt2.n];
        res.heSo[i]=heso;
        for(int j=0; j<=dt2.n; j++)
            dividend.heSo[i+j]-=heso*dt2.heSo[j];
    }
    return res;
}
cDaThuc operator%(const cDaThuc& dt1, const cDaThuc& dt2){
    bool check=true;
    for(int i=0; i<=dt2.n; i++){
        if(dt2.heSo[i]){
            check=false;
            break;
        }
    }
    if(check){
        cout<<"Loi! Khong the chia cho da thuc 0"<<endl;
        return cDaThuc();
    }
    if(dt1.n<dt2.n) return dt1;
    cDaThuc dividend=dt1;
    int n=dt1.n-dt2.n;
    for(int i=n; i>=0; i--){
        double heso=dividend.heSo[i+dt2.n]/dt2.heSo[dt2.n];
        for(int j=0; j<=dt2.n; j++)
            dividend.heSo[i+j]-=heso*dt2.heSo[j];
    }
    int BacDu=dt2.n-1;
    while(BacDu>=0&&abs(dividend.heSo[BacDu])<1e-10) BacDu--;
    if(BacDu<0) return cDaThuc();
    cDaThuc res(BacDu);
    for(int i=0; i<=BacDu; i++) res.heSo[i]=dividend.heSo[i];
    return res;
}
bool operator==(const cDaThuc& dt1, const cDaThuc& dt2){
    int BacMax=max(dt1.n, dt2.n);
    for(int i=0; i<=BacMax; i++){
        double hs1=(i<=dt1.n)?dt1.heSo[i]:0;
        double hs2=(i<=dt2.n)?dt2.heSo[i]:0;
        if(abs(hs1-hs2)>1e-10) return false;
    }
    return true;
}
bool operator>(const cDaThuc& dt1, const cDaThuc& dt2){
    int BacMax=max(dt1.n, dt2.n);
    for(int i=BacMax; i>=0; i--){
        double hs1=(i<=dt1.n)?dt1.heSo[i]:0;
        double hs2=(i<=dt2.n)?dt2.heSo[i]:0;
        if(abs(hs1-hs2)>1e-10) return hs1>hs2;
    }
    return false;
}
bool operator<(const cDaThuc& dt1, const cDaThuc& dt2){
    int BacMax=max(dt1.n, dt2.n);
    for(int i=BacMax; i>=0; i--){
        double hs1=(i<=dt1.n)?dt1.heSo[i]:0;
        double hs2=(i<=dt2.n)?dt2.heSo[i]:0;
        if(abs(hs1-hs2)>1e-10) return hs1<hs2;
    }
    return false;
}
bool operator>=(const cDaThuc& dt1, const cDaThuc& dt2){
    return dt1>dt2||dt1==dt2;
}
bool operator<=(const cDaThuc& dt1, const cDaThuc& dt2){
    return dt1<dt2||dt1==dt2;
}
bool operator!=(const cDaThuc& dt1, const cDaThuc& dt2){
    return !(dt1==dt2);
}
cDaThuc cDaThuc::DaoHam() const{
    if(!n) return cDaThuc();
    cDaThuc res(n-1);
    for(int i=1; i<=n; i++)
        res.heSo[i-1]=heSo[i]*i;
    return res;
}
cDaThuc cDaThuc::TichPhan() const{
    cDaThuc res(n+1);
    res.heSo[0]=0;
    for(int i=0; i<=n; i++)
        res.heSo[i+1]=heSo[i]/(i+1);
    return res;
}
void cDaThuc::ToiGian(){
    int BacThuc=n;
    while(BacThuc>0&&abs(heSo[BacThuc])<1e-10)
        BacThuc--;
    if(BacThuc!=n){
        double* heSoMoi=new double[BacThuc+1];
        for(int i=0; i<=BacThuc; i++)
            heSoMoi[i]=heSo[i];
        delete[] heSo;
        heSo=heSoMoi;
        n=BacThuc;
    }
}
double cDaThuc::TinhGiaTri(double x) const{
    double res=0;
    for(int i=0; i<=n; i++)
        res+=heSo[i]*pow(x, i);
    return res;
}