/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
#include<malloc.h>
int findSingleOccurenceNumber(int *A, int len) {
	int ind = 0,*arr;
	if (A==nullptr||len<1)
		return -1;
	if (len == 1)
		return A[0];
	arr =(int *)calloc(sizeof(int),255);
	for (ind = 0; ind < len;ind++)
	{
		arr[A[ind]]++;
	}
	for (ind = 0; ind <255; ind++)
	{
		if (arr[ind] == 1)
			return ind;
	}
	return -1;
}