#include <bits/stdc++.h>
using namespace std;
int main() {
	int max = 0,min = 0;
	
	
	printf("請輸入質數的尋找範圍，以半形逗號隔開：");
	scanf("%d,%d",&min,&max);
	if (min > max) { // 用xor的特性交換數字 
		max ^= min;
		min ^= max;
		max ^= min;
	}
	
	
	printf("您輸入的範圍：%d~%d\n",min,max);
	min += !(min%2), max -= !(max%2);
	printf("實際執行的範圍：%d~%d\n",min,max);
	
	bool result;
	for (int i = min;i<=max;i+=2){
		result = 1;
		for (int j = 2; j <= sqrt(i); j++) {
			result &= (bool)(i%j);
		}
		if (result) printf("%10d\n",i);
	}
}
