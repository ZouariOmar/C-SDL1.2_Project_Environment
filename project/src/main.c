/***************************************************
 * @file      main.c
 * @author    @ZouariOmar (zouariomar20@gmail.com)
 * @brief     IDE__VSC
 * @version   0.1
 * @date      2024-06-06
 * @copyright Copyright (c) 2024
 ***************************************************/

//? ------------------------------ INCLUDE PROTOTYPE DECLARATION PART ------------------------------
#include "../inc/inc.h"

//? --------------------------------- MAIN() INT FUNCTION DEV PART ---------------------------------
int main() {
  //* init part
  initEverything();

  //* close the prog at exit
  closeEverything();

  //* game lunching fn
  //! her...

  //* free the main screen surface
  SDL_FreeSurface(screen);

  return 0;
}
