#include"dongvat.h"
#pragma once
#ifndef _BO
#define _BO
class Bo : public DongVat{
    private:
        static int dem;
    public:
        ~Bo();
        Bo();
        Bo(double, int);
        Bo(const Bo&);
        Bo& operator=(const Bo&);
        static int GetDem();
        void ChoSua();
        void Keu();
        string GetLoai();
};
#endif
