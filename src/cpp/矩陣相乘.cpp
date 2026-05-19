#include<iostream>
#include<iomanip>
#include<stdint.h>
#include"xorShift.hpp"

typedef struct size size;

struct size {
	uint8_t width, height;
};

void Mmult(float* matrixA, size sizeA, float* matrixB, size sizeB);

const uint8_t aHeight = 2, aWidth = 4;
const uint8_t bHeight = 3, bWidth = 2;

int main() {
	RandSeed();
	RandInterger();
	float a[aHeight][aWidth], b[bHeight][bWidth];
	size A = {aWidth,aHeight}, B = {bWidth,bHeight};
	std::cout << "matrix A:" << std::endl;
	for(uint8_t i=0; i<aWidth; i++) {
		for(uint8_t j=0; j<aHeight; j++) {
			uint64_t temp = 1000000000000000000;
			a[j][i] = RandInterger()/temp;
			std::cout << std::setw(8) << a[j][i];
		}
		std::cout << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "matrix B:" << std::endl;
	for(uint8_t i=0; i<bWidth; i++) {
		for(uint8_t j=0; j<bHeight; j++) {
			uint64_t temp = 1000000000000000000;
			b[j][i] = RandInterger()/temp;
			std::cout << std::setw(8) << b[j][i];
		}
		std::cout << std::endl;
	}
	
	std::cout << std::endl;
	Mmult(&a[0][0],A,&b[0][0],B);
}

void Mmult(float* matrixA, size sizeA, float* matrixB, size sizeB) {
	if (sizeA.height == sizeB.width) {
		float temp;
		size resultSize = {sizeA.width,sizeB.height};
		std::cout << "計算結果..." << std::endl;
		for (uint8_t i=0;i<sizeA.width;i++) {
			for (uint8_t j=0;j<sizeB.height;j++) {
				temp = 0;
				for (uint8_t k=0;k<sizeA.height;k++) {
//					std::cout << std::setw(10) << (matrixA+(k*sizeA.width+i));
					temp += *(matrixA+(k*sizeA.width+i)) * *(matrixB+(j*sizeB.width+k));
				}
				std::cout << std::setw(8) << temp;
			}
			std::cout << std::endl;
		}
	} else {
		std::cout << "大小對不上！";
	}
}
