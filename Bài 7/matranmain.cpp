#include"matran.cpp"
int main(){
    cout<<"\n===== CHUONG TRINH MINH HOA LOP CMATRIX =====\n";
    int arr1[2][3]={{1, 2, 3}, {4, 5, 6}};
    int arr2[2][3]={{7, 8, 9}, {10, 11, 12}};
    int arr3[2][3]={{0, 0, 0}, {0, 0, 0}};
    int** p1=new int*[2];
    int** p2=new int*[2];
    int** p3 = new int*[2];
    for(int i=0; i<2; i++){
        p1[i]= new int[3];
        p2[i]= new int[3];
        p3[i]= new int[3];
        for(int j=0; j<3; j++){
            p1[i][j]=arr1[i][j];
            p2[i][j]=arr2[i][j];
            p3[i][j]=arr3[i][j];
        }
    }
    CMatrix m1(2, 3, p1);
    CMatrix m2(2, 3, p2);
    CMatrix m3(2, 3, p3);
    CMatrix m4;
    cout<<"Matrix m1: "<<m1<<endl;
    cout<<"Matrix m2: "<<m2<<endl;
    cout<<"Matrix m3: "<<m3<<endl;
    cout<<"Matrix m4: "<<m4<<endl;  
    for(int i=0; i<2; i++){
        delete[] p1[i];
        delete[] p2[i];
        delete[] p3[i];
    }
    delete[] p1;
    delete[] p2;
    delete[] p3;
    cout<<"\n===== CAC PHEP TOAN CO BAN =====\n";
    cout<<"Nhap lan luot 2 ma tran\n";
    cout<<"Nhap ma tran thu nhat:\n";
    cin>>m1;
    cout<<"Nhap ma tran thu hai:\n";
    cin>>m2;
    cout<<"Tong hai ma tran: "<<(m1+m2)<<endl;
    cout<<"Hieu hai ma tran: "<<(m1-m2)<<endl;
    double x;
    cout<<"Nhap gia tri x: ";
    cin>>x;
    cout<<"Tich ma tran thu nhat voi x: "<<(m1*x)<<endl;
    cout<<"Thuong ma tran thu hai voi x: "<<(m2/x)<<endl;
    cout<<"\n===== CAC PHEP SO SANH =====\n";
    cout<<"Ma tran thu nhat bang ma tran thu hai: "<<(m1==m2?"true":"false")<<endl;
    cout<<"Ma tran thu nhat khac ma tran thu hai: "<<(m1!=m2?"true":"false")<<endl;
    cout<<"Ma tran thu nhat nho hon ma tran thu hai (so sanh tong phan tu): "
    <<(m1<m2?"true":"false")<<endl;
    cout<<"\n===== CAC PHUONG THUC KHAC =====\n";
    cout<<"Nhap ma tran thu 3:\n";
    cin>>m3;
    cout<<"Ma tran thu ba: "<<m3<<endl;
    CMatrix m5; m5.PhatSinh();
    cout<<"Ma tran ngau nhien 5: "<<m5<<endl;
    cout<<"Chuyen vi cua ma tran thu nhat: "<<m1.ChuyenVi()<<endl;
    cout<<"\n===== CAC PHEP TOAN NANG CAO =====\n";
    cout<<"Nhap ma tran de nhan voi ma tran thu nhat:\n";
    CMatrix m6; cin>>m6;
    cout<<"Ma tran thu nhat nhan voi ma tran vua nhap: "<<(m1*m6)<<endl;
    cout<<"Dinh thuc cua cua ma tran vua nhap: "<<fixed<<setprecision(4)
    <<m6.TinhDinhThuc()<<endl;
    cout<<"Nghich dao cua ma tran vua nhap: "<<m6.MaTranNghichDao()<<endl;
    int n; cout<<"Nhap so chieu cua vector: "; cin>>n;
    if(n<=0||n!=m1.GetSoCot()) 
    cout<<"Chieu vector khong hop le hoac khong khop voi so cot cua ma tran!"<<endl;
    else{
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cout<<"Nhap cac diem: "; cin>>v[i];
        }
        int* vec=v.data();
        cout<<"Ma tran thu nhat nhan voi vector: "<<(m1*vec)<<endl;
    }
    cout<<"\n===== KIEM TRA MA TRAN =====\n";
    cout<<"m1: "<<m1<<endl;
    cout<<"m2: "<<m2<<endl;
    cout<<"m3: "<<m3<<endl;
    bool isZero=true;
    for(int i=0; i<m3.GetSoDong(); i++){
        for(int j=0; j<m3.GetSoCot(); j++){
            if(m3(i, j)!=0) {
                isZero=false;
                break;
            }
        }
    }
    cout<<"m3 la ma tran 0: "<<(isZero?"true":"false")<<endl;
    cout<<"\nSo luong doi tuong ma tran da tao: "<<CMatrix::GetDem()<<endl;
    return 0;
}