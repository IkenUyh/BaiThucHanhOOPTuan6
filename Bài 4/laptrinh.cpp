#include"laptrinh.h"
int LapTrinhVien::dem=0;
LapTrinhVien::~LapTrinhVien(){
    cout<<"Da huy mot lap trinh vien"<<endl;
    --dem;
}
LapTrinhVien::LapTrinhVien():NhanVien(), sogioot(0){
    ++dem;
}
LapTrinhVien::LapTrinhVien(string manv, string hoten, int tuoi, string sdt, string email, double luongcb, int sogioot):NhanVien(manv, hoten, tuoi, sdt, email, luongcb), sogioot(sogioot){
    ++dem;
}
LapTrinhVien::LapTrinhVien(const LapTrinhVien& ltv):NhanVien(ltv){
    this->sogioot=ltv.sogioot;
    ++dem;
}
LapTrinhVien& LapTrinhVien::operator=(const LapTrinhVien& ltv){
    NhanVien::operator=(ltv);
    this->sogioot=ltv.sogioot;
    return *this;
}
int LapTrinhVien::GetSoGioOT(){
    return this->sogioot;
}
int LapTrinhVien::GetDem(){
    return dem;
}
void LapTrinhVien::SetSoGioOT(int sogioot){
    while(sogioot<0){
        cout<<"So gio overtime khong hop le! Moi ban nhap lai: ";
        cin>>sogioot;
    }
    this->sogioot=sogioot;
}
void LapTrinhVien::Nhap(){
    NhanVien::Nhap();
    do{
        cout<<"Nhap so gio overtime: "; cin>>sogioot;
        if(sogioot<0) cout<<"So gio overtime khong hop le! Moi ban nhap lai"<<endl;
    }while(sogioot<0);
}
void LapTrinhVien::Xuat(){
    NhanVien::Xuat();
    cout<<"So gio overtime: "<<sogioot<<endl;
}
string LapTrinhVien::GetLoai(){
    return "Lap trinh vien";
}
double LapTrinhVien::TinhLuong(){
    return luongcb+sogioot*200000;
}