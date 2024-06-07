/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 03/06/2024 11:39:59 ******************************************************
** keryan.houssin <keryan.houssin@terechkova.efrits.fr>
** - EfDesktop -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"efdesktop.h"
#include		"draw.h"

t_bunny_response	display(void			*data2)
{
  t_data		*data;

  data = (t_data *)data2;
  efclear_pixelarray(data->px, data->bg);
  efdisplay_window(data->win, data->px);
  bunny_blit(&data->screen->buffer, &data->px->clipable, NULL);
  bunny_display(data->screen);
  return(GO_ON);
}
