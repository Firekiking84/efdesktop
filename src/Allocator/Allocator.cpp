// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/06/2024 18:07:53 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - EfDesktop -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include	"allocator.hh"

ef::Allocator::Allocator(size_t	_maxRam,
			 size_t	_currentRamUsed)
  : currentRamUsed(_currentRamUsed)
  , maxRam(_maxRam)
{
}

ef::Allocator::~Allocator()
{
}
