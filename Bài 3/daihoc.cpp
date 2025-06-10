#include"daihoc.h"
int SinhVienDaiHoc::dem=0;
SinhVienDaiHoc::~SinhVienDaiHoc(){
    cout<<"Da huy mot sinh vien dai hoc"<<endl;
    --dem;
}
SinhVienDaiHoc::SinhVienDaiHoc():SinhVien(), tenluanvan(""), diemluanvan(0){
    ++dem;
}
SinhVienDaiHoc::SinhVienDaiHoc(string mssv, string hoten, string diachi, int tongtinchi, double diemtb, string tenluanvan, double diemluanvan)
:SinhVien(mssv, hoten, diachi, tongtinchi, diemtb), tenluanvan(tenluanvan), diemluanvan(diemluanvan){
    ++dem;
}
SinhVienDaiHoc::SinhVienDaiHoc(const SinhVienDaiHoc& svdh):SinhVien(svdh), tenluanvan(svdh.tenluanvan), diemluanvan(svdh.diemluanvan){
    ++dem;
}
SinhVienDaiHoc& SinhVienDaiHoc::operator=(const SinhVienDaiHoc& svdh){
    SinhVien::operator=(svdh);
    this->tenluanvan=svdh.tenluanvan;
    this->diemluanvan=svdh.diemluanvan;
    return *this;
}
string SinhVienDaiHoc::GetTenLuanVan(){
    return this->tenluanvan;
}
double SinhVienDaiHoc::GetDiemLuanVan(){
    return this->diemluanvan;
}
int SinhVienDaiHoc::GetDem(){
    return dem;
}
void SinhVienDaiHoc::SetTenLuanVan(string tenluanvan){
    this->tenluanvan=tenluanvan;
}
void SinhVienDaiHoc::SetDiemLuanVan(double diemluanvan){
    while(diemluanvan<0||diemluanvan>10){
        cout<<"Diem luan van khong hop le! Moi ban nhap lai: "<<endl;
        cin>>diemluanvan;
    }
    this->diemluanvan=diemluanvan;
}
void SinhVienDaiHoc::Nhap(){
    SinhVien::Nhap();
    cin.ignore();
    cout<<"Nhap ten luan van: "; getline(cin, tenluanvan);
    do{
        cout<<"Nhap diem luan van: "; cin>>diemluanvan;
        if(diemluanvan<0||diemluanvan>10) cout<<"Diem luan van khong hop le! Moi ban nhap lai"<<endl;
    }while(diemluanvan<0||diemluanvan>10);
}
void SinhVienDaiHoc::Xuat(){
    SinhVien::Xuat();
    cout<<"Ten luan van: "<<tenluanvan<<endl;
    cout<<"Diem luan van: "<<fixed<<setprecision(2)<<diemluanvan<<endl;
}
string SinhVienDaiHoc::GetLoai(){
    return "Dai hoc";
}
bool SinhVienDaiHoc::TotNghiep(){
    return tongtinchi>=170&&diemtb>=5.0&&diemluanvan>=5.0;
}