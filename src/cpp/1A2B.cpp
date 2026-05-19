#include <stdio.h>
#include "XorShift.h" 
using namespace std;

unsigned short valueToHex(unsigned short);

int main() {
	RandSeed();
	unsigned short Ans = 10000*RandFloat();
	unsigned short Guess = 0;
	printf("%04u,%04X\n",Ans,valueToHex(Ans));
	
	printf("歡迎使用1A2B C++低配版\n");
	printf("請輸入一個小於一萬的數以開始遊戲: ");
	unsigned char currentChar;
	while( (currentChar=getchar()) != '\n' ) {
		if (currentChar>0x2f && currentChar<0x3a) {
			Guess<<=4;
			Guess+=currentChar-0x30;
		} else {
			printf("輸入有誤，請重試！");
			continue;
		}
	}
	printf("您輸入的數：%X",Guess);
}

unsigned short valueToHex(unsigned short value) {
	unsigned short result = 0;
	for (unsigned char i = 0; i<4; i++) {
		result += (value%10)<<(4*i);
		value/=10;
	}
	return result;
}
