#pragma once
#ifndef _NHANVIEN
#define _NHANVIEN
#include<iostream>
#include<iomanip>
#include<sstream>
using namespace std;
class NhanVien{
    protected:
        string hoten;
        string ngaysinh;
        double luong;
        static int dem;
    public:
        virtual ~NhanVien();
        NhanVien();
        NhanVien(string, string);
        NhanVien(const NhanVien&);
        NhanVien& operator=(const NhanVien&);
        string GetHoTen();
        string GetNgaySinh();
        double GetLuong();
        static int GetDem();
        void SetHoTen(string);
        void SetNgaySinh(string);
        void SetLuong(double);
        virtual void Nhap();
        virtual void Xuat();
        virtual string GetLoai()=0;
        virtual void TinhLuong()=0;
};
#endif