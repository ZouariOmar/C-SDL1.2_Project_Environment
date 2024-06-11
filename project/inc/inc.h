/***************************************************
 * @file      main.c
 * @author    @ZouariOmar (zouariomar20@gmail.com)
 * @brief     IDE__VSC
 * @version   0.1
 * @date      2024-06-06
 * @copyright Copyright (c) 2024
 ***************************************************/

#ifndef __INC_H__
#define __INC_H__

//? -------------------- DEFINE PROTOTYPE DECLARATION PART --------------------
#define MAX_PATH 260

//? -------------------- INCLUDE PROTOTYPE DECLARATION PART --------------------
//* STANDER LIBS INCLUDE PART
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

//* SDL1.2 INCLUDE PART
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_ttf.h>

//? --------------------- PUBLIC VARS DECLARATION PART ---------------------
//* SCREEN SURFACE DECLARATION
extern SDL_Surface *screen;

//* SCREEN RESOLUTION DECLARATION
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const int SCREEN_BPP;

//* SDL_COLOR PUBLIC DECLARATION
extern const SDL_Color WHITE;
extern const SDL_Color BLACK;

//? --------------------- STRUCT PROTOTYPE DECLARATION PART ----------------------
//? Surface struct
typedef struct Surface {
  SDL_Surface *win;
  SDL_Rect pos;
} surface;

//? -------------------- FUNCTIONS PROTOTYPE DECLARATION PART --------------------
/*
? --- initEverything() void func ---
* initialisation SDL1.2 environment
*/
void initEverything();

/*
? setScreen(int) void func
* x : 0               :: the screen will be in Windowed Mode
* x : SDL_FULLSCREEN  :: the screen will be in Fullscreen Mode
*/
void setScreen(int);

/*
? --- load_img(char *) SDL_Surface* ---
* optimizing the img process :: creat a new 32 bit img
*/
SDL_Surface *load_img(char *);

/*
? closeEverything() void func
* close SDL1.2 resources in exit action
*/
void closeEverything();

/* ---------------------------------------------
? --- LOAD && FREEING FUNCS DECLARATION PART ---
------------------------------------------------*/
/*
? set_pos(surface *, char *, int) void fn
* set all (Sint16 x, Sint16 y) surfaces pos
*/
void set_pos(surface *, char *, int);

/*
? loadResources(surface* sub, char* path, int f_res, int l_res) void fun
* load all resources
*/
void loadResources(surface *, char *, int, int);

//? freeResources(surface*) void fun
void freeResources(surface *, TTF_Font *, Mix_Chunk *, int);

#endif
