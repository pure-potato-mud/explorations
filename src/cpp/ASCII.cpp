#include<stdio.h>
using namespace std;
int main() {
	for (unsigned char i=0x20; i<=0x80; i++) printf("%c%c",i,(i%0x10==0xf)?'\n':' ');
}
