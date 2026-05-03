#include <bits/stdc++.h>
using namespace std;

int main() {
	char gird[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
	char pos[2]={0,0}; 
	bool Gaming = 1; 
	bool turn = 0; 
	char nowSymbol = ' ';
	char winner = 0; 
	
	// game content 
	for (int i = 0; (i<9 ^ (bool)winner); i+=1) {
		
		nowSymbol =  (turn? 'X' : 'O'); 
		printf("Now it's %c's turn!\n",nowSymbol); 
		
		// get input 
		while (true) { 
		
			cout << "put a posision to place the symbol: ";
			cin >> pos[0] >> pos[1]; 
//			if (pos[0] == 'x' && pos[1] == 't') break; //exit game
			
			// test for position 
			if (pos[0] < 0x33 && pos[0] > 0x2f && pos[1] < 0x33 && pos[1] > 0x2f) {	
				
				// test if gird is empty 
				if (gird[pos[0]-0x30][pos[1]-0x30] == ' ') {
					cout << "Success: position test passed." << endl;
					break; 
				} else { 
					cout << "Error: this position has been placed, please input position again."<<endl; 
				} 
				
			} else {
				cout << "Error: your inputs " << pos[0] << " or " << pos[1] << " were invaided, please input position again." << endl; 
			}
			
		}
//		if (pos[0] == 'x' && pos[1] == 't') break; //exit game 
		
		gird[pos[0]-0x30][pos[1]-0x30] = nowSymbol;
		turn = !turn; 
		
		// reflesh display 
		for (int j = 0; j<4; ++j) {
			if (j == 0) {
				printf("y/x| 0 | 1 | 2 \n---|---|---|---\n");
			} else {
				printf(" %d | %c | %c | %c \n",(j-1),gird[0][j-1],gird[1][j-1],gird[2][j-1]);
				if (j<3) cout << "---|---|---|---" << endl;
			}
		}
		
		// test if someone win
		for (int j = 0; j<3; j++) {
			// vertictal and horizontal 
			if ( (gird[j][0]+gird[j][1]+gird[j][2])/3 == nowSymbol || (gird[0][j]+gird[1][j]+gird[2][j])/3 == nowSymbol) {
				winner = turn + 1; 
			} 
		}
		//diagonal
		if ( (gird[0][0]+gird[1][1]+gird[2][2])/3 == nowSymbol || (gird[2][0]+gird[1][1]+gird[0][2])/3 == nowSymbol ) {
			winner = turn+1; 
		}
	
	}
	
	if (winner) {
		cout<< "the winner is " << nowSymbol << "!" << endl; 
	} else {
		cout << "Draw..." << endl; 
	}
}
