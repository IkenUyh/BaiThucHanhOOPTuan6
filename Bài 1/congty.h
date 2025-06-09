#include"nhanvien.h"
#pragma once
#ifndef _CONGTY
#define _CONGTY
class CongTy{
    private:
        NhanVien** ct;
        int sl;
        static int dem;
    public:
        ~CongTy();
        CongTy();
        CongTy(int);
        CongTy(int, NhanVien**);
        CongTy(const CongTy&);
        CongTy& operator=(const CongTy&);
        int GetSoLuong();
        static int GetDem();
        void SetSoLuong(int);
        void Nhap();
        NhanVien* Nhap1();
        void Xuat();
        double TongLuong();
        void NhanVienSXLuongThapNhat();
        void NhanVienVPTuoiCaoNhat();
};
#endif