#include"kiemchung.h"
int KiemChungVien::dem=0;
KiemChungVien::~KiemChungVien(){
    cout<<"Da huy mot kiem chung vien"<<endl;
    --dem;
}
KiemChungVien::KiemChungVien():NhanVien(), soloi(0){
    ++dem;
}
KiemChungVien::KiemChungVien(string manv, string hoten, int tuoi, string sdt, string email, double luongcb, int soloi):NhanVien(manv, hoten, tuoi, sdt, email, luongcb), soloi(soloi){
    ++dem;
}
KiemChungVien::KiemChungVien(const KiemChungVien& kcv):NhanVien(kcv){
    this->soloi=kcv.soloi;
    ++dem;
}
KiemChungVien& KiemChungVien::operator=(const KiemChungVien& kcv){
    NhanVien::operator=(kcv);
    this->soloi=kcv.soloi;
    return *this;
}
int KiemChungVien::GetSoLoi(){
    return this->soloi;
}
int KiemChungVien::GetDem(){
    return dem;
}
void KiemChungVien::SetSoLoi(int soloi){
    while(soloi<0){
        cout<<"So loi khong hop le! Moi ban nhap lai: ";
        cin>>soloi;
    }
    this->soloi=soloi;
}
void KiemChungVien::Nhap(){
    NhanVien::Nhap();
    do{
        cout<<"Nhap so loi phat hien: "; cin>>soloi;
        if(soloi<0) cout<<"So loi khong hop le! Moi ban nhap lai"<<endl;
    }while(soloi<0);
}
void KiemChungVien::Xuat(){
    NhanVien::Xuat();
    cout<<"So loi phat hien: "<<soloi<<endl;
}
string KiemChungVien::GetLoai(){
    return "Kiem chung vien";
}
double KiemChungVien::TinhLuong(){
    return luongcb+soloi*50000;
}