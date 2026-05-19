#include<stdio.h>

int main() {
	int a = 10;
	int *iPtr = &a;
	unsigned long long iPtru = (unsigned long long)iPtr;
	printf("%p\n%016llX\n%p",iPtr,iPtru,*(int*)iPtru);
}
