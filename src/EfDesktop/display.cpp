#include	"efDesktop.hh"

void		ef::EfDesktop::display(Pixels		&pixels)
{
  size_t	i;

  for (i = 0; i < windows.size(); i += 1)
    windows[i].display(pixels);
}
