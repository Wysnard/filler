/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:36:49 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/30 16:37:17 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# ifndef SET_FLAG
#  define SET_FLAG(x, y) ((y) |= (x))
# endif

# ifndef UNSET_FLAG
#  define UNSET_FLAG(x, y) ((y) &= ~(x))
# endif

# ifndef IS_FLAG
#  define IS_FLAG(x, y) (((y) & (x)) == (x))
# endif

# ifndef IS_POW2
#  define IS_POW2(x) (((x) != 0) && (((x) & (~(x) + 1)) == (x)))
# endif

# ifndef NOT_FLAG
#  define NOT_FLAG(x, y) (!((y) & (x)))
# endif

# ifndef IS_WHITESPACE
#  define IS_WHITESPACE(x) ((x) == ' ' || (x) == '\n' || (x) == '\t')
# endif

# ifndef ABS
#  define ABS(x) ({__typeof__(x) _x = (x);_x < 0 ? -_x : _x;})
# endif

# ifndef MIN
#  define MIN(a, b) ({__typeof__(a)_a=(a);__typeof__(b)_b=(b);_a>_b ? _b : _a;})
# endif

# ifndef MAX
#  define MAX(a, b) ({__typeof__(a)_a=(a);__typeof__(b)_b=(b);_a<_b ? _b : _a;})
# endif

# ifndef POW2
#  define POW2(x) ((x) * (x))
# endif

#endif
