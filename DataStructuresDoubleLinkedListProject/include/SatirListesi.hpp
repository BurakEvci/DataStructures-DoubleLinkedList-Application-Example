/**
* Burak Can Evci 
* G211210091
* 2B
* 1. Ödev
* SatirListesi.hpp
**/

#ifndef SATIRLISTESI_HPP
#define SATIRLISTESI_HPP

#include "SatirListesiNode.hpp"

#include <iomanip>

class SatirListesi {
private:
    SatirListesiNode *head;
    int size;

    SatirListesiNode* FindPreviousByPosition(int index);
public:
    SatirListesi();
	bool isEmpty()const;
    int Count()const;
    void insert(int index, const int& item);
    const int& ilk();
    const int& son();
	bool bul(const int& item);
    int indexOf(const int& item);
	void ekle(const int& item);
    void sil(const int& item);
    void silme(int index);
    void TersCevir();
    const int& elementAt(int index);
    void temizle();
    friend ostream& operator<<(ostream& screen, SatirListesi& rgt);
	void printReverseOrder();
    void printNodesFromPositionInReverseOrder(int index);
    void YazdirSatirListesi(int x, int y);
    ~SatirListesi();

};


#endif 

