#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

constexpr unsigned DOW_MON      = 0b0000'0001;
constexpr unsigned DOW_TUE      = 0b0000'0010;
constexpr unsigned DOW_WED      = 0b0000'0100;
constexpr unsigned DOW_THU      = 0b0000'1000;
constexpr unsigned DOW_FRI      = 0b0001'0000;
constexpr unsigned DOW_SAT      = 0b0010'0000;
constexpr unsigned DOW_SUN      = 0b0100'0000;
constexpr unsigned DOW_WORKDAYS = DOW_MON | DOW_TUE | DOW_WED | DOW_THU | DOW_FRI;
constexpr unsigned DOW_WEEKEND  = DOW_SAT | DOW_SUN;
constexpr unsigned DOW_ALL      = DOW_WORKDAYS | DOW_WEEKEND;

typedef struct TDate
{
  unsigned m_Year;
  unsigned m_Month;
  unsigned m_Day;
} TDATE;

TDATE makeDate(unsigned y, unsigned m, unsigned d)
{
  TDATE res = { y, m, d };
  return res;
}
#endif /* __PROGTEST__ */

int is_leap_year(unsigned year) {
  if (year % 4000 == 0) return 0;
  if (year % 400 == 0) return 1;
  if (year % 100 == 0) return 0;
  return year % 4 == 0;
}

unsigned get_days_in_month(unsigned year, unsigned month) {
  const unsigned days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  return days_in_month[month - 1] + (month == 2 && is_leap_year(year));
}

int is_valid_date(TDATE date) {
  if (date.m_Year < 2000 || date.m_Year > 1000000000  || date.m_Month < 1 || date.m_Month > 12)
    return 0;
  return (date.m_Day >= 1 && date.m_Day <= get_days_in_month(date.m_Year, date.m_Month));
}

int day_of_week_from_number(long long day_number) {
  return (int)(day_number % 7);
}

long long date_to_day_number(TDATE date) {
  long long a = (14 - date.m_Month) / 12;
  long long y = date.m_Year + 4800 - a;
  long long m = date.m_Month + 12 * a - 3;
  long long jdn = date.m_Day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
  long long jdn_base = 2451545;
  return jdn - jdn_base;
}

void day_number_to_date(long long day_number, TDATE *date) {
  long long jdn = day_number + 2451545;
  long long l = jdn + 68569;
  long long n = (4 * l) / 146097;
  l = l - (146097 * n + 3) / 4;
  long long i = (4000 * (l + 1)) / 1461001;
  l = l - (1461 * i) / 4 + 31;
  long long j = (80 * l) / 2447;
  long long d = l - (2447 * j) / 80;
  l = j / 11;
  long long m = j + 2 - 12 * l;
  long long y = 100 * (n - 49) + i + l;

  date->m_Year = (unsigned) y;
  date->m_Month = (unsigned) m;
  date->m_Day = (unsigned) d;
}

unsigned long long count_occurrences(unsigned long long N, int h_from, int D) {
  int offset = (D - h_from + 7) % 7;
  if ((unsigned long long) offset >= N)
    return 0;
  unsigned long long total_days = N - offset;
  return (total_days + 6) / 7;
}

long long countConnections(TDATE from, TDATE to, unsigned per_work_day, unsigned dow_mask) {
  if (!is_valid_date(from) || !is_valid_date(to))
    return -1;
  long long day_from = date_to_day_number(from);
  long long day_to = date_to_day_number(to);
  if (day_from > day_to)
    return -1;
  unsigned long long N = (unsigned long long) (day_to - day_from + 1);
  int h_from = day_of_week_from_number(day_from);
  long long total_connections = 0;

  for (int D = 0; D <= 6; ++D) {
    unsigned dow_constant = 0;
    switch (D) {
      case 0:
        dow_constant = DOW_SAT;
      break;
      case 1:
        dow_constant = DOW_SUN;
      break;
      case 2:
        dow_constant = DOW_MON;
      break;
      case 3:
        dow_constant = DOW_TUE;
      break;
      case 4:
        dow_constant = DOW_WED;
      break;
      case 5:
        dow_constant = DOW_THU;
      break;
      case 6:
        dow_constant = DOW_FRI;
      break;
      default:
        break;
    }
    if ((dow_mask & dow_constant) == 0)
      continue;
    unsigned long long count_D = count_occurrences(N, h_from, D);
    unsigned per_day_connections = 0;
    if (D >= 2) {
      per_day_connections = per_work_day;
    } else if (D == 0) {
      per_day_connections = (per_work_day + 1) / 2;
    } else if (D == 1) {
      per_day_connections = (per_work_day + 2) / 3;
    }
    total_connections += (long long) (count_D * per_day_connections);
  }
  return total_connections;
}


TDATE endDate(TDATE from, long long connections, unsigned per_work_day, unsigned dow_mask) {
  TDATE invalid_date = {0, 0, 0};
  if (!is_valid_date(from) || connections < 0 || per_work_day == 0 || dow_mask == 0)
    return invalid_date;
  long long connections_for_from_date = countConnections(from, from, per_work_day, dow_mask);
  if (connections_for_from_date > connections)
    return invalid_date;
  long long day_from = date_to_day_number(from);
  long long low = day_from;
  long long high = day_from + connections * 7 + 1;
  long long best_day = day_from;

  while (low <= high) {
    long long mid = low + (high - low) / 2;
    TDATE mid_date;
    day_number_to_date(mid, &mid_date);
    long long total_connections = countConnections(from, mid_date, per_work_day, dow_mask);
    if (total_connections <= connections) {
      best_day = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  TDATE result_date;
  day_number_to_date(best_day, &result_date);
  return result_date;
}



#ifndef __PROGTEST__
int main ()
{
    TDATE res = endDate (makeDate ( 4001, 1, 22 ), 5, 6, DOW_SAT );

    printf("res: %d %d %d\n", res.m_Year, res.m_Month, res.m_Day);
        
    return 0;
}
#endif /* __PROGTEST__ */
