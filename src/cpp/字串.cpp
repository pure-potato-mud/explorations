// 可用輸入： 你好!這些總共30.5￡~ 冇手續費! 

#include<stdio.h>
#include<windows.h>
using namespace std;

bool judge(unsigned char*);
void printBin(unsigned long long , unsigned short = 32,bool = true);
unsigned short charToShort(unsigned char, unsigned char);
void shortToChar(unsigned short,unsigned char&, unsigned char&);
void printString(unsigned char* ,unsigned short );

int main() {
	/* 宣告 */ 
	unsigned char input[32] = {};
	unsigned char output[32] = {};
	unsigned long long Type = 0;
	unsigned short stringLength = 0;
	bool Direction = 0;
	unsigned short inputWchar = 0;
	unsigned short outputWchar = 0;
	unsigned short distance = 0;
	/* 輸入 */
	printf("請輸入至多31位元組的句子(ASCII算1位元組，其餘以2計)：");
	scanf("%31[^\t\n]",input);
	
	/* 取得字串長度 */ 
	for (int i = 0; i<sizeof(input); i++) {
		if(input[i] != 0x00) stringLength+=1;
		else break;
	}
//	printf("%d\n",stringLength); //For debug
	
	/* 判斷字元類型--是big5還是ASCII? */
	for (unsigned char i = 0; i < 0x1e; i++) {
		Type >>= 1;
		if (!(Type >> 28)) Type += (judge(&input[i])<<29); 
//		printBin(Type); // For debug
	}
	printf("\n\n");
//	printBin(Type); printf("%x",Type); // For debug
	/* 輸出前確認 */ 
	printf("您的輸入字串為「%s」，請於準備好後",input);
	system("pause");
	
	/* 這次主要想做的東西--沒什麼意義但很酷的文字效果 */
	system("cls");
	
	for (int i = 0; i < stringLength; i++) {
		bool nowBit = (Type bitand (1<<i)), lastBit = Type bitand (1<<(i>0?i-1:0));
//		printf("nowbit(%d) : %d, lastbit(%d) : %d\n",i,(bool)(Type&(1<<i)),(i-1>0?i-1:0),(bool)(Type&(1<<(i-1>0?i-1:0))));
		if(i>0 && lastBit) continue; //這裡沒有寫好 條件是如果上一個位元是1就跳過 減少漢字迴圈次數
		/* 具體的亂碼不知道怎麼決定
		/ 應該會用逼近法(牛頓?)讓字在規定範圍內跳躍並收斂到目標 */

		if (nowBit) {
			/*
			- 定義域 -
			高位範圍 0x81~0xfE
			低位範圍 0x40~0x7E,	0xA1 ~ 0xFE 
			
			- 有字的範圍 - 
			0xA140	到	0xA3BF	中間值	0xA26E或 0xA26F
			0xA440	到	0xC67E	中間值	0xB55F
			0xC940	到	0xF9DC	中間值	0xE17D
			*/
			
			//  0xA440	到	0xC67E	中間值	0xB55F
			inputWchar = charToShort(input[i],input[i+1]);
			if(inputWchar >= 0xa140 && inputWchar<=0xa3bf) {  //0xA140	到	0xA3BF	中間值	0xA26E或 0xA26F
				outputWchar = 0xa26e;
				Direction = inputWchar > 0xa26e;
				
				shortToChar(outputWchar,output[i],output[i+1]);
				printf("%s\n",output);
				Sleep(1); // 延遲 
				while (outputWchar != inputWchar) {
					distance = ((int)inputWchar-outputWchar)*(Direction? 1: -1);
					if (distance > 0xff) outputWchar += 0x100*((Direction)? 1: -1);
					else if (distance > 0xf) outputWchar += 0x10*((Direction)? 1: -1);
					else outputWchar += (Direction)? 1: -1;
					
					shortToChar(outputWchar,output[i],output[i+1]);
					if( output[i+1] > 0x7e && output[i+1] < 0xa1) {
						outputWchar += ((Direction)?0xa1:0x7e)-(short)output[i+1];
						shortToChar(outputWchar,output[i],output[i+1]);
					} else if( output[i+1] < 0x40 ) {
						outputWchar += ((Direction)?0x40:-2)-(short)output[i+1];
						shortToChar(outputWchar,output[i],output[i+1]);
					} else if( output[i+1] > 0xfe ) {
						outputWchar += ((Direction)?0x140:0xfe)-(short)output[i+1];
						shortToChar(outputWchar,output[i],output[i+1]);
					}
					
					//印出 
					printf("%s\n",output);
					Sleep(1); // 延遲 1ms
				}
			} else if (inputWchar >= 0xa440 && inputWchar<=0xc67e) { //0xA440	到	0xC67E	中間值	0xB55F
				outputWchar = 0xb55f;
				Direction = inputWchar > 0xb55f;
				
				shortToChar(outputWchar,output[i],output[i+1]);
				printf("%s\n",output);
				Sleep(1); // 延遲 
				while (outputWchar != inputWchar) {
					distance = ((int)inputWchar-outputWchar)*(Direction? 1: -1);
					if (distance > 0xff) outputWchar += 0x100*((Direction)? 1: -1);
					else if (distance > 0xf) outputWchar += 0x10*((Direction)? 1: -1);
					else outputWchar += (Direction)? 1: -1;
					
					shortToChar(outputWchar,output[i],output[i+1]);
					if( output[i+1] > 0x7e && output[i+1] < 0xa1) {
						outputWchar += ((Direction)?0xa1:0x7e)-(short)output[i+1];
						shortToChar(outputWchar,output[i],output[i+1]);
					} else if( output[i+1] < 0x40 ) {
						outputWchar += ((Direction)?0x40:-2)-(short)output[i+1];
						shortToChar(outputWchar,output[i],output[i+1]);
					} else if( output[i+1] > 0xfe ) {
						outputWchar += ((Direction)?0x140:0xfe)-(short)output[i+1];
						shortToChar(outputWchar,output[i],output[i+1]);
					}
					
					//印出 
					printf("%s\n",output);
					Sleep(1); // 延遲 1ms
				}
			}  else if (inputWchar >= 0xc940 && inputWchar<=0xf9dc) { //0xC940	到	0xF9DC	中間值	0xE17D
				outputWchar = 0xe17d;
				Direction = inputWchar > 0xe17d;
				
				shortToChar(outputWchar,output[i],output[i+1]);
				printf("%s\n",output);
				Sleep(1); // 延遲 
				while (outputWchar != inputWchar) {
					distance = ((int)inputWchar-outputWchar)*(Direction? 1: -1);
					if (distance > 0xff) outputWchar += 0x100*((Direction)? 1: -1);
					else if (distance > 0xf) outputWchar += 0x10*((Direction)? 1: -1);
					else outputWchar += (Direction)? 1: -1;
					
					shortToChar(outputWchar,output[i],output[i+1]);
					if( output[i+1] > 0x7e && output[i+1] < 0xa1) {
						outputWchar += ((Direction)?0xa1:0x7e)-(short)output[i+1];
						shortToChar(outputWchar,output[i],output[i+1]);
					} else if( output[i+1] < 0x40 ) {
						outputWchar += ((Direction)?0x40:-2)-(short)output[i+1];
						shortToChar(outputWchar,output[i],output[i+1]);
					} else if( output[i+1] > 0xfe ) {
						outputWchar += ((Direction)?0x140:0xfe)-(short)output[i+1];
						shortToChar(outputWchar,output[i],output[i+1]);
					}
					
					//印出 
					printf("%s\n",output);
					Sleep(1); // 延遲 1ms
				}
			}
			
		} else {
			output[i] = 0x4f;
			Direction = input[i] > 0x4f;
			
			printf("%s\n",output);
			Sleep(1); // 延遲  
			while (output[i] != input[i]) {
				output[i] += (Direction)? 1: -1;
					
				//印出 
				printf("%s\n",output);
				Sleep(1); // 延遲 1ms
			}
		}
	}
	
//	system("pause");
	
	return 0;
}

//粗略判斷是否在大五碼定義範圍內
bool judge(unsigned char* c ) {  
//	printf("%2x,%2x : ",*c,*(c+1)); //For debug 
	return ((  *c   >= 0x81 &&   *c   <= 0xFE)
	     &&((*(c+1) >= 0x40 && *(c+1) <= 0x7E)
		 ||(*(c+1) >= 0xA1 && *(c+1) <= 0xFE)));
}

// 將數字轉為二進位並印出 
void printBin(unsigned long long input, unsigned short length,bool newline) { 
	for (int i = (length-1); i >= 0 ; i--) {
		printf("%c",(input bitand ((unsigned long long)1<<i))? '1':'0');
		if (i%8==0) printf(" ");
	}
	if(newline) printf("\n");
}

unsigned short charToShort(unsigned char upper, unsigned char lower) {
	return ((unsigned short)upper << 8) + (unsigned short)lower;
}

void shortToChar(unsigned short ShortNumber,unsigned char& upper, unsigned char& lower) {
	upper = (unsigned char)((ShortNumber>>8) & 0xff);
	lower = (unsigned char)(ShortNumber & 0xff); 
}

void printString(unsigned char* firstElement ,unsigned short length ) {
	for (int i = 0; i < length; i++) {
		printf("%c",*(firstElement+i));
	}
	printf("\n");
}
