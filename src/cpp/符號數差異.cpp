#include<stdio.h>
using namespace std;

int main() {
	char a;
	unsigned char ua;
	for (int i=0; i<0x100; i++) {
		a++; ua++;
		printf("%4hhd,%4hhu ",a,ua);
		if (i%0x8==0x7) printf("\n");
		// 0x1000 0000
	}
}
