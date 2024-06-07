// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/06/2024 16:00:20 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - EfDesktop -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"window.hh"

void		ef::Window::manageTBSideResize(t_bunny_mouse_move_event const	*event)
{
  int			delta;

  delta = (event->y - pos.y) - delta_click.y;
  if (side_resize == S_TOP ||
      side_resize == S_TOP_LEFT ||
      side_resize == S_TOP_RIGHT)
    {
      size.y -= delta;
      if (size.y < 20)
	{
	  pos.y -= 20 - size.y;
	  size.y = 20;
	}
      pos.y = pos_end.y - size.y;
      head_pos_end.y = pos.y + 20;
    }
  else if (side_resize == S_BOTTOM ||
	   side_resize == S_BOTTOM_LEFT ||
	   side_resize == S_BOTTOM_RIGHT)
    {
      size.y += delta;
      if (size.y < 20)
	size.y = 20;
      pos_end.y = pos.y + size.y;
    }
}
