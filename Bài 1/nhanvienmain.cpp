#include"congty.cpp"
#include"nhanvien.cpp"
#include"vanphong.cpp"
#include"sanxuat.cpp"
int main(){
    CongTy ct;
    cout<<"\n===== CHUONG TRINH QUAN LY CONG TY =====\n";
    cout<<"1. Nhap danh sach nhan vien: "<<endl; ct.Nhap();
    cout<<"Danh sach nhan vien vua nhap: "<<endl; ct.Xuat();
    cout<<"2. Tong luong cong ty phai tra: "<<fixed<<setprecision(2)<<ct.TongLuong()<<endl;
    cout<<"3. Nhan vien san xuat co luong thap nhat: "; ct.NhanVienSXLuongThapNhat();
    cout<<"4. Nhan vien van phong co lon tuoi nhat: "; ct.NhanVienVPTuoiCaoNhat();
    cout<<endl;
    cout<<"5. Thong ke: "<<endl;
    cout<<"So luong nhan vien: "<<NhanVien::GetDem()<<endl;
    cout<<"So luong nhan vien san xuat: "<<SanXuat::GetDem()<<endl;
    cout<<"So luong nhan vien van phong: "<<VanPhong::GetDem()<<endl;
    cout<<"\n===== KET THUC CHUONG TRINH =====\n";
    return 0;
}