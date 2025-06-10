#include"khachhanga.h"
#include"khachhangb.h"
#include"khachhangc.h"
#include"congty.h"
int CongTy::dem=0;
CongTy::~CongTy(){
    if(kh!=nullptr){
        for(int i=0; i<x+y+z; i++)
            delete kh[i];
        delete[] kh;
        kh=nullptr;
        x=y=z=0;
    }
    --dem;
}
CongTy::CongTy():x(0), y(0), z(0), kh(nullptr){
    ++dem;
}
CongTy::CongTy(int x, int y, int z):x(x), y(y), z(z), kh(nullptr){
    if(x+y+z>0){
        kh=new KhachHang*[x+y+z];
        for(int i=0; i<x+y+z; i++)
            kh[i]=nullptr;
    }
    ++dem;
}
CongTy::CongTy(const CongTy& other):x(other.x), y(other.y), z(other.z), kh(nullptr){
    if(x+y+z>0&&other.kh!=nullptr){
        kh=new KhachHang*[x+y+z];
        for(int i=0; i<x+y+z; i++){
            if(i<x)
                kh[i]=new KhachHangA(*(KhachHangA*)other.kh[i]);
            else if(i<x+y)
                kh[i]=new KhachHangB(*(KhachHangB*)other.kh[i]);
            else
                kh[i]=new KhachHangC(*(KhachHangC*)other.kh[i]);
        }
    }
    ++dem;
}
CongTy& CongTy::operator=(const CongTy& other){
    if(this!=&other){
        if(kh!=nullptr){
            for(int i=0; i<x+y+z; i++)
                delete kh[i];
            delete[] kh;
        }
        x=other.x;
        y=other.y;
        z=other.z;
        if(x+y+z>0&&other.kh!=nullptr){
            kh=new KhachHang*[x+y+z];
            for(int i=0; i<x+y+z; i++){
                if(i<x)
                    kh[i]=new KhachHangA(*(KhachHangA*)other.kh[i]);
                else if(i<x+y)
                    kh[i]=new KhachHangB(*(KhachHangB*)other.kh[i]);
                else
                    kh[i]=new KhachHangC(*(KhachHangC*)other.kh[i]);
            }
        }
        else kh=nullptr;
    }
    return *this;
}
int CongTy::GetX(){
    return this->x;
}
int CongTy::GetY(){
    return this->y;
}
int CongTy::GetZ(){
    return this->z;
}
int CongTy::GetDem(){
    return dem;
}
void CongTy::SetX(int x){
    while(x<0||x>=1000){
        cout<<"So luong khach hang A khong hop le! Moi ban nhap lai: ";
        cin>>x;
    }
    this->x=x;
}
void CongTy::SetY(int y){
    while(y<0||y>=1000){
        cout<<"So luong khach hang B khong hop le! Moi ban nhap lai: ";
        cin>>y;
    }
    this->y=y;
}
void CongTy::SetZ(int z){
    while(z<0||z>=1000){
        cout<<"So luong khach hang C khong hop le! Moi ban nhap lai: ";
        cin>>z;
    }
    this->z=z;
}
void CongTy::Nhap(){
    ifstream fin("XYZ.INP");
    streambuf* cin_backup=cin.rdbuf();
    cin.rdbuf(fin.rdbuf());
    do{
        cout<<"Nhap so luong khach hang A: "; cin>>x;
        if(x<0||x>=1000) cout<<"So luong khach hang A khong hop le! Moi ban nhap lai"<<endl;
    }while(x<0||x>=1000);
    do{
        cout<<"Nhap so luong khach hang B: "; cin>>y;
        if(y<0||y>=1000) cout<<"So luong khach hang B khong hop le! Moi ban nhap lai"<<endl;
    }while(y<0||y>=1000);
    do{
        cout<<"Nhap so luong khach hang C: "; cin>>z;
        if(z<0||z>=1000) cout<<"So luong khach hang C khong hop le! Moi ban nhap lai"<<endl;
    }while(z<0||z>=1000);
    cin.ignore();
    if(x+y+z>0){
        kh=new KhachHang*[x+y+z];
        for(int i=0; i<x+y+z; i++)
            kh[i]=nullptr;
        for(int i=0; i<x; i++){
            cout<<"\n===========================\n";
            cout<<"Nhap thong tin khach hang A thu "<<i+1<<": "<<endl;
            kh[i]=new KhachHangA;
            kh[i]->Nhap();
            cin.ignore();
        }
        for(int i=x; i<x+y; i++){
            cout<<"\n===========================\n";
            cout<<"Nhap thong tin khach hang B thu "<<i-x+1<<": "<<endl;
            kh[i]=new KhachHangB;
            kh[i]->Nhap();
            cin.ignore();
        }
        for(int i=x+y; i<x+y+z; i++){
            cout<<"\n===========================\n";
            cout<<"Nhap thong tin khach hang C thu "<<i-x-y+1<<": "<<endl;
            kh[i]=new KhachHangC;
            kh[i]->Nhap();
            cin.ignore();
        }
    }
    cin.rdbuf(cin_backup);
    fin.close();
}
void CongTy::Xuat(){
    ofstream fout("XYZ.OUT");
    streambuf* cout_backup=cout.rdbuf();
    cout.rdbuf(fout.rdbuf());
    if(kh==nullptr) cout<<"Danh sach khach hang rong"<<endl;
    else{
        double tong=0;
        cout<<"\n=====THONG TIN KHACH HANG=====\n";
        for(int i=0; i<x; i++){
            cout<<"---KHACH HANG A THU "<<i+1<<"---"<<endl;
            kh[i]->Xuat();
            tong+=kh[i]->ThanhTien();
            cout<<endl;
        }
        for(int i=x; i<x+y; i++){
            cout<<"---KHACH HANG B THU "<<i-x+1<<"---"<<endl;
            kh[i]->Xuat();
            tong+=kh[i]->ThanhTien();
            cout<<endl;
        }
        for(int i=x+y; i<x+y+z; i++){
            cout<<"---KHACH HANG C THU "<<i-x-y+1<<"---"<<endl;
            kh[i]->Xuat();
            tong+=kh[i]->ThanhTien();
            cout<<endl;
        }
        cout<<"Tong so tien cong ty thu duoc: "<<fixed<<setprecision(2)<<tong<<endl;
    }
    cout.rdbuf(cout_backup);
    fout.close();
}