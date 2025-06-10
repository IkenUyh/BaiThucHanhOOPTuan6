#include"de.h"
int De::dem=0;
De::~De(){
    cout<<"Da huy mot con de"<<endl;
    --dem;
}
De::De():DongVat(){
    ++dem;
}
De::De(double sua, int con):DongVat(sua, con){
    ++dem;
}
De::De(const De& de):DongVat(de){
    ++dem;
}
De& De::operator=(const De& de){
    DongVat::operator=(de);
    return *this;
}
int De::GetDem(){
    return dem;
}
void De::ChoSua(){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 10);
    this->sua=dis(gen);
}
void De::Keu(){
    cout<<"Deeeeee deeeeee."<<endl;
}
string De::GetLoai(){
    return "De";
}