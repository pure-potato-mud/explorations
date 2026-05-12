#include<stdio.h>
#include<stdint.h>
#include<process.h>
using namespace std;


struct xorshift32_state {
		uint32_t a;
};


uint32_t xorshift32(struct xorshift32_state*);

int main() {
	struct xorshift32_state seed = {a:0x00000001};
	
	while(true) {
		
		for(uint8_t i=31; i<32; i--) {
			if (seed.a>>(i)&0x1) printf("█");
			else printf(" ");
//			if(!(i%8)) printf(" ");
		} 
		
		xorshift32(&seed);
		system("pause");
	}
} 

uint32_t xorshift32(struct xorshift32_state *state) {
	uint32_t x = state->a;
	x ^= x<<13; //跟移位後的自己做異或運算 
	x ^= x>>17;
	x ^= x<<5 ;
	return state->a = x;
}	
