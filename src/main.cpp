/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 06/06/2024 13:05:47 ******************************************************
** keryan.houssin <keryan.houssin@aldrin.efrits.fr>
** - EfDesktop -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include	"efDesktop.hh"
#include	"bunny_env.hh"

int		main(void)
{
  t_bunny_position	pos;
  t_bunny_size		size;
  t_bunny_color		color;

  color.full = BLUE;
  
  t_data	data(500, 500, "Desk", color);

  pos.x = 100;
  pos.y = 100;
  size.x = 100;
  size.y = 100;
  color.full = RED;
  data.desk.addNewWindow(pos, size, color);
  bunny_set_loop_main_function(loop);
  bunny_set_display_function(display);
  bunny_set_event_response(event_response);
  bunny_loop(data.win, 60, &data);
  return(0);
}
