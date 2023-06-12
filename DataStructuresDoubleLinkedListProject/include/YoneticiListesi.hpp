/**
* Burak Can Evci 
* G211210091
* 2B
* 1. Ödev
* YoneticiListesi.hpp
**/


#ifndef YONETICILISTESI_HPP
#define YONETICILISTESI_HPP

#include <iostream>

#include "SatirListesi.hpp"
#include "YoneticiNode.hpp"
#include <stdlib.h>     
#include <time.h>       
#include "KonsolPozisyonu.hpp"

class YoneticiListesi {
private:
    YoneticiNode *head;
    int size;

    YoneticiNode* FindPosition(int index);
    YoneticiNode* FindPreviousByPosition(int index);

public:

    YoneticiListesi();
	bool isEmpty()const;
    int Count()const;
    void ekle(SatirListesi*& item);
	void sil(SatirListesi*& item);
	void silme(int index);
    int indexOf(SatirListesi*& item);
	void insert(int index, SatirListesi*& item);
    SatirListesi*& first();
    SatirListesi*& last();
	int RastgeleUretici(int index);
    void SatirListesindenRastgeleSilme(int index, int inlineIndex);
    void calculateAveragee(int index);
    void DugumTasi(int from, int to);
    void TersCevir();
    void ortalamayaGoreSirala();
    SatirListesi*& elementAt(int index);
    void temizle();
	bool bul(SatirListesi*& item);
    void YazdirIndex(int index, int x, int y);
    ~YoneticiListesi();

};


#endif 

