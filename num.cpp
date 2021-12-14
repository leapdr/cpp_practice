#include <iostream>

using namespace std;

int myFunction(){
	cout << "This is my function" << endl;
	return 0;
}

int main()
{
	int num = 86;
	int y = 13;
	int x = 44.26;

	// if, if else if, if else if else, switch, while, do while, for, break, continue

	// true && (false || true)
	// true && true
	// true
	if(num >= 86 && (y % 2 == 0 || x / 2 >= 22) && false)
	{
		cout << "has display" << endl;
	}

	int b = 3;
	while(b > 0){
		if(b == 3){
			b--;
			continue;
		}

		cout << b << endl;
		b--;
	}

	return 0;

	int a = 1;
	switch(a){
		case 1: cout << "asdf"; break;
		case 2: 
			cout << "fdsa";
			break;
		default:
			break;
	}

	myFunction();

	return true;
}

