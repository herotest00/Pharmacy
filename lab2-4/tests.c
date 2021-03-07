#include "domain.h"
#include "repository.h"
#include "service.h"
#include "validator.h"
#include "ui.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>


void runAdd()
{
	MyArray list = constructorArray();
	for (int i = 0; i < 180; i++)
		addMedS(i, "qqq", 33, 8, &list);
	for (int i = 0; i < 180; i++)
		delMedS(&list, i);
	assert(addMedS(5, "asd", 14, 2, &list) == 0);
	assert(addMedS(14, "qweqe", 19, 4, &list) == 0);
	assert(addMedS(5, "gqqd", 16, 3, &list) == 0);
	assert(getQty(&(list.elems[0])) == 5);
	assert(addMedS(99, "GM", 44, 0, &list) != 0);
	destructorArray(&list);
}

void runAct()
{
	MyArray list = constructorArray();
	addMedS(5, "asd", 14, 2, &list);
	addMedS(14, "qweqe", 19, 4, &list);
	addMedS(5, "gqqd", 16, 3, &list);
	assert(actualMedS(5, "dddd", 24, &list) == 0);
	assert(strcmp(getName(&(list.elems[0])), "dddd") == 0);
	assert(getConc(&(list.elems[0])) == 24);
	assert(actualMedS(3, "xyz", 44, &list) == -1);
	assert(actualMedS(-4, "xxz", 16, &list) != 0);
	destructorArray(&list);
}

void runDel()
{
	MyArray list = constructorArray();
	addMedS(5, "asd", 14, 2, &list);
	addMedS(14, "qweqe", 19, 4, &list);
	addMedS(5, "gqqd", 16, 3, &list);
	assert(delMedS(&list, 4) == -1);
	assert(delMedS(&list, -99) != 0);
	assert(delMedS(&list, 5) == 0);
	destructorArray(&list);
}

void runAfis()
{
	MyArray list = constructorArray();
	
	Med obj1 = constructorMed(15, "pppp", 60, 14);
	addMedR(&list, &obj1);
	addMedS(14, "qweqe", 19, 4, &list);
	sortMedN(&list, cmpbyName);
	assert(getID(&(list.elems[0])) == 15);
	assert(getID(&(list.elems[1])) == 14);
	
	Med obj2 = constructorMed(19, "pvvv", 58, 8);
	addMedR(&list, &obj2);
	sortMedQ(&list, cmpbyQty);
	assert(getID(&(list.elems[0])) == 14);
	assert(getID(&(list.elems[1])) == 19);
	assert(getID(&(list.elems[2])) == 15);
	
	MyArray aux1 = constructorArray();
	filtrMedNS(&list, &aux1, "p");
	assert(getID(&(aux1.elems[0])) == 19);
	assert(getID(&(aux1.elems[1])) == 15);
	
	MyArray aux2 = constructorArray();
	filtrMedQS(&list, &aux2, 9);
	assert(getID(&(aux2.elems[0])) == 14);
	assert(getID(&(aux2.elems[1])) == 19);

	destructorArray(&aux1);
	destructorArray(&aux2);
	destructorArray(&list);
}

void runGet()
{
	MyArray list = constructorArray();
	Med obj = constructorMed(4, "xxz", 14, 3);
	addMedR(&list, &obj);
	assert(getID(&(list.elems[0])) == 4);
	assert(strcmp (getName(&(list.elems[0])), "xxz") == 0);
	assert(getConc(&(list.elems[0])) == 14);
	assert(getQty(&(list.elems[0])) == 3);
	assert(getSize(&(list)) == 1);
	destructorArray(&list);
}

void runSet()
{
	MyArray list = constructorArray();
	Med obj1 = constructorMed(4, "xxz", 14, 3);
	addMedR(&list, &obj1);
	setID(&(list.elems[0]), 2);
	assert(getID(&(list.elems[0])) == 2);
	setName(&(list.elems[0]), "marius");
	assert(strcmp(getName(&(list.elems[0])), "marius") == 0);
	setConc(&(list.elems[0]), 99);
	assert(getConc(&(list.elems[0])) == 99);
	setQty(&(list.elems[0]), 14);
	assert(getQty(&(list.elems[0])) == 14);
	destructorArray(&list);
}

void runValid()
{
	Med obj1 = constructorMed(-1, "asd", 4, 9);
	assert(validator(&obj1) == 1);
	Med obj2 = constructorMed(4, "", 4, 9);
	assert(validator(&obj2) == 2);
	Med obj3 = constructorMed(4, "asd", -7, 9);
	assert(validator(&obj3) == 3);
	Med obj4 = constructorMed(4, "asd", 4, 0);
	assert(validator(&obj4) == 4);
	setQty(&obj4, 2);
	assert(validator(&obj4) == 0);
	destructorMed(&obj1);
	destructorMed(&obj2);
	destructorMed(&obj3);
	destructorMed(&obj4);
}

void runTests()
{
	runAdd();
	runAct();
	runDel();
	runAfis();
	runGet();
	runSet();
	runValid();
}