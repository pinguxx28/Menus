#include "menus.h"


int main () {
	clear_screen();
	hide_cursor();

	set_xy(10, 10);
	printf("hello world\n");

	show_cursor();
	return 0;
}
