#include "FatFsDateFormat.h"


/** fatfs FILINFO 
	Link: http://www.elm-chan.org/fsw/ff/pf/sfileinfo.html */

#define TIME_DATE_STR_BUF_LEN 	10
#define FAT_FS_YEAR_BASE		1980


/*	fatfs FILINFO fdate
	Indicates the date that the file was modified or the directory was created.
	bit15:9
	Year origin from 1980 (0..127)
	bit8:5
	Month (1..12)
	bit4:0
	Day (1..31)*/
#define FAT_FS_DATE_MASK_YEAR 	0xFE00
#define FAT_FS_DATE_MASK_MONTH  0x01E0
#define FAT_FS_DATE_MASK_DAY	0x001F

#define FAT_FS_DATE_YEAR_OFFSET  9
#define FAT_FS_DATE_MONTH_OFFSET 5
#define FAT_FS_DATE_DAY_OFFSET	 0

#define FAT_FS_YEAR_VAL(Date) (((Date & FAT_FS_DATE_MASK_YEAR)   >> FAT_FS_DATE_YEAR_OFFSET) + FAT_FS_YEAR_BASE)
#define FAT_FS_MONTH_VAL(Date) 	((Date & FAT_FS_DATE_MASK_MONTH) >> FAT_FS_DATE_MONTH_OFFSET)
#define FAT_FS_DAY_VAL(Date) 	((Date & FAT_FS_DATE_MASK_DAY)   >> FAT_FS_DATE_DAY_OFFSET)

/**  fatfs FILINFO ftime
	Indicates the time that the file was modified or the directory was created.
	bit15:11
	Hour (0..23)
	bit10:5
	Minute (0..59)
	bit4:0
	Second / 2 (0..29)*/
#define FAT_FS_TIME_MASK_HOUR 	0xF800
#define FAT_FS_TIME_MASK_MIN 	0x07E0
#define FAT_FS_TIME_MASK_SEC	0x001F

#define FAT_FS_TIME_HOUR_OFFSET  11
#define FAT_FS_TIME_MIN_OFFSET 	 5
#define FAT_FS_TIME_SEC_OFFSET	 0

#define FAT_FS_HOUR_VAL(Time) 	((Time & FAT_FS_TIME_MASK_HOUR) >> FAT_FS_TIME_HOUR_OFFSET)
#define FAT_FS_MIN_VAL(Time) 	((Time & FAT_FS_TIME_MASK_MIN)  >> FAT_FS_TIME_MIN_OFFSET)
#define FAT_FS_SEC_VAL(Time) 	(((Time & FAT_FS_TIME_MASK_SEC)  >> FAT_FS_TIME_SEC_OFFSET) * 2)


void DateFormatToStr(unsigned int Date,char *pDate,unsigned int DateBufLen)
{
	char DateFormat[] = "%04u%02u%02u";
		
	if(NULL == pDate || (DateBufLen < 2))
	{
		return;
	}

	if(0 == Date)
	{
		pDate[0] = '0';
		pDate[1] = '\0';
		return;
	}
	
	unsigned short  Year  =  FAT_FS_YEAR_VAL(Date);
	unsigned short	Month =  FAT_FS_MONTH_VAL(Date);
	unsigned short	Day   =  FAT_FS_DAY_VAL(Date);

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
		
	if(0 == Time)
	{
		pTime[0] = '0';
		pTime[1] = '\0';
		return;
	}
	
	unsigned short  Hour  	=  FAT_FS_HOUR_VAL(Time);
	unsigned short	Minute 	=  FAT_FS_MIN_VAL(Time);
	unsigned short	Second  =  FAT_FS_SEC_VAL(Time);;

	if(TimeBufLen > 6)
	{
		sprintf(pTime,TimeFormat,Hour,Minute,Second);	
	}
}


