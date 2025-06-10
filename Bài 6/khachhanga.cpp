#include"khachhanga.h"
int KhachHangA::dem=0;
KhachHangA::~KhachHangA(){
    cout<<"Da huy mot khach hang A"<<endl;
    --dem;
}
KhachHangA::KhachHangA():KhachHang(){
    ++dem;
}
KhachHangA::KhachHangA(string hoten, double soluonghang, double dongia):KhachHang(hoten, soluonghang, dongia){
    ++dem;
}
KhachHangA::KhachHangA(const KhachHangA& kha):KhachHang(kha){
    ++dem;
}
KhachHangA& KhachHangA::operator=(const KhachHangA& kha){
    KhachHang::operator=(kha);
    return *this;
}
int KhachHangA::GetDem(){
    return dem;
}
void KhachHangA::Nhap(){
    KhachHang::Nhap();
}
void KhachHangA::Xuat(){
    KhachHang::Xuat();
}
double KhachHangA::ThanhTien(){
    return soluonghang*dongia*1.1;
}