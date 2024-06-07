/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 31/05/2024 12:53:01 ******************************************************
** keryan.houssin <keryan.houssin@terechkova.efrits.fr>
** - EfDesktop -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"window.h"
#include		"draw.h"

static void		format_draw_pos(t_bunny_position	pos,
					t_bunny_position	pos_end,
					t_bunny_size		screen_size,
					t_bunny_position	*draw_pos)
{
  if (pos.x < 0)
    draw_pos[0].x = 0;
  else
    draw_pos[0].x = pos.x;
  if (pos.y < 0)
    draw_pos[0].y = 0;
  else
    draw_pos[0].y = pos.y;
  if (pos_end.x > screen_size.x)
    draw_pos[1].x = screen_size.x - 1;
  else
    draw_pos[1].x = pos_end.x;
  if (pos_end.y > screen_size.y)
    draw_pos[1].y = screen_size.y - 1;
  else
    draw_pos[1].y = pos_end.y;
}

void			efdisplay_window(t_window		*win,
					 t_bunny_pixelarray	*px)
{
  t_bunny_position	pos[2];
  t_bunny_size		size_px;
  t_bunny_color		col_head;

  if (win->pos.x > px->clipable.buffer.width ||
      win->pos.y > px->clipable.buffer.height ||
      win->pos_end.x < 0 || win->pos_end.y < 0)
    return;
  size_px.x = px->clipable.buffer.width;
  size_px.y = px->clipable.buffer.height;
  format_draw_pos(win->pos, win->pos_end, size_px, pos);
  draw_rectangle(px, &pos[0], &pos[1], &win->col);
  format_draw_pos(win->pos, win->head_pos_end, size_px, pos);
  col_head.full = BLACK;
  draw_rectangle(px, &pos[0], &pos[1], &col_head);
}
