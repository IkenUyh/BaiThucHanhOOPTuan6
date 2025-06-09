#include"giaodichnha.h"
int GiaoDichNhaPho::dem=0;
GiaoDichNhaPho::~GiaoDichNhaPho(){
    cout<<"Da huy mot giao dich nha pho"<<endl;
    --dem;
}
GiaoDichNhaPho::GiaoDichNhaPho():GiaoDich(), loainha(""), diachi(""){
    ++dem;
}
GiaoDichNhaPho::GiaoDichNhaPho(string magd, string ngaygd, double dongia, double dientich, string loainha, string diachi)
:GiaoDich(magd, ngaygd, dongia, dientich), loainha(loainha), diachi(diachi){
    ++dem;
}
GiaoDichNhaPho::GiaoDichNhaPho(const GiaoDichNhaPho& gdnp):GiaoDich(gdnp), loainha(gdnp.loainha), diachi(gdnp.diachi){
    ++dem;
}
GiaoDichNhaPho& GiaoDichNhaPho::operator=(const GiaoDichNhaPho& gdnp){
    GiaoDich::operator=(gdnp);
    this->loainha=gdnp.loainha;
    this->diachi=gdnp.diachi;
    return *this;
}
string GiaoDichNhaPho::GetLoaiNha(){
    return this->loainha;
}
string GiaoDichNhaPho::GetDiaChi(){
    return this->diachi;
}
int GiaoDichNhaPho::GetDem(){
    return dem;
}
void GiaoDichNhaPho::SetLoaiNha(string loainha){
    this->loainha=loainha;
}
void GiaoDichNhaPho::SetDiaChi(string diachi){
    this->diachi=diachi;
}
void GiaoDichNhaPho::Nhap(){
    GiaoDich::Nhap();
    cin.ignore();
    do{
        cout<<"Nhap loai nha (1: cao cap, 2: thuong): "; getline(cin, loainha);
        if(loainha!="cao cap"&&loainha!="thuong")
            cout<<"Loai nha khong hop le! Moi ban nhap lai"<<endl;
    }while(loainha!="cao cap"&&loainha!="thuong");
    cout<<"Nhap dia chi: "; getline(cin, diachi);
}
void GiaoDichNhaPho::Xuat(){
    GiaoDich::Xuat();
    cout<<"Loai nha: "<<loainha<<endl;
    cout<<"Dia chi: "<<diachi<<endl;
}
string GiaoDichNhaPho::GetLoai(){
    return "Giao dich nha pho";
}
double GiaoDichNhaPho::ThanhTien(){
    if(loainha=="cao cap") return dientich*dongia;
    return dientich*dongia*0.9;
}