/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 31/05/2024 11:55:12 ******************************************************
** keryan.houssin <keryan.houssin@terechkova.efrits.fr>
** - EfDesktop -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"window.h"

static void	efcheck_click_move_window(t_window				*win,
					  t_bunny_mouse_button_event const	*event)
{
   if (event->x >= win->pos.x &&
       event->x < win->head_pos_end.x &&
       event->y >= win->pos.y &&
       event->y < win->head_pos_end.y)
     {
       win->is_moving = true;
       win->delta_click.x = event->x - win->pos.x;
       win->delta_click.y = event->y - win->pos.y;
     }
}

static void	manage_mouse_move_window(t_window				*win,
					 t_bunny_mouse_move_event const		*event)
{
  win->pos.x = event->x - win->delta_click.x;
  win->pos.y = event->y - win->delta_click.y;
  win->pos_end.x = win->pos.x + win->size.x;
  win->pos_end.y = win->pos.y + win->size.y;
  win->head_pos_end.x = win->pos_end.x;
  win->head_pos_end.y = win->pos.y + 20;
}

static void	manage_mouse_moved(t_window					*win,
				   t_bunny_mouse_move_event const		*event)
{
  if (win->is_moving)
    manage_mouse_move_window(win, event);
  else if (win->is_resize)
    efmanage_mouse_resize_window(win, event);
}

void			efevents_window(t_window				*win,
					const t_bunny_event			*event)
{
  if (event->type == BET_MOUSE_MOVED)
    manage_mouse_moved(win, &event->mouse_moved);
  else if (event->type == BET_MOUSE_BUTTON_PRESSED && event->mouse_button.button == BMB_LEFT)
    {
      if (!efcheck_click_resize_window(win, &event->mouse_button))
	efcheck_click_move_window(win, &event->mouse_button);
    }
  else if (event->type == BET_MOUSE_BUTTON_RELEASED && event->mouse_button.button == BMB_LEFT)
    {
      win->is_moving = false;
      win->is_resize = false;
      win->side_resize = S_NONE;
    }
}
