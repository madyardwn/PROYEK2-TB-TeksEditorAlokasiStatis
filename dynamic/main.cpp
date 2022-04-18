#include <stdio.h>
#include <stdlib.h>
#include "input.h"

int main() 
{
	list L;
	
	create_text_editor(&L);
	input_keyboard(&L);
	tampil_list(L);
	
	return 0;
}