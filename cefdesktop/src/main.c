/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 03/06/2024 11:43:36 ******************************************************
** keryan.houssin <keryan.houssin@terechkova.efrits.fr>
** - EfDesktop -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"efdesktop.h"

int			main(void)
{
  t_data		data;
  t_bunny_color		win_color;
  t_bunny_position	win_pos;
  t_bunny_size		win_size;

  bunny_set_error_descriptor(2);
  data.screen = bunny_start(500, 500, false, "Test flottant");
  data.px = bunny_new_pixelarray(500, 500);
  win_pos.x = 100;
  win_pos.y = 100;
  win_size.x = 100;
  win_size.y = 100;
  win_color.full = RED;
  data.bg.full = win_color.full | PINK;
  data.win = efnew_window(win_pos, win_size, win_color);
  if (!data.win)
    return(1);
  bunny_set_loop_main_function(loop);
  bunny_set_display_function(display);
  bunny_set_event_response(event_response);
  bunny_loop(data.screen, 60, &data);
  bunny_stop(data.screen);
  bunny_delete_clipable(&data.px->clipable);
  efdelete_window(data.win);
  return(0);
}
