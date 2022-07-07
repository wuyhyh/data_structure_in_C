#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

#include"data_type.h"
#include"primary_sort.h"
#include"shell_sort.h"
#include"heap_sort.h"
#include"quick_sort.h"
#include"merge_sort.h"
#include"radix_sort.h"

int main()
{
	int jrr[10] = { 0,1,512,343,64,125,216,27,8,729 };
	for (int i = 0; i < 10; i++)
		printf("%d ", jrr[i]);
	printf("\n\n");

	LSD_radix_sort(jrr, 10);

	for (int i = 0; i < 10; i++)
		printf("%d ", jrr[i]);
	printf("\n\n");

	return 0;
}