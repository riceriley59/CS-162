#include <iostream>

using namespace std;

void pattern(int n, int col){
	if(n < 1){
		return ;
	}

	pattern(n / 2, col);
	for(int i = 0; i < col; i++) cout << "  ";
	for(int i = 0; i < n; i++) cout << "* ";
	cout << endl;
	pattern(n / 2, col + n / 2);
}

int main(){
	cout << "This is pattern(2, 2): \n";
	pattern(2, 2);
	cout << "\n\n";

	cout << "This is pattern(4, 1): \n";
	pattern(4, 1);
	cout << "\n\n";

	cout << "This is pattern(8, 0): \n";
	pattern(8, 0);
	cout << "\n\n";

	return 0;
}
