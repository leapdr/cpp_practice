#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Enter the size of inverted right triangle: ";
	cin >> n;

	for(int x=n; x>=1; x--)
	{
		int y=1;
		do{
			cout << "*";
			++y;
		}while(y<=(x*2-1));
		cout << "\n";
	}
	return 0;
}
