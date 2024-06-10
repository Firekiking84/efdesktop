#ifndef			__CONTENT_HH__

#define			__CONTENT_HH__

#include		"pixels.hh"

#include		<lapin.h>

namespace		ef
{
  // Interface for contents of a window
  class			IContent
  {
  public:
    IContent() = default;
    virtual IContent(IContent const	&other) = 0;
    virtual ~IContent() = default;

    virtual IContent	&operator=(IContent const	&other) = 0;

    // Manage the events given by the window
    virtual void	events(const t_bunny_event	*event) = 0;

    // Display the content into the window
    virtual void	display(Pixels			&pixels,
				t_bunny_position	pos,
				t_bunny_position	pos_end) = 0;

    // Refresh the content
    virtual void	refresh() = 0;

    // Optimise the memory of the content
    virtual void	optmise() = 0;
  private:
  };
}

#endif	//		__CONTENT_HH__
