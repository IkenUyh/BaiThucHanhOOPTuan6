#include"sinhvien.h"
int SinhVien::dem=0;
bool KiemTraTen(string s){
    if(s.empty()) return 0;
    for(char c:s)
        if(!isalpha(c)&&c!=' ')
            return 0;
    return 1;
}
void ChuanHoaTen(string &s){
    stringstream ss(s);
    string res, w;
    while(ss>>w){
        res+=toupper(w[0]);
        for(char c:w)
            res+=tolower(c);
        res+=" ";
    }
    res.pop_back();
    s=res;
}
SinhVien::~SinhVien(){
    cout<<"Da huy mot sinh vien"<<endl;
    --dem;
}
SinhVien::SinhVien():mssv(""), hoten(""), diachi(""), tongtinchi(0), diemtb(0){
    ++dem;
}
SinhVien::SinhVien(string mssv, string hoten, string diachi, int tongtinchi, double diemtb)
:mssv(mssv), hoten(hoten), diachi(diachi), tongtinchi(tongtinchi), diemtb(diemtb){
    ++dem;
}
SinhVien::SinhVien(const SinhVien& sv)
:mssv(sv.mssv), hoten(sv.hoten), diachi(sv.diachi), tongtinchi(sv.tongtinchi), diemtb(sv.diemtb){
    ++dem;
}
SinhVien& SinhVien::operator=(const SinhVien& sv){
    this->mssv=sv.mssv;
    this->hoten=sv.hoten;
    this->diachi=sv.diachi;
    this->tongtinchi=sv.tongtinchi;
    this->diemtb=sv.diemtb;
    return *this;
}
string SinhVien::GetMSSV(){
    return this->mssv;
}
string SinhVien::GetHoTen(){
    return this->hoten;
}
int SinhVien::GetTongTinChi(){
    return this->tongtinchi;
}
double SinhVien::GetDiemTB(){
    return this->diemtb;
}
int SinhVien::GetDem(){
    return dem;
}
void SinhVien::SetHoTen(string hoten){
    cin.ignore();
    while(!KiemTraTen(hoten)){
        cout<<"Ho ten khong hop le! Moi ban nhap lai: ";
        getline(cin, hoten);
    }
    this->hoten=hoten;
}
void SinhVien::SetDiaChi(string diachi){
    this->diachi=diachi;
}
void SinhVien::SetTongTinChi(int tongtinchi){
    while(tongtinchi<0){
        cout<<"Tong tin chi khong hop le! Moi ban nhap lai: ";
        cin>>tongtinchi;
    }
    this->tongtinchi=tongtinchi;
}
void SinhVien::SetDiemTB(double diemtb){
    while(diemtb<0||diemtb>10){
        cout<<"Diem trung binh khong hop le! Moi ban nhap lai: ";
        cin>>diemtb; 
    }
    this->diemtb=diemtb;
}
void SinhVien::Nhap(){
    cin.ignore();
    cout<<"Nhap ma so sinh vien: "; getline(cin, mssv);
    do{
        cout<<"Nhap ho ten sinh vien: "; getline(cin, hoten);
        if(!KiemTraTen(hoten)) cout<<"Ho ten khong hop le! Moi ban nhap lai"<<endl;
    }while(!KiemTraTen(hoten));
    ChuanHoaTen(hoten);
    cout<<"Nhap dia chi: "; getline(cin, diachi);
    do{
        cout<<"Nhap tong so tin chi: "; cin>>tongtinchi;
        if(tongtinchi<0) cout<<"Tong so tin chi khong hop le! Moi ban nhap lai"<<endl;
    }while(tongtinchi<0);
    do{
        cout<<"Nhap diem trung binh: "; cin>>diemtb;
        if(diemtb<0||diemtb>10) cout<<"Diem trung binh khong hop le! Moi ban nhap lai"<<endl;
    }while(diemtb<0||diemtb>10);
}
void SinhVien::Xuat(){
    cout<<"Ma so sinh vien: "<<mssv<<endl;
    cout<<"Ho ten sinh vien: "<<hoten<<endl;
    cout<<"Dia chi: "<<diachi<<endl;
    cout<<"Tong so tinh chi: "<<tongtinchi<<endl;
    cout<<"Diem trung binh: "<<fixed<<setprecision(2)<<diemtb<<endl;
    cout<<"He: "<<GetLoai()<<endl;
    cout<<"Tot nghiep: "<<(TotNghiep()?"Co":"Khong")<<endl;
}