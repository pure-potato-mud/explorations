#include<bits/stdc++.h>
using namespace std;
int main() {
	unsigned int a = 0xDFC101D;
	unsigned int b = 0x47D88825;
	unsigned int m = 0xB350E090;
	unsigned int seed = (a*time(NULL)+b)%m;

	while(1) {
//		seed = time(NULL);
//		printf("%16X\t",seed);
		
		seed = (a*seed+b)%m;
		
		
		//雖然可用只有到小數點下 7位但最長可以到小數點下 32位 
		printf("%16X\t",seed);
		printf("%34.32f\t",seed/(float)0xB350E090);
		
		system("pause");
	}
}
