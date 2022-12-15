#ifndef __MENUS_H
#define __MENUS_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

// screen 
void clear_screen (void);

// cursor visibilty
void hide_cursor (void); 
void show_cursor (void); 

// move cursor position
void move_xy (int x, int y);
void move_x  (int x);
void move_y  (int y);

// get cursor position
void where_xy (int *x, int *y);
int  where_x  (void);
int  where_y  (void); 

// set cursor position
void set_xy (int x, int y); 
void set_x  (int x); 
void set_y  (int y); 

// character actions
void put_char (char c); 
int  get_char (void); 

// get window dimensions
int get_w (void);
int get_h (void);

// color support
extern int dec;
extern int bgc;
extern int fgc;

typedef enum {
	BLACK = 30,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	PURPLE,
	CYAN,
	WHITE,
} color_t;

typedef enum {
	BOLD		= 1,
	BRIGHT		= 1,
	FAINT		= 2,
	DIM		= 2,
	ITALIC		= 3,
	UNDERLINE	= 4,
	FADE		= 5,
	SLOW_BLINK	= 5,
	REVERSE		= 7,
	INVERT		= 7,
	CONCEAL		= 8,
	HIDE		= 8,
	CROSSED_OUT	= 9,
	STRIKE		= 9,
	DOUBLE_UNDERLINE= 21,
	UNDERLINE2	= 21,
	NORMAL		= 22,
} decor_t;

void reset(void);
void set_dec(decor_t deco);
void set_fgc(color_t col);
void set_bgc(color_t col);

#endif
