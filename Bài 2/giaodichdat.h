#include"giaodich.h"
#pragma once
#ifndef _GIAODICHDAT
#define _GIAODICHDAT
class GiaoDichDat : public GiaoDich{
    private:
        char loaidat;
        static int dem;
    public:
        ~GiaoDichDat();
        GiaoDichDat();
        GiaoDichDat(string, string, double, double, char);
        GiaoDichDat(const GiaoDichDat&);
        GiaoDichDat& operator=(const GiaoDichDat&);
        char GetLoaiDat();
        static int GetDem();
        void SetLoaiDai(char);
        void Nhap();
        void Xuat();
        string GetLoai();
        double ThanhTien();
};
#endif