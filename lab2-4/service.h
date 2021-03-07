#pragma once

#include "domain.h"
#include "repository.h"


typedef int (*FunctieCmp) (Med*, Med*);

/*
in: ID - ID
	name - nume
	conc - concentratie
	qty - cantitate
	list - adresa listei cu medicamente
functia trimite parametrii catre validator si functia propriu-zisa
out: 0 - daca a avut loc adaugarea
	 !0 - altfel
*/
int addMedS(int, char*, int, int, MyArray*);

/*
in: ID - ID
	name - nume
	conc - concentratie
	qty - cantitate
	list - adresa listei cu medicamente
functia trimite parametrii catre validator si functia propriu-zisa
out: 0 - daca a avut loc adaugarea
	 !0 - altfel
*/
int actualMedS(int, char*, int, MyArray*);

/*
in: list - adresa listei cu medicamente
	ID - ID-ul medicamentului care se sterge
functia trimite parametrii catre validator si functia propriu-zisa
out: 0 - daca s-a sters
	 !0 - altfel
*/
int delMedS(MyArray*, int);

/*
in: aux - adresa listei cu medicamente
	cmp - functie de comparare
functia sorteaza elementele dupa nume
out: -
*/
void sortMedN(MyArray*, FunctieCmp);

/*
in: aux - adresa listei cu medicamente
	cmp - functie de comparare
functia sorteaza elementele dupa cantitate
out: -
*/
void sortMedQ(MyArray*, FunctieCmp);

/*
in: list - adresa listei initiale cu medicamente
	aux - adresa listei filtrate cu medicamente
	c - caracterul dupa care se face filtrarea
functia filtreaza elem din list
out: -
*/
void filtrMedNS (MyArray*, MyArray*, char*);

/*
in: list - adresa listei initiale cu medicamente
	aux - adresa listei filtrate cu medicamente
	qty - cantitatea dupa care se face filtrarea
functia filtreaza elem din list
out: -
*/
void filtrMedQS (MyArray*, MyArray*, int);