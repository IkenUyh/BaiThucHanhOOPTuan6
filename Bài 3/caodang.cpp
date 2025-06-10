#include"caodang.h"
int SinhVienCaoDang::dem=0;
SinhVienCaoDang::~SinhVienCaoDang(){
    cout<<"Da huy mot sinh vien cao dang"<<endl;
    --dem;
}
SinhVienCaoDang::SinhVienCaoDang():SinhVien(), diemtn(0){
    ++dem;
}
SinhVienCaoDang::SinhVienCaoDang(string mssv, string hoten, string diachi, int tongtinchi, double diemtb, double diemtn)
:SinhVien(mssv, hoten, diachi, tongtinchi, diemtb), diemtn(diemtn){
    ++dem;
}
SinhVienCaoDang::SinhVienCaoDang(const SinhVienCaoDang& svcd):SinhVien(svcd), diemtn(svcd.diemtn){
    ++dem;
}
SinhVienCaoDang& SinhVienCaoDang::operator=(const SinhVienCaoDang& svcd){
    SinhVien::operator=(svcd);
    this->diemtn=svcd.diemtn;
}
double SinhVienCaoDang::GetDiemTN(){
    return this->diemtn;
}
int SinhVienCaoDang::GetDem(){
    return dem;
}
void SinhVienCaoDang::SetDiemTN(double diemtn){
    while(diemtn<0||diemtn>10){
        cout<<"Diem thi tot nghiep khong hop le! Moi ban nhap lai: ";
        cin>>diemtn;
    }
    this->diemtn=diemtn;
}
void SinhVienCaoDang::Nhap(){
    SinhVien::Nhap();
    do{
        cout<<"Nhap diem thi tot nghiep: "; cin>>diemtn;
        if(diemtn<0||diemtn>10) cout<<"Diem thi tot nghiep khong hop le! Moi ban nhap lai: ";
    }while(diemtn<0||diemtn>10);
    this->diemtn=diemtn;
}
void SinhVienCaoDang::Xuat(){
    SinhVien::Xuat();
    cout<<"Diem thi tot nghiep: "<<fixed<<setprecision(2)<<diemtn<<endl;
}
string SinhVienCaoDang::GetLoai(){
    return "Cao dang";
}
bool SinhVienCaoDang::TotNghiep(){
    return tongtinchi>=120&&diemtb>=5.0&&diemtn>=5.0;
}