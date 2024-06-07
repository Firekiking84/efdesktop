// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/06/2024 15:57:04 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - EfDesktop -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"window.hh"

void		ef::Window::manageRLSideResize(t_bunny_mouse_move_event const	*event)
{
  int			delta;

  delta = (event->x - pos.x) - delta_click.x;
  if (side_resize == S_LEFT ||
      side_resize == S_BOTTOM_LEFT ||
      side_resize == S_TOP_LEFT)
    {
      size.x -= delta;
      if (size.x < 20)
	size.x = 20;
      pos.x = pos_end.x - size.x;
    }
  else if (side_resize == S_RIGHT ||
	   side_resize == S_BOTTOM_RIGHT ||
	   side_resize == S_TOP_RIGHT)
    {
      size.x += delta;
      if (size.x < 20)
	  size.x = 20;
      pos_end.x = pos.x + size.x;
      head_pos_end.x = pos_end.x;
    }
}
