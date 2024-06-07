/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 31/05/2024 11:49:45 ******************************************************
** keryan.houssin <keryan.houssin@terechkova.efrits.fr>
** - EfDesktop -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#ifndef			__WINDOW_H__

#define			__WINDOW_H__

#include		<lapin.h>

typedef enum		e_side
  {
    S_NONE = -1,
    S_LEFT,
    S_RIGHT,
    S_TOP,
    S_BOTTOM,
    S_BOTTOM_LEFT,
    S_BOTTOM_RIGHT,
    S_TOP_LEFT,
    S_TOP_RIGHT
  }			t_side;

typedef struct		s_window
{
  t_bunny_position	pos;
  t_bunny_position	pos_end;
  t_bunny_position	head_pos_end;
  t_bunny_size		size;
  t_bunny_color		col;
  bool			is_moving;
  bool			is_resize;
  int			side_resize;
  t_bunny_position	delta_click;
}			t_window;

// Create a new window
t_window		*efnew_window(t_bunny_position					pos,
				      t_bunny_size					size,
				      t_bunny_color					color);

// Delete the window
void			efdelete_window(t_window					*win);

// Manage event for the window
void			efevents_window(t_window					*win,
					const t_bunny_event				*event);

// Sub function of efevents_window
// Deal with the detection of click in the border to the window to resize it
// Return true if click is in the border
bool			efcheck_click_resize_window(t_window				*win,
						    t_bunny_mouse_button_event const	*event);

// Sub function of efevents_window
// Manage the resize of the window with the movement of the mouse
void			efmanage_mouse_resize_window(t_window				*win,
						     t_bunny_mouse_move_event const	*event);

// Display the window
void			efdisplay_window(t_window					*win,
					 t_bunny_pixelarray				*px);

#endif	//	__WINDOW_H__
