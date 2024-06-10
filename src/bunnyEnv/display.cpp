#include		"bunny_env.hh"

#include		"draw.h"

t_bunny_response	display(void		*data2)
{
  t_data		*data;

  data = (t_data *)data2;
  efclear_pixelarray(data->pixels.getPixels(), data->bg);
  data->desk.display(data->pixels);
  bunny_blit(&data->win->buffer, &(data->pixels.getPixels()->clipable), NULL);
  bunny_display(data->win);
  return(GO_ON);
}
