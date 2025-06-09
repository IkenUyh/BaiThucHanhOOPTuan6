#include"giaodich.cpp"
#include"giaodichdat.cpp"
#include"giaodichnha.cpp"
#include"giaodichchungcu.cpp"
#include"congty.cpp"
int main(){
    CongTyBatDongSan ct;
    cout<<"\n===== CHUONG TRINH QUAN LY GIAO DICH =====\n";
    cout<<"1. Nhap danh sach cac giao dich: "<<endl; ct.Nhap();
    cout<<"Danh sach cac giao dich vua nhap: "<<endl; ct.Xuat();
    cout<<"2. Tong so luong cac giao dich: "<<endl; 
    ct.TongSoLuongGiaoDich();
    cout<<"3. Trung binh thanh tien cua giao dich chung cu: "
    <<fixed<<setprecision(2)<<ct.TrungBinhThanhTienChungCu()<<endl;
    cout<<"4. Nha pho co gia tri cao nhat: "<<endl;
    ct.NhaPhoCoGiaTriCaoNhat();
    cout<<"5. Cac giao dich thang 12 nam 2024: "<<endl;
}