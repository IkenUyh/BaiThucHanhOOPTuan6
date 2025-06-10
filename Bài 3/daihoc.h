#include"sinhvien.h"
#pragma once
#ifndef _SINHVIENDAIHOC
#define _SINHVIENDAIHOC
class SinhVienDaiHoc : public SinhVien{
    private:
        string tenluanvan;
        double diemluanvan;
        static int dem;
    public:
        ~SinhVienDaiHoc();
        SinhVienDaiHoc();
        SinhVienDaiHoc(string, string, string, int, double, string, double);
        SinhVienDaiHoc(const SinhVienDaiHoc&);
        SinhVienDaiHoc& operator=(const SinhVienDaiHoc&);
        string GetTenLuanVan();
        double GetDiemLuanVan();
        static int GetDem();
        void SetTenLuanVan(string);
        void SetDiemLuanVan(double);
        void Nhap();
        void Xuat();
        string GetLoai();
        bool TotNghiep();
};
#endif