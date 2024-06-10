#include		"terminal.hh"

ef::Terminal::Terminal()
  : history()
  , lineOffset(0)
  , buffer()
{
  bg.full = BLACK;
  fontColor.full = WHITE;
}

ef::Terminal::Terminal(Terminal const	&other)
  : history(other.history)
  , lineOffset(other.lineOffset)
  , buffer(other.buffer)
  , bg(other.bg)
  , fontColor(other.fontColor)
{
}

ef::Terminal::~Terminal()
{
}
   
