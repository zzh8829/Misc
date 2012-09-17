  
#include "stdio.h"        /* Required for MS-DOS use */ 
#define ENTER   0x1C0D  /* Enter key */ 
int year, month, day; 
static char *days[8] = {"         ","Sunday   ","Monday      ","Tuesday  ", 
                        "Wednesday","Thursday ","Friday   ","Saturday "}; 
struct TIMEDATE { 
        int year;       /* year 1980..2099              */ 
        int month;      /* month 1=Jan 2=Feb, etc.      */ 
        int day;        /* day of month 0..31           */ 
        int hours;      /* hour 0..23                   */ 
        int minutes;    /* minute 0..59                 */ 
        int seconds;    /* second 0..59                 */ 
        int hsecs;      /* 1/100ths of second 0..99     */ 
        char dateline[47];      /* date & time together */ 
        }; 
static struct TIMEDATE today; 
main() 
 { 
  char cmonth[3]; 
  char cday[3]; 
  char cyear[5]; 
  double getdays(); 
  double daynumb, numbnow; 
  int weekday, retcode, dayer, i; 
  dayer = datetime(&today); 
  clrscn(); 
  for (i=0;i<3;++i)cmonth[i]='\0'; 
  for (i=0;i<3;++i)cday[i]='\0'; 
  for (i=0;i<5;++i)cyear[i]='\0'; 
  putstr(5,8,14,"Enter date in MM DD YYYY format:"); 
  while (retcode != ENTER) 
    { 
     retcode = bufinp(5,41,13,2,cmonth); 
     if (retcode != ENTER) retcode = bufinp(5,44,13,2,cday); 
     if (retcode != ENTER) retcode = bufinp(5,47,13,4,cyear); 
    } 
  year = atoi(&cyear); 
  month = atoi(&cmonth); 
  day = atoi(&cday); 
  daynumb = getdays(year, month, day); 
  numbnow = getdays(today.year, today.month, today.day); 
  weekday = weekdays(daynumb); 
  if (numbnow - daynumb == 0) 
      printf("\n\n%02d-%02d-%d is",month, day, year); 
  if (numbnow - daynumb > 0) 
      printf("\n\n%02d-%02d-%d was",month, day, year); 
  if (numbnow - daynumb < 0) 
      printf("\n\n%02d-%02d-%d will be",month, day, year); 
  printf(" a %s\n",days[weekday]); 
 }  /* end MAIN */ 
/************************************************************ 
 * GETDAYS  - From integer values of year (YYYY), month     * 
 *            (MM) and day (DD) this subroutine returns a   * 
 *            double float number which represents the      * 
 *            number of days since Jan 1, 1980 (day 1).     * 
 *            This routine is the opposite of GETDATE.      * 
 ************************************************************/ 
 double getdays(year, month, day) 
  int year, month, day; 
  { 
   int y,m; 
   double a,b,d, daynumb; 
   double floor(),intg(); 
   /********************************** 
   ** make correction for no year 0 ** 
   **********************************/ 
   if (year < 0) y = year + 1; 
     else y = year; 
   /********************************************************* 
   ** Jan and Feb are months 13 and 14 in this calculation ** 
   *********************************************************/ 
   m = month; 
   if (month < 3) 
     { 
       m = m + 12; 
       y = y - 1; 
     } 
   /************************** 
   ** calculate Julian days ** 
   **************************/ 
   d = floor(365.25 * y) + intg(30.6001 * (m + 1)) + day - 723244.0; 
   /********************************************** 
   ** use Julian calendar if before Oct 5, 1582 ** 
   **********************************************/ 
   if (d < -145068.0) daynumb = d; 
   /************************************* 
   ** otherwise use Gregorian calendar ** 
   *************************************/ 
     else 
       { 
        a = floor(y / 100.0); 
        b = 2 - a + floor(a / 4.0); 
        daynumb = d + b; 
       } 
   return(daynumb); 
   } /* end GETDAYS */ 
/******************************************************** 
 * GETDATE - This routine takes a double float number   * 
 *          representing the number of days since Jan 1,* 
 *          1980 (day 1) and returns the year month and * 
 *          day as pointer integers                     * 
 *          This routine is the opposite of GETDAYS     * 
 ********************************************************/ 
 getdate(numb) 
   double numb; 
   { 
    double a,aa,b,c,d,e,z; 
    double date; 
  
    date = numb; 
    z = intg(date + 2444239.0); 
    if (date < -145078.0) a = z; 
      else 
        { 
         aa = floor((z - 1867216.25) / 36524.25); 
         a = z + 1 + aa - floor(aa/4.0); 
        } 
    b = a + 1524.0; 
    c = intg((b - 122.1) / 365.25); 
    d = intg(365.25 * c); 
    e = intg((b - d) / 30.6001); 
   day = b - d - intg(30.6001 * e); 
   if (e > 13.5) month = e - 13.0; 
     else month = e - 1.0; 
   if (month > 2) year = c - 4716.0; 
     else year = c - 4715.0; 
   if (year < 1) --year; 
    return; 
   } /* end GETDATE */ 
/******************************************************** 
 * WEEKDAYS - This routine takes a double float number  * 
 *          representing the number of days since Jan 1,* 
 *          1980 (day 1) and returns the day of the week* 
 *          where 1 = Sunday, 2 = Tuesday, etc.         * 
 ********************************************************/ 
 int weekdays(numb) 
   double numb; 
   { 
    double dd; 
    int day; 
  
    dd = numb; 
    while (dd > 28000.0) dd = dd - 28000.0; 
    while (dd < 0) dd = dd + 28000.0; 
    day = dd; 
    day = ((day + 1) % 7) + 1; 
    return(day); 
   } 
/******************************************************** 
 * FRACT -  This routine takes a double float number    * 
 *          and returns the fractional part as a double * 
 *          float number                                * 
 ********************************************************/ 
 double fract(numb) 
   double numb; 
   { 
    int inumb; 
    double fnumb; 
  
    while (numb < -32767) numb += 32767; 
    while (numb > 32767) numb -= 32767; 
    inumb = numb; 
    fnumb = inumb; 
    return(numb-fnumb); 
   } /* end FRACT */ 
/******************************************************** 
 * FLOOR -  This routine takes a double float number    * 
 *          and returns the next smallest integer       * 
 ********************************************************/ 
 double floor(numb) 
   double numb; 
   { 

    double fract(), intg(); 
    double out; 
    out = intg(numb); 
    if (numb < 0 && fract(numb) != 0) out -= 1.0; 
    return(out); 
   } /* end FLOOR */ 
/******************************************************** 
 * INTG  -  This routine takes a double float number    * 
 *          and returns the integer part as a double    * 
 *          float number                                * 
 ********************************************************/ 
 double intg(numb) 
   double numb; 
   { 
    double fract(); 
    return(numb - fract(numb)); 
   } /* end INTG */ 
  
  
