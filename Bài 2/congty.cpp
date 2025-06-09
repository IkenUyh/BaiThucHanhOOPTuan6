#include"giaodichdat.h"
#include"giaodichnha.h"
#include"giaodichchungcu.h"
#include"congty.h"
int CongTyBatDongSan::dem=0;
CongTyBatDongSan::~CongTyBatDongSan(){
    if(ct!=nullptr){
        for(int i=0; i<sl; i++)
            delete ct[i];
        delete[] ct;
        ct=nullptr;
        sl=0;
    }
    --dem;
}
CongTyBatDongSan::CongTyBatDongSan():sl(0), ct(nullptr){
    ++dem;
}
CongTyBatDongSan::CongTyBatDongSan(int sl):sl(sl), ct(nullptr){
    if(sl>0){
        ct=new GiaoDich*[sl];
        for(int i=0; i<sl; i++)
            ct[i]=nullptr;
    }
    ++dem;
}
CongTyBatDongSan::CongTyBatDongSan(int sl, GiaoDich** other):sl(sl), ct(nullptr){
    if(sl>0&&other!=nullptr){
        ct=new GiaoDich*[sl];
        for(int i=0; i<sl; i++){
            if(other[i]->GetLoai()=="Giao dich dat")
                ct[i]=new GiaoDichDat(*(GiaoDichDat*)other[i]);
            else if(other[i]->GetLoai()=="Giao dich nha pho")
                ct[i]=new GiaoDichNhaPho(*(GiaoDichNhaPho*)other[i]);
            else 
                ct[i]=new GiaoDichChungCu(*(GiaoDichChungCu*)other[i]);
        }
    }
    ++dem;
}
CongTyBatDongSan::CongTyBatDongSan(const CongTyBatDongSan& other):sl(other.sl), ct(nullptr){
    if(sl>0&&other.ct!=nullptr){
        ct=new GiaoDich*[sl];
        for(int i=0; i<sl; i++){
            if(other.ct[i]->GetLoai()=="Giao dich dat")
                ct[i]=new GiaoDichDat(*(GiaoDichDat*)other.ct[i]);
            else if(other.ct[i]->GetLoai()=="Giao dich nha pho")
                ct[i]=new GiaoDichNhaPho(*(GiaoDichNhaPho*)other.ct[i]);
            else
                ct[i]=new GiaoDichChungCu(*(GiaoDichChungCu*)other.ct[i]);
        }
    }
    ++dem;
}
CongTyBatDongSan& CongTyBatDongSan::operator=(const CongTyBatDongSan& other){
    if(this!=&other){
        if(ct!=nullptr){
            for(int i=0; i<sl; i++)
                delete ct[i];
            delete[] ct;
        }
        this->sl=other.sl;
        if(sl>0&&other.ct!=nullptr){
            ct=new GiaoDich*[sl];
            for(int i=0; i<sl; i++){
                if(other.ct[i]->GetLoai()=="Giao dich dat")
                    ct[i]=new GiaoDichDat(*(GiaoDichDat*)other.ct[i]);
                else if(other.ct[i]->GetLoai()=="Giao dich nha pho")
                    ct[i]=new GiaoDichNhaPho(*(GiaoDichNhaPho*)other.ct[i]);
                else
                    ct[i]=new GiaoDichChungCu(*(GiaoDichChungCu*)other.ct[i]);
            }
        }
        else ct=nullptr;
    }
    return *this;
}
int CongTyBatDongSan::GetSoLuong(){
    return this->sl;
}
int CongTyBatDongSan::GetDem(){
    return dem;
}
void CongTyBatDongSan::SetSoLuong(int sl){
    while(sl<1){
        cout<<"So luong khong hop le! Moi ban nhap lai: ";
        cin>>sl;
    }
    this->sl=sl;
}
void CongTyBatDongSan::Nhap(){
    int loai;
    do{
        cout<<"Nhap so luong cac giao dich: "; cin>>sl;
        if(sl<1) cout<<"So luong khong hop le! Moi ban nhap lai"<<endl;
    }while(sl<1);
    ct=new GiaoDich*[sl];
    for(int i=0; i<sl; i++){
        cout<<"\n======================\n";
        cout<<"Nhap thong tin giao dich thu "<<i+1<<": "<<endl;
        do{
            cout<<"Nhap loai ";
            cout<<"(1: Giao dich dat, 2: Giao dich nha pho, 3: Giao dich chung cu): ";
            cin>>loai;
            if(loai!=1&&loai!=2&&loai!=3) cout<<"Loai khong hop le! Moi ban nhap lai"<<endl;
        }while(loai!=1&&loai!=2&&loai!=3);
        if(loai==1) ct[i]=new GiaoDichDat;
        else if(loai==2) ct[i]=new GiaoDichNhaPho;
        else ct[i]=new GiaoDichChungCu;
        ct[i]->Nhap();
        ct[i]->ThanhTien();
    }
}
GiaoDich* CongTyBatDongSan::Nhap1(){
    GiaoDich* gd;
    int loai;
    do{
        cout<<"Nhap loai ";
        cout<<"(1: Giao dich dat, 2: Giao dich nha pho, 3: Giao dich chung cu): ";
        cin>>loai;
        if(loai!=1&&loai!=2&&loai!=3) cout<<"Loai khong hop le! Moi ban nhap lai"<<endl;
    }while(loai!=1&&loai!=2&&loai!=3);
    if(loai==1) gd=new GiaoDichDat;
    else if(loai==2) gd=new GiaoDichNhaPho;
    else gd=new GiaoDichChungCu;
    gd->Nhap();
    gd->Xuat();
    return gd;
}
void CongTyBatDongSan::Xuat(){
    if(ct==nullptr||sl==0) cout<<"Danh sach giao dich rong"<<endl;
    else{
        cout<<"\n===== THONG TIN CAC GIAO DICH=====\n";
        for(int i=0; i<sl; i++){
            cout<<"--- GIAO DICH THU "<<i+1<<" ---"<<endl;
            ct[i]->Xuat();
            cout<<endl;
        }
    }
}
void CongTyBatDongSan::TongSoLuongGiaoDich(){
    cout<<"So luong giao dich dat: "<<GiaoDichDat::GetDem()<<endl;
    cout<<"So luong giao dich nha pho: "<<GiaoDichNhaPho::GetDem()<<endl;
    cout<<"So luong giao dich can ho chung cu: "<<GiaoDichChungCu::GetDem()<<endl;
    cout<<"Tong so luong cac giao dich: "<<GiaoDich::GetDem()<<endl;
}
double CongTyBatDongSan::TrungBinhThanhTienChungCu(){
    int cnt=0;
    double res=0;
    for(int i=0; i<sl; i++)
        if(ct[i]->GetLoai()=="Giao dich can ho chung cu"){
            res+=ct[i]->ThanhTien();
            cnt++;
        }
    return cnt>0?res/cnt:0;
}
void CongTyBatDongSan::NhaPhoCoGiaTriCaoNhat(){
    double nmax=-1;
    for(int i=0; i<sl; i++){
        if(ct[i]->GetLoai()=="Giao dich nha pho"&&ct[i]->ThanhTien()>nmax)
            nmax=ct[i]->ThanhTien();
    }
    if(nmax==-1){
        cout<<"Khong ton tai giao dich nha pho";
        return;
    } 
    cout<<"\n===== GIAO DICH NHA PHO CO GIA TRI CAO NHAT =====\n";
    for(int i=0; i<sl; i++){
        if(ct[i]->GetLoai()=="Giao dich nha pho"&&ct[i]->ThanhTien()==nmax)
        cout<<"--- GIAO DICH THU "<<i+1<<" ---"<<endl;
        ct[i]->Xuat();
        cout<<endl;
    }
}
void CongTyBatDongSan::GiaoDichThang12Nam2024(){
    bool check=false;
    for(int i=0; i<sl; i++){
        string ngay=ct[i]->GetNgayGD();
        if(ngay.length()>=7&&ngay.substr(ngay.length()-7)=="12/2024"){
            check=true;
            cout<<"--- GIAO DICH THU "<<i+1<<" ---"<<endl;
            ct[i]->Xuat();
            cout<<endl;
        }
    }
    if(!check) cout<<"Khong co giao dich vao thang 12 nam 2024"<<endl;
}