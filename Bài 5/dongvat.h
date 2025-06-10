#include<iostream>
#include<iomanip>
#include<random>
#include<string>
using namespace std;
#pragma once
#ifndef _DONGVAT
#define _DONGVAT
class DongVat{
    protected:
        double sua;
        int con;
        static int dem;
    public:
        virtual ~DongVat();
        DongVat();
        DongVat(double, int);
        DongVat(const DongVat&);
        DongVat& operator=(const DongVat&);
        double GetSua();
        int GetCon();
        static int GetDem();
        void SinhCon();
        virtual void ChoSua()=0;
        virtual void Keu()=0;
        virtual string GetLoai()=0;
};
#endif