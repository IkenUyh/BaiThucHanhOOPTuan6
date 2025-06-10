#include"nhanvien.h"
int NhanVien::dem=0;
NhanVien::~NhanVien(){
    cout<<"Da huy mot nhan vien"<<endl;
    --dem;
}
NhanVien::NhanVien():manv(""), hoten(""), tuoi(0), sdt(""), email(""), luongcb(0){
    ++dem;
}
NhanVien::NhanVien(string manv, string hoten, int tuoi, string sdt, string email, double luongcb):manv(manv), hoten(hoten), tuoi(tuoi), sdt(sdt), email(email), luongcb(luongcb){
    ++dem;
}
NhanVien::NhanVien(const NhanVien& nv){
    this->manv=nv.manv;
    this->hoten=nv.hoten;
    this->tuoi=nv.tuoi;
    this->sdt=nv.sdt;
    this->email=nv.email;
    this->luongcb=nv.luongcb;
    ++dem;
}
NhanVien& NhanVien::operator=(const NhanVien& nv){
    this->manv=nv.manv;
    this->hoten=nv.hoten;
    this->tuoi=nv.tuoi;
    this->sdt=nv.sdt;
    this->email=nv.email;
    this->luongcb=nv.luongcb;
    return *this;
}
string NhanVien::GetMaNV(){
    return this->manv;
}
string NhanVien::GetHoTen(){
    return this->hoten;
}
int NhanVien::GetTuoi(){
    return this->tuoi;
}
string NhanVien::GetSDT(){
    return this->sdt;
}
string NhanVien::GetEmail(){
    return this->email;
}
double NhanVien::GetLuongCB(){
    return this->luongcb;
}
int NhanVien::GetDem(){
    return dem;
}
void NhanVien::SetHoTen(string hoten){
    this->hoten=hoten;
}
void NhanVien::SetTuoi(int tuoi){
    while(tuoi<18){
        cout<<"Tuoi khong hop le! Moi ban nhap lai: ";
        cin>>tuoi;
    }
    this->tuoi=tuoi;
}
void NhanVien::SetSDT(string sdt){
    this->sdt=sdt;
}
void NhanVien::SetEmail(string email){
    this->email=email;
}
void NhanVien::SetLuongCB(double luongcb){
    while(luongcb<0){
        cout<<"Luong co ban khong hop le! Moi ban nhap lai: ";
        cin>>luongcb;
    }
    this->luongcb=luongcb;
}
void NhanVien::Nhap(){
    cin.ignore();
    cout<<"Nhap ma nhan vien: "; getline(cin, manv);
    cout<<"Nhap ho ten nhan vien: "; getline(cin, hoten);
    cout<<"Nhap tuoi: "; cin>>tuoi;
    while(tuoi<18){
        cout<<"Tuoi khong hop le! Moi ban nhap lai: ";
        cin>>tuoi;
    }
    cin.ignore();
    cout<<"Nhap so dien thoai: "; getline(cin, sdt);
    cout<<"Nhap email: "; getline(cin, email);
    cout<<"Nhap luong co ban: "; cin>>luongcb;
    while(luongcb<0){
        cout<<"Luong co ban khong hop le! Moi ban nhap lai: ";
        cin>>luongcb;
    }
}
void NhanVien::Xuat(){
    cout<<"Ma nhan vien: "<<manv<<endl;
    cout<<"Ho ten nhan vien: "<<hoten<<endl;
    cout<<"Tuoi: "<<tuoi<<endl;
    cout<<"So dien thoai: "<<sdt<<endl;
    cout<<"Email: "<<email<<endl;
    cout<<"Luong co ban: "<<fixed<<setprecision(2)<<luongcb<<endl;
    cout<<"Loai: "<<GetLoai()<<endl;
    cout<<"Tong luong: "<<fixed<<setprecision(2)<<TinhLuong()<<endl;
}