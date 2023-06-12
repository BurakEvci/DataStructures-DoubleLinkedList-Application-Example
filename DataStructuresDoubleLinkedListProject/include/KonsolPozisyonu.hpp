/**
* Burak Can Evci 
* G211210091
* 2B
* 1. Ödev
* KonsoldaPozisyonu.hpp
**/

#ifndef KONSOLPOZISYONU_HPP
#define KONSOLPOZISYONU_HPP

#include <windows.h>

static class KonsolPozisyonu {
public:

    static void gotoxy(int x, int y) {
        COORD m;
        m.X = x;
        m.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m);
    }


} KonsolPozisyonu;


#endif 

