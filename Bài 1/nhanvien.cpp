#include"nhanvien.h"
int NhanVien::dem=0;
bool KiemTraTen(string s){
    if(s.empty()) return 0;
    for(char c:s)
        if(!isalpha(c)&&c!=' ') return 0;
    return 1;
}
void ChuanHoaTen(string &s){
    stringstream ss(s);
    string res, w;
    while(ss>>w){
        res+=toupper(w[0]);
        for(int i=1; i<w.size(); i++)
            res+=tolower(w[i]);
        res+=" ";
    }
    res.pop_back();
    s=res;
}
void ChuanHoaNgaySinh(string &s){
    if(s[1]=='/') s='0'+s;
    if(s[4]=='/') s.insert(3, "0");
}
NhanVien::~NhanVien(){
    cout<<"Da huy mot nhan vien"<<endl;
    --dem;
}
NhanVien::NhanVien():hoten(""), ngaysinh(""), luong(0){
    ++dem;
}
NhanVien::NhanVien(string hoten, string ngaysinh):hoten(hoten), 
ngaysinh(ngaysinh), luong(0){
    ++dem;
}
NhanVien::NhanVien(const NhanVien& nv){
    this->hoten=nv.hoten;
    this->ngaysinh=nv.ngaysinh;
    this->luong=nv.luong;
    ++dem;
}
NhanVien& NhanVien::operator=(const NhanVien& nv){
    this->hoten=nv.hoten;
    this->ngaysinh=nv.ngaysinh;
    this->luong=nv.luong;
    return *this;
}
string NhanVien::GetHoTen(){
    return this->hoten;
}
string NhanVien::GetNgaySinh(){
    return this->ngaysinh;
}
double NhanVien::GetLuong(){
    return this->luong;
}
int NhanVien::GetDem(){
    return dem;
}
void NhanVien::SetHoTen(string hoten){
    this->hoten=hoten;
}
void NhanVien::SetNgaySinh(string ngaysinh){
    this->ngaysinh=ngaysinh;
}
void NhanVien::SetLuong(double luong){
    while(luong<0){
        cout<<"Luong khong hop le! Moi ban nhap lai: ";
        cin>>luong;
    }
    this->luong=luong;
}
void NhanVien::Nhap(){
    cin.ignore();
    do{
        cout<<"Nhap ho ten nhan vien: "; getline(cin, hoten);
        if(!KiemTraTen(hoten)) cout<<"Ten khong hop le! Moi ban nhap lai"<<endl;
    }while(!KiemTraTen(hoten));
    ChuanHoaTen(hoten);
    cout<<"Nhap ngay sinh (dd/mm/yyyy): "; 
    getline(cin, ngaysinh); ChuanHoaNgaySinh(ngaysinh);
}
void NhanVien::Xuat(){
    cout<<"Ho ten nhan vien: "<<hoten<<endl;
    cout<<"Ngay sinh: "<<ngaysinh<<endl;
    cout<<"Loai: "<<GetLoai()<<endl;
    cout<<"Luong: "<<fixed<<setprecision(2)<<luong<<endl;
}