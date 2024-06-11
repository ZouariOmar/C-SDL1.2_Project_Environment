/* -----------------------------------------------
* @team:   by_kayori_Nova_Grp
* @author: @ZouariOmar
* @IDE:    @vsc
* @update: 05/15/24
? @file:   lib.c
----------------------------------------------- */

//? ----------------------- NOTE SECTION DECLARATION PART -----------------------
/*
 * NONE...
 */

//? -------------------- INCLUDE PROTOTYPE DECLARATION PART --------------------
#include "../inc/inc.h"

//* SCREEN SURFACE DEFINTION
SDL_Surface *screen = NULL;

//* SCREEN RESOLUTION DEFINTION
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;
const int SCREEN_BPP = 32;

//* SDL_COLOR PUBLIC DEFINTION
const SDL_Color WHITE = {255, 255, 255, 0};
const SDL_Color BLACK = {0, 0, 0, 0};

//? ----------------------- FUNCTIONS PROTOTYPE DEV PART -----------------------
void initEverything() {
  //* SDL initialisation process
  if (SDL_Init(SDL_INIT_EVERYTHING)) {
    fprintf(stderr, "%s !", SDL_GetError());
    exit(1);
  }

  //* TTF initialisation process
  TTF_Init();

  //* Mix initialisation process
  if ((Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024))) {
    fprintf(stderr, "%s !", SDL_GetError());
    exit(1);
  }

  //* IMG initialisation process
  IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

  //* upload the screen mode
  setScreen(0);

  //* set the game caption
  SDL_WM_SetCaption("Hollow Vessels", NULL);
}

void closeEverything() {
  atexit(Mix_Quit);
  atexit(IMG_Quit);
  atexit(TTF_Quit);
  atexit(SDL_Quit);
}

SDL_Surface *load_img(char *path) {
  SDL_Surface *loadedImg = IMG_Load(path),
              *optimizedImg = NULL;
  if (loadedImg) {
    optimizedImg = SDL_DisplayFormatAlpha(loadedImg);
    SDL_FreeSurface(loadedImg);
  }
  return optimizedImg;
}

void setScreen(int x) {
  const SDL_VideoInfo *Video_Info = SDL_GetVideoInfo();
  if (Video_Info)
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF | x);
  else
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF | x);
  if (!screen) {
    fprintf(stderr, "%s !", SDL_GetError());
    exit(1);
  }
}

//? ----------------------- LOAD && FREEING FUNCTIONS DEV PART -----------------------
void set_pos(surface *sub, char *path, int nb_res) {
  //* open the settings file
  FILE *file = fopen(path, "r");
  if (!file) {
    perror("Error: can't open settings_ref file !");
    exit(EXIT_FAILURE);
  }

  //* fill all surface positions
  int i = 0;
  while (i < nb_res && fscanf(file, "%hd%hd", &(sub[i].pos.x), &(sub[i].pos.y)) == 2)
    i++;

  //* close the settings file
  fclose(file);
}

void loadResources(surface *sub, char *path, int begin_res, int nbr_res) {
  while (begin_res < nbr_res) {
    char tmp_path[260];
    sprintf(tmp_path, "%s%d%s", path, begin_res, ".png");
    sub[begin_res].win = load_img(tmp_path);
    begin_res++;
  }
}

void freeResources(surface *sub, TTF_Font *font, Mix_Chunk *pip, int nb_res) {
  for (int i = 0; i < nb_res; i++)
    SDL_FreeSurface(sub[i].win);
  TTF_CloseFont(font);
  Mix_FreeChunk(pip);
}