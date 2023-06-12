/**
* Burak Can Evci 
* G211210091
* 2B
* 1. Ödev
* YoneticiNode.hpp
**/


#ifndef YONETICINODE_HPP
#define YONETICINODE_HPP


#include "SatirListesi.hpp"

class YoneticiNode {
public:
    SatirListesi* data;
    YoneticiNode *next;
    YoneticiNode *prev;
    double ortalama;


    YoneticiNode(SatirListesi* data, YoneticiNode *next, YoneticiNode *prev);
    YoneticiNode(SatirListesi* data, YoneticiNode *next);
    YoneticiNode(SatirListesi* data);
    double ortalamaHesapla();
};


#endif 

