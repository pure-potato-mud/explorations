#include<stdio.h>

int main() {
	unsigned char i=0;
	printf("\e[48;2;0;0;0m\e[38;2;255;255;255m");
	for (i=0x20; i<0x7f; i++) {
		printf("\e[7m");
		if (i!=0x20) printf(" ");
		if (i%0x10==0) printf("\n%33s\n "," ");
		printf("\e[27m%c",i);
	}
	printf("\e[7m   \n%33s\n"," ");
}
