#include "menus.h"


int main () {
	clear_screen();
	hide_cursor();

	set_fgc(RED);
	set_dec(NORMAL);
	printf("hello world\n");

	reset();

	show_cursor();
	return 0;
}
