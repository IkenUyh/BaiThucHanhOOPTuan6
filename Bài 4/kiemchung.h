#include"nhanvien.h"
#pragma once
#ifndef _KIEMCHUNGVIEN
#define _KIEMCHUNGVIEN
class KiemChungVien : public NhanVien{
    private:
        int soloi;
        static int dem;
    public:
        ~KiemChungVien();
        KiemChungVien();
        KiemChungVien(string, string, int, string, string, double, int);
        KiemChungVien(const KiemChungVien&);
        KiemChungVien& operator=(const KiemChungVien&);
        int GetSoLoi();
        static int GetDem();
        void SetSoLoi(int);
        void Nhap();
        void Xuat();
        string GetLoai();
        double TinhLuong();
};
#endif