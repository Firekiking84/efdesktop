// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/06/2024 18:36:01 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - EfDesktop -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#ifndef		__EF_DESKTOP_HH__

#define		__EF_DESKTOP_HH__

#include	"window.hh"

#include	<vector>

namespace	ef
{
  class		EfDesktop
  {
  public:
    EfDesktop();
    EfDesktop(std::string const	&conf);
    ~EfDesktop();

    void	addNewWindow(t_bunny_position	pos,
			     t_bunny_size	size,
			     t_bunny_color	color);

    // Dispatch events to all elements
    void	events(const t_bunny_event				*event);

    // Display the elements
    void	display(Pixels						&pixels);

  private:
    std::vector<Window>		windows;

    void	parseDabsic(std::string const	&conf);
  };
}

#endif	//	__EF_DESKTOP_HH__
