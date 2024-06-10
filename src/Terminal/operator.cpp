#include        "terminal.hh"

ef::Terminal    ef::Terminal::operator=(IContent const  &other)
  {
    history = other.history;
    lineOffset = other.lineOffset;
    buffer = other.buffer;
    bg = other.bg;
    fontColor = other.fontColor;
  }
