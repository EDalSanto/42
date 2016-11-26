void	adjust_scale(t_map *map)
{
	int		arr_i;
	int		point_i;
	t_point	*point;

	arr_i = 0;
	while (points[arr_i] != NULL)
	{
		point_i = 0;
		while (!((points[arr_i][point_i]).end))
		{
			point = &(points[arr_i][point_i]); 
			point->z_init += (point->z_init * .1 * map->zoom_factor);
			point->x_init += (point->x_init * .1 * map->zoom_factor);
			point->y_init += (point->y_init * .1 * map->zoom_factor);
			point_i++;  		
		}
		arr_i++;
	}
}
