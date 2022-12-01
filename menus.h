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

#endif
