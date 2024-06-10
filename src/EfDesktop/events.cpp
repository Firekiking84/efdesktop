#include	"efDesktop.hh"

void		ef::EfDesktop::events(const t_bunny_event	*event)
{
  size_t	i;

  for (i = 0; i < windows.size(); i += 1)
    windows[i].events(event);
}
