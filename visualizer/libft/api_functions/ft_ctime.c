/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 13:22:07 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 18:29:38 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ctime_private.h"

static const char		g_month_day[12] =
{
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

static const char		g_month_leap_day[12] =
{
	31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

static const char		g_months[12][3] =
{
	"Jan",
	"Feb",
	"Mar",
	"Apr",
	"May",
	"Jun",
	"Jul",
	"Aug",
	"Sep",
	"Oct",
	"Nov",
	"Dec"
};

static const char		g_days[7][3] =
{
	"Mon",
	"Tue",
	"Wed",
	"Thu",
	"Fri",
	"Sat",
	"Sun"
};

static char						*minitoa(int n)
{
	char		*str;

	FAILZ(str = ft_strnew(2), NULL);
	if (n > 9)
	{
		str[0] = n / 10 + 48;
		str[1] = n % ((n / 10) * 10) + 48;
	}
	else
	{
		str[0] = 48;
		str[1] = n + 48;
	}
	GIMME(str);
}

static int8_t					get_day(const struct s_time *tm)
{
	int8_t		day;

	day = (tm->day_n\
		+ ((153 * (tm->month + 12 * ((14 - tm->month) / 12) - 3) + 2) / 5)\
		+ (365 * (tm->year_n + 4800 - ((14 - tm->month) / 12)))\
		+ ((tm->year_n + 4800 - ((14 - tm->month) / 12)) / 4)\
		- ((tm->year_n + 4800 - ((14 - tm->month) / 12)) / 100)\
		+ ((tm->year_n + 4800 - ((14 - tm->month) / 12)) / 400)\
		- 32045) % 7;
	GIMME(day);
}

static int						get_ymd(struct s_time *tm, time_t *epoch_secs)
{
	int8_t		leap;

	leap = 2;
	while (++tm->year_n && ((!leap && *epoch_secs >= LEAP_YEAR_SECONDS)
		|| (leap && *epoch_secs >= YEAR_SECONDS)))
	{
		*epoch_secs -= YEAR_SECONDS + (!leap ? 24 * 3600 : 0);
		++leap;
		leap = (leap == 4 ? 0 : leap);
	}
	FAILZ(tm->year = ft_itoa(tm->year_n), -1);
	while ((!leap && *epoch_secs >= 24 * 3600 * g_month_leap_day[tm->month - 1])
		|| (leap && *epoch_secs >= 24 * 3600 * g_month_day[tm->month - 1]))
	{
		*epoch_secs -= 24 * 3600 * g_month_day[tm->month - 1]\
			+ (!leap && tm->month == 2 ? 24 * 3600 : 0);
		++tm->month;
	}
	while (++tm->day_n && *epoch_secs >= 24 * 3600)
		*epoch_secs -= 24 * 3600;
	FAILZ(tm->day = minitoa(tm->day_n), -1);
	if ((tm->month == 3 && tm->day_n > 26) || (tm->month > 3 && tm->month < 10)
		|| (tm->month == 10 && tm->day_n < 26))
		*epoch_secs += 3600;
	KTHXBYE;
}

static struct s_time			*initialize_struct(const time_t *clock)
{
	int					n;
	struct s_time		*tm;
	time_t				epoch_secs;

	FAILZ(tm = (struct s_time *)malloc(sizeof(struct s_time)), NULL);
	tm->year_n = 1969;
	tm->month = 1;
	tm->day_n = 0;
	epoch_secs = *clock;
	EPICFAILZ(get_ymd(tm, &epoch_secs), NULL);
	n = 0;
	while (epoch_secs >= 3600 && ++n)
		epoch_secs -= 3600;
	FAILZ(tm->hour = minitoa(n), NULL);
	n = 0;
	while (epoch_secs >= 60 && ++n)
		epoch_secs -= 60;
	FAILZ(tm->minutes = minitoa(n), NULL);
	FAILZ(tm->seconds = minitoa(epoch_secs), NULL);
	GIMME(tm);
}

char							*ft_ctime(const time_t *clock)
{
	char				*string;
	struct s_time		*tm;

	FAILZ(string = ft_strnew(25), NULL);
	FAILZ(tm = initialize_struct(clock), NULL);
	ft_strncat(string, g_days[get_day(tm)], 3);
	ft_strcat(string, " ");
	ft_strncat(string, g_months[tm->month - 1], 3);
	ft_strcat(string, " ");
	ft_strcat(string, tm->day);
	ft_strcat(string, " ");
	ft_strcat(string, tm->hour);
	ft_strcat(string, ":");
	ft_strcat(string, tm->minutes);
	ft_strcat(string, ":");
	ft_strcat(string, tm->seconds);
	ft_strcat(string, " ");
	ft_strcat(string, tm->year);
	string[24] = '\n';
	ft_cleanup("PPPPP", tm->year, tm->day, tm->hour, tm->minutes, tm->seconds);
	ft_memdel((void **)&tm);
	GIMME(string);
}
