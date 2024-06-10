#ifndef		__BUNNY_ENV_HH__

#define		__BUNNY_ENV_HH__

#include	"pixels.hh"
#include	"efDesktop.hh"

#include	<lapin.h>

struct		t_data
{
  t_data(size_t			width,
	 size_t			height,
	 std::string const	&screenName,
	 t_bunny_color		_bg)
    : win(bunny_start(width, height, false, screenName.data()))
    , pixels(width, height)
    , desk()
    , bg(_bg)
  {    
  }
  ~t_data()
  {
    bunny_stop(win);
  }
  t_bunny_window	*win;
  ef::Pixels		pixels;
  ef::EfDesktop		desk;
  t_bunny_color		bg;
};

t_bunny_response	event_response(t_bunny_event const	*event,
				       void			*data2);

t_bunny_response	loop(void				*data2);

t_bunny_response	display(void				*data2);

#endif	//	__BUNNY_ENV_HH__
