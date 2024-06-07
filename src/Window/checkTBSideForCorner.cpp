// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/06/2024 15:35:09 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - EfDesktop -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"window.hh"

bool		ef::Window::checkTBSideForCorner(t_bunny_mouse_button_event const	*event,
						 int					side)
{
  if ((event->x - pos.x) < 3)
    return(saveEditValues(event, side + 2));
  else if ((pos_end.x - event->x) < 3)
    return(saveEditValues(event, side + 4));
  return(saveEditValues(event, side));
}
