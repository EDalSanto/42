# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    pseudo                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edal-san <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/17 10:09:40 by edal-san          #+#    #+#              #
/*   Updated: 2016/10/20 20:05:02 by edal-san         ###   ########.fr       */
#                                                                              #
# **************************************************************************** #

//No need to do buffer management

//format string is a character string
	//can be composed of zero or more directives
		//ordinary characters (not preceded by %) are copied to output stream unchanged
		//conversion specificiations (preceded by %) and ends with conversion specifier 
			//in between conversion specifier there can be zero or more flags,
			//an optional minimum field width, an optional precision and an
			//optional length modifier 
		//need to account for all Flag characters, Field width, Precision,
		//Length modifiers, and conversion specifiers
			// conversions: "sSpdDioOuUxXcC"
				//bonus: "eE, fF, gG, aA, n"
				//Store them in array of pointers to functions
				// i.e., d -> putnbr, h -> dec->hex
			// "%%"
			// flags: "#0-+ and space"
			// "precision"
			// flags: "hh, h, l, ll, j, z"
				// bonus: *, $, L, '
				// bonus: non existing flags management: %b to print binary, %r
				// to print a string of non-printable chars, %k to print a date in any ordin					ary ISO format etc.
//Return: the number of characters printed(excluding the null byte), or a
//negative value if an error is encountered
//
//Variadic function -> function of indefinite arity, one which accpets a variable number of arguments 
//	can be handled with stdarg.h
//		-to access the unnamed variables, one must declare a var of type va_list
//		the mactro va_start is then called with two arguments: the var of type
//		va_list and the name of the last named parameter of the function
//		-	
//

Pseudo
//While format string
//	if char is ordinary character, that is not proceeded by an escaped %, write
//	else (it is a conversion specifier)
//		find out which one it is (conversion specifier detective)
//			there may be optional flags, field widths, precisions, and length modifiers in t			his order
//				how to account for that?
//					series of sequential checks:
//						check if next char is a Flag character 
//							if so, create va_list to manage while flags chars
//							(increment string past flag characters)									
//						check if next char is an int for field width  
//
//					or find conversion specifier first and act accoringly,
//					because flags, precision, and length modifiers depend on
//					conversion specifiers
//						and then do checks above which respond according to flag
//						found
//			get arg from va_list	
//			create temp buffer in which to write before standardout?
//

Other Helper Fucntions
//itoa_base
//	in particular hex and octal

Plan
//Make array of functions to account for all "actions" from conversions specs,
	//flags, min field width, precision and length modifier
//Enable va_arg to accept unlimited num of arguments and flags, etc.
//functions to check for case and perform appropriate function
