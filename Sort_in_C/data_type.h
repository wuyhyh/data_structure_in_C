#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

typedef int elemtype;

void swap(elemtype* a, elemtype* b)
{
	elemtype temp = *a;
	*a = *b;
	*b = temp;
}
