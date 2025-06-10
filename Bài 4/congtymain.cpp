#include"nhanvien.cpp"
#include"laptrinh.cpp"
#include"kiemchung.cpp"
#include"congty.cpp"
int main(){
    CongTy ct;
    cout<<"===== CHUONG TRINH QUAN LY CONG TY HOAN CAU =====\n\n";
    cout<<"1. Nhap danh sach nhan vien:\n";
    ct.Nhap();
    cout<<"Danh sach vua nhap:\n"; ct.Xuat();
    cout<<"\n2. Nhan vien co luong thap hon trung binh:\n";
    ct.NVCoLuongThapHonTB();
    cout<<"\n3. Nhan vien co luong cao nhat:\n";
    ct.NVCaoNhatLuong();
    cout<<"\n4. Nhan vien co luong thap nhat:\n";
    ct.NVThapNhatLuong();
    cout<<"\n5. Lap trinh vien co luong cao nhat:\n";
    ct.LTVCaoNhatLuong();
    cout<<"\n6. Kiem chung vien co luong thap nhat:\n";
    ct.KCVCaoNhatLuong();
    cout<<"\n7. Thong ke:\n";
    cout<<"So luong nhan vien: "<<NhanVien::GetDem()<<endl;
    cout<<"So luong lap trinh vien: "<<LapTrinhVien::GetDem()<<endl;
    cout<<"So luong kiem chung vien: "<<KiemChungVien::GetDem()<<endl;
    cout<<"\n===== KET THUC CHUONG TRINH =====\n";
    return 0;
}