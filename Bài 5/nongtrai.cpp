#include"bo.h"
#include"cuu.h"
#include"de.h"
#include"nongtrai.h"
int NongTrai::dem=0;
NongTrai::~NongTrai(){
    if(this->dv!=nullptr){
        for(int i=0; i<this->sl; i++)
            delete this->dv[i];
        delete[] this->dv;
        this->dv=nullptr;
        this->sl=0;
    }
    cout<<"Da huy mot nong trai"<<endl;
    --dem;
}
NongTrai::NongTrai():sl(0), dv(nullptr){
    ++dem;
}
NongTrai::NongTrai(int sl):sl(sl), dv(nullptr){
    if(this->sl>0){
        this->dv=new DongVat*[this->sl];
        for(int i=0; i<this->sl; i++)
            this->dv[i]=nullptr;
    }
    ++dem;
}
NongTrai::NongTrai(const NongTrai& other):sl(other.sl), dv(nullptr){
    if(this->sl>0&&other.dv!=nullptr){
        this->dv=new DongVat*[this->sl];
        for(int i=0; i<this->sl; i++){
            if(other.dv[i]->GetLoai()=="Bo")
                this->dv[i]=new Bo(*(Bo*)other.dv[i]);
            else if(other.dv[i]->GetLoai()=="Cuu")
                this->dv[i]=new Cuu(*(Cuu*)other.dv[i]);
            else
                this->dv[i]=new De(*(De*)other.dv[i]);
        }
    }
    ++dem;
}
NongTrai& NongTrai::operator=(const NongTrai& other){
    if(this!=&other){
        if(this->dv!=nullptr){
            for(int i=0; i<this->sl; i++)
                delete this->dv[i];
            delete[] this->dv;
        }
        this->sl=other.sl;
        if(this->sl>0&&other.dv!=nullptr){
            this->dv=new DongVat*[this->sl];
            for(int i=0; i<this->sl; i++){
                if(other.dv[i]->GetLoai()=="Bo")
                    this->dv[i]=new Bo(*(Bo*)other.dv[i]);
                else if(other.dv[i]->GetLoai()=="Cuu")
                    this->dv[i]=new Cuu(*(Cuu*)other.dv[i]);
                else
                    this->dv[i]=new De(*(De*)other.dv[i]);
            }
        }
        else this->dv=nullptr;
    }
    return *this;
}
int NongTrai::GetSL(){
    return this->sl;
}
int NongTrai::GetDem(){
    return dem;
}
void NongTrai::SetSL(){
    while(this->sl<1){
        cout<<"So luong gia suc khong hop le! Moi ban nhap lai: ";
        cin>>this->sl;
    }
}
void NongTrai::Nhap(){
    int loai;
    if(this->dv!=nullptr){
        for(int i=0; i<this->sl; i++)
            delete this->dv[i];
        delete[] this->dv;
        this->dv=nullptr;
    }
    do{
        cout<<"Nhap so luong gia suc: "; cin>>this->sl;
        if(this->sl<1) cout<<"So luong gia suc khong hop le! Moi ban nhap lai"<<endl;
    }while(this->sl<1);
    this->dv=new DongVat*[this->sl];
    for(int i=0; i<this->sl; i++){
        cout<<"\n===========================\n";
        cout<<"Nhap thong tin gia suc thu "<<i+1<<": "<<endl;
        do{
            cout<<"Nhap loai (1: Bo, 2: Cuu, 3: De): ";
            cin>>loai;
            if(loai!=1&&loai!=2&&loai!=3) cout<<"Loai gia suc khong hop le! Moi ban nhap lai"<<endl;
        }while(loai!=1&&loai!=2&&loai!=3);
        if(loai==1)
            this->dv[i]=new Bo;
        else if(loai==2)
            this->dv[i]=new Cuu;
        else
            this->dv[i]=new De;
    }
}
void NongTrai::Hungry(){
    if(this->dv==nullptr){
        cout<<"Nong trai khong co gia suc"<<endl;
        return;
    }
    cout<<"\n=====TIENG KEU CUA GIA SUC KHI DOI=====\n";
    for(int i=0; i<this->sl; i++){
        cout<<"Gia suc thu "<<i+1<<" ("<<this->dv[i]->GetLoai()<<"): ";
        this->dv[i]->Keu();
    }
}
void NongTrai::Xuat(){
    if(this->dv==nullptr){
        cout<<"Nong trai khong co gia suc"<<endl;
        return;
    }
    cout<<"\n=====THONG KE NONG TRAI=====\n";
    for(int i=0; i<this->sl; i++){
        this->dv[i]->SinhCon();
        this->dv[i]->ChoSua();
    }
    double tongSua=0;
    int soBo=0, soCuu=0, soDe=0;
    int conBo=0, conCuu=0, conDe=0;
    for(int i=0; i<this->sl; i++){
        tongSua+=this->dv[i]->GetSua();
        if(this->dv[i]->GetLoai()=="Bo"){
            soBo++;
            conBo+=this->dv[i]->GetCon();
        }
        else if(this->dv[i]->GetLoai()=="Cuu"){
            soCuu++;
            conCuu+=this->dv[i]->GetCon();
        }
        else{
            soDe++;
            conDe+=this->dv[i]->GetCon();
        }
    }
    cout<<fixed<<setprecision(2);
    cout<<"Tong so lit sua thu duoc: "<<tongSua<<endl;
    cout<<"So bo trong nong trai: "<<soBo<<endl;
    cout<<"So bo con: "<<conBo<<endl;
    cout<<"So cuu trong nong trai: "<<soCuu<<endl;
    cout<<"So cuu con: "<<conCuu<<endl;
    cout<<"So de trong nong trai: "<<soDe<<endl;
    cout<<"So de con: "<<conDe<<endl;
}