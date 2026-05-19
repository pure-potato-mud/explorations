#include<stdio.h>
#include<stdint.h>
using namespace std;

typedef struct uint128_t {
	uint64_t upper,lower;
};

uint8_t length(uint64_t);
uint16_t length(uint128_t);
uint128_t mutiple(uint128_t,uint32_t);

void printEncode(char*,uint128_t);
void printInBase4(uint128_t);
char Encode(uint8_t);

int main() {
	//宣告 
	uint32_t list[9] = {0};
	uint128_t result = {0x0,0x1};
	printInBase4(result);
	
	//階乘 
	for (uint8_t i=0; i<9; i++) {
		
		list[i]=1;
		if (i>0) list[i] = list[i-1] * (i+1);
		printf("* %X\n= ",list[i]);
		result = mutiple(result,list[i]);
		printInBase4(result);
	}
	printf("\n%016llx_%016llx",result.upper,result.lower);
	
	
	// 印出所有編碼對應 
//	for(uint8_t i=0; i<64; i++) {
//		if (i%8==0) printf("\n");
//		printf("%c ",Encode(i));	
//	}

	printf("\n\n");
	
	// 輸出編碼 
	char String[23]="                      ";
	printEncode(String,result);
	printf("%s\n",String);
	
	// OtZH,Fnv0,0000 --> 所有排列組合 
	
	return 0;
}

uint128_t mutiple(uint128_t input,uint32_t mutiplier) {
	uint64_t split[4] = {input.upper>>32, (uint32_t)input.upper, input.lower>>32, (uint32_t)input.lower};
//	printf("[0x%016X_%016X_%016X_%016X\n",split[0],split[1],split[2],split[3]);
	uint128_t result = {0,0};
	for (uint8_t i=0; i<4; i++) split[i] *= mutiplier;
	result.upper = (split[0]<<32) + split[1] + (split[2]>>32);
	result.lower = (split[2]<<32) + split[3];
//	printf("]\n");
	return result;
}

void printInBase4(uint128_t input){
	uint64_t p = 3; p<<=62;
	for(uint8_t i=0; i<32; i++) {
		printf("%c",((p&input.upper)>>62)+0x30);
		input.upper<<=2;
	}
	for(uint8_t i=0; i<32; i++) {
		printf("%c",((p&input.lower)>>62)+0x30);
		input.lower<<=2;
	}
}


uint8_t length(uint64_t input){
	if (input == 0) return 0;
	uint8_t i=0;
	uint64_t p = 1; p<<=63;
	while (!(input&p)&&i<64) {
		input<<=1; i++;
	}
	return 64-i;
}

uint16_t length(uint128_t input){
	if (input.upper==0) return length(input.lower);
	else return 64+length(input.upper);
}

void printEncode(char* buffer,uint128_t input) {
	for (uint8_t i=0; i<10; i++) {
		buffer[21-i] = Encode(input.lower&0x3F);
		input.lower >>= 6;
	}
	buffer[11] = Encode(input.lower+((input.upper&0x3)<<4));
	input.upper>>=2;
	for (uint8_t i=0; i<10; i++) {
		buffer[10-i] = Encode(input.upper&0x3F);
		input.upper >>= 6;
	}
	buffer[0] = Encode(input.upper);
	uint8_t length = 0;
	for(uint8_t i=0; i<22&&buffer[i]=='0'; i++){
		length = i+1;
		buffer[i] = 0;
	}
//	printf("%u",length);
	for (uint8_t i=0; i<22;i++) {
		if (i>21-length) buffer[i] = 0;
		else buffer[i] = buffer[length+i];
	}
}

char Encode(uint8_t code) {
	//輸出後每6位元轉換成30~6F的ASCIIcode作為ID，按順序如下： 
	/*
	 0~ 9  0~9 10   0x30 ~ 0x39
	10~35  A~Z 26	  0x41 ~ 0x5a
	36~61  a~z 26	  0x61 ~ 0x7a
	62,63  - = 2	  0x2d , 0x3d
	*/ 
	if (code<0x24) {
		if (code<0xa) return 0x30+code;
		else return 0x37+code;
	} else {
		if (code==0x3e) return 0x2d;
		else if (code==0x3f) return 0x3d;
		else return 0x3D+code;
	}
}
