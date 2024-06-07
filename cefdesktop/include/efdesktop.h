/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 03/06/2024 11:37:01 ******************************************************
** keryan.houssin <keryan.houssin@terechkova.efrits.fr>
** - EfDesktop -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#ifndef			__EF_DESKTOP_H__

#define			__EF_DESKTOP_H__

#include		"window.h"

#include		<lapin.h>

typedef struct		s_data
{
  t_bunny_window	*screen;
  t_bunny_color		bg;
  t_bunny_pixelarray	*px;
  t_window		*win;
}			t_data;

t_bunny_response	event_response(t_bunny_event const	*event,
				       void			*data2);
t_bunny_response	loop(void				*data2);
t_bunny_response	display(void				*data2);


#endif //		__EF_DESKTOP_H__
