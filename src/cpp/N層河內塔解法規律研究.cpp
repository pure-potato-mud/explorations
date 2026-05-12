#include<stdio.h>
using namespace std;
void findSolStep(unsigned int,unsigned int ,unsigned char);
int main() {
	int reply = 0;
	printf("請輸入需要解開的層數：");
	scanf("%d",&reply);
	
//	int count = 0;
	for(unsigned int i =1; i<(0x1<<reply);i++) {
		findSolStep(reply,i,3);
		printf("%c",((i)%8)? ' ':'\n');
	}
//	old_findSol(reply,count);
	return 0;
} 

//數字順序的部分，可以由i^(i-1)，並取得唯一的1所在位置而得
//或者說可以從前面的數字的低位數上來的第一個零所在位置 
//字母還沒研究出來 

void findSolStep(unsigned int layer,unsigned int stepIndex,unsigned char targetPillar) {
	unsigned int p = 0x1;
	unsigned int diskIndex = 0;
	int pillarPos = 2;
	for (;~stepIndex bitand (p<<diskIndex);diskIndex++);
	printf("%u.",diskIndex+1);
	for(unsigned int i=diskIndex+1;i<layer;i++) {
		if(~stepIndex bitand (p<<i))
			pillarPos += ((layer-i)%2)? -1 : 1;
			while(pillarPos<0) pillarPos+=3;
			while (pillarPos>2) pillarPos-=3;
	}
	printf("%c",pillarPos+0x41);
	
}

