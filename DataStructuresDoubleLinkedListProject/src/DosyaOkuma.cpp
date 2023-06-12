/**
* Burak Can Evci 
* G211210091
* 2B
* 1. Ödev
* DosyaOkuma.cpp
**/

#include "DosyaOkuma.hpp"

YoneticiListesi* DosyaOkuma::GetFillYoneticiListesi(){
    readLine();
    YoneticiListesi *tmp=new YoneticiListesi();
    int count=lineCount();
    for(int i=0;i<count;++i){
        tmp->ekle(this->lines[i]);
    }
    return tmp;
    
}



DosyaOkuma::DosyaOkuma(std::string DosyaAdi) {
    this->DosyaAdi = DosyaAdi;


    int numlines = lineCount();
    this->lines = new SatirListesi*[numlines];
    for (int i = 0; i < numlines; i++) {
        this->lines[i] = new SatirListesi();
    }
}

int DosyaOkuma::lineCount() {
    int counter = 0;
    std::ifstream file(this->DosyaAdi);
    std::string unused;
    while (std::getline(file, unused))
        ++counter;

    file.close();
    return counter;
}

void DosyaOkuma::readLine() {
    std::string token;
    std::ifstream file(this->DosyaAdi);
    std::string str;
    int index = 0;
    while (std::getline(file, token)) {
        std::istringstream ss(token);

        while (std::getline(ss, str, ' ')) {
            this->lines[index]->ekle(stoi(str));

        }
        index++;

    }
    file.close();
}

DosyaOkuma::~DosyaOkuma(){
	if(lines!=0){
		int count =lineCount();
		for (int i = 0; i < count; i++){
			if(lines[i]!=0) delete lines[i];
		}
		delete[] lines;
	}
	
}
