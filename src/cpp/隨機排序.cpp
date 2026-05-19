#include<stdio.h>
#include"xorShift.h"
#include<process.h>
using namespace std;

void printList(uint8_t*);
void swap(uint8_t&,uint8_t&);

int main() {
	RandSeed();
	uint8_t data[9] = {0};
	for (uint8_t i=0; i<9; i++) data[i]=i+1;
	printList(data);
	for (uint8_t i=0; i<9; i++) {
		uint8_t random = RandFloat()*(8-i)+i;
		swap(data[i],data[random]);
		printList(data);
	}
}

void printList(uint8_t* list){
	for (uint8_t i=0; i<9; i++) {
		printf("%d ",list[i]);
	}
	printf("\n");
}

void swap(uint8_t& first,uint8_t& last) {
	uint8_t temp = first;
	first = last;
	last = temp;
}
