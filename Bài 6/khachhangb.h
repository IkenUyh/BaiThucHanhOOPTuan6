#include"khachhang.h"
#pragma once
#ifndef _KHACHHANGB
#define _KHACHHANGB
class KhachHangB:public KhachHang{
private:
    double sonamthanthiet;
    static int dem;
public:
    ~KhachHangB();
    KhachHangB();
    KhachHangB(string, double, double, double);
    KhachHangB(const KhachHangB&);
    KhachHangB& operator=(const KhachHangB&);
    double GetSoNamThanhThiet();
    static int GetDem();
    void SetSoNamThanhThiet(double);
    void Nhap();
    void Xuat();
    double ThanhTien();
};
#endif