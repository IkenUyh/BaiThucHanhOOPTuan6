#include"nhanvien.h"
#pragma once
#ifndef _SANXUAT
#define _SANXUAT
class SanXuat : public NhanVien{
    private:
        double luongcb;
        int sosanpham;
        static int dem;
    public:
        ~SanXuat();
        SanXuat();
        SanXuat(string, string, double, int);
        SanXuat(const SanXuat&);
        SanXuat& operator=(const SanXuat&);
        double GetLuongCanBan();
        int GetSoSanPham();
        static int GetDem();
        void SetLuongCanBan(double);
        void SetSoSanPham(int);
        void Nhap();
        void Xuat();
        string GetLoai();
        void TinhLuong();
};
#endif