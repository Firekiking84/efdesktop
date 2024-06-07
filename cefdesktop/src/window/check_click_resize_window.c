/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 03/06/2024 15:33:00 ******************************************************
** keryan.houssin <keryan.houssin@terechkova.efrits.fr>
** - EfDesktop -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"window.h"

#include		<stdio.h>

static bool		apply_on_win(t_window						*win,
				     t_bunny_mouse_button_event const			*event,
				     int						side)
{
  win->is_resize = true;
  win->side_resize = side;
  win->delta_click.x = event->x - win->pos.x;
  win->delta_click.y = event->y - win->pos.y;
  return(true);
}

static bool		check_rl_side_for_corner(t_window				*win,
						 t_bunny_mouse_button_event const	*event,
						 int					side)
{
  if ((event->y - win->pos.y) < 3)
    return(apply_on_win(win, event, side + 6));
  else if ((win->pos_end.y - event->y) < 3)
    return(apply_on_win(win, event, side + 4));
  return(apply_on_win(win, event, side));
}

static bool		check_tb_side_for_corner(t_window				*win,
						 t_bunny_mouse_button_event const	*event,
						 int					side)
{
  if ((event->x - win->pos.x) < 3)
    return(apply_on_win(win, event, side + 2));
  else if ((win->pos_end.x - event->x) < 3)
    return(apply_on_win(win, event, side + 4));
  return(apply_on_win(win, event, side));
}

static bool		check_for_corner(t_window					*win,
					 t_bunny_mouse_button_event const		*event,
					 int						side)
{
  if (side == S_LEFT)
    return(check_rl_side_for_corner(win, event, side));
  else if (side == S_RIGHT)
    return(check_rl_side_for_corner(win, event, side));
  else if (side == S_TOP)
    return(check_tb_side_for_corner(win, event, side));
  else if (side == S_BOTTOM)
    return(check_tb_side_for_corner(win, event, side));
  return(apply_on_win(win, event, side));
}

bool			efcheck_click_resize_window(t_window				*win,
						    t_bunny_mouse_button_event const	*event)
{
  if (event->y >= win->pos.y && event->y < win->pos_end.y)
    {
      if (event->x >= win->pos.x && event->x < (win->pos.x + 3))
	return(check_for_corner(win, event, S_LEFT));
      else if (event->x >= (win->pos_end.x - 3) && event->x < win->pos_end.x)
	return(check_for_corner(win, event, S_RIGHT));
    }
  if (event->x >= win->pos.x && event->x < win->pos_end.x)
    {
      if (event->y >= win->pos.y && event->y < (win->pos.y + 3))
	return(check_for_corner(win, event, S_TOP));
      else if (event->y >= (win->pos_end.y - 3) && event->y < win->pos_end.y)
	return(check_for_corner(win, event, S_BOTTOM));
    }
  return(false);
}
