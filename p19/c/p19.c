#include <stdio.h>

#define STR(x) #x

enum {
    MON = 0,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN,
    DAYS_IN_WEEK
};

const char * weekday_names[] = {
    STR(MON),
    STR(TUE),
    STR(WED),
    STR(THU),
    STR(FRI),
    STR(SAT),
    STR(SUN)
};

enum {
    JAN = 0,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
};

int days_in_month[] = {
    31, /* JAN */
    28, /* FEB */
    31, /* MAR */
    30, /* APR */
    31, /* MAY */
    30, /* JUN */
    31, /* JUL */
    31, /* AUG */
    30, /* SEP */
    31, /* OCT */
    30, /* NOV */
    31  /* DEC */
};

/* A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400. */
static int
is_leap(int year) {
    return (year % 4 == 0) && (!(year % 100 == 0) || (year % 400 == 0));
}

/* How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)? */
int main()
{
    int weekday = MON; /* 1 Jan 1900 was a Monday. */
    int year;
    int answer = 0;
    for (year = 1900; year < 2001; year++) {
        int m;
        for (m = JAN; m <= DEC; m++) {
            if (year >= 1901 && weekday == SUN)
                answer++;
            int m_days = (m == FEB && is_leap(year)) ? 29 : days_in_month[m];
            weekday = (weekday + m_days) % DAYS_IN_WEEK;
        }
    }
    printf("%d\n", answer);

    return 0;
}
