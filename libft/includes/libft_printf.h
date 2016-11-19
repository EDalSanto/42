/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 20:44:18 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/10 20:32:12 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# define IS_BASE_10(c)		(c=='d'||c=='D'||c=='i')
# define IS_UNSIGNED(c)		(c=='u'||c=='U')
# define IS_BASE_8(c)		(c=='o'||c=='O')
# define IS_BASE_16(c)		(c=='x'||c=='X')
# define IS_UNSIGNED_ALL(c) (IS_UNSIGNED(c)||IS_BASE_8(c)||IS_BASE_16(c))
# define IS_NUM(c)	(IS_BASE_10(c)||IS_UNSIGNED(c)||IS_BASE_8(c)||IS_BASE_16(c))

typedef struct				s_pf_detective
{
	va_list					ap;
	int						printed;
	char					*fmt_cpy;
	char					invalid;
	size_t					arg_len;
	size_t					spaces_to_print;
	size_t					zeros_to_print;
	char					convsp;
	char					percentage;
	char					str_holder[10000];
	wchar_t					*wide_str_holder;
	long long int			signed_int_holder;
	unsigned long long int	unsigned_int_holder;
	void					*mem_holder;
	unsigned char			char_holder;
	wchar_t					wc_holder;
	char					flags[10000];
	int						flags_idx;
	int						hash_flag;
	int						zero_flag;
	int						minus_flag;
	int						space_flag;
	int						plus_flag;
	char					precision[10000];
	int						pr_flag;
	char					field_width[10000];
	char					len_mod[10000];
	char					*temp;
}							t_pf_detective;

int							ft_printf(const char *fmt, ...);
int							len_mod_detected(char s);
int							convsp_detected(char s);
int							flag_detected(char s);
int							second_quote(char *fmt);
void						add_flag(t_pf_detective *pf, char flag);
void						add_len_mod(t_pf_detective *pf, char len_mod);
void						handle_int(t_pf_detective *pf);
void						handle_long_int(t_pf_detective *pf);
void						handle_octal(t_pf_detective *pf);
void						handle_hex(t_pf_detective *pf);
void						handle_unsigned(t_pf_detective *pf);
void						handle_str(t_pf_detective *pf);
void						handle_char(t_pf_detective *pf);
void						handle_widestr(t_pf_detective *pf);
void						handle_widechar(t_pf_detective *pf);
void						handle_addr(t_pf_detective *pf);
void						handle_quot(t_pf_detective *pf);
void						ft_putwchar(wchar_t w, char *buffer);
size_t						ft_wcharlen(wchar_t w);
size_t						ft_wstrlen(wchar_t *wstr);
void						ft_putwstr(wchar_t *wstr, char *buffer);
void						parse_nums(t_pf_detective *pf);
int							valid_char(char c);
int							pr_or_fw_found(char *c);
void						fmt_detective(t_pf_detective *pf,
										char **place_holder);
int							parse_convsp(t_pf_detective *pf);
void						wildcard_fw_detective(t_pf_detective *pf,
														int fw_value);
void						wildcard_pr_detective(t_pf_detective *pf,
														int pr_value);
void						find_fw_and_pr(t_pf_detective *pf, char *fw,
													char *pr, int pr_value);
void						get_int_arg(t_pf_detective *pf);
void						get_unsigned_int_arg(t_pf_detective *pf);
void						get_char_arg(t_pf_detective *pf);
void						get_str_arg(t_pf_detective *pf);
void						get_arg(t_pf_detective *pf);
void						get_intarg_len(t_pf_detective *pf);
void						get_arg_len(t_pf_detective *pf);
void						handle_num_convsp(t_pf_detective *pf);
void						handle_convsp(t_pf_detective *pf);
void						handle_hash_flag(t_pf_detective *pf);
void						handle_space_flag(t_pf_detective *pf);
void						handle_plus_flag(t_pf_detective *pf);
void						handle_flags(t_pf_detective *pf);
int							wide_char_space_left(t_pf_detective *pf,
									size_t byte_len_so_far, size_t i);
size_t						widechar_last_len_detective(t_pf_detective *pf);
void						str_spaces_detective(t_pf_detective *pf,
													size_t pr, size_t fw);
void						num_spaces_detective(t_pf_detective *pf,
													size_t pr, size_t fw);
void						spaces_detective(t_pf_detective *pf,
													size_t pr, size_t fw);
void						pr_detective(t_pf_detective *pf, size_t pr);
void						fw_detective(t_pf_detective *pf, size_t fw);
void						pr_and_fw_detective(t_pf_detective *pf,
													size_t pr, size_t fw);
void						print_detective(t_pf_detective *pf);
void						handle_num_convsp(t_pf_detective *pf);
void						handle_convsp(t_pf_detective *pf);
int							handle_arg(t_pf_detective *pf);
void						print_left_just(t_pf_detective *pf);
void						print_right_just(t_pf_detective *pf);
void						print_f(t_pf_detective *pf);
void						reset_flags(t_pf_detective *pf);
void						print(t_pf_detective *pf);
char						*only_valid_chars(char *place_holder);

#endif
