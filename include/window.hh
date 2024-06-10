// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/06/2024 15:44:16 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - EfDesktop -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#ifndef		__WINDOW_HH__

#define		__WINDOW_HH__

#include	"content.hh"
#include	"pixels.hh"

#include	<lapin.h>

namespace	ef
{

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

  // Window of desktop
  class		Window
  {
  public:

    // Window constructor
    Window(t_bunny_position	_pos,
	   t_bunny_size		_size,
	   t_bunny_color	_color,
	   IContent		*_content=NULL);

    // Window copy constructor
    Window(Window const		&other);

    // Window destructor
    ~Window();

    // Copy operator
    Window&	operator=(const Window	&other);

    // Manage events for the window
    void	events(const t_bunny_event				*event);

    // Display the window
    void	display(Pixels						&pixels);

    // Change the window content
    void	changeContent(I_Content					*_content);

  private:
    t_bunny_position	pos;
    t_bunny_position	pos_end;
    t_bunny_position	head_pos_end;
    t_bunny_size	size;
    t_bunny_color       color;
    bool		is_moving;
    bool		is_resize;
    int			side_resize;
    t_bunny_position	delta_click;
    IContent		*content;

    // Sub function of events
    // Format the position of the window into drawPos to not draw out of the canvas
    void	formatDrawPos(t_bunny_position				pos,
			      t_bunny_position				pos_end,
			      t_bunny_size				size_px,
			      t_bunny_position				*drawPos);
    
    // Sub function of events
    // Deal with mouse movements
    void	manageMouseMoved(t_bunny_mouse_move_event const		*event);

    // Sub function of manageMouseMoved
    // Deal the movement of the window lead by the mouse movements
    void	manageMouseMoveWindow(t_bunny_mouse_move_event const	*event);

    // Sub function of manageMouseMoved
    // Manage the resize of the window with the movement of the mouse
    void	manageMouseResizeWindow(t_bunny_mouse_move_event const	*event);

    // Sub function of manageMouseResizeWindow
    // Manage the resize of the side Left and Right
    void	manageRLSideResize(t_bunny_mouse_move_event const	*event);

    // Sub function of manageMouseResizeWindow
    // Manage the resize of the side Left and Right
    void	manageTBSideResize(t_bunny_mouse_move_event const	*event);
    // Sub function of events
    // Check click position, if it is in head box
    void	checkClickMoveWindow(t_bunny_mouse_button_event const	*event);

    // Sub function of events
    // Deal with the detection of click in the border to the window to resize it
    // Return true if click is in the border
    bool	checkClickResizeWindow(t_bunny_mouse_button_event const	*event);

    // Sub function of checkClickResizeWindow
    // check if the click is in a corner
    // Return true
    bool	checkForCorner(t_bunny_mouse_button_event const		*event,
			       int					side);

    // Sub function of checkForCorner
    // Check the side Right and Left
    // Return true
    bool	checkRLSideForCorner(t_bunny_mouse_button_event const	*event,
				     int				side);

    // Sub Function of checkForCorner
    // Check the side Top and Bottom
    // Return true
    bool	checkTBSideForCorner(t_bunny_mouse_button_event const	*event,
				     int				side);

    // Sub Function of checkTBSideForCorner and checkRLSideForCorner
    // Apply the init resize value on the class attribut
    // Return true
    bool	saveEditValues(t_bunny_mouse_button_event const		*event,
			       int					side);
  };
}


#endif	//	__WINDOW_HH__
