#pragma once

typedef struct
{
	int ID, conc, qty;
	char* name;
}Med;

/*
in: obj - adresa unui medicament
functia returneaza ID-ul lui obj
out: ID - ID-ul unui medicament
*/
int getID(Med*);

/*
in: obj - adresa unui medicament
functia returneaza numele lui obj
out: ID - numele unui medicament
*/
char* getName(Med*);

/*
in: obj - adresa unui medicament
	conc - concentratia noua
functia modifica concentratia lui obj
out: -
*/
int getConc(Med*);

/*
in: obj - adresa unui medicament
functia returneaza cantitatea lui obj
out: ID - cantitatea unui medicament
*/
int getQty(Med*);

/*
in: obj - adresa unui medicament
	ID - ID-ul nou
functia modifica ID-ul unui med
out: -
*/
void setID(Med*, int);

/*
in: obj - adresa unui medicament
	name - numele nou
functia modifica numele lui obj
out: -
*/
void setName(Med*, char*);

/*
in: obj - adresa unui medicament
	conc - concentratia noua
functia modifica concentratia lui obj
out: -
*/
void setConc(Med*, int);

/*
in: obj - adresa unui medicament
	qty - cantitatea noua
functia modifica cantitatea lui obj
out: -
*/
void setQty(Med*, int);

/*
in:	ID - ID
	name - nume
	conc - concentratie
	qty - cantitate
functia initializeaza obj
out:
*/
Med constructorMed(int, char*, int, int);

/*
in: obj - adresa unui medicament
functia dealoca memoria
out: -
*/
void destructorMed(Med*);