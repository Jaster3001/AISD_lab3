#include <iostream>
#include "Common.h"
#include "ListP.h"

using namespace std;

Element* newElement(int value);

ListP* newPList() {
	ListP* list = new ListP;
	list->first = NULL;
	list->last = NULL;
	list->rozmiar = 0;
	return list;
}

void destroyPList(ListP* list) {
	if (list != NULL) {
		while (list->first != NULL) {
			Element* curr = list->first;
			if (list->first == list->last) list->first = NULL;
			else list->first = list->first->next;
			delete curr;
		}
		delete list;
	}
}

void addToPList(ListP* list, int value) {
	Element* adres= newElement(value);
	Element* ostatni=list->last;
	if (ostatni != NULL) {
	ostatni->next = adres;
	}
	list->last = adres;
	delete ostatni;
	delete adres;
}

Element* search(ListP* list, int value) {;
	Element* curr = list->first;
	int w = curr->value;
	while(w!= value || curr!= NULL){
		w = curr->value;
		curr = curr->next;
	}
	return curr;
	delete curr;
}

int getFromPList(ListP* list, int index) {
	Element* curr = list->first;
	int w = curr->value;
	for (int i = 1; i <= index; i++) {
		curr = curr->next;
		w = curr->value;
	}
	delete curr;
	return w;

}

Element* newElement(int value) {
	Element* element = new Element;
	element->value = value;
	element->next = NULL;
	return element;
}

int removeFromPList(ListP* list, int index) {
	Element* curr = list->first;
	int i = 0;
	Element* prev = NULL;
	while (curr != NULL && i < index) {
		prev = curr;
		curr = curr->next;
		i++;
	}
	int value;
	if (curr == NULL) { //Będzie null jeśli lista jest pusta
		list->last = prev;
		value = NaN;
	}
	else { 
		if (prev != NULL) { //Sprawdzant czy to nie pierwszy element listy		
			prev->next = curr->next;			
		}
		else {
			list->first = curr->next;
		}		
		if (curr->next == NULL) { //Jak koniec kolejki
			list->last = prev;
		}
		value = curr->value;
		list->rozmiar--;
		delete curr;
	}
	return value;
}

int sizeP(ListP* list) {
	if (list!=NULL)
		return list->rozmiar;
	return NaN;
}
/*
auto_ptr<IteratorP> getPIterator(ListP* list) {
	IteratorP* wynik = new IteratorP;
	wynik->lista = list;
	wynik->curr = list->first;

}

int iterateP(IteratorP* iterator) {
	//Tutaj dokonaj implementacji funkcji
}
*/