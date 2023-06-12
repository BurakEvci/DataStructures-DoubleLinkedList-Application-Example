/**
* Burak Can Evci 
* G211210091
* 2B
* 1. Ödev
* SatirListesiNode.cpp
**/

#include "SatirListesiNode.hpp"

SatirListesiNode::SatirListesiNode(const int data, SatirListesiNode *next , SatirListesiNode *prev ) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}
SatirListesiNode::SatirListesiNode(const int data, SatirListesiNode *next) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}
SatirListesiNode::SatirListesiNode(const int data) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}
