#include"khachhangc.h"
int KhachHangC::dem=0;
KhachHangC::~KhachHangC(){
    cout<<"Da huy mot khach hang C"<<endl;
    --dem;
}
KhachHangC::KhachHangC():KhachHang(){
    ++dem;
}
KhachHangC::KhachHangC(string hoten, double soluonghang, double dongia):KhachHang(hoten, soluonghang, dongia){
    ++dem;
}
KhachHangC::KhachHangC(const KhachHangC& khc):KhachHang(khc){
    ++dem;
}
KhachHangC& KhachHangC::operator=(const KhachHangC& khc){
    KhachHang::operator=(khc);
    return *this;
}
int KhachHangC::GetDem(){
    return dem;
}
void KhachHangC::Nhap(){
    KhachHang::Nhap();
}
void KhachHangC::Xuat(){
    KhachHang::Xuat();
}
double KhachHangC::ThanhTien(){
    return soluonghang*dongia*0.5*1.1;
}