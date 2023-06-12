/**
* Burak Can Evci 
* G211210091
* 2B
* 1. Ödev
* SatirListesi.cpp
**/


#include "SatirListesi.hpp"
#include "KonsolPozisyonu.hpp"

SatirListesiNode* SatirListesi::FindPreviousByPosition(int index) {
    if (index < 0 || index > size) cout << "Listemiz bos";
    SatirListesiNode *prv = head;
    int i = 1;
    for (SatirListesiNode*itr = head; itr->next != NULL && i != index; itr = itr->next, i++) {
        prv = prv->next;
    }
    return prv;
}

SatirListesi::SatirListesi() {
    head = NULL;
    size = 0;
}


bool SatirListesi::isEmpty()const {
    return size == 0;
}

int SatirListesi::Count()const {
    return size;
}


void SatirListesi::ekle(const int& item) {
    insert(size, item);
}

void SatirListesi::insert(int index, const int& item) {
    if (index < 0 || index > size) cout << "Listemiz bos";
    if (index == 0) {
        head = new SatirListesiNode(item, head);
        if (head->next != NULL) head->next->prev = head;
    } else {
        SatirListesiNode *prv = FindPreviousByPosition(index);
        prv->next = new SatirListesiNode(item, prv->next, prv);
        if (prv->next->next != NULL)
            prv->next->next->prev = prv->next;
    }
    size++;
}

const int& SatirListesi::ilk() {
    if (isEmpty()) cout << "Listemiz bos";
    return head->data;
}

const int& SatirListesi::son() {
    if (isEmpty()) cout << "Listemiz bos";
    return FindPreviousByPosition(size)->data;
}

int SatirListesi::indexOf(const int& item) {
    int index = 0;
    for (SatirListesiNode *itr = head; itr != NULL; itr = itr->next) {
        if (itr->data == item) return index;
        index++;
    }
    cout << "Listemiz bos";
}


bool SatirListesi::bul(const int& item) {
    for (SatirListesiNode *itr = head; itr != NULL; itr = itr->next) {
        if (itr->data == item) return true;
    }
    return false;
}

void SatirListesi::sil(const int& item) {
    int index = indexOf(item);
    silme(index);
}

void SatirListesi::silme(int index) {
    if (index < 0 || index >= size) cout<<"Gecerli deger girin";
    SatirListesiNode *del;
    if (index == 0) {
        del = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
    } else {
        SatirListesiNode *prv = FindPreviousByPosition(index);
        del = prv->next;
        prv->next = del->next;
        if (del->next != NULL)
            del->next->prev = prv;
    }
    size--;
    delete del;
}

const int& SatirListesi::elementAt(int index) {
    if (index < 0 || index >= size)cout << "Gecerli deger girin";
    if (index == 0) return head->data;
    return FindPreviousByPosition(index)->next->data;
}

void SatirListesi::temizle() {
    while (!isEmpty())
        silme(0);
}


void SatirListesi::TersCevir() {
    for (SatirListesiNode *itr = head; itr != NULL;) {
        SatirListesiNode *tmp = itr->next;
        itr->next = itr->prev;
        itr->prev = tmp;
        if (tmp == NULL) {
            head = itr;
            break;
        }
        itr = tmp;
    }
}


ostream& operator <<(ostream& screen, SatirListesi& rgt) {

    for (SatirListesiNode *itr = rgt.head; itr != NULL; itr = itr->next) {
        screen<<itr<<"\n";
        screen<<"-----------\n";
        screen<<"|"<<setw(5)<<itr->data<<setw(5)<<"|"<<endl;
        screen<<"-----------\n";
        screen<<"|"<<itr->next<<setw(3)<<"|\n";
        screen<<"-----------\n\n";
    }
    screen << endl;
    return screen;
}

void SatirListesi::printNodesFromPositionInReverseOrder(int index) {
    if (index < 0 || index >= size) cout <<"Gecerli deger girin";
    for (SatirListesiNode *itr = FindPreviousByPosition(index + 1); itr != NULL; itr = itr->prev) {
        
        cout << itr->data << " <-> ";
    }
    cout << endl;
}

void SatirListesi::printReverseOrder() {
    printNodesFromPositionInReverseOrder(size - 1);
}
void SatirListesi::YazdirSatirListesi(int x,int y){
    int yIndex=y; 
    KonsolPozisyonu.gotoxy(x,yIndex);
    cout<<"vvvvvvvv\n"; 
     for (SatirListesiNode *itr = this->head; itr != NULL; itr = itr->next) {
      
        KonsolPozisyonu.gotoxy(x,++yIndex);
        cout<<itr<<"\n";
        
        KonsolPozisyonu.gotoxy(x,++yIndex);
        cout<<"-----------\n";
        KonsolPozisyonu.gotoxy(x,++yIndex);
        cout<<"|"<<setw(5)<<itr->data<<setw(5)<<"|"<<endl;
        KonsolPozisyonu.gotoxy(x,++yIndex);
        cout<<"-----------\n";
        KonsolPozisyonu.gotoxy(x,++yIndex);
        cout<<"|"<<itr->next<<setw(3)<<"|\n";
        KonsolPozisyonu.gotoxy(x,++yIndex);
        cout<<"-----------\n\n";
    }
}

SatirListesi::~SatirListesi() {
    temizle();
}
