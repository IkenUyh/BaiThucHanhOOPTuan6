#include"giaodich.h"
#pragma once
#ifndef _GIAODICHCHUNGCU
#define _GIAODICHCHUNGCU
class GiaoDichChungCu : public GiaoDich{
    private:
        string macan;
        int vitritang;
        static int dem;
    public:
        ~GiaoDichChungCu();
        GiaoDichChungCu();
        GiaoDichChungCu(string, string, double, double, string, int);
        GiaoDichChungCu(const GiaoDichChungCu&);
        GiaoDichChungCu& operator=(const GiaoDichChungCu&);
        string GetMaCan();
        int GetViTriTang();
        static int GetDem();
        void SetMaCan(string);
        void SetViTriTang(int);
        void Nhap();
        void Xuat();
        string GetLoai();
        double ThanhTien();
};
#endif