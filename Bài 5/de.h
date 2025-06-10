#include"dongvat.h"
#pragma once
#ifndef _DE
#define _DE
class De : public DongVat{
    private:
        static int dem;
    public:
        ~De();
        De();
        De(double, int);
        De(const De&);
        De& operator=(const De&);
        static int GetDem();
        void ChoSua();
        void Keu();
        string GetLoai();
};
#endif