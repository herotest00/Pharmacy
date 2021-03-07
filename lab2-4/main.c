#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h> 
#include "ui.h"
#include "tests.h" 

int main()
{
	runTests();
	run();
	_CrtDumpMemoryLeaks();
	return 0;
}
