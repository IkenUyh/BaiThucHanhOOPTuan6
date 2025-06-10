#include"bo.h"
int Bo::dem=0;
Bo::~Bo(){
    cout<<"Da huy mot con bo"<<endl;
    --dem;
}
Bo::Bo():DongVat(){
    ++dem;
}
Bo::Bo(double sua, int con):DongVat(sua, con){
    ++dem;
}
Bo::Bo(const Bo& bo):DongVat(bo){
    ++dem;
}
Bo& Bo::operator=(const Bo& bo){
    DongVat::operator=(bo);
    return *this;
}
int Bo::GetDem(){
    return dem;
}
void Bo::ChoSua(){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 20);
    this->sua=dis(gen);
}
void Bo::Keu(){
    cout<<"Ummmm boooo."<<endl;
}
string Bo::GetLoai(){
    return "Bo";
}