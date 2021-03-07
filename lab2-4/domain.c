#include "domain.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int getID(Med* obj)
{
	return obj->ID;
}

char* getName(Med* obj)
{
	return obj->name;
}

int getConc(Med* obj)
{
	return obj->conc;
}

int getQty(Med* obj)
{
	return obj->qty;
}

void setID(Med* obj, int ID)
{
	obj->ID = ID;
}

void setName(Med* obj, char* name)
{
	if (strlen(name) > strlen(obj->name))
	{
		free(obj->name);
		obj->name = (char*)malloc(strlen(name) * (sizeof(char)+1));
	}
	strcpy(obj->name, name);
}

void setConc(Med* obj, int conc)
{
	obj->conc = conc;
}

void setQty(Med* obj, int qty)
{
	obj->qty = qty;
}

Med constructorMed(int ID, char* name, int conc, int qty)
{
	Med obj;
	setID(&obj, ID);
	obj.name = (char*)malloc((strlen(name) + 1) * sizeof(char));
	setName(&obj, name);
	setConc(&obj, conc);
	setQty(&obj, qty);
	return obj;
}

void destructorMed(Med* obj)
{
	free(obj->name);
}