#include"nhanvien.h"
#pragma once
#ifndef _LAPTRINHVIEN
#define _LAPTRINHVIEN
class LapTrinhVien : public NhanVien{
    private:
        int sogioot;
        static int dem;
    public:
        ~LapTrinhVien();
        LapTrinhVien();
        LapTrinhVien(string, string, int, string, string, double, int);
        LapTrinhVien(const LapTrinhVien&);
        LapTrinhVien& operator=(const LapTrinhVien&);
        int GetSoGioOT();
        static int GetDem();
        void SetSoGioOT(int);
        void Nhap();
        void Xuat();
        string GetLoai();
        double TinhLuong();
};
#endif