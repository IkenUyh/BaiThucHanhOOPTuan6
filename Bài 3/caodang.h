#include"sinhvien.h"
#pragma once
#ifndef _SINHVIENCAODANG
#define _SINHVIENCAODANG
class SinhVienCaoDang : public SinhVien{
    private:
        double diemtn;
        static int dem;
    public:
        ~SinhVienCaoDang();
        SinhVienCaoDang();
        SinhVienCaoDang(string, string, string, int, double, double);
        SinhVienCaoDang(const SinhVienCaoDang&);
        SinhVienCaoDang& operator=(const SinhVienCaoDang&);
        double GetDiemTN();
        static int GetDem();
        void SetDiemTN(double);
        void Nhap();
        void Xuat();
        string GetLoai();
        bool TotNghiep();
};
#endif