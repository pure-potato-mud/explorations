#include<stdio.h>
using namespace std;

int main() {
	unsigned short count=0,area=0;
	for(unsigned short i=0xa4; i<=0xc6; i++) {
		printf("%c%c ",i,0x5c);
		
//		unsigned char upper = (i&0xff00)>>8, lower = i&0xff;
		
//		if(lower%0x10==0) printf("%X ",i>>4);
//		if((lower>=0x40&&lower<=0x7e)||(lower>=0xa1&&lower<=0xfe)) {
//			printf("%c%c",upper,lower);
//			++count;
////			if (lower == '\\') printf("\\");
//		} else {
//			printf("　");
//		}
////		printf("%x",lower%0x20);
//		switch (lower%0x20) {
//			case 0xf: {
//				printf("%8s",""); break;
//			}
//			case 0x1f: {
//				printf("\n"); break;
//			}
//			default: {
//				printf(" "); break;
//			}
//		}
//		area = i-0xa43f;
	}
	printf("\n\n以上可用漢字總計%u個,空白區域有%u個",count,area-count);
}
