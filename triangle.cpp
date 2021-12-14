#include <iostream>

using namespace std;

int main(){
	int num;

	cout << "Enter a number: ";
	cin >> num;

	while(num != 0){
		int line = num;
		while(line != 0){
			cout << "*";
			line--;
		}
		cout << endl;
		num--;
	}
}
