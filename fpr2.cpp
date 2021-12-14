#include <iostream>
#include <iomanip>
#include <conio.h>
#define BIAS 127;

using namespace std;

int main(){
    int sig_frac_par[23];
    int count, bin_whole;
    double input;
    cout << "Enter floating point number: ";
    cin >> input;
    int whole = static_cast <int> (input);
    cout << "Processing...\n" << endl;
    
    //converting whole number to binary
    count = whole;
    int x=1, y=0;
    while(count!=0){
                    if(count%2==1) bin_whole = bin_whole + x;
                    count = count / 2;
                    x = x * 10;
                    y++;
    }
    cout << "Whole Number: " << bin_whole << "\n\n";
    
    getch();
    return 0;
}
