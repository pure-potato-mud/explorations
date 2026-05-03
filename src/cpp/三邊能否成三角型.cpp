#include <iostream> 
using namespace std;
int main() {
	int x =0, y=0, z=0;
	cout << "put three lengths: ";
	cin >> x >> y >> z;
	cout << "your inputs: " << x << y << z << endl; 
	string result = ((x+y+z > 2*max(x,max(y,z))) ? "can" : "can't");
	cout << "These lengths " << result << " make a triangle." << endl;
}
