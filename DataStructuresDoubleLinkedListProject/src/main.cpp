/**
* Burak Can Evci 
* G211210091
* 2B
* 1. Ödev
* main.cpp
**/



#include <cstdlib>
#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"
#include "DosyaOkuma.hpp"
#include "KonsoldaGoruntuleme.hpp"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    DosyaOkuma * readingFile = new DosyaOkuma("veriler.txt");

    YoneticiListesi *yoneticiListesi = readingFile->GetFillYoneticiListesi();

    KonsoldaGoruntuleme *console = new KonsoldaGoruntuleme(yoneticiListesi);
    yoneticiListesi->ortalamayaGoreSirala();
    string karakter = "";
    do {
        console->YazdirYoneticiListesi();
        cin>>karakter;
        if (karakter == "c") 
		{
            Direction direction = up;
            console->setState(direction);
        } 
		
		else if (karakter == "z") 
		{
            Direction direction = down;
            console->setState(direction);
        } 
		
		else if (karakter == "a") 
		{
            console->SetPage(downPage);
        }
		
		else if (karakter == "d") 
		{
            console->SetPage(upPage);
        } 
		
		
		else if (karakter == "k") 
		{
            int rastgeleIndex = 0;
            try 
			{
                rastgeleIndex = console->GosterRastgeleSeciliDugum();
            } catch (...) 
			{
                continue;
            }
            cin>>karakter;
            if (karakter == "k") 
			{

                console->SilRastgeleSeciliDugum(rastgeleIndex);
                yoneticiListesi->ortalamayaGoreSirala();

            }
        } 
		
		else if (karakter == "p") 
		{
            console->SilYoneticiDugum();
        } 




    } while (karakter != "q");



    return 0;



}

