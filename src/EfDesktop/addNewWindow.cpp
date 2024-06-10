#include	"efDesktop.hh"

void		ef::EfDesktop::addNewWindow(t_bunny_position	pos,
					    t_bunny_size	size,
					    t_bunny_color	color)
{
  Window        window(pos, size, color);

  windows.push_back(window);
}
