#pragma once
#ifndef _GIAODICH
#define _GIAODICH
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class GiaoDich{
    protected:
        string magd;
        string ngaydg;
        double dongia;
        double dientich;
        static int dem;
    public:
        virtual ~GiaoDich();
        GiaoDich();
        GiaoDich(string, string, double, double);
        GiaoDich(const GiaoDich&);
        GiaoDich& operator=(const GiaoDich&);
        string GetMaGD();
        string GetNgayGD();
        double GetDonGia();
        double GetDienTich();
        static int GetDem();
        void SetMaGD(string);
        void SetNgayGD(string);
        void SetDonGia(double);
        void SetDienTich(double);
        virtual void Nhap();
        virtual void Xuat();
        virtual string GetLoai()=0;
        virtual double ThanhTien()=0;
};
#endif