#include"dongvat.h"
#include"bo.h"
#include"cuu.h"
#include"de.h"
#pragma once
#ifndef _NONGTRAI
#define _NONGTRAI
class NongTrai{
    private:
        DongVat** dv;
        int sl;
        static int dem;
    public:
        ~NongTrai();
        NongTrai();
        NongTrai(int);
        NongTrai(const NongTrai&);
        NongTrai& operator=(const NongTrai&);
        int GetSL();
        static int GetDem();
        void SetSL();
        void Nhap();
        void Hungry();
        void Xuat();
};
#endif