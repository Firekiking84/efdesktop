// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/06/2024 12:33:23 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - EfDesktop -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"window.hh"

void		ef::Window::events(const t_bunny_event	*event)
{
  if (event->type == BET_MOUSE_MOVED)
    manageMouseMoved(&event->mouse_moved);
  else if (event->type == BET_MOUSE_BUTTON_PRESSED && event->mouse_button.button == BMB_LEFT)
    {
      if (!checkClickResizeWindow(&event->mouse_button))
	checkClickMoveWindow(&event->mouse_button);
    }
  else if (event->type == BET_MOUSE_BUTTON_RELEASED && event->mouse_button.button == BMB_LEFT)
    {
      is_moving = false;
      is_resize = false;
      side_resize = S_NONE;
    }
}
