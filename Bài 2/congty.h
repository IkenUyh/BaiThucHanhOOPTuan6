#include"giaodich.h"
#pragma once 
#ifndef _CONGTYBDS
#define _CONGTYBDS
class CongTyBatDongSan{
    private:
        GiaoDich** ct;
        int sl;
        static int dem;
    public:
        ~CongTyBatDongSan();
        CongTyBatDongSan();
        CongTyBatDongSan(int);
        CongTyBatDongSan(int, GiaoDich**);
        CongTyBatDongSan(const CongTyBatDongSan&);
        CongTyBatDongSan& operator=(const CongTyBatDongSan&);
        int GetSoLuong();
        static int GetDem();
        void SetSoLuong(int);
        void Nhap();
        GiaoDich* Nhap1();
        void Xuat();
        void TongSoLuongGiaoDich();
        double TrungBinhThanhTienChungCu();
        void NhaPhoCoGiaTriCaoNhat();
        void GiaoDichThang12Nam2024();
};
#endif