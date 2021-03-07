#include "validator.h"
#include "service.h"
#include <string.h>

int addMedS(int ID, char* name, int conc, int qty, MyArray* list)
{
	Med obj = constructorMed(ID, name, conc, qty);
	int check = validator(&obj);
	if (check != 0)
	{
		destructorMed(&obj);
		return check;
	}
	addMedR(list, &obj);
	return 0;
}

int actualMedS(int ID, char* name, int conc, MyArray* list)
{	
	Med obj = constructorMed(ID, name, conc, 1);
	int check = validator(&obj);
	if (check != 0)
	{
		destructorMed(&obj);
		return check;
	}
	check = actualMedR(list, &obj);
	if (check == -1)
	{
		destructorMed(&obj);
		return check;
	}
	destructorMed(&obj);
	return 0;
}

int delMedS(MyArray* list, int ID)
{
	Med obj = constructorMed(ID, "1", 1, 1);
	int check = validator(&obj);
	destructorMed(&obj);
	if (check != 0)
		return check;
	check = delMedR(list, ID);
	if (check == -1)
		return check;
	return 0;
}

void swap(MyArray* list, int i, int j)
{
	Med temp;
	temp = *getElem(list, i);
	list->elems[i] = *getElem(list, j);
	list->elems[j] = temp;
}

void sortMedN(MyArray* list, FunctieCmp cmp)
{
	for (int i = 0; i < list->len - 1; i++)
		for (int j = i + 1; j < list->len; j++)
			if (cmp(&list->elems[i], &list->elems[j]) > 0)
				swap(list, i, j);
}

void sortMedQ(MyArray* list, FunctieCmp cmp)
{
	for (int i = 0; i < list->len - 1; i++)
		for (int j = i + 1; j < list->len; j++)
			if (cmp(&list->elems[i], &list->elems[j]))
				swap(list, i, j);
}

void filtrMedNS(MyArray* list, MyArray* aux, char* c)
{

	for (int i = 0; i < list->len; i++)
		if (getName(&(list->elems[i]))[0] == c[0])
		{
			aux->elems[aux->len] = constructorMed(list->elems[i].ID, list->elems[i].name, list->elems[i].conc, list->elems[i].qty);
			aux->len++;
			if (aux->len == aux->capac)
				marire(aux);
		}
}

void filtrMedQS(MyArray* list, MyArray* aux, int qty)
{
	for (int i = 0; i < list->len; i++)
		if (getQty(&(list->elems[i])) < qty)
		{
			aux->elems[aux->len] = constructorMed(list->elems[i].ID, list->elems[i].name, list->elems[i].conc, list->elems[i].qty);
			aux->len++;
			if (aux->len == aux->capac)
				marire(aux);
		}
}
