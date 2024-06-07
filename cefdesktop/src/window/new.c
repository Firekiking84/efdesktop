/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 31/05/2024 16:42:39 ******************************************************
** keryan.houssin <keryan.houssin@terechkova.efrits.fr>
** - EfDesktop -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"window.h"

t_window		*efnew_window(t_bunny_position	pos,
				      t_bunny_size	size,
				      t_bunny_color	color)
{
  t_window		*win;

  win = bunny_malloc(sizeof(t_window));
  if (!win)
    {
      bunny_perror("Error malloc t_window");
      return(NULL);
    }
  win->pos = pos;
  win->size = size;
  win->pos_end.x = win->pos.x + win->size.x;
  win->pos_end.y = win->pos.y + win->size.y;
  win->head_pos_end.x = win->pos_end.x;
  win->head_pos_end.y = win->pos.y + 20;
  win->col.full = color.full;
  win->is_moving = false;
  win->is_resize = false;
  win->side_resize = S_NONE;
  win->delta_click.x = 0;
  win->delta_click.y = 0;
  return(win);
}
