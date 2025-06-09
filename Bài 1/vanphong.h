#include"nhanvien.h"
#pragma once
#ifndef _VANPHONG
#define _VANPHONG
class VanPhong : public NhanVien{
    private:
        int songaylam;
        static int dem;
    public:
        ~VanPhong();
        VanPhong();
        VanPhong(string, string, int);
        VanPhong(const VanPhong&);
        VanPhong& operator=(const VanPhong&);
        int GetSoNgayLam();
        static int GetDem();
        void SetSoNgayLam(int);
        void Nhap();
        void Xuat();
        string GetLoai();
        void TinhLuong();
};
#endif