/**
* Burak Can Evci 
* G211210091
* 2B
* 1. Ödev
* KonsoldaGoruntuleme.hpp
**/

#ifndef KONSOLDAGORUNTULEME_HPP
#define KONSOLDAGORUNTULEME_HPP

#include "YoneticiListesi.hpp"
#include "KonsolPozisyonu.hpp"

#define DisplayperOnePage 8
#define BeginOffset 0

enum Direction {
    up = 0,
    down = 1,
    refresh = 2,

};

enum PageDirection {
    upPage = 0,
    downPage = 1,
};

class KonsoldaGoruntuleme {
private:
    YoneticiListesi *yonetici;
    int beginOffset;
    int finishOffset;
	int state;
    void setOffsets();
public:

	void SetPage(PageDirection pdr);
    void setState(Direction dr);
    

    KonsoldaGoruntuleme(YoneticiListesi* yonetici);

    void YazdirYoneticiListesi();

    void YazdirSeciliSatirListesi(int x, int y);

    void SilYoneticiDugum();

    void SilRastgeleSeciliDugum(int randomIndex);
	
	int GosterRastgeleSeciliDugum();
};

#endif 

