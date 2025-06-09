#include"sanxuat.h"
int SanXuat::dem=0;
SanXuat::~SanXuat(){
    cout<<"Da huy mot nhan vien san xuat"<<endl;
    --dem;
}
SanXuat::SanXuat():NhanVien(), luongcb(0), sosanpham(0){
    ++dem;
}
SanXuat::SanXuat(string hoten, string ngaysinh, double luongcb, int sosanpham)
:NhanVien(hoten, ngaysinh), luongcb(luongcb), sosanpham(sosanpham){
    ++dem;
}
SanXuat::SanXuat(const SanXuat& sx):NhanVien(sx){
    this->luongcb=sx.luongcb;
    this->sosanpham=sx.sosanpham;
    ++dem;
}
SanXuat& SanXuat::operator=(const SanXuat& sx){
    NhanVien::operator=(sx);
    this->luongcb=sx.luongcb;
    this->sosanpham=sx.sosanpham;
    return *this;
}
double SanXuat::GetLuongCanBan(){
    return this->luongcb;
}
int SanXuat::GetSoSanPham(){
    return this->sosanpham;
}
int SanXuat::GetDem(){
    return dem;
}
void SanXuat::SetLuongCanBan(double luongcb){
    while(luongcb<0){
        cout<<"Luong can ban khong hop le! Moi ban nhap lai: ";
        cin>>luongcb;
    }
    this->luongcb=luongcb;
}
void SanXuat::SetSoSanPham(int sosanpham){
    while(sosanpham<0){
        cout<<"So san pham khong hop le! Moi ban nhap lai: ";
        cin>>sosanpham;
    }
    this->sosanpham=sosanpham;
}
void SanXuat::Nhap(){
    NhanVien::Nhap();
    do{
        cout<<"Nhap luong can ban: "; cin>>luongcb;
        if(luongcb<0) cout<<"Luong can ban khong hop le! Moi ban nhap lai"<<endl;
    }while(luongcb<0);
    do{
        cout<<"Nhap so san pham: "; cin>>sosanpham;
        if(sosanpham<0) cout<<"So san pham khong hop le! Moi ban nhap lai"<<endl;
    }while(sosanpham<0);
}
void SanXuat::Xuat(){
    NhanVien::Xuat();
    cout<<"Luong can ban: "<<fixed<<setprecision(2)<<luongcb<<endl;
    cout<<"So san pham: "<<sosanpham<<endl;
}
string SanXuat::GetLoai(){
    return "Nhan vien san xuat";
}
void SanXuat::TinhLuong(){
    luong=luongcb+sosanpham*5000;
}