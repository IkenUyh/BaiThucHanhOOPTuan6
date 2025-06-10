#include"khachhanga.cpp"
#include"khachhangb.cpp"
#include"khachhangc.cpp"
#include"congty.cpp"
#include"khachhang.cpp"
int main(){
    CongTy ct;
    cout<<"===== CHUONG TRINH QUAN LY KHACH HANG XYZ =====\n\n";
    cout<<"1. Nhap danh sach khach hang tu file XYZ.INP:\n";
    ct.Nhap();
    cout<<"\n2. Xuat danh sach khach hang ra file XYZ.OUT:\n";
    ct.Xuat();
    cout<<"\n3. Thong ke:\n";
    cout<<"So luong khach hang: "<<KhachHang::GetDem()<<endl;
    cout<<"So luong khach hang A: "<<KhachHangA::GetDem()<<endl;
    cout<<"So luong khach hang B: "<<KhachHangB::GetDem()<<endl;
    cout<<"So luong khach hang C: "<<KhachHangC::GetDem()<<endl;
    cout<<"\n===== KET THUC CHUONG TRINH =====\n";
    return 0;
}