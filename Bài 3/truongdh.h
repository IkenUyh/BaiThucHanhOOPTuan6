#include"sinhvien.h"
#pragma once
#ifndef _TRUONGDAIHOC
#define _TRUONGDAIHOC
class TruongDaiHoc{
    private:   
        SinhVien** dh;
        int sl;
        static int dem;
    public:
        ~TruongDaiHoc();
        TruongDaiHoc();
        TruongDaiHoc(int);
        TruongDaiHoc(int, SinhVien**);
        TruongDaiHoc(const TruongDaiHoc&);
        TruongDaiHoc& operator=(const TruongDaiHoc&);
        int GetSoLuong();
        static int GetDem();
        void SetSoLuong(int);
        void Nhap();
        SinhVien* Nhap1();
        void Xuat();
        void SinhVienDuDieuKienTotNghiep();
        void SinhVienKhongDuDieuKienTotNghiep();
        void SinhVienDaiHocCoDiemTBCaoNhat();
        void SinhVienCaoDangCoDiemTBCaoNhat();
        void ThongKeSinhVienKhongTotNghiep();
};
#endif