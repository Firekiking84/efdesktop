/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 06/06/2024 13:26:47 ******************************************************
** keryan.houssin <keryan.houssin@aldrin.efrits.fr>
** - EfDesktop -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include	"window.h"

Window&		ef::Window::operator=(const Window	&other)
{
  alloc = other.alloc;
  pos = other.pos;
  pos_end = other.pos_end;
  head_pos_end = other.head_pos_end;
  size = other.size;
  color = other.color;
  is_moving = other.is_moving;
  is_resize = other.is_resize;
  side_resize = other.side_resize;
  delta_click = other.delta_click;
  return(*this);
}
