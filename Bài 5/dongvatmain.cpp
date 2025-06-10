#include"nongtrai.cpp"
#include"bo.cpp"
#include"cuu.cpp"
#include"de.cpp"
#include"dongvat.cpp"
int main(){
    NongTrai nt;
    cout<<"===== CHUONG TRINH QUAN LY NONG TRAI =====\n\n";
    cout<<"1. Nhap danh sach gia suc:\n";
    nt.Nhap();
    cout<<"\n2. Tieng keu cua gia suc khi doi:\n";
    nt.Hungry();
    cout<<"\n3. Thong ke nong trai:\n";
    nt.Xuat();
    cout<<"\n4. Thong ke:\n";
    cout<<"Tong so dong vat: "<<DongVat::GetDem()<<endl;
    cout<<"Tong so bo: "<<Bo::GetDem()<<endl;
    cout<<"Tong so cuu: "<<Cuu::GetDem()<<endl;
    cout<<"Tong so de: "<<De::GetDem()<<endl;
    cout<<"\n===== KET THUC CHUONG TRINH =====\n";
    return 0;
}