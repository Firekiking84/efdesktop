// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/06/2024 13:28:55 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - EfDesktop -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"window.hh"

void		ef::Window::manageMouseMoveWindow(t_bunny_mouse_move_event const	*event)
{
  pos.x = event->x - delta_click.x;
  pos.y = event->y - delta_click.y;
  pos_end.x = pos.x + size.x;
  pos_end.y = pos.y + size.y;
  head_pos_end.x = pos_end.x;
  head_pos_end.y = pos.y + 20;
}

