#include	"efDesktop.hh"

void		ef::efDesktop::addNewWindow(t_bunny_position	pos,
					    t_bunny_size	size,
					    t_bunny_color	color)
{
  Window        *Window;
  
  alloc.allocate<Window>(pos, size, color, &alloc);
}
