#pragma once
#ifndef _SINHVIEN
#define _SINHVIEN
#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
using namespace std;
class SinhVien{
    protected:
        string mssv;
        string hoten;
        string diachi;
        int tongtinchi;
        double diemtb;
        static int dem;
    public:
        virtual ~SinhVien();
        SinhVien();
        SinhVien(string, string, string, int, double);
        SinhVien(const SinhVien&);
        SinhVien& operator=(const SinhVien&);
        string GetMSSV();
        string GetHoTen();
        string GetDiaChi();
        int GetTongTinChi();
        double GetDiemTB();
        static int GetDem();
        void SetHoTen(string);
        void SetDiaChi(string);
        void SetTongTinChi(int);
        void SetDiemTB(double);
        virtual void Nhap();
        virtual void Xuat();
        virtual string GetLoai()=0;
        virtual bool TotNghiep()=0;
};
#endif