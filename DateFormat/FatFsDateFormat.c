#include "FatFsDateFormat.h"


/** fatfs FILINFO Link: http://www.elm-chan.org/fsw/ff/pf/sfileinfo.html */

#define TIME_DATE_STR_BUF_LEN 10

void DateFormatToStr(unsigned int Date,char *pDate,unsigned int DateBufLen)
{
	char DateFormat[] = "%04u%02u%02u";
		
	if(NULL == pDate || (DateBufLen < 2))
	{
		return;
	}
	
	/*  fatfs FILINFO fdate
		Indicates the date that the file was modified or the directory was created.
		bit15:9
		Year origin from 1980 (0..127)
		bit8:5
		Month (1..12)
		bit4:0
		Day (1..31)*/
	if(0 == Date)
	{
		pDate[0] = '0';
		pDate[1] = '\0';
		return;
	}
	
	unsigned short  Year  =  (Date & 0xFE00) >> 9;
					Year += 1980;
	unsigned short	Month =  (Date & 0x01E0) >> 5;
	unsigned short	Day   =  (Date & 0x001F) >> 0;;

	if(DateBufLen > 8)
	{
		sprintf(pDate,DateFormat,Year,Month,Day);	
	}
}

void TimeFormatToStr(unsigned int Time,char *pTime,unsigned int TimeBufLen)
{
	char TimeFormat[] = "%02u%02u%02u";

	/** buffer size min is 2 */
	if(NULL == pTime || (TimeBufLen < 2))
	{
		return;
	}
		
	/**  fatfs FILINFO ftime
		Indicates the time that the file was modified or the directory was created.
		bit15:11
		Hour (0..23)
		bit10:5
		Minute (0..59)
		bit4:0
		Second / 2 (0..29)*/
	if(0 == Time)
	{
		pTime[0] = '0';
		pTime[1] = '\0';
		return;
	}
	
	unsigned short  Hour  	=  (Time & 0xF800) >> 11;
	unsigned short	Minute 	=  (Time & 0x07E0) >> 5;
	unsigned short	Second  =  (Time & 0x001F) >> 0;;

	if(TimeBufLen > 6)
	{
		sprintf(pTime,TimeFormat,Hour,Minute,Second);	
	}
}


