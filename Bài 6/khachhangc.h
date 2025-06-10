#include"khachhang.h"
#pragma once
#ifndef _KHACHHANGC
#define _KHACHHANGC
class KhachHangC:public KhachHang{
private:
    static int dem;
public:
    ~KhachHangC();
    KhachHangC();
    KhachHangC(string, double, double);
    KhachHangC(const KhachHangC&);
    KhachHangC& operator=(const KhachHangC&);
    static int GetDem();
    void Nhap();
    void Xuat();
    double ThanhTien();
};
#endif