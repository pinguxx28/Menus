#include "menus.h"

// screen
void clear_screen (void) {
	printf("\e[1;1H\e[2J");
}


// cursor visibility
void hide_cursor (void) {
	printf("\033[?25l");
}

void show_cursor (void) {
	printf("\033[?25h");
}


// move cursor position
void move_xy (int x, int y) {
	     if (x > 0) printf("\033[%dC", abs(x));
	else if (x < 0) printf("\033[%dD", abs(x));
	
	     if (y > 0) printf("\033[%dB", abs(y));
	else if (y < 0) printf("\033[%dA", abs(y));
}

void move_x  (int x) {
	move_xy(x, 0);
}

void move_y  (int y) {
	move_xy(0, y);
}


// get cursor position
void where_xy (int *x, int *y) {
    printf("\033[6n");
    if (get_char() != '\x1B') return;
    if (get_char() != '\x5B') return;

    int in;
    int ly = 0;
    while ((in = get_char()) != ';')

    ly = ly * 10 + in - '0';	
    int lx = 0;
    while ((in = get_char()) != 'R')

    lx = lx * 10 + in - '0';
    *x = lx;
    *y = ly;
}

int  where_x  (void) {
	int x = 0, y = 0;
	where_xy(&x, &y);
	return x;
}

int  where_y  (void) {
	int x = 0, y = 0;
	where_xy(&x, &y);
	return y;
}


// set cursor position
void set_xy (int x, int y) {
	printf("\033[%d;%dH", y, x);
}

void set_x  (int x) {
	set_xy(x, where_y());
}

void set_y  (int y) {
	set_xy(where_x(), y);
}


// character actions
void put_char (char c) {
	printf("%c", c);
}

int  get_char (void) {
	struct termios oldt, newt;
	int ch;
	tcgetattr( STDIN_FILENO, &oldt );
	newt = oldt;
	newt.c_lflag &= ~ICANON;
	newt.c_lflag &= ~ECHO;
	tcsetattr( STDIN_FILENO, TCSANOW, &newt );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
	return ch;
}


// get window dimensions
int get_w (void) {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w.ws_col;
}

int get_h (void) {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w.ws_row;
}


// color support
int dec = NORMAL;
int bgc = BLACK + 10;
int fgc = WHITE;

void reset(void) {
	printf("\033[0m");
}

void set_dec(decor_t deco) {
	dec = deco;
	printf("\033[%d;%d;%dm", dec, fgc, bgc);
}

void set_fgc(color_t col) {
	fgc = col;
	printf("\033[%d;%d;%dm", dec, fgc, bgc);
}

void set_bgc(color_t col) {
	bgc = col + 10;
	printf("\033[%d;%d;%dm", dec, fgc, bgc);
}
