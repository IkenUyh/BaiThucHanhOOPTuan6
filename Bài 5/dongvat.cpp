#include"dongvat.h"
int DongVat::dem=0;
DongVat::~DongVat(){
    cout<<"Da huy mot dong vat"<<endl;
    --dem;
}
DongVat::DongVat():sua(0), con(0){
    ++dem;
}
DongVat::DongVat(double sua, int con):sua(sua), con(con){
    ++dem;
}
DongVat::DongVat(const DongVat& dv){
    this->sua=dv.sua;
    this->con=dv.con;
    ++dem;
}
DongVat& DongVat::operator=(const DongVat& dv){
    this->sua=dv.sua;
    this->con=dv.con;
    return *this;
}
double DongVat::GetSua(){
    return this->sua;
}
int DongVat::GetCon(){
    return this->con;
}
int DongVat::GetDem(){
    return dem;
}
void DongVat::SinhCon(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);
    this->con=dis(gen);
}