#include "repository.h"
#include <string.h>
#include <stdlib.h>

MyArray constructorArray()
{
	MyArray list;
	list.len = 0;
	list.capac = 1;
	list.elems = (Med*)malloc(list.capac * sizeof(Med));
	return list;
}

void marire(MyArray* list)
{
	MyArray aux;
	list->capac *= 2;
	aux.elems = (Med*)malloc(list->capac * sizeof(Med));
	copyArray(list, &aux);
	free(list->elems);
	list->elems = aux.elems;
}

void mics(MyArray* list)
{
	list->capac = list->capac / 5 + 1;
	if (list->len > list->capac)
		return;
	MyArray aux;
	aux.elems = (Med*)malloc(list->capac * sizeof(Med));
	copyArray(list, &aux);
	free(list->elems);
	list->elems = aux.elems;
}

int searchID(MyArray* list, int ID)
{
	for (int i = 0; i < list->len; i++)
		if (getID(&(list->elems[i])) == ID)
			return i;
	return -1;
}

int addMedR(MyArray* list, Med* obj)
{
	int pos = searchID(list, getID(obj));
	if (pos == -1)
	{
		list->elems[list->len] = *obj;
		list->len++;
		if (list->len == list->capac)
			marire(list);
	}
	else
	{
		setQty(&(list->elems[pos]), getQty(obj) + getQty(&(list->elems[pos])));
		destructorMed(obj);
	}
		return 0;
}

int actualMedR(MyArray* list, Med* obj)
{
	int pos = searchID(list, getID(obj));
	if (pos == -1)
		return pos;
	setName(&(list->elems[pos]), getName(obj));
	setConc(&(list->elems[pos]), getConc(obj));
	return 0;
}

int delMedR(MyArray* list, int ID)
{
	int pos = searchID(list, ID);
	if (pos == -1)
		return pos;
	destructorMed(&list->elems[pos]);
	for (int i = pos; i < (list->len) - 1; i++)
		list->elems[i] = list->elems[i + 1];
	list->len--;
	if (list->len * 5 < list->capac)
		mics(list);
	return 0;
}

Med* getElem(MyArray* list, int poz)
{
	return &(list->elems[poz]);
}

int getSize(MyArray* list)
{
	return list->len;
}

void copyArray(MyArray* list1, MyArray* list2)
{
	for (int i = 0; i < list1->len; i++)
		list2->elems[i] = list1->elems[i];
}

void destructorArray(MyArray* list)
{
	for (int i = 0; i < list->len; i++)
		destructorMed (&list->elems[i]);
	free(list->elems);
}