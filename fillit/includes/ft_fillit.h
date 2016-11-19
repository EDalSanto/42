/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 10:29:58 by edal-san          #+#    #+#             */
/*   Updated: 2016/10/13 19:43:08 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# define NON_VALID(b) (b!='\n'&&b!='#'&&b!='.')
# define ABS(n) ((n)<0 ? -(n) : (n))
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct		s_offsets
{
	int				offset0;
	int				offset1;
	int				offset2;
	int				offset3;
	char			letter;
}					t_offsets;

void				display_usage(char *program_name);
void				print_arr(char **arr);
char				**file_to_arr(char *argv);
char				**make_arr(char **arr, int fd);
void				destroy_arr(char **arr);
int					valid_file(int fd);
int					valid_blocks(char **arr);
int					*block_indexes(char *row);
char				*make_solution_arr(void);
int					highest_sqrt(void);
void				print_solution(char *solution_arr, int size);
t_offsets			tetri_detective(char *row);
t_offsets			first_seven(char *row, int c);
t_offsets			struct_cpy(t_offsets struct_to_copy);
t_offsets			*make_input_arr(char **tetri_arr);
t_offsets			t_offset_creator(int offset1, int offset2,
					int offset3, int offset4);
int					valid_placement(char *solution_arr, int sa_i,
					t_offsets tetri);
void				place_tetri(char *sol_arr, int sa_i, t_offsets t);
void				remove_tetri(char *solution_arr, int sa_i, t_offsets tetri);

/*
**	globals
*/

int					g_tetriminos;
int					g_size;
int					g_spaces;
unsigned int		g_counter;

#endif
