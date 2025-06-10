#include"khachhang.h"
#pragma once
#ifndef _KHACHHANGA
#define _KHACHHANGA
class KhachHangA:public KhachHang{
private:
    static int dem;
public:
    ~KhachHangA();
    KhachHangA();
    KhachHangA(string, double, double);
    KhachHangA(const KhachHangA&);
    KhachHangA& operator=(const KhachHangA&);
    static int GetDem();
    void Nhap();
    void Xuat();
    double ThanhTien();
};
#endif