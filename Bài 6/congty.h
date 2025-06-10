#include"khachhang.h"
#pragma once
#ifndef _CONGTY
#define _CONGTY
class CongTy{
private:
    KhachHang** kh;
    int x, y, z;
    static int dem;
public:
    ~CongTy();
    CongTy();
    CongTy(int, int, int);
    CongTy(const CongTy&);
    CongTy& operator=(const CongTy&);
    int GetX();
    int GetY();
    int GetZ();
    static int GetDem();
    void SetX(int);
    void SetY(int);
    void SetZ(int);
    void Nhap();
    void Xuat();
};
#endif