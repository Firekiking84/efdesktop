// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/06/2024 12:20:15 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - EfDesktop -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include		"window.hh"

ef::Window::Window(t_bunny_position	_pos,
		   t_bunny_size		_size,
		   t_bunny_color	_color,
		   I_Content		*_content)
  : pos(_pos)
  , size(_size)
  , color(_color)
  , is_moving(false)
  , is_resize(false)
  , side_resize(ef::S_NONE)
  , content(_content)
{
  pos_end.x = pos.x + size.x;
  pos_end.y = pos.y + size.y;
  head_pos_end.x = pos_end.x;
  head_pos_end.y = pos.y + 20;
  delta_click.x = 0;
  delta_click.y = 0;
}

ef::Window::Window(Window const		&other)
  : pos(other.pos)
  , pos_end(other.pos_end)
  , head_pos_end(other.head_pos_end)
  , size(other.size)
  , color(other.color)
  , is_moving(other.is_moving)
  , is_resize(other.is_resize)
  , side_resize(other.side_resize)
  , delta_click(other.delta_click)
  , content(other.content)
{
}

ef::Window::~Window()
{
}
