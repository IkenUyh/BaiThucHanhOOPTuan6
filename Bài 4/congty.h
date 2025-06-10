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
        int GetSL();
        static int GetDem();
        void SetSL();
        void Nhap();
        NhanVien* Nhap1();
        void Xuat();
        double LuongTBCuaNhanVien();
        void NVCoLuongThapHonTB();
        void NVCaoNhatLuong();
        void NVThapNhatLuong();
        void LTVCaoNhatLuong();
        void KCVCaoNhatLuong();
};
#endif