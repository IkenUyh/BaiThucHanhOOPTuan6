#include"truongdh.cpp"
#include"sinhvien.cpp"
#include"caodang.cpp"
#include"daihoc.cpp"
int main(){
    TruongDaiHoc dh;
    cout<<"\n===== CHUONG TRINH QUAN LY SINH VIEN =====\n";
    cout<<"1. Nhap danh sach sinh vien: "<<endl; dh.Nhap();
    cout<<"Danh sach sinh vien vua nhap: "<<endl; dh.Xuat();
    cout<<"2. Sinh vien du dieu kien tot nghiep: "<<endl;
    dh.SinhVienDuDieuKienTotNghiep();
    cout<<"3. Sinh vien khong du dieu kien tot nghiep: "<<endl;
    dh.SinhVienKhongDuDieuKienTotNghiep();
    cout<<"4. Cac sinh vien dai hoc co diem trung binh cao nhat: "<<endl;
    dh.SinhVienDaiHocCoDiemTBCaoNhat();
    cout<<"5. Cac sinh vien cao dang co diem trung binh cao nhat: "<<endl;
    dh.SinhVienCaoDangCoDiemTBCaoNhat();
    cout<<"6. Thong ke cac sinh vien khong tot nghiep "<<endl;
    dh.ThongKeSinhVienKhongTotNghiep();
    cout<<"So luong sinh vien: "<<SinhVien::GetDem()<<endl;
    cout<<"So luong sinh vien cao dang: "<<SinhVienCaoDang::GetDem()<<endl;
    cout<<"So luong sinh vien dai hoc: "<<SinhVienDaiHoc::GetDem()<<endl;
    return 0;
}