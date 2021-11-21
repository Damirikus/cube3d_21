#include "cub3d.h"
int main(int argc, char **argv)
{
    t_data *data;

	data = malloc(sizeof (t_data));
    if (argc == 2)
    {
    	check_type(argv[1]);
    	parser(argc, argv, data);
    }
    return(1);
}
