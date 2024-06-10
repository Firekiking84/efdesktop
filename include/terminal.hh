#ifndef                 __TERMINAL_HH__

#define                 __TERMINAL_HH__

#include                "pixels.hh"

#include                <lapin.h>

namespace               ef
{
    class               Terminal : public IContent
    {
    public:
        Terminal(std::vector<std::string> const         &env);
        Terminal(Terminal const &other);
        ~Terminal();

        Terminal        &operator=(IContent const       &other);

        // Manage the Terminal events
        void            events(t_bunny_event const      *event);

        // Display the Terminal
        void            display(Pixels                  &pixels,
                                t_bunny_position        pos,
                                t_bunny_position        pos_end);

        // Refresh the terminal
        void            refresh();

        // Optimise the memory of the terminal
        void            optimise();
    
    private:
        // Old lines write by the user and the terminal programs
        // A few lines are deleted when the cap is reach
        // Empty when the function optimise is called
        std::string     history;

        // Store the offset of the line. The previous line are not display
        size_t          lineOffset;

        // Contains the current command the user is writing
        std::string     buffer;

        // Background color
        t_bunny_color   bg;

        // Text color
        t_bunny_color   fontColor;
    }
}

#endif  //              __TERMINAL_HH__
