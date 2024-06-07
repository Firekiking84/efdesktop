// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/06/2024 13:33:46 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - EfDesktop -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"window.hh"

void		ef::Window::checkClickMoveWindow(t_bunny_mouse_button_event const	*event)
{
   if (event->x >= pos.x &&
       event->x < head_pos_end.x &&
       event->y >= pos.y &&
       event->y < head_pos_end.y)
     {
       is_moving = true;
       delta_click.x = event->x - pos.x;
       delta_click.y = event->y - pos.y;
     }
}
