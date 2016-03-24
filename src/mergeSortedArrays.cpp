/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int comp(int *date1, int *date2)
{
	int i;
	for (i = 2; i >= 0; i--)
	{
		if (date1[i] < date2[i])
			return 1;
		else if (date1[i] > date2[i])
			return -1;
	}
	return 0;
}
int chkValid(int date[3])
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
void calcDate(char *dot, int *date)
{
	date[0] = dot[0] * 10 + dot[1] - 528;
	date[1] = dot[3] * 10 + dot[4] - 528;
	date[2] = dot[6] * 1000 + dot[7] * 100 + dot[8] * 10 + dot[9] - 53328;
}
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	struct transaction *mer;
	int ind = 0, j = 0, i = 0,k=0,*date1,*date2;
	if (A==NULL||B==NULL||ALen<1||BLen<1)
	return NULL;
	mer = (struct transaction*)malloc(sizeof(struct transaction)*(ALen+BLen));
	date1 = (int *)malloc(sizeof(int) * 3);
	date2 = (int*)malloc(sizeof(int) * 3);
	while((i < ALen)&&(j < BLen))
	{
			calcDate(A[i].date, date1);
			if (chkValid(date1)==0)
			{
				i++;
				continue;
			}
			calcDate(B[j].date, date2);
			if (chkValid(date2)==0)
			{
				j++;
				continue;
			}
			k = comp(date1, date2);
			if (k>=0)
			{
				mer[ind] = A[i];
				ind++;
				i++;
			}
			else if (k<0)
			{
				mer[ind] = B[j];
				ind++;
				j++;
			}

	}
	free(date1);
	free(date2);
	while (j<BLen)
	{
		mer[ind] = B[j];
		ind++;
		j++;
	}
	while (i<ALen)
	{
		mer[ind] = A[i];
		ind++;
		i++;
	}
	return mer;
}