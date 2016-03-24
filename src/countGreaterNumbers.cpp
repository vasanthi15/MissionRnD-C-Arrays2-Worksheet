/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<malloc.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
void calc(char *dot, int *date)
{
	date[0] = dot[0] * 10 + dot[1]-528;
	date[1] = dot[3] * 10 + dot[4]-528;
	date[2] = dot[6] * 1000 + dot[7] * 100 + dot[8] * 10 + dot[9]-53328;
}
int chckValid(int *date)
{
	if (date[2]>9999 || date[1]>12 || date[0]>31)
		return 0;
	if (date[1] == 2)
	{
		if (date[2] % 4 == 0 && date[0] > 29)
			return 0;
		else if (date[2] > 28)
			return 0;
	}
	else
	{
		if (date[1] % 2 == 0 && date[0] > 30)
			return 0;
	}

	return 1;
}
int compare(int *gdate, int *refdate)
{
	int i;
	for (i = 2; i >= 0; i--)
	{
		if (gdate[i] > refdate[i])
			return 1;
		else if (gdate[i] < refdate[i])
			return 0;
	}
	return 0;
}
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i = 0, gr=0, gdate[3],refdate[3];
	if (Arr == nullptr||date==nullptr)
		return -1;
	calc(date,refdate);
	if (!chckValid(refdate))
			return -1;
	for (i = 0; i < len; i++)
	{
		calc(Arr[i].date, gdate);
		if (!chckValid(gdate))
			continue;
		gr+=compare(gdate, refdate);
	}
	return gr;
}
