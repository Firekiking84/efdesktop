// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/06/2024 11:41:31 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - EfDesktop -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#ifndef			__PIXELS_HH__

#define			__PIXELS_HH__

#include		<lapin.h>

namespace		ef
{
  class			Pixels
  {
  public:
    Pixels(int		width,
	   int		height);
    ~Pixels();

    t_bunny_pixelarray	*getPixels();

  private:
    t_bunny_pixelarray	*px;
  };
}

#endif	//	__PIXELS_HH__
