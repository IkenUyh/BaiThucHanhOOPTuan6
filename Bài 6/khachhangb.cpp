#include"khachhangb.h"
int KhachHangB::dem=0;
KhachHangB::~KhachHangB(){
    cout<<"Da huy mot khach hang B"<<endl;
    --dem;
}
KhachHangB::KhachHangB():KhachHang(), sonamthanthiet(0){
    ++dem;
}
KhachHangB::KhachHangB(string hoten, double soluonghang, double dongia, double sonamthanthiet):KhachHang(hoten, soluonghang, dongia), sonamthanthiet(sonamthanthiet){
    ++dem;
}
KhachHangB::KhachHangB(const KhachHangB& khb):KhachHang(khb){
    this->sonamthanthiet=khb.sonamthanthiet;
    ++dem;
}
KhachHangB& KhachHangB::operator=(const KhachHangB& khb){
    KhachHang::operator=(khb);
    this->sonamthanthiet=khb.sonamthanthiet;
    return *this;
}
double KhachHangB::GetSoNamThanhThiet(){
    return this->sonamthanthiet;
}
int KhachHangB::GetDem(){
    return dem;
}
void KhachHangB::SetSoNamThanhThiet(double sonamthanthiet){
    while(sonamthanthiet<0){
        cout<<"So nam thanh thiet khong hop le! Moi ban nhap lai: ";
        cin>>sonamthanthiet;
    }
    this->sonamthanthiet=sonamthanthiet;
}
void KhachHangB::Nhap(){
    KhachHang::Nhap();
    do{
        cout<<"Nhap so nam thanh thiet: "; cin>>sonamthanthiet;
        if(sonamthanthiet<0) cout<<"So nam thanh thiet khong hop le! Moi ban nhap lai"<<endl;
    }while(sonamthanthiet<0);
}
void KhachHangB::Xuat(){
    KhachHang::Xuat();
    cout<<"So nam thanh thiet: "<<fixed<<setprecision(2)<<sonamthanthiet<<endl;
}
double KhachHangB::ThanhTien(){
    double khuyenmai=max(sonamthanthiet*5,50.0)/100;
    return soluonghang*dongia*(1-khuyenmai)*1.1;
}