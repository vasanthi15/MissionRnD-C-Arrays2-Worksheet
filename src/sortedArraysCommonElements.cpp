/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int checkValid(int *date)
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
void calculate(char *dot, int *date)
{
	date[0] = dot[0] * 10 + dot[1] - 528;
	date[1] = dot[3] * 10 + dot[4] - 528;
	date[2] = dot[6] * 1000 + dot[7] * 100 + dot[8] * 10 + dot[9] - 53328;
}
int compar(int gdate[3], int refdate[3])
{
	int i;
	for (i = 2; i >= 0; i--)
	{
		if (gdate[i]!=refdate[i])
			return 0;
	}
	return 1;
}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i = 0, gr,j, ind = 0,*Adate,*Bdate;
	struct transaction *comele;
	if (A==NULL||B==NULL||ALen<1||BLen<1)
	return NULL;
	comele = (struct transaction*)malloc(sizeof(struct transaction)*(ALen>BLen?BLen:ALen));
	Adate = (int *)malloc(sizeof(int)*3);
	Bdate = (int*)malloc(sizeof(int)*3);
	for (i = 0; i < ALen; i++)
	{
		for (j = 0; j < BLen; j++)
		{
			calculate(A[i].date, Adate);
			calculate(B[j].date, Bdate);
			if (!checkValid(Bdate) || !checkValid(Adate))
				continue;
			gr = compar(Bdate, Adate);
			if (gr == 1)
			{
				comele[ind]= A[i];
				ind++;
			}
		}
	}
	free(Bdate);
	free(Adate);
	if (ind == 0)
		return NULL;
	return comele;
}