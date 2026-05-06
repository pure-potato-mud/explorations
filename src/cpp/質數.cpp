#include<stdio.h>
#include<math.h>
using namespace std;

int main() {
	int input = 1001;
	while (1) {
		input+=2
		// 簡單判定：如果輸入的整數數小於2，
		// 則印出提示文字，讓使用者重新輸入。 
		if(input<=1) {
			printf("輸入與條件不相符，請重試：");
			continue;
		}
		
		// 用for測試該數字能否被自己與1以外的數整除
		// 將這些結果以and串接，只要有能被整除的數字出現就會變成0 
		bool test = 1;
		for (int i = 2; i < sqrt(input); i++){
			test&=(bool)(input%i);
		}
		
		// 依據上方的判斷結果顯示對應文字 
		if (test) {
			printf("這個數是質數\n");
		} else {
			printf("這個數不是質數\n");
		}
		system("pause");
	}
}
