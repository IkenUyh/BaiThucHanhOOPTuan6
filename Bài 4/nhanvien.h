#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
#pragma once
#ifndef _NHANVIEN
#define _NHANVIEN
class NhanVien{
    protected:
        string manv;
        string hoten;
        int tuoi;
        string sdt;
        string email;
        double luongcb;
        static int dem;
    public:
        virtual ~NhanVien();
        NhanVien();
        NhanVien(string, string, int, string, string, double);
        NhanVien(const NhanVien&);
        NhanVien& operator=(const NhanVien&);
        string GetMaNV();
        string GetHoTen();
        int GetTuoi();
        string GetSDT();
        string GetEmail();
        double GetLuongCB();
        static int GetDem();
        void SetHoTen(string);
        void SetTuoi(int);
        void SetSDT(string);
        void SetEmail(string);
        void SetLuongCB(double);
        virtual void Nhap();
        virtual void Xuat();
        virtual string GetLoai()=0;
        virtual double TinhLuong()=0;
};
#endif