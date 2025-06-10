#include"dongvat.h"
#pragma once
#ifndef _CUU
#define _CUU
class Cuu : public DongVat{
    private:
        static int dem;
    public:
        ~Cuu();
        Cuu();
        Cuu(double, int);
        Cuu(const Cuu&);
        Cuu& operator=(const Cuu&);
        static int GetDem();
        void ChoSua();
        void Keu();
        string GetLoai();
};
#endif