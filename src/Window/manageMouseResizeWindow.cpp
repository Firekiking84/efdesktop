// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/06/2024 15:52:34 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - EfDesktop -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"window.hh"

void		ef::Window::manageMouseResizeWindow(t_bunny_mouse_move_event const	*event)
{
  manageRLSideResize(event);
  manageTBSideResize(event);
  delta_click.x = event->x - pos.x;
  delta_click.y = event->y - pos.y;
}
