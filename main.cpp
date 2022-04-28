#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "file.h"

int main() 
{
	list L;

	create_text_editor(&L);
	input_keyboard(&L, 0, 0);
	tampil_list(L);
//	modify(&L);
//	save(L);
	return 0;
}
