// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/06/2024 14:26:54 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - EfDesktop -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"window.hh"

bool		ef::Window::checkForCorner(t_bunny_mouse_button_event const	*event,
					   int					side)
{
  if (side == S_LEFT || side == S_RIGHT)
    return(checkRLSideForCorner(event, side));
  else if (side == S_TOP || side == S_BOTTOM)
    return(checkTBSideForCorner(event, side));
  return(saveEditValues(event, side));
}
