/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 03/06/2024 15:48:18 ******************************************************
** keryan.houssin <keryan.houssin@terechkova.efrits.fr>
** - EfDesktop -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"window.h"

static void		manage_rl_side_resize(t_window					*win,
					      t_bunny_mouse_move_event const		*event)
{
  int			delta;

  delta = (event->x - win->pos.x) - win->delta_click.x;
  if (win->side_resize == S_LEFT ||
      win->side_resize == S_BOTTOM_LEFT ||
      win->side_resize == S_TOP_LEFT)
    {
      win->size.x -= delta;
      if (win->size.x < 20)
	win->size.x = 20;
      win->pos.x = win->pos_end.x - win->size.x;
    }
  else if (win->side_resize == S_RIGHT ||
	   win->side_resize == S_BOTTOM_RIGHT ||
	   win->side_resize == S_TOP_RIGHT)
    {
      win->size.x += delta;
      if (win->size.x < 20)
	  win->size.x = 20;
      win->pos_end.x = win->pos.x + win->size.x;
      win->head_pos_end.x = win->pos_end.x;
    }
}

static void		manage_tb_side_resize(t_window					*win,
					      t_bunny_mouse_move_event const		*event)
{
  int			delta;

  delta = (event->y - win->pos.y) - win->delta_click.y;
  if (win->side_resize == S_TOP ||
      win->side_resize == S_TOP_LEFT ||
      win->side_resize == S_TOP_RIGHT)
    {
      win->size.y -= delta;
      if (win->size.y < 20)
	{
	  win->pos.y -= 20 - win->size.y;
	  win->size.y = 20;
	}
      win->pos.y = win->pos_end.y - win->size.y;
      win->head_pos_end.y = win->pos.y + 20;
    }
  else if (win->side_resize == S_BOTTOM ||
	   win->side_resize == S_BOTTOM_LEFT ||
	   win->side_resize == S_BOTTOM_RIGHT)
    {
      win->size.y += delta;
      if (win->size.y < 20)
	win->size.y = 20;
      win->pos_end.y = win->pos.y + win->size.y;
    }
}

void			efmanage_mouse_resize_window(t_window				*win,
						     t_bunny_mouse_move_event const	*event)
{
  manage_rl_side_resize(win, event);
  manage_tb_side_resize(win, event);
  win->delta_click.x = event->x - win->pos.x;
  win->delta_click.y = event->y - win->pos.y;
}
