/* Check whether a particular date(dd-mm-yyyy format) is valid in 
the range 21-05-1969 to 05-06-2014 */

#include <stdio.h>

void main()
{
	int date, month, year, valid = 1;
	printf("Enter date in dd-mm-ff format\n");
	scanf("%d-%d-%d", &date, &month, &year);

	if( year < 1986 || year > 2008 || date < 1 || date > 31 || month < 1 || month > 12 )
		valid = 0;
	else
	{
		if(year == 1986 && (month < 6 || (month == 6 && date < 21))) valid = 0;
		if(year == 2008 && (month > 2 || (month == 2 && date > 5))) valid = 0;
		if((month == 4 || month == 6 || month == 9 || month == 11) && date == 31) valid = 0;
		if(month == 2)
		{
			if(((year % 4) == 0) && date > 29) valid = 0;
			else if(((year % 4) != 0) && date > 28) valid = 0;
		}
	}

	if(valid) printf("Date is valid\n");
	else printf("Date is not valid\n");
}
