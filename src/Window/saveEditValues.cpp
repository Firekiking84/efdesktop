// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/06/2024 15:40:39 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - EfDesktop -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"window.hh"


bool		ef::Window::saveEditValues(t_bunny_mouse_button_event const	*event,
					   int					side)
{
  is_resize = true;
  side_resize = side;
  delta_click.x = event->x - pos.x;
  delta_click.y = event->y - pos.y;
  return(true);
}
