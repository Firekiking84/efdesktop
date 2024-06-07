// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/06/2024 14:32:07 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - EfDesktop -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"window.hh"

bool		ef::Window::checkRLSideForCorner(t_bunny_mouse_button_event const	*event,
						 int					side)
{
  if ((event->y - pos.y) < 3)
    return(saveEditValues(event, side + 6));
  else if ((pos_end.y - event->y) < 3)
    return(saveEditValues(event, side + 4));
  return(saveEditValues(event, side));
}
