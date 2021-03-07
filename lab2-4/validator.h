#pragma once

#include "domain.h"

int validator(Med*);
/*
in: obj - adresa unui medicament
functia verifica daca datele de intrare sunt valide
out: 0 - daca datele sunt valide
	 1 - daca ID-ul este gresit
	 2 - daca numele este gresit
	 3 - daca concentratia este gresita
	 4 - daca cantiatea este gresita
*/