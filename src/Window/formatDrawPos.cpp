#include		"window.hh"

void			ef::Window::formatDrawPos(t_bunny_position	_pos,
						  t_bunny_position	_pos_end,
						  t_bunny_size		size_px,
						  t_bunny_position	*drawPos)
{
  if (_pos.x < 0)
    drawPos[0].x = 0;
  else
    drawPos[0].x = _pos.x;
  if (_pos.y < 0)
    drawPos[0].y = 0;
  else
    drawPos[0].y = _pos.y;
  if (_pos_end.x > size_px.x)
    drawPos[1].x = size_px.x - 1;
  else
    drawPos[1].x = _pos_end.x;
  if (_pos_end.y > size_px.y)
    drawPos[1].y = size_px.y - 1;
  else
    drawPos[1].y = _pos_end.y;
}
