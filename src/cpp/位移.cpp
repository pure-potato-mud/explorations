#include<stdio.h>
using namespace std;

int main() {
	unsigned int a=0x10;
	printf("%x, %x, %x, %x",a<<1,a<<-1,a>>1,a>>-1);
}
