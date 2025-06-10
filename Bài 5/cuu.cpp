#include"cuu.h"
int Cuu::dem=0;
Cuu::~Cuu(){
    cout<<"Da huy mot con cuu"<<endl;
    --dem;
}
Cuu::Cuu():DongVat(){
    ++dem;
}
Cuu::Cuu(double sua, int con):DongVat(sua, con){
    ++dem;
}
Cuu::Cuu(const Cuu& cuu):DongVat(cuu){
    ++dem;
}
Cuu& Cuu::operator=(const Cuu& cuu){
    DongVat::operator=(cuu);
    return *this;
}
int Cuu::GetDem(){
    return dem;
}
void Cuu::ChoSua(){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 5);
    this->sua=dis(gen);
}
void Cuu::Keu(){
    cout<<"Beeee Beeeeef."<<endl;
}
string Cuu::GetLoai(){
    return "Cuu";
}