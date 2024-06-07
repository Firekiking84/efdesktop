#include		"efDesktop.hh"

void			ef::EfDesktop::parseDabsic(std::string const	&conf_name)
{
  t_bunny_configuration	*cnf;
  size_t		max_allocation;

  cnf = bunny_open_configuration(conf_name.data(), NULL);
  if (!cnf)
    {
      bunny_perror("Error while openning configuration");
      return;
    }
  if (!bunny_configuration_getf_int(cnf, (int *)&max_allocation, "max_allocation"))
    {
      bunny_perror("Error while getting the size of max allocation");
      return;
    }
  alloc.editMaxMemory(max_allocation);
  bunny_delete_configuration(cnf);
}
