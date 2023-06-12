/**
* Burak Can Evci 
* G211210091
* 2B
* 1. Ödev
* DosyaOkuma.hpp
**/


#ifndef DOSYAOKUMA_HPP
#define DOSYAOKUMA_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"

class DosyaOkuma {
private:
    std::string DosyaAdi;
    int lineCount();
    SatirListesi **lines;
    void readLine();
public:
    DosyaOkuma(std::string);
    ~DosyaOkuma();
    YoneticiListesi* GetFillYoneticiListesi();



};

#endif 

