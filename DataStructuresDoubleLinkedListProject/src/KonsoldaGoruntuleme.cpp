/**
* Burak Can Evci 
* G211210091
* 2B
* 1. Ödev
* KonsoldaGoruntuleme.cpp
**/

#include "KonsoldaGoruntuleme.hpp"

KonsoldaGoruntuleme::KonsoldaGoruntuleme(YoneticiListesi* yonetici) {
    this->yonetici = yonetici;
    if (this->yonetici->Count() < DisplayperOnePage) {
        this->finishOffset = this->yonetici->Count();
    } else {
        this->finishOffset = DisplayperOnePage;
    }

    this->beginOffset = BeginOffset;

}




void KonsoldaGoruntuleme::SetPage(PageDirection pdr) {
    if (pdr == downPage) {
        for (int i = 0; i < DisplayperOnePage; ++i) {
            this->setState(down);
        }
    } else if (pdr == upPage) {
        for (int i = 0; i < DisplayperOnePage; ++i) {
            this->setState(up);
        }
    }
}

void KonsoldaGoruntuleme::setOffsets() {
    int page = state / DisplayperOnePage;
    this->beginOffset = DisplayperOnePage*page;
    this->finishOffset = DisplayperOnePage * (page + 1);
    if (this->finishOffset >= this->yonetici->Count()) {
        this->finishOffset = this->yonetici->Count();

    }
}


void KonsoldaGoruntuleme::setState(Direction dr) {

    if (dr == up) {
        if (state >= this->yonetici->Count() - 1) {
            return;
        }
        ++state;
        setOffsets();
    } else if (dr == down) {
        if (state <= 0) {

            return;
        }
        --state;
        setOffsets();
    } else if (dr == refresh) {
        setOffsets();
    }

}


void KonsoldaGoruntuleme::YazdirYoneticiListesi() {

    int count = yonetici->Count();
    system("cls");
    if (count == 0) {
        cout << "Goruntulenecek bir Yonetici listesi yok\n";
        exit(1);
        return;
    }


    KonsolPozisyonu.gotoxy(0, 0);
    if (this->beginOffset == 0) {
        cout << "<--ilk--";
    } else {
        cout << "<---geri--";
    }


    int showingNodeCount = this->finishOffset - this->beginOffset;
    showingNodeCount *= 13;


    KonsolPozisyonu.gotoxy(showingNodeCount, 0);


    if (this->finishOffset == yonetici->Count()) {
        cout << "son-->";
    } else {
        cout << "ileri-->";
    }
    for (int i = this->beginOffset; i<this->finishOffset; ++i) {


        int mod = i % DisplayperOnePage;
        this->yonetici->YazdirIndex(i, 15 * mod, 1);

    }
    this->YazdirSeciliSatirListesi((this->state % DisplayperOnePage) *15, 9);
}


  int KonsoldaGoruntuleme::GosterRastgeleSeciliDugum() {

        int RastgeleSecili = this->yonetici->RastgeleUretici(this->state);
        int xPosition = ((this->state % DisplayperOnePage) + 1)*15;
        int yPosition = (RastgeleSecili)*6;
        yPosition += 12;
        KonsolPozisyonu.gotoxy(xPosition, yPosition);
        cout << "<---silinecek";
        yPosition = this->yonetici->elementAt(this->state)->Count()*6 + 12;

        KonsolPozisyonu.gotoxy(0, yPosition - 1);


        return RastgeleSecili;

    }
  void KonsoldaGoruntuleme::SilYoneticiDugum() {
        this->yonetici->silme(this->state);
       this->setState(refresh);
      
        if(this->state==this->finishOffset){
            this->state--;
        }
         this->setState(refresh);

    }
	
	
 void KonsoldaGoruntuleme::YazdirSeciliSatirListesi(int x, int y) {
        this->yonetici->elementAt(this->state)->YazdirSatirListesi(x, y);

    }
	
  void KonsoldaGoruntuleme::SilRastgeleSeciliDugum(int rastgeleIndex) {
        this->yonetici->SatirListesindenRastgeleSilme(this->state, rastgeleIndex);
    }

