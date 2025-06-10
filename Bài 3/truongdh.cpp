#include"daihoc.h"
#include"caodang.h"
#include"truongdh.h"
int TruongDaiHoc::dem=0;
TruongDaiHoc::~TruongDaiHoc(){
    if(dh!=nullptr){
        for(int i=0; i<sl; i++)
            delete dh[i];
        delete[] dh;
        dh=nullptr;
        sl=0;
    }
    --dem;
}
TruongDaiHoc::TruongDaiHoc():sl(0), dh(nullptr){
    ++dem;
}
TruongDaiHoc::TruongDaiHoc(int sl):sl(sl), dh(nullptr){
    if(sl>0){
        dh=new SinhVien*[sl];
        for(int i=0; i<sl; i++)
            dh[i]=nullptr;
    }
    ++dem;
}
TruongDaiHoc::TruongDaiHoc(int sl, SinhVien** other):sl(sl), dh(nullptr){
    if(sl>0&&other!=nullptr){
        dh=new SinhVien*[sl];
        for(int i=0; i<sl; i++){
            if(other[i]->GetLoai()=="Cao dang")
                dh[i]=new SinhVienCaoDang(*(SinhVienCaoDang*)other[i]);
            else 
                dh[i]=new SinhVienDaiHoc(*(SinhVienDaiHoc*)other[i]);
        }
    }
    ++dem;
}
TruongDaiHoc::TruongDaiHoc(const TruongDaiHoc& other):sl(other.sl), dh(nullptr){
    if(sl>0&&other.dh!=nullptr){
        dh=new SinhVien*[sl];
        for(int i=0; i<sl; i++){
            if(other.dh[i]->GetLoai()=="Cao dang")
                dh[i]=new SinhVienCaoDang(*(SinhVienCaoDang*)other.dh[i]);
            else 
                dh[i]=new SinhVienDaiHoc(*(SinhVienDaiHoc*)other.dh[i]);
        }
    }
    ++dem;
}
TruongDaiHoc& TruongDaiHoc::operator=(const TruongDaiHoc& other){
    if(this!=&other){
        if(dh!=nullptr){
            for(int i=0; i<sl; i++)
                delete dh[i];
            delete[] dh;
        }
        this->sl=other.sl;
        if(sl>0&&other.dh!=nullptr){
            dh=new SinhVien*[sl];
            for(int i=0; i<sl; i++){
                if(other.dh[i]->GetLoai()=="Cao dang")
                    dh[i]=new SinhVienCaoDang(*(SinhVienCaoDang*)other.dh[i]);
                else
                    dh[i]=new SinhVienDaiHoc(*(SinhVienDaiHoc*)other.dh[i]);
            }
        }
        else dh=nullptr;
    }
    return *this;
}
int TruongDaiHoc::GetSoLuong(){
    return this->sl;
}
int TruongDaiHoc::GetDem(){
    return dem;
}
void TruongDaiHoc::SetSoLuong(int sl){
    while(sl<1){
        cout<<"So luong sinh vien khong hop le! Moi ban nhap lai"<<endl;
        cin>>sl;
    }
    this->sl=sl;
}
void TruongDaiHoc::Nhap(){
    if(dh!=nullptr){
        for(int i=0; i<sl; i++)
            delete dh[i];
        delete[] dh;
        dh=nullptr;
    }
    int loai;
    do{
        cout<<"Nhap so luong sinh vien: "; cin>>sl;
        if(sl<1) cout<<"So luong khong hop le! Moi ban nhap lai"<<endl;
    }while(sl<1);
    dh=new SinhVien*[sl];
    for(int i=0; i<sl; i++){
        cout<<"\n========================\n";
        cout<<"Nhap thong tin hoc sinh thu "<<i+1<<": "<<endl;
        do{
            cout<<"Nhap he (1: Cao dang, 2: Dai hoc): "; cin>>loai;
            if(loai!=1&&loai!=2) cout<<"He sinh vien khong hop le! Moi ban nhap lai"<<endl;
        }while(loai!=1&&loai!=2);
        if(loai==1)
            dh[i]=new SinhVienCaoDang;
        else
            dh[i]=new SinhVienDaiHoc;
        dh[i]->Nhap();
        dh[i]->TotNghiep();
    }
}
SinhVien* TruongDaiHoc::Nhap1(){
    int loai; SinhVien* sv;
    do{
        cout<<"Nhap he (1: Cao dang, 2: Dai hoc): "; cin>>loai;
        if(loai!=1&&loai!=2) cout<<"He sinh vien khong hop le! Moi ban nhap lai"<<endl;
    }while(loai!=1&&loai!=2);
    if(loai==1) sv=new SinhVienCaoDang;
    else sv=new SinhVienDaiHoc;
    sv->Nhap();
    sv->TotNghiep();
    return sv;
}
void TruongDaiHoc::Xuat(){
    if(sl==0||dh==nullptr){
        cout<<"Danh sach sinh vien rong"<<endl;
        return;
    }
    cout<<"\n===== DANH SACH SINH VIEN =====\n";
    for(int i=0; i<sl; i++){
        cout<<"--- THONG TIN SINH VIEN THU "<<i+1<<" ---"<<endl;
        dh[i]->Xuat();
        cout<<endl;
    }
}
void TruongDaiHoc::SinhVienDuDieuKienTotNghiep(){
    bool check=false;
    cout<<"\n===== SINH VIEN DU DIEU KIEN TOT NGHIEP =====\n";
    for(int i=0; i<sl; i++)
        if(dh[i]->TotNghiep()){
            check=true;
            cout<<"--- THONG TIN SINH VIEN THU "<<i+1<<" ---"<<endl;
            dh[i]->Xuat();
            cout<<endl;
        }
    if(!check) cout<<"Khong co sinh vien nao du dieu kien tot nghiep"<<endl;
}
void TruongDaiHoc::SinhVienKhongDuDieuKienTotNghiep(){
    bool check=false;
    cout<<"\n==== SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP =====\n";
    for(int i=0; i<sl; i++)
        if(!(dh[i]->TotNghiep())){
            check=true;
            cout<<"--- THONG TIN SINH VIEN THU "<<i+1<<" ---"<<endl;
            dh[i]->Xuat();
            cout<<endl;
        }
    if(!check) cout<<"Khong co sinh vien nao khong du dieu kien tot nghiep"<<endl;
}
void TruongDaiHoc::SinhVienDaiHocCoDiemTBCaoNhat(){
    double nmax=-1;
    for(int i=0; i<sl; i++)
        if(dh[i]->GetLoai()=="Dai hoc"&&dh[i]->GetDiemTB()>nmax)
            nmax=dh[i]->GetDiemTB();
    if(nmax==-1) cout<<"Khong co sinh vien dai hoc"<<endl;
    else{
        cout<<"\n===== SINH VIEN DAI HOC CO DIEM TRUNG BINH CAO NHAT =====\n";
        for(int i=0; i<sl; i++)
            if(dh[i]->GetLoai()=="Dai hoc"&&dh[i]->GetDiemTB()==nmax){
                cout<<"--- THONG TIN SINH VIEN THU "<<i+1<<" ---"<<endl;
                dh[i]->Xuat();
                cout<<endl;
            }
    }
}
void TruongDaiHoc::SinhVienCaoDangCoDiemTBCaoNhat(){
    double nmax=-1;
    for(int i=0; i<sl; i++)
        if(dh[i]->GetLoai()=="Cao dang"&&dh[i]->GetDiemTB()>nmax)
            nmax=dh[i]->GetDiemTB();
    if(nmax==-1) cout<<"Khong co sinh vien cao dang"<<endl;
    else{
        cout<<"\n===== SINH VIEN CAO DANG CO DIEM TRUNG BINH CAO NHAT =====\n";
        for(int i=0; i<sl; i++)
            if(dh[i]->GetLoai()=="Cao dang"&&dh[i]->GetDiemTB()==nmax){
                cout<<"--- THONG TIN SINH VIEN THU "<<i+1<<" ---"<<endl;
                dh[i]->Xuat();
                cout<<endl;
            }
    }
}
void TruongDaiHoc::ThongKeSinhVienKhongTotNghiep(){
    int cntcd=0, cntdh=0;
    for(int i=0; i<sl; i++){
        if(dh[i]->GetLoai()=="Cao dang"&&!(dh[i]->TotNghiep())) cntcd++;
        else if(dh[i]->GetLoai()=="Dai hoc"&&!(dh[i]->TotNghiep())) cntdh++;
    }
    cout<<"\n===== SO LUONG SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP =====\n";
    cout<<"So luong sinh vien cao dang khong du dieu kien tot nghiep: "<<cntcd<<endl;
    cout<<"So luong sinh vien dai hoc khong du dieu kien tot nghiep: "<<cntdh<<endl;
}