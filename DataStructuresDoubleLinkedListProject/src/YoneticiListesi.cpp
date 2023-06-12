/**
* Burak Can Evci 
* G211210091
* 2B
* 1. Ödev
* YoneticiListesi.cpp
**/

#include "YoneticiListesi.hpp"

YoneticiNode* YoneticiListesi::FindPreviousByPosition(int index) {
    if (index < 0 || index > size) cout << "Gecerli deger girin";
    YoneticiNode *prv = head;
    int i = 1;
    for (YoneticiNode *itr = head; itr->next != NULL && i != index; itr = itr->next, i++) {
        prv = prv->next;
    }
    return prv;
}

YoneticiNode* YoneticiListesi::FindPosition(int index) {
    if (index < 0 || index >= size) cout << "Gecerli deger girin";
    return this->FindPreviousByPosition(index + 1);

}

YoneticiListesi::YoneticiListesi() {
    head = NULL;
    size = 0;
}

bool YoneticiListesi::isEmpty()const {
    return size == 0;
}

int YoneticiListesi::Count()const {
    return size;
}


void YoneticiListesi::insert(int index, SatirListesi*& item) {
    if (index < 0 || index > size) cout << "Gecerli deger girin";
    if (index == 0) {
        head = new YoneticiNode(item, head);
        if (head->next != NULL) head->next->prev = head;
    } else {
        YoneticiNode *prv = FindPreviousByPosition(index);
        prv->next = new YoneticiNode(item, prv->next, prv);
        if (prv->next->next != NULL)
            prv->next->next->prev = prv->next;
    }
    size++;
}



void YoneticiListesi::ekle(SatirListesi*& item) {
    insert(size, item);
}



int YoneticiListesi::indexOf(SatirListesi*& item) {
    int index = 0;
    for (YoneticiNode *itr = head; itr != NULL; itr = itr->next) {
        if (itr->data == item) return index;
        index++;
    }
    cout << "Gecerli deger girin";
}


SatirListesi*& YoneticiListesi::first() {
    if (isEmpty()) cout << "Listemiz bos";;
    return head->data;
}

SatirListesi*& YoneticiListesi::last() {
    if (isEmpty()) cout << "Listemiz bos";;
    return FindPreviousByPosition(size)->data;
}

void YoneticiListesi::calculateAveragee(int index) {
    YoneticiNode* yoneticiNode = this->FindPosition(index);
    if (yoneticiNode == NULL) {

        cout << "hata";

    }


    double total = 0;
    if (yoneticiNode->data->isEmpty()) {

        yoneticiNode->ortalama = total;
        return;
    }


    int count = yoneticiNode->data->Count();
    for (int i = 0; i < count; ++i) {
        total += yoneticiNode->data->elementAt(i);
    }
    yoneticiNode->ortalama = total / count;



}

int YoneticiListesi::RastgeleUretici(int index) {
    int count = this->Count();

    if (index < 0 || index >= count)
        cout << "Gecerli deger girin";

    srand(time(NULL));
    SatirListesi* satirListesi = this->elementAt(index);

    int range = satirListesi->Count();
    if (range == 0) {
        cout << "Gecerli deger girin";;
    }
    int inlineIndex = rand() % range;

    return inlineIndex;
}

void YoneticiListesi::sil(SatirListesi*& item) {
    int index = indexOf(item);
    silme(index);
}

void YoneticiListesi::SatirListesindenRastgeleSilme(int index, int inlineIndex) {

    int count = this->Count();
    if (index < 0 || index >= count)
        cout << "Gecerli deger girin";

    SatirListesi* satirListesi = this->elementAt(index);

    satirListesi->silme(inlineIndex);
    calculateAveragee(index);
	
	if(satirListesi->isEmpty()){
		this->silme(index);
	}
}


void YoneticiListesi::silme(int index) {
    if (index < 0 || index >= size) cout << "Gecerli deger girin";
    YoneticiNode *del;
    if (index == 0) {
        del = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
    } else {
        YoneticiNode *prv = FindPreviousByPosition(index);
        del = prv->next;
        prv->next = del->next;
        if (del->next != NULL)
            del->next->prev = prv;
    }
    size--;
    delete del;
}

void YoneticiListesi::DugumTasi(int from, int to) {
    if (from < 0 || from >= size) cout << "Gecerli deger girin";;
    YoneticiNode *del;
    if (from == 0) {
        del = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
    } else {
        YoneticiNode *prv = FindPreviousByPosition(from);
        del = prv->next;
        prv->next = del->next;
        if (del->next != NULL)
            del->next->prev = prv;
    }
    size--;
    if (to < 0 || to > size) cout << "Gecerli deger girin";
    if (to == 0) {

        del->next = head;
        del->prev = NULL;
        head = del;
        if (head->next != NULL) head->next->prev = head;
    } else {
        YoneticiNode *prv = FindPreviousByPosition(to);

        del->next = prv->next;
        del->prev = prv;
        prv->next = del;
        if (prv->next->next != NULL)
            prv->next->next->prev = prv->next;
    }
    size++;
}

bool YoneticiListesi::bul(SatirListesi*& item) {
    for (YoneticiNode *itr = head; itr != NULL; itr = itr->next) {
        if (itr->data == item) return true;
    }
    return false;
}

void YoneticiListesi::TersCevir() {
    for (YoneticiNode *itr = head; itr != NULL;) {
        YoneticiNode *tmp = itr->next;
        itr->next = itr->prev;
        itr->prev = tmp;
        if (tmp == NULL) {
            head = itr;
            break;
        }
        itr = tmp;
    }
}

void YoneticiListesi::ortalamayaGoreSirala() {
    if (this->size <= 1)
        return;

    for (int step = 0; step < size; ++step) {


        for (int i = 0; i < size - step - 1; ++i) {
            YoneticiNode *tmp = this->FindPosition(i);
            YoneticiNode *tmp2 = tmp->next;

            if (tmp->ortalama > tmp2->ortalama) {


                this->DugumTasi(i + 1, i);
            }
        }
    }

}

SatirListesi*& YoneticiListesi::elementAt(int index) {
    if (index < 0 || index >= size) cout << "Gecerli deger girin";
    if (index == 0) return head->data;
    return FindPreviousByPosition(index)->next->data;
}

void YoneticiListesi::temizle() {
    while (!isEmpty())
        silme(0);
}

void YoneticiListesi::YazdirIndex(int index, int x, int y) {
    YoneticiNode *node = this->FindPosition(index);
    KonsolPozisyonu.gotoxy(x, y);
    cout << fixed << setprecision(2);
    cout << node << "\n";
    KonsolPozisyonu.gotoxy(x, y + 1);
    cout << "-----------\n";
    KonsolPozisyonu.gotoxy(x, y + 2);
    cout << "|" << node->prev << setw(3) << "|\n";
    KonsolPozisyonu.gotoxy(x, y + 3);
    cout << "-----------\n";
    KonsolPozisyonu.gotoxy(x, y + 4);
    cout << "|" << setw(3) << node->ortalama << setw(5) << "|" << endl;
    KonsolPozisyonu.gotoxy(x, y + 5);
    cout << "-----------\n";
    KonsolPozisyonu.gotoxy(x, y + 6);
    cout << "|" << node->next << setw(3) << "|\n";
    KonsolPozisyonu.gotoxy(x, y + 7);
    cout << "-----------\n\n";

}

YoneticiListesi::~YoneticiListesi() {
    temizle();
}