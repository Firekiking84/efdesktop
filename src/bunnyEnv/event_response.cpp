#include		"bunny_env.hh"

t_bunny_response	event_response(t_bunny_event const	*event,
				       void			*data2)
{
  t_data		*data;

  data = (t_data *)data2;
  data->desk.events(event);
  if (event->type == BET_KEY_PRESSED)
    {
      if (event->key.sym == BKS_ESCAPE)
	return(EXIT_ON_SUCCESS);
    }
  return(GO_ON);
}
