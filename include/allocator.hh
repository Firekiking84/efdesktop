// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/06/2024 16:06:01 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - EfDesktop -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#ifndef		__ALLOCATOR_HH__

#define		__ALLOCATOR_HH__

#include	<string>
#include	<vector>
#include	<iostream>

namespace	ef
{
  class		Allocator
  {
  public:
    Allocator(size_t		_maxRam=20480,
	      size_t		_currentRamUsed=0);
    ~Allocator();

    void	editMaxMemory(size_t	newSize);

    template <typename Type, typename... Args>
    Type* allocate(Args...	args)
    {
      if ((currentRamUsed + sizeof(Type)) > maxRam)
	{
	  std::cerr << "Cannot allocate : Out of memory ! \n" << std::endl;
	  return(NULL);
	}
      else
	{
	  currentRamUsed += sizeof(Type);
	  return new Type(args...);
	}
    }

  private:
    size_t	currentRamUsed; // ko
    size_t	maxRam; // ko
  };
}

#endif //	__ALLOCATOR_HH__
