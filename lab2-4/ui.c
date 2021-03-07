#include "service.h"
#include "ui.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmpbyName(Med* obj1, Med* obj2)
{
	return strcmp(getName(obj1), getName(obj2));
}

int cmpbyQty(Med* obj1, Med* obj2)
{
	return getQty(obj1) > getQty(obj2);
}

void addMed(MyArray* list)
{
	int ID, conc, qty;
	char name[10];
	printf("ID: ");
	scanf_s("%d", &ID);
	printf("Nume: ");
	int count = scanf_s("%s", name, 20);
	if (count == EOF)
		perror("Error while reading string.");
	printf("Concentratie: ");
	scanf_s("%d", &conc);
	printf("Cantitate: ");
	scanf_s("%d", &qty);
	int check = addMedS(ID, name, conc, qty, list);
	if (check == 1)
		printf("ID-ul trebuie sa fie pozitiv.\n");
	else if (check == 2)
		printf("Nume invalid.\n");
	else if (check == 3)
		printf("Concentratia trebuie sa fie pozitiva.\n");
	else if (check == 4)
		printf("Cantitatea trebuie sa fie pozitiva.\n");
	else
		printf("Medicament adaugat cu succes!\n");
}

void actualMed(MyArray* list)
{
	int ID, conc;
	char name[20];
	printf("ID: ");
	scanf_s("%d", &ID);
	printf("Nume nou: ");
	scanf_s("%s", name, 20);
	printf("Concentratie noua: ");
	scanf_s("%d", &conc);
	int check = actualMedS(ID, name, conc, list);
	if (check == -1)
		printf("ID inexistent.\n");
	else if (check == 1)
		printf("ID-ul trebuie sa fie pozitiv.\n");
	else if (check == 2)
		printf("Nume invalid.\n");
	else if (check == 3)
		printf("Concentratia trebuie sa fie pozitiva.\n");
	else
		printf("Element actualizat cu succes!\n");
}

void delMed(MyArray* list)
{
	int ID;
	printf("ID: ");
	scanf_s("%d", &ID);
	int check = delMedS(list, ID);
	if (check == 1)
		printf("ID-ul trebuie sa fie pozitiv.\n");
	else if (check == -1)
		printf("ID inexistent.\n");
	else
		printf("Element sters cu succes!\n");
}

void afisareNorm(MyArray* list)
{
	for (int i = 0; i < list->len; i++)
		printf("%d. ID: %d, Nume: %s, Concentratie: %d, Cantitate: %d\n", i + 1, getID(&(list->elems[i])), getName(&(list->elems[i])), getConc(&(list->elems[i])), getQty(&(list->elems[i])));
	printf("\n");
}

void filtrMedN(MyArray* list)
{
	char c[2];
	MyArray aux = constructorArray();
	printf("Caracter: ");
	int count  = scanf("%s", c);
	if (count == EOF)
		perror("Error while reading string.");
	filtrMedNS(list, &aux, c);
	afisareNorm(&aux);
	destructorArray(&aux);
}

void filtrMedQ(MyArray* list)
{
	int qty;
	MyArray aux = constructorArray();
	printf("Cantitate: ");
	scanf_s("%d", &qty);
	filtrMedQS(list, &aux, qty);
	afisareNorm(&aux);
	destructorArray(&aux);
}

void menu()
{
	printf("1. Adauga medicament\n2. Actualizare medicament\n3. Stergere medicament\n4. Afisare\n\n");
}


int run()
{
	MyArray list = constructorArray();
	int opt;
	while (1)
	{
		menu();
		scanf_s ("%d", &opt);
		if (opt == 1)
			addMed(&list);
		else if (opt == 2)
			actualMed(&list);
		else if (opt == 3)
			delMed(&list);
		else if (opt == 4)
		{
			printf("1. Afisare normala\n2. Sortare dupa nume\n3. Sortare dupa cantitate\n");
			printf("4. Filtrare dupa un caracter dat\n5. Filtrare dupa o cantitate data\n");
			scanf_s ("%d", &opt);
			if (opt == 1)
				afisareNorm(&list);
			else if (opt == 2)
				sortMedN(&list, cmpbyName);
			else if (opt == 3)
				sortMedQ(&list, cmpbyQty);
			else if (opt == 4)
				filtrMedN(&list);
			else if (opt == 5)
				filtrMedQ(&list);
			else
				printf("Optiune invalida!\n\n");
		}
		else if (opt == 0)
		{
			destructorArray(&list);
			return 0;
		}
		else
			printf("Optiune invalida!\n\n");
	}
}