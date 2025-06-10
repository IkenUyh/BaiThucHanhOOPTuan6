#include"congty.h"
#include"laptrinh.h"
#include"kiemchung.h"
int CongTy::dem=0;
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
            if(nv[i]->GetLoai()=="Lap trinh vien")
                ct[i]=new LapTrinhVien(*(LapTrinhVien*)nv[i]);
            else
                ct[i]=new KiemChungVien(*(KiemChungVien*)nv[i]);
        }
    }
    ++dem;
}
CongTy::CongTy(const CongTy& other):sl(other.sl), ct(nullptr){
    if(sl>0&&other.ct!=nullptr){
        ct=new NhanVien*[sl];
        for(int i=0; i<sl; i++){
            if(other.ct[i]->GetLoai()=="Lap trinh vien")
                ct[i]=new LapTrinhVien(*(LapTrinhVien*)other.ct[i]);
            else
                ct[i]=new KiemChungVien(*(KiemChungVien*)other.ct[i]);
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
        sl=other.sl;
        if(sl>0&&other.ct!=nullptr){
            ct=new NhanVien*[sl];
            for(int i=0; i<sl; i++){
                if(other.ct[i]->GetLoai()=="Lap trinh vien")
                    ct[i]=new LapTrinhVien(*(LapTrinhVien*)other.ct[i]);
                else
                    ct[i]=new KiemChungVien(*(KiemChungVien*)other.ct[i]);
            }
        }
        else ct=nullptr;
    }
    return *this;
}
int CongTy::GetSL(){
    return this->sl;
}
int CongTy::GetDem(){
    return dem;
}
void CongTy::SetSL(){
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
        cout<<"\n===========================\n";
        cout<<"Nhap thong tin nhan vien thu "<<i+1<<": "<<endl;
        do{
            cout<<"Nhap loai (1: Lap trinh vien, 2: Kiem chung vien): ";
            cin>>loai;
            if(loai!=1&&loai!=2) cout<<"Loai nhan vien khong hop le! Moi ban nhap lai"<<endl;
        }while(loai!=1&&loai!=2);
        if(loai==1)
            ct[i]=new LapTrinhVien;
        else
            ct[i]=new KiemChungVien;
        ct[i]->Nhap();
    }
}
NhanVien* CongTy::Nhap1(){
    int loai;
    NhanVien* nv;
    do{
        cout<<"Nhap loai (1: Lap trinh vien, 2: Kiem chung vien): ";
        cin>>loai;
        if(loai!=1&&loai!=2) cout<<"Loai nhan vien khong hop le! Moi ban nhap lai"<<endl;
    }while(loai!=1&&loai!=2);
    if(loai==1)
        nv=new LapTrinhVien;
    else
        nv=new KiemChungVien;
    nv->Nhap();
    return nv;
}
void CongTy::Xuat(){
    if(ct==nullptr) cout<<"Danh sach nhan vien rong"<<endl;
    else{
        cout<<"\n=====THONG TIN NHAN VIEN======\n";
        for(int i=0; i<sl; i++){
            cout<<"---NHAN VIEN THU "<<i+1<<"---"<<endl;
            ct[i]->Xuat();
            cout<<endl;
        }
    }
}
double CongTy::LuongTBCuaNhanVien(){
    double sum=0;
    int dem=0;
    for(int i=0; i<sl; i++){
        sum+=ct[i]->TinhLuong();
        dem++;
    }
    return dem>0?sum/dem:0;
}
void CongTy::NVCoLuongThapHonTB(){
    double tb=LuongTBCuaNhanVien();
    int cnt=0;
    cout<<"\n=====NHAN VIEN CO LUONG THAP HON TRUNG BINH ("<<fixed<<setprecision(2)<<tb<<")=====\n";
    for(int i=0; i<sl; i++)
        if(ct[i]->TinhLuong()<tb){
            cout<<"---NHAN VIEN THU "<<cnt+1<<"---"<<endl;
            ct[i]->Xuat();
            cout<<endl;
            cnt++;
        }
    if(!cnt) cout<<"Khong co nhan vien nao co luong thap hon trung binh!"<<endl;
}
void CongTy::NVCaoNhatLuong(){
    double maxLuong=-1;
    for(int i=0; i<sl; i++)
        if(ct[i]->TinhLuong()>maxLuong)
            maxLuong=ct[i]->TinhLuong();
    if(maxLuong==-1){
        cout<<"Cong ty khong co nhan vien"<<endl;
        return;
    }
    cout<<"\n=====NHAN VIEN CO LUONG CAO NHAT=====\n";
    for(int i=0; i<sl; i++)
        if(ct[i]->TinhLuong()==maxLuong){
            cout<<"---NHAN VIEN THU "<<i+1<<"---"<<endl;
            ct[i]->Xuat();
            cout<<endl;
        }
}
void CongTy::NVThapNhatLuong(){
    double minLuong=1e9;
    for(int i=0; i<sl; i++)
        if(ct[i]->TinhLuong()<minLuong)
            minLuong=ct[i]->TinhLuong();
    if(minLuong==1e9){
        cout<<"Cong ty khong co nhan vien"<<endl;
        return;
    }
    cout<<"\n=====NHAN VIEN CO LUONG THAP NHAT=====\n";
    for(int i=0; i<sl; i++)
        if(ct[i]->TinhLuong()==minLuong){
            cout<<"---NHAN VIEN THU "<<i+1<<"---"<<endl;
            ct[i]->Xuat();
            cout<<endl;
        }
}
void CongTy::LTVCaoNhatLuong(){
    double maxLuong=-1;
    for(int i=0; i<sl; i++)
        if(ct[i]->GetLoai()=="Lap trinh vien"&&ct[i]->TinhLuong()>maxLuong)
            maxLuong=ct[i]->TinhLuong();
    if(maxLuong==-1){
        cout<<"Cong ty khong co lap trinh vien"<<endl;
        return;
    }
    cout<<"\n=====LAP TRINH VIEN CO LUONG CAO NHAT=====\n";
    for(int i=0; i<sl; i++)
        if(ct[i]->GetLoai()=="Lap trinh vien"&&ct[i]->TinhLuong()==maxLuong){
            cout<<"---NHAN VIEN THU "<<i+1<<"---"<<endl;
            ct[i]->Xuat();
            cout<<endl;
        }
}
void CongTy::KCVCaoNhatLuong(){
    double minLuong=1e9;
    for(int i=0; i<sl; i++)
        if(ct[i]->GetLoai()=="Kiem chung vien"&&ct[i]->TinhLuong()<minLuong)
            minLuong=ct[i]->TinhLuong();
    if(minLuong==1e9){
        cout<<"Cong ty khong co kiem chung vien"<<endl;
        return;
    }
    cout<<"\n=====KIEM CHUNG VIEN CO LUONG THAP NHAT=====\n";
    for(int i=0; i<sl; i++)
        if(ct[i]->GetLoai()=="Kiem chung vien"&&ct[i]->TinhLuong()==minLuong){
            cout<<"---NHAN VIEN THU "<<i+1<<"---"<<endl;
            ct[i]->Xuat();
            cout<<endl;
        }
}