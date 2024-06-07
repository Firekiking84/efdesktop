// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/06/2024 13:48:13 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - EfDesktop -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"window.hh"

bool		ef::Window::checkClickResizeWindow(t_bunny_mouse_button_event const	*event)
{
  if (event->y >= pos.y && event->y < pos_end.y)
    {
      if (event->x >= pos.x && event->x < (pos.x + 3))
	return(checkForCorner(event, S_LEFT));
      else if (event->x >= (pos_end.x - 3) && event->x < pos_end.x)
	return(checkForCorner(event, S_RIGHT));
    }
  if (event->x >= pos.x && event->x < pos_end.x)
    {
      if (event->y >= pos.y && event->y < (pos.y + 3))
	return(checkForCorner(event, S_TOP));
      else if (event->y >= (pos_end.y - 3) && event->y < pos_end.y)
	return(checkForCorner(event, S_BOTTOM));
    }
  return(false);
}
