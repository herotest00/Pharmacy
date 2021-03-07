#include <string.h>
#include "validator.h"

int validator (Med* obj)
{
	if (getID (obj) < 0)
		return 1;
	if (strcmp(getName(obj), "") == 0)
		return 2;
	if (getConc(obj) < 0)
		return 3;
	if (getQty(obj) < 1)
		return 4;
	return 0;
}