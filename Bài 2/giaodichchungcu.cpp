#include"giaodichchungcu.h"
int GiaoDichChungCu::dem=0;
GiaoDichChungCu::~GiaoDichChungCu(){
    cout<<"Da huy mot giao dich chung cu"<<endl;
    --dem;
}
GiaoDichChungCu::GiaoDichChungCu():GiaoDich(), macan(""), vitritang(0){
    ++dem;
}
GiaoDichChungCu::GiaoDichChungCu(string magd, string ngaygd, double dongia, double dientich, string macan, int vitritang)
:GiaoDich(magd, ngaygd, dongia, dientich), macan(macan), vitritang(vitritang){
    ++dem;
}
GiaoDichChungCu::GiaoDichChungCu(const GiaoDichChungCu& gdcc): GiaoDich(gdcc), macan(gdcc.macan), vitritang(gdcc.vitritang){
    ++dem;
}
GiaoDichChungCu& GiaoDichChungCu::operator=(const GiaoDichChungCu& gdcc){
    GiaoDich::operator=(gdcc);
    this->macan=gdcc.macan;
    this->vitritang=gdcc.vitritang;
    return *this;
}
string GiaoDichChungCu::GetMaCan(){
    return this->macan;
}
int GiaoDichChungCu::GetViTriTang(){
    return this->vitritang;
}
int GiaoDichChungCu::GetDem(){
    return dem;
}
void GiaoDichChungCu::SetMaCan(string macan){
    this->macan=macan;
}
void GiaoDichChungCu::SetViTriTang(int vitritang){
    this->vitritang=vitritang;
}
void GiaoDichChungCu::Nhap(){
    GiaoDich::Nhap();
    cin.ignore();
    cout<<"Nhap ma can: "; getline(cin, macan);
    do{
        cout<<"Nhap vi tri tang "; cin>>vitritang;
        if(vitritang<=0) cout<<"Vi tri tang khong hop le! Moi ban nhap lai"<<endl;
    }while(vitritang<=0);
}
void GiaoDichChungCu::Xuat(){
    GiaoDich::Xuat();
    cout<<"Ma can: "<<macan<<endl;
    cout<<"Vi tri tang: "<<vitritang<<endl;
}
string GiaoDichChungCu::GetLoai(){
    return "Giao dich can ho chung cu";
}
double GiaoDichChungCu::ThanhTien(){
    if(vitritang==1) return dientich*dongia*2;
    else if(vitritang>=15) return dientich*dongia*1.2;
    return dientich*dongia;
}