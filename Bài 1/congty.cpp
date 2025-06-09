#include"congty.h"
#include"vanphong.h"
#include"sanxuat.h"
int CongTy::dem=0;
bool CheckDob(string s, string t){
    stringstream ss1(s), ss2(t);
    int d1, m1, y1, d2, m2, y2;
    string tmp;
    getline(ss1, tmp, '/'); d1=stoi(tmp);
    getline(ss1, tmp, '/'); m1=stoi(tmp);
    getline(ss1, tmp, '/'); y1=stoi(tmp);
    getline(ss2, tmp, '/'); d2=stoi(tmp);
    getline(ss2, tmp, '/'); m2=stoi(tmp);
    getline(ss2, tmp, '/'); y2=stoi(tmp);
    if(y1!=y2) return y1<y2;
    if(m1!=m2) return m1<m2;
    return d1<d2;
}
CongTy::~CongTy(){
    if(ct!=nullptr){
        for(int i=0; i<sl; i++)
            delete ct[i];
        delete[] ct;
        ct=nullptr;
        sl=0;
    }
    --dem;
}
CongTy::CongTy():sl(0), ct(nullptr){
    ++dem;
}
CongTy::CongTy(int sl):sl(sl), ct(nullptr){
    if(sl>0){
        ct=new NhanVien*[sl];
        for(int i=0; i<sl; i++)
            ct[i]=nullptr;
    }
    ++dem;
}
CongTy::CongTy(int sl, NhanVien** nv):sl(sl), ct(nullptr){
    if(sl>0&&nv!=nullptr){
        ct=new NhanVien*[sl];
        for(int i=0; i<sl; i++){
            if(nv[i]->GetLoai()=="Nhan vien van phong")
                ct[i]=new VanPhong(*(VanPhong*)nv[i]);
            else 
                ct[i]=new SanXuat(*(SanXuat*)nv[i]);
        }
    }
    ++dem;
}
CongTy::CongTy(const CongTy& other):sl(other.sl), ct(nullptr){
    if(sl>0&&other.ct!=nullptr){
        ct=new NhanVien*[sl];
        for(int i=0; i<sl; i++){
            if(other.ct[i]->GetLoai()=="Nhan vien van phong")
                ct[i]=new VanPhong(*(VanPhong*)other.ct[i]);
            else
                ct[i]=new SanXuat(*(SanXuat*)other.ct[i]);
        }
    }
    ++dem;
}
CongTy& CongTy::operator=(const CongTy& other){
    if(this!=&other){
        if(ct!=nullptr){
            for(int i=0; i<sl; i++)
                delete ct[i];
            delete[] ct;
        }
        this->sl=other.sl;
        if(sl>0&&other.ct!=nullptr){
            ct=new NhanVien*[sl];
            for(int i=0; i<sl; i++){
                if(other.ct[i]->GetLoai()=="Nhan vien van phong")
                    ct[i]=new VanPhong(*(VanPhong*)other.ct[i]);
                else 
                    ct[i]=new SanXuat(*(SanXuat*)other.ct[i]);
            }
        }
        else ct=nullptr;
    }
    return *this;
}
int CongTy::GetSoLuong(){
    return this->sl;
}
int CongTy::GetDem(){
    return dem;
}
void CongTy::SetSoLuong(int sl){
    while(sl<1){
        cout<<"So luong khong hop le! Moi ban nhap lai: ";
        cin>>sl;
    }
    this->sl=sl;
}
void CongTy::Nhap(){
    int loai;
    do{
        cout<<"Nhap so luong nhan vien: "; cin>>sl;
        if(sl<1) cout<<"So luong khong hop le! Moi ban nhap lai"<<endl;
    }while(sl<1);
    ct=new NhanVien*[sl];
    for(int i=0; i<sl; i++){
        cout<<"\n======================\n";
        cout<<"Nhap thong tin nhan vien thu "<<i+1<<": "<<endl;
        do{
            cout<<"Nhap loai (1: Nhan vien van phong, 2: Nhan vien san xuat): "; cin>>loai;
            if(loai!=1&&loai!=2) cout<<"Loai khong hop le! Moi ban nhap lai"<<endl; 
        }while(loai!=1&&loai!=2);
        if(loai==1) ct[i]=new VanPhong;
        else ct[i]=new SanXuat;
        ct[i]->Nhap();
        ct[i]->TinhLuong();
    }
}
NhanVien* CongTy::Nhap1(){
    int loai;
    NhanVien* nv;
    do{
        cout<<"Nhap loai (1: Nhan vien van phong, 2: Nhan vien san xuat): "; cin>>loai;
        if(loai!=1&&loai!=2) cout<<"Loai khong hop le! Moi ban nhap lai"<<endl;
    }while(loai!=1&&loai!=2);
    if(loai==1) nv=new VanPhong;
    else nv=new SanXuat;
    nv->Nhap();
    nv->TinhLuong();
    return nv;
}
void CongTy::Xuat(){
    if(ct==nullptr||sl==0) cout<<"Danh sach nhan vien rong"<<endl;
    else{
        cout<<"\n===== THONG TIN NHAN VIEN =====\n";
        for(int i=0; i<sl; i++){
            cout<<"--- NHAN VIEN THU "<<i+1<<" ---"<<endl;
            ct[i]->Xuat();
            cout<<endl;
        }
    }
}
double CongTy::TongLuong(){
    double res=0;
    for(int i=0; i<sl; i++)
        res+=ct[i]->GetLuong();
    return res;
}
void CongTy::NhanVienSXLuongThapNhat(){
    double mluong=-1;
    for(int i=0; i<sl; i++){
        if(ct[i]->GetLoai()=="Nhan vien san xuat"&&
        (mluong==-1||mluong>ct[i]->GetLuong()))
            mluong=ct[i]->GetLuong();
    }
    if(mluong==-1) cout<<"Khong co nhan vien san xuat"<<endl;
    else{
        cout<<"\n===== NHAN VIEN SAN XUAT CO LUONG THAP NHAT =====\n";
        for(int i=0; i<sl; i++){
            if(ct[i]->GetLoai()=="Nhan vien san xuat"&&
            mluong==ct[i]->GetLuong()){
                cout<<"--- NHAN VIEN THU "<<i+1<<" ---"<<endl;
                ct[i]->Xuat();
                cout<<endl;
            }
        }
    }
}
void CongTy::NhanVienVPTuoiCaoNhat(){
    string mnam="01/01/9999";
    for(int i=0; i<sl; i++){
        if(ct[i]->GetLoai()=="Nhan vien van phong"&&
        CheckDob(ct[i]->GetNgaySinh(), mnam))
            mnam=ct[i]->GetNgaySinh();
    }
    if(mnam=="01/01/9999"){
        cout<<"Khong co nhan vien van phong "<<endl;
        return;
    }
    cout<<"\n===== NHAN VIEN VAN PHONG LON TUOI NHAT =====\n";
    for(int i=0; i<sl; i++)
        if(ct[i]->GetLoai()=="Nhan vien van phong"&&
        ct[i]->GetNgaySinh()==mnam){
            cout<<"--- NHAN VIEN THU "<<i+1<<" ---"<<endl;
            ct[i]->Xuat();
            cout<<endl;
        }
}