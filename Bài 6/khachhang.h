#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
#pragma once
#ifndef _KHACHHANG
#define _KHACHHANG
class KhachHang{
protected:
    string hoten;
    double soluonghang;
    double dongia;
    static int dem;
public:
    virtual ~KhachHang();
    KhachHang();
    KhachHang(string, double, double);
    KhachHang(const KhachHang&);
    KhachHang& operator=(const KhachHang&);
    string GetHoTen();
    double GetSoLuongHang();
    double GetDonGia();
    static int GetDem();
    void SetHoTen(string);
    void SetSoLuongHang(double);
    void SetDonGia(double);
    virtual void Nhap();
    virtual void Xuat();
    virtual double ThanhTien()=0;
};
#endif