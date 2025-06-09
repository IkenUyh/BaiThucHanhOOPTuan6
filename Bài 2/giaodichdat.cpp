#include"giaodichdat.h"
int GiaoDichDat::dem=0;
GiaoDichDat::~GiaoDichDat(){
    cout<<"Da huy mot giao dich dat"<<endl;
    --dem;
}
GiaoDichDat::GiaoDichDat():GiaoDich(), loaidat('\0'){
    ++dem;
}
GiaoDichDat::GiaoDichDat(string magd, string ngaygd, double dongia, double dientich, char loaidat)
:GiaoDich(magd, ngaygd, dongia, dientich), loaidat(loaidat){
    ++dem;
}
GiaoDichDat::GiaoDichDat(const GiaoDichDat& gdd): GiaoDich(gdd), loaidat(gdd.loaidat){
    ++dem;
}
GiaoDichDat& GiaoDichDat::operator=(const GiaoDichDat& gdd){
    GiaoDich::operator=(gdd);
    this->loaidat=gdd.loaidat;
    return *this;
}
char GiaoDichDat::GetLoaiDat(){
    return this->loaidat;
}
int GiaoDichDat::GetDem(){
    return dem;
}
void GiaoDichDat::SetLoaiDai(char loaidat){
    this->loaidat=loaidat;
}
void GiaoDichDat::Nhap(){
    GiaoDich::Nhap();
    do{
        cout<<"Nhap loai dat (A/B/C): "; cin>>loaidat;
        if(loaidat!='A'&&loaidat!='B'&&loaidat!='C')
            cout<<"Loai dat khong hop le! Moi ban nhap lai"<<endl;
    }while(loaidat!='A'&&loaidat!='B'&&loaidat!='C');
}
void GiaoDichDat::Xuat(){
    GiaoDich::Xuat();
    cout<<"Loai dat: "<<loaidat<<endl;
}
string GiaoDichDat::GetLoai(){
    return "Giao dich dat";
}
double GiaoDichDat::ThanhTien(){
    if(loaidat=='A') return dientich*dongia*1.5;
    return dientich*dongia;
}