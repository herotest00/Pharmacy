#pragma once

#include "domain.h"

typedef struct
{
	Med* elems;
	int len;
	int capac;
}MyArray;


/*
in: -
functia initializeaza lista cu medicamente
out: o structura de tip lista
*/
MyArray constructorArray();

/*
in: list - adresa listei cu medicamente
functia dealoca din memorie adresa listei
out: -
*/
void destructorArray(MyArray*);

/*
in: list - adresa listei cu medicamente
functia mareste spatiul alocat pentru medicamente
out: -
*/
void marire(MyArray*);

/*
in: list - adresa listei cu medicamente
functia micsoreaza spatiul alocat pentru medicamente
out: -
*/
void micsorare(MyArray*);

/*
in: list - adresa listei cu medicamente
	i, j - indecsi
functia interschimba valorile de pe pozitiile i si j
out: -
*/
void swap(MyArray*, int, int);

/*
in: list - adresa listei cu medicamente
	ID - ID-ul de cautat
functia cauta ID in lista cu medicamente
out: -1 - daca nu exista medicament cu ID-ul dat
	 !-1 - pozitia medicamentului cu ID-ul dat
*/
int searchID(MyArray*, int);

/*
in: list - adresa listei cu medicamente
	obj - adresa obiectului medicament
functia adauga in lista de medicamente obiectul
out: true
*/
int addMedR(MyArray*, Med*);

/*
in: list - adresa listei cu medicamente
	obj - adresa unui medicament
functia actualizeaza medicamentul pt ID
out: -1 - daca nu exista medicamentul
	  0 - daca a fost actualizat
*/
int actualMedR(MyArray*, Med*);

/*
in: list - adresa listei cu medicamente
	ID - ID-ul medicamentului
functia sterge un medicament
out: -1 - daca nu exista ID-ul
	  0 - daca a fost sters
*/
int delMedR(MyArray*, int);

/*
in: list - adresa listei cu medicamente
	poz - pozitia din lista cu medicamente
functia returneaza elementul de tip Med din lista cu medicamente
out: adresa elementului de pe poz
*/
Med* getElem(MyArray*, int);

/*
in: list - adresa listei cu medicamente
functia returneaza dimensiunea listei
out: lungimea listei cu medicamente
*/
int	getSize(MyArray* list);

/*
in: list1, list2 - adresele listelor cu medicamente
functia copiaza elem din list1 in list2
out: -
*/
void copyArray(MyArray*, MyArray*);