#include"vanphong.h"
int VanPhong::dem=0;
VanPhong::~VanPhong(){
    cout<<"Da huy mot nhan vien van phong"<<endl;
    --dem;
}
VanPhong::VanPhong():NhanVien(), songaylam(0){
    ++dem;
}
VanPhong::VanPhong(string hoten, string ngaysinh, int songaylam)
:NhanVien(hoten, ngaysinh), songaylam(songaylam){
    ++dem;
}
VanPhong::VanPhong(const VanPhong& vp):NhanVien(vp){
    this->songaylam=vp.songaylam;
    ++dem;
}
VanPhong& VanPhong::operator=(const VanPhong& vp){
    NhanVien::operator=(vp);
    this->songaylam=vp.songaylam;
    return *this;
}
int VanPhong::GetSoNgayLam(){
    return this->songaylam;
}
int VanPhong::GetDem(){
    return dem;
}
void VanPhong::SetSoNgayLam(int songaylam){
    while(songaylam<0){
        cout<<"So ngay lam viec khong hop le! Moi ban nhap lai: ";
        cin>>songaylam;
    }
    this->songaylam=songaylam;
}
void VanPhong::Nhap(){
    NhanVien::Nhap();
    do{
        cout<<"Nhap so ngay lam viec: "; cin>>songaylam;
        if(songaylam<0) cout<<"So ngay lam vien khong hop le! Moi ban nhap lai"<<endl;
    }while(songaylam<0);
}
void VanPhong::Xuat(){
    NhanVien::Xuat();
    cout<<"So ngay lam viec: "<<songaylam<<endl;
}
string VanPhong::GetLoai(){
    return "Nhan vien van phong";
}
void VanPhong::TinhLuong(){
    luong=songaylam*100000;
}