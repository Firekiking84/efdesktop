#include		"window.hh"

#include		"draw.h"

void			ef::Window::display(Pixels	&pixels)
{
  if (pos.x > pixels.getPixels()->clipable.buffer.width ||
      pos.y > pixels.getPixels()->clipable.buffer.height ||
      pos_end.x < 0 || pos_end.y < 0)
    return;

  t_bunny_position	drawPos[2];
  t_bunny_size		size_px;
  t_bunny_color		col_head;
  
  size_px.x = pixels.getPixels()->clipable.buffer.width;
  size_px.y = pixels.getPixels()->clipable.buffer.height;
  formatDrawPos(pos, pos_end, size_px, drawPos);
  ::draw_rectangle(pixels.getPixels(), &drawPos[0], &drawPos[1], &color);
  formatDrawPos(pos, head_pos_end, size_px, drawPos);
  col_head.full = BLACK;
  ::draw_rectangle(pixels.getPixels(), &drawPos[0], &drawPos[1], &col_head);
}
