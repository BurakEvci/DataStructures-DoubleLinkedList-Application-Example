/**
* Burak Can Evci 
* G211210091
* 2B
* 1. Ödev
* YoneticiNode.cpp
**/


#include "YoneticiNode.hpp"


YoneticiNode::YoneticiNode(SatirListesi* data, YoneticiNode *next , YoneticiNode *prev) {
    this->data = data;
    this->next = next;
    this->prev = prev;
    this->ortalama = ortalamaHesapla();
}

YoneticiNode::YoneticiNode(SatirListesi* data, YoneticiNode *next ) {
    this->data = data;
    this->next = next;
    this->prev = prev;
    this->ortalama = ortalamaHesapla();
}

YoneticiNode::YoneticiNode(SatirListesi* data) {
    this->data = data;
    this->next = next;
    this->prev = prev;
    this->ortalama = ortalamaHesapla();
}
double YoneticiNode::ortalamaHesapla() {
    double total = 0;
    if (this->data->isEmpty())
        return total;

    int count = this->data->Count();
    for (int i = 0; i < count; ++i) {
        total += this->data->elementAt(i);
    }
    return total / count;
}
