#include"giaodich.h"
#pragma once
#ifndef _GIAODICHNHAPHO
#define _GIAODICHNHAPHO
class GiaoDichNhaPho : public GiaoDich{
    private:
        string loainha;
        string diachi;
        static int dem;
    public:
        ~GiaoDichNhaPho();
        GiaoDichNhaPho();
        GiaoDichNhaPho(string, string, double, double, string, string);
        GiaoDichNhaPho(const GiaoDichNhaPho&);
        GiaoDichNhaPho& operator=(const GiaoDichNhaPho&);
        string GetLoaiNha();
        string GetDiaChi();
        static int GetDem();
        void SetLoaiNha(string);
        void SetDiaChi(string);
        void Nhap();
        void Xuat();
        string GetLoai();
        double ThanhTien();
};
#endif