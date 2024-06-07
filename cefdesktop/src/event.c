/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 03/06/2024 11:36:54 ******************************************************
** keryan.houssin <keryan.houssin@terechkova.efrits.fr>
** - EfDesktop -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"efdesktop.h"

t_bunny_response	event_response(t_bunny_event const	*event,
				       void			*data2)
{
  t_data		*data;

  data = (t_data *)data2;
  if (event->type == BET_KEY_PRESSED)
    {
      if (event->key.sym == BKS_ESCAPE)
	return(EXIT_ON_SUCCESS);
    }
  efevents_window(data->win, event);
  return(GO_ON);
}
