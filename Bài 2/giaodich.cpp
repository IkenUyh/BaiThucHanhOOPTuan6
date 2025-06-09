#include"giaodich.h"
int GiaoDich::dem=0;
GiaoDich::~GiaoDich(){
    cout<<"Da huy mot giao dich"<<endl;
    --dem;
}
GiaoDich::GiaoDich():magd(""), ngaydg(""), dongia(0), dientich(0){
    ++dem;
}
GiaoDich::GiaoDich(string magd, string ngaygd, double dongia, double dientich)
:magd(magd), ngaydg(ngaydg), dongia(dongia), dientich(dientich){
    ++dem;
}
GiaoDich::GiaoDich(const GiaoDich& gd):magd(gd.magd), ngaydg(gd.ngaydg),
dongia(gd.dongia), dientich(gd.dientich){
    ++dem;
}
GiaoDich& GiaoDich::operator=(const GiaoDich& gd){
    this->magd=gd.magd;
    this->ngaydg=gd.ngaydg;
    this->dongia=gd.dongia;
    this->dientich=gd.dientich;
    return *this;
}
string GiaoDich::GetMaGD(){
    return this->magd;
}
string GiaoDich::GetNgayGD(){
    return this->ngaydg;
}
double GiaoDich::GetDonGia(){
    return this->dongia;
}
double GiaoDich::GetDienTich(){
    return this->dientich;
}
int GiaoDich::GetDem(){
    return dem;
}
void GiaoDich::SetMaGD(string magd){
    this->magd=magd;
}
void GiaoDich::SetNgayGD(string ngaygd){
    this->ngaydg=ngaydg;
}
void GiaoDich::SetDonGia(double dongia){
    while(dongia<=0){
        cout<<"Don gia khong hop le! Moi ban nhap lai: ";
        cin>>dongia;
    }
    this->dongia=dongia;
}
void GiaoDich::SetDienTich(double dientich){
    while(dientich<=0){
        cout<<"Dien tich khong hop le! Moi ban nhap lai: ";
        cin>>dientich;
    }
    this->dientich=dientich;
}
void GiaoDich::Nhap(){
    cin.ignore();
    cout<<"Nhap ma giao dich: "; getline(cin, magd);
    cout<<"Nhap ngay giao dich (dd/mm/yyyy): "; getline(cin, ngaydg);
    do{
        cout<<"Nhap don gia: "; cin>>dongia;
        if(dongia<=0) cout<<"Don gia khong hop le! Moi ban nhap lai"<<endl;
    }while(dongia<=0);
    do{
        cout<<"Nhap dien tich: "; cin>>dientich;
        if(dientich<=0) cout<<"Dien tich khong hop le! Moi ban nhap lai"<<endl;
    }while(dientich<=0);
}
void GiaoDich::Xuat(){
    cout<<"Ma giao dich: "<<magd<<endl;
    cout<<"Ngay giao dich (dd/mm/yyyy): "<<ngaydg<<endl;
    cout<<"Don gia: "<<fixed<<setprecision(2)<<dongia<<endl;
    cout<<"Dien tich: "<<fixed<<setprecision(2)<<dientich<<endl;
    cout<<"Loai: "<<GetLoai()<<endl;
    cout<<"Thanh tien: "<<fixed<<setprecision(2)<<ThanhTien()<<endl;
}