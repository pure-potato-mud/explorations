#include<stdio.h>
#include<stdint.h>
#include<process.h>
#include"xorShift.h"
using namespace std;

static uint8_t data[9][9] = {0};

void printView(void);
bool check(uint8_t,uint8_t,uint8_t=0);
void swap(uint8_t&,uint8_t&);

int main() {
	extern uint8_t data[9][9];
	RandSeed();
	uint8_t temp=0;
	uint8_t load=0;
	uint8_t failTimes = 0;

	for (uint8_t i=0;i<9;i++) {
		if (i==0) {
			for (uint8_t j=0; j<9; j++) {
				uint8_t rand = RandFloat()*(9-j)+j;
				if (data[0][rand] == 0) data[0][rand] = rand+1;
				if (data[0][j] == 0) data[0][j] = j+1;
				swap(data[0][j],data[0][rand]);
			}
			continue;
		}
		for (uint8_t j=0;j<9;j++) {
//			system("cls");
			uint8_t remove[9] = {0},left = 9, temp=0, rand=0;
			uint8_t lost = 0;
			for (uint8_t k=0; k<j; k++) {
				remove[data[i][k]-1] = data[i][k];
//					printf("-%c",data[i][k]+0x30);
				left-=1;
			}
			for (uint8_t k=0; k<i; k++) {
				if (remove[data[k][j]-1]==0) {
					remove[data[k][j]-1] = data[k][j];
//					printf("|%c",data[k][j]+0x30);
					left-=1;
				}
			}
			uint8_t x=i%3,y=j%3+1;
			uint8_t X=i/3,Y=j/3;
			for (uint8_t k=0; k<3*x+y; k++) {
				temp = data[X*3+k/3][Y*3+k%3];
				if (temp == 0) break;
				if (remove[temp-1]==0) {
					remove[temp-1] = temp;
//					printf("@%c",temp+0x30);
					left-=1;
				}
			}
//			printf("\n");
			uint8_t randomList[left] = {};
			left = 0;
			for (uint8_t k=0;k<9;k++) {
//				printf("%u.",remove[k]+0x30);
				if(remove[k]==0) {
					randomList[left] = k+1;
//					printf("%u ",randomList[left]);
					left+=1;
				}
			}
			if(left == 0) {
				if (failTimes == 0xff) {
					printf("generation failed...\n");
					printView();
					return 0;
				}
				j=0xff;
				failTimes+=1;
				for (uint8_t k=0;k<9;k++){
					data[i][k] = 0;
				}
				continue;
			} else {
				rand = RandFloat()*left;
//				printf(":%u,%u",left,rand);
				data[i][j] = randomList[rand];
			}
//			printf("\n\n");
//			printView();
//			system("pause");
		}
	}
	printf("row fail times: %u\n",failTimes);
	printView();
}

void printView(void){
	extern uint8_t data[9][9];
	uint8_t temp[2][9] = {0};
	for (uint8_t i=0; i<10; i++) {
		if (i<9) {
			for (uint8_t j=0; j<9; j++) {
				temp[1][i] += data[i][j];
				temp[0][j] += data[i][j];
				printf("%c  ",data[i][j]+0x30);
			}
			printf(" %-2u\n",temp[1][i]);
		} else {
			for (uint8_t j=0; j<9; j++) printf("%-2u ",temp[0][j]);
			printf("\n");
		}
	}
} 

bool check(uint8_t x,uint8_t y,uint8_t value){
	extern uint8_t data[9][9];
	if (value==0) value = data[x][y];
//	for (uint8_t i=0; i<9; i++) if (data[x][i]==value) return 0;
	for (uint8_t i=0; i<9; i++) if (data[i][y]==value) return 0;
//	for (uint8_t i=0; i<9; i++) if (data[y/3+i/3][x/3+i%3]==value) return 0;
	return 1;
}

void swap(uint8_t& first,uint8_t& last) {
	uint8_t temp = first;
	first = last;
	last = temp;
}

