#include"khachhang.h"
int KhachHang::dem=0;
KhachHang::~KhachHang(){
    cout<<"Da huy mot khach hang"<<endl;
    --dem;
}
KhachHang::KhachHang():hoten(""), soluonghang(0), dongia(0){
    ++dem;
}
KhachHang::KhachHang(string hoten, double soluonghang, double dongia):hoten(hoten), soluonghang(soluonghang), dongia(dongia){
    ++dem;
}
KhachHang::KhachHang(const KhachHang& kh){
    this->hoten=kh.hoten;
    this->soluonghang=kh.soluonghang;
    this->dongia=kh.dongia;
    ++dem;
}
KhachHang& KhachHang::operator=(const KhachHang& kh){
    this->hoten=kh.hoten;
    this->soluonghang=kh.soluonghang;
    this->dongia=kh.dongia;
    return *this;
}
string KhachHang::GetHoTen(){
    return this->hoten;
}
double KhachHang::GetSoLuongHang(){
    return this->soluonghang;
}
double KhachHang::GetDonGia(){
    return this->dongia;
}
int KhachHang::GetDem(){
    return dem;
}
void KhachHang::SetHoTen(string hoten){
    this->hoten=hoten;
}
void KhachHang::SetSoLuongHang(double soluonghang){
    while(soluonghang<0){
        cout<<"So luong hang khong hop le! Moi ban nhap lai: ";
        cin>>soluonghang;
    }
    this->soluonghang=soluonghang;
}
void KhachHang::SetDonGia(double dongia){
    while(dongia<0){
        cout<<"Don gia khong hop le! Moi ban nhap lai: ";
        cin>>dongia;
    }
    this->dongia=dongia;
}
void KhachHang::Nhap(){
    cin.ignore();
    cout<<"Nhap ho ten khach hang: "; getline(cin, hoten);
    cout<<"Nhap so luong hang: "; cin>>soluonghang;
    while(soluonghang<0){
        cout<<"So luong hang khong hop le! Moi ban nhap lai: ";
        cin>>soluonghang;
    }
    cout<<"Nhap don gia: "; cin>>dongia;
    while(dongia<0){
        cout<<"Don gia khong hop le! Moi ban nhap lai: ";
        cin>>dongia;
    }
}
void KhachHang::Xuat(){
    cout<<"Ho ten khach hang: "<<hoten<<endl;
    cout<<"So luong hang: "<<fixed<<setprecision(2)<<soluonghang<<endl;
    cout<<"Don gia: "<<fixed<<setprecision(2)<<dongia<<endl;
    cout<<"Thanh tien: "<<fixed<<setprecision(2)<<ThanhTien()<<endl;
}