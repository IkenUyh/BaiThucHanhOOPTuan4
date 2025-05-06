#include"matran.h"
int CMatrix::dem=0;
CMatrix::~CMatrix(){
    if(p!=nullptr) {
        for(int i=0; i<sd; i++)
            delete[] p[i];
        delete[] p;
    }
    --dem;
}
CMatrix::CMatrix():sd(0), sc(0), p(nullptr){
    //sd=sc=0; p=nullptr;
    dem++;
}
CMatrix::CMatrix(int n):sd(n), sc(n){
    //sd=sc=n;
    p=new int*[sd];
    for(int i=0; i<sd; i++)
        p[i]=new int[sc]();
    ++dem;
}
CMatrix::CMatrix(int sd, int sc):sd(sd), sc(sc){
    //this->sd=sd; this->sc=sc;
    p=new int*[sd];
    for(int i=0; i<sd; i++)
        p[i]=new int[sc]();
    ++dem;
}
CMatrix::CMatrix(int sd, int sc, int** arr){
    this->sd=sd; this->sc=sc;
    p=new int*[sd];
    for(int i=0; i<sd; i++){
        p[i]= new int[sc];
        for(int j=0; j<sc; j++){
            p[i][j]=arr[i][j];
        }
    }
    ++dem;
}
CMatrix::CMatrix(const CMatrix& a){
    this->sd=a.sd;
    this->sc=a.sc;
    p=new int*[sd];
    for(int i=0; i<sd; i++){
        p[i]=new int[sc];
        for(int j=0; j<sc; j++){
            p[i][j]=a.p[i][j];
        }
    }
    ++dem;
}
CMatrix& CMatrix::operator=(const CMatrix& a){
    if(this!=&a){
        if(p!=nullptr){
            for(int i=0; i<sd; i++){
                delete[] p[i];
            }
            delete[] p;
        }
        this->sd=a.sd;
        this->sc=a.sc;
        p=new int*[sd];
        for(int i=0; i<sd; i++){
            p[i]=new int[sc];
            for(int j=0; j<sc; j++){
                p[i][j]=a.p[i][j];
            }
        }
    }
    return *this;
}
int CMatrix::GetSoDong() const{
    return this->sd;
}
int CMatrix::GetSoCot() const{
    return this->sc;
}
int** CMatrix::GetP() const{
    return this->p;
}
int CMatrix::GetDem(){
    return dem;
}
void CMatrix::SetSoDong(int sd){
    this->sd=sd;
}
void CMatrix::SetSoCot(int sc){
    this->sc=sc;
}
void CMatrix::SetP(const CMatrix& a){
    if(p!=nullptr){
        for(int i=0; i<sd; i++){
            delete[] p[i];
        }
        delete[] p;
    }
    this->sd=a.sd;
    this->sc=a.sc;
    p=new int*[sd];
    for(int i=0; i<sd; i++){
        p[i]=new int[sc];
        for(int j=0; j<sc; j++){
            p[i][j]=a.p[i][j];
        }
    }
}
istream& operator>>(istream& in, CMatrix& mt){
    cout<<"Nhap so dong: "; in>>mt.sd;
    cout<<"Nhap so cot: "; in>>mt.sc;
    if(mt.sd<=0||mt.sc<=0){
        cout<<"So dong va so cot phai lon hon 0!"<<endl;
        mt.sd=mt.sc=0;
        mt.p=nullptr;
        return in;
    }
    if(mt.p!=nullptr){
        for(int i=0; i<mt.sd; i++)
            delete[] mt.p[i];
        delete[] mt.p;
    }
    mt.p=new int*[mt.sd];
    for(int i=0; i<mt.sd; i++)
        mt.p[i]=new int[mt.sc]();
    for(int i=0; i<mt.sd; i++){
        for(int j=0; j<mt.sc; j++){
            cout<<"p["<<i<<"]["<<j<<"] = ";
            in>>mt.p[i][j];
        }
    }
    return in;
}
ostream& operator<<(ostream& out, const CMatrix& mt){
    out<<endl;
    for(int i=0; i<mt.sd; i++){
        for(int j=0; j<mt.sc; j++){
            out<<mt.p[i][j]<<" ";
        }
        out<<endl;
    }
    return out;
}
CMatrix operator+(const CMatrix& mt1, const CMatrix& mt2){
    if(mt1.sd!=mt2.sd||mt1.sc!=mt2.sc){
        return CMatrix();
    }
    CMatrix res(mt1.sd, mt1.sc);
    for(int i=0; i<mt1.sd; i++){
        for(int j=0; j<mt1.sc; j++){
            res.p[i][j]=mt1.p[i][j]+mt2.p[i][j];
        }
    }
    return res;
}
CMatrix operator+(CMatrix mt, double k){
    CMatrix res(mt.sd, mt.sc);
    for(int i=0; i<mt.sd; i++){
        for(int j=0; j<mt.sc; j++){
            res.p[i][j]=mt.p[i][j]+(int)k;
        }
    }
    return res;
}
CMatrix operator+(double k, const CMatrix& mt){
    return mt+k;
}
CMatrix operator-(const CMatrix& mt1, const CMatrix& mt2){
    if(mt1.sd!=mt2.sd||mt1.sc!=mt2.sc){
        return CMatrix();
    }
    CMatrix res(mt1.sd, mt1.sc);
    for(int i=0; i<mt1.sd; i++){
        for(int j=0; j<mt1.sc; j++){
            res.p[i][j]=mt1.p[i][j]-mt2.p[i][j];
        }
    }
    return res;
}
CMatrix operator-(CMatrix mt, double k){
    CMatrix res(mt.sd, mt.sc);
    for(int i=0; i<mt.sd; i++){
        for(int j=0; j<mt.sc; j++){
            res.p[i][j]=mt.p[i][j]-(int)k;
        }
    }
    return res;
}
CMatrix operator-(double k, const CMatrix& mt){
    CMatrix res(mt.sd, mt.sc);
    for(int i=0; i<mt.sd; i++){
        for(int j=0; j<mt.sc; j++){
            res.p[i][j]=(int)k-mt.p[i][j];
        }
    }
    return res;
}
CMatrix operator*(const CMatrix& mt1, const CMatrix& mt2){
    if(mt1.sc!=mt2.sd) {
        return CMatrix();
    }
    CMatrix res(mt1.sd, mt2.sc);
    for(int i=0; i<mt1.sd; i++){
        for(int j=0; j<mt2.sc; j++){
            for(int k=0; k<mt1.sc; k++){
                res.p[i][j]+=mt1.p[i][k]*mt2.p[k][j];
            }
        }
    }
    return res;
}
CMatrix operator*(const CMatrix& mt, int* v){
    CMatrix res(mt.sd, 1);
    for(int i=0; i<mt.sd; i++){
        res.p[i][0]=0;
        for(int k=0; k<mt.sc; k++){
            res.p[i][0]+=mt.p[i][k]*v[k];
        }
    }
    return res;
}
CMatrix operator*(int* v, const CMatrix& mt){
    CMatrix res(1, mt.sc);
    for(int j=0; j<mt.sc; j++){
        res.p[0][j]=0;
        for(int k=0; k<mt.sd; k++){
            res.p[0][j]+=v[k]*mt.p[k][j];
        }
    }
    return res;
}
CMatrix operator*(CMatrix mt, double k){
    CMatrix res(mt.sd, mt.sc);
    for(int i=0; i<mt.sd; i++){
        for(int j=0; j<mt.sc; j++){
            res.p[i][j]=mt.p[i][j]*(int)k;
        }
    }
    return res;
}
CMatrix operator*(double k, const CMatrix& mt){
    return mt*k;
}
CMatrix operator/(CMatrix mt, double k){
    if(!k){
        cout<<"Loi chia cho so 0!"<<endl;
        return CMatrix();
    } 
    CMatrix res(mt.sd, mt.sc);
    for(int i=0; i<mt.sd; i++){
        for(int j=0; j<mt.sc; j++){
            res.p[i][j]=mt.p[i][j]/(int)k;
        }
    }
    return res;
}
bool operator==(const CMatrix& mt1, const CMatrix& mt2){
    if(mt1.sd!=mt2.sd||mt1.sc!=mt2.sc){
        cout<<"Khong the so sanh: Kich thuoc ma tran khong giong nhau!"<<endl;
        return false;
    }
    for(int i=0; i<mt1.sd; i++){
        for(int j=0; j<mt1.sc; j++){
            if(mt1.p[i][j]!=mt2.p[i][j]) return false;
        }
    }
    return true;
}
bool operator>(const CMatrix& mt1, const CMatrix& mt2){
    if(mt1.sd!=mt2.sd||mt1.sc!=mt2.sc){
        cout<<"Khong the so sanh: Kich thuoc ma tran khong giong nhau!"<<endl;
        return false;
    } 
    int sum1=0, sum2=0;
    for(int i=0; i<mt1.sd; i++){
        for(int j=0; j<mt1.sc; j++){
            sum1+=mt1.p[i][j];
            sum2+=mt2.p[i][j];
        }
    }
    return sum1>sum2;
}
bool operator<(const CMatrix& mt1, const CMatrix& mt2){
    if(mt1.sd!=mt2.sd||mt1.sc!=mt2.sc){
        cout<<"Khong the so sanh: Kich thuoc ma tran khong giong nhau!"<<endl;
        return false;
    } 
    int sum1=0, sum2=0;
    for(int i=0; i<mt1.sd; i++){
        for(int j=0; j<mt1.sc; j++){
            sum1+=mt1.p[i][j];
            sum2+=mt2.p[i][j];
        }
    }
    return sum1<sum2;
}
bool operator>=(const CMatrix& mt1, const CMatrix& mt2){
    return(mt1>mt2)||(mt1 == mt2);
}
bool operator<=(const CMatrix& mt1, const CMatrix& mt2){
    return(mt1<mt2)||(mt1 == mt2);
}
bool operator!=(const CMatrix& mt1, const CMatrix& mt2){
    return !(mt1==mt2);
}
void CMatrix::PhatSinh(){
    if(p==nullptr||sd <= 0||sc<=0){
        cout<<"Ma tran chua duoc khoi tao hop le!"<<endl;
        return;
    }
    srand(time(0));
    for(int i=0; i<sd; i++){
        for(int j=0; j<sc; j++){
            p[i][j]=rand()%100+1; 
        }
    }
}
int& CMatrix::operator()(int i, int j){
    static int dummy=0;
    if(i>=0&&i<sd&&j>=0&&j<sc) 
        return p[i][j];
    cout<<"Chi so khong hop le"<<endl;
    return dummy;
}
int CMatrix::operator()(int i, int j) const{
    if(i>=0&&i<sd&&j>=0&&j<sc) 
        return p[i][j];
    cout<<"Chi so khong hop le"<<endl;
    return 0;
}
CMatrix& operator+=(CMatrix& mt1, const CMatrix& mt2){
    if(mt1.sd!=mt2.sd||mt1.sc!=mt2.sc) {
        cout<<"Kich thuoc ma tran khong giong nhau";
        return mt1;
    }
    for(int i=0; i<mt1.sd; i++){
        for(int j=0; j<mt1.sc; j++){
            mt1.p[i][j]+=mt2.p[i][j];
        }
    }
    return mt1;
}
CMatrix& operator-=(CMatrix& mt1, const CMatrix& mt2){
    if(mt1.sd!=mt2.sd||mt1.sc!=mt2.sc) {
        cout<<"Kich thuoc ma tran khong giong nhau";
        return mt1;
    }
    for(int i=0; i<mt1.sd; i++){
        for(int j=0; j<mt1.sc; j++){
            mt1.p[i][j]-=mt2.p[i][j];
        }
    }
    return mt1;
}
CMatrix& operator*=(CMatrix& mt1, const CMatrix& mt2){
    if(mt1.sc!=mt2.sd) {
        cout<<"Kich thuoc ma tran khong giong nhau";
        return mt1;
    }
    CMatrix temp(mt1.sd, mt2.sc);
    for(int i=0; i<mt1.sd; i++){
        for(int j=0; j<mt2.sc; j++){
            for(int k=0; k<mt1.sc; k++){
                temp.p[i][j]+=mt1.p[i][k]*mt2.p[k][j];
            }
        }
    }
    mt1=temp;
    return mt1;
}
CMatrix& operator*=(CMatrix& mt, double k){
    for(int i=0; i<mt.sd; i++){
        for(int j=0; j<mt.sc; j++){
            mt.p[i][j]*=(int)k;
        }
    }
    return mt;
}
CMatrix& operator*=(CMatrix& mt, int* v){
    CMatrix temp=mt*v;
    mt=temp;
    return mt;
}
CMatrix CMatrix::ChuyenVi() const{
    CMatrix res(sc, sd); 
    for(int i=0; i<sd; i++){
        for(int j=0; j<sc; j++){
            res.p[j][i]=p[i][j];
        }
    }
    return res;
}
int CMatrix::TinhDinhThuc() const{
    if(sd!=sc){
        cout<<"Ma tran phai la ma tran vuong";
        return 0;
    }
    if(sd==1){
        return p[0][0];
    }
    if(sd==2){
        return p[0][0]*p[1][1]-p[0][1]*p[1][0];
    }
    int det=0;
    for(int j=0; j<sc; j++){
        CMatrix temp(sd-1, sc-1);
        for(int r=1; r<sd; r++){
            int tempidx=0;
            for(int c=0; c<sc; c++){
                if(c!=j){
                    temp.p[r-1][tempidx++]=p[r][c];
                }
            }
        }
        det+=(j%2==0?1:-1)*p[0][j]*temp.TinhDinhThuc();
    }
    return det;
}
CMatrix CMatrix::MaTranNghichDao() const{
    if(sd!=sc){
        cout<<"Ma tran phai la ma tran vuong";
        return CMatrix();
    }
    int det=TinhDinhThuc();
    if(det==0){
        cout<<"Ma tran khong the dao nguoc";
        return CMatrix();
    }
    CMatrix adj(sd, sc); 
    for(int i=0; i<sd; i++){
        for(int j=0; j<sc; j++){
            CMatrix temp(sd-1, sc-1);
            for(int r=0; r<sd; r++){
                if(r==i) continue;
                int temphang=(r < i)?r:r-1;
                int tempcot=0;
                for(int c=0; c<sc; c++){
                    if(c==j) continue;
                    temp.p[temphang][tempcot++]=p[r][c];
                }
            }
            adj.p[j][i]=((i + j)%2==0?1:-1)*temp.TinhDinhThuc();
        }
    }
    CMatrix nghichdao=adj/(double)det;
    return nghichdao;
}