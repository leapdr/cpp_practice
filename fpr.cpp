//Aaron S. Basco
//BSCS 4A
//Floating Point Representation

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

//function for changing digits to Hexadecimal
char hexer(int t){
     char counter;
     switch(t){
               case 0:{ counter = '0'; return counter;} break;
               case 1:{ counter = '1'; return counter;} break;
               case 2:{ counter = '2'; return counter;} break;
               case 3:{ counter = '3'; return counter;} break;
               case 4:{ counter = '4'; return counter;} break;
               case 5:{ counter = '5'; return counter;} break;
               case 6:{ counter = '6'; return counter;} break;
               case 7:{ counter = '7'; return counter;} break;
               case 8:{ counter = '8'; return counter;} break;
               case 9:{ counter = '9'; return counter;} break;
               case 10:{ counter = 'A'; return counter;} break;
               case 11:{ counter = 'B'; return counter;} break;
               case 12:{ counter = 'C'; return counter;} break;
               case 13:{ counter = 'D'; return counter;} break;
               case 14:{ counter = 'E'; return counter;} break;
               case 15:{ counter = 'F'; return counter;} break;
               default: cout << "Not HEX"; break;
               }
     }


int main(){
    char final[8]; 
    int fprc[32]; //Floating Point Represetation Cotainer (fprc)
    double input, bin_dec;
    int count, bin_whole=0, a=9, b, c; //a, b, c [counters]
    
    cout << "Enter decimal: ";
    cin >> input;
    int whole = static_cast <int> (input);
    
    //converting whole number to binary digits
    count = c = whole;
    int x=1, y=0;
    while(count!=0){
                    if(count%2==1) bin_whole = bin_whole + x;
                    count = count / 2;
                    x = x * 10;
                    y++;
    }
    
    //storing to array
    x=1; count=1;
    while(count<y){
                 x=x*10; count++;
    }
    y--;
    b=y;
    bin_whole = bin_whole - x;
    x = x / 10;
    while(y >= 0){
                    if(bin_whole - x >= 0){ fprc[a] = 1; bin_whole = bin_whole - x;}
                    else fprc[a] = 0;
                    x = x / 10;
                    a++;
                    y--;
                    }
    
    //converting decimal to binary and storing values to array
    bin_dec = input - c; a--;
    while(a<32){
                if(bin_dec * 2 >= 1) fprc[a]=1;
                else fprc[a]=0;
                c = static_cast <int> (bin_dec * 2);
                bin_dec = (bin_dec * 2) - c;
                a++;
    }
    
    //converting BIAS to binary and storing the values to array
    b = 127 + b; a=1; //127 + number of decimal place/s change
    while(b!=0){
                if(b%2==1) fprc[a] = 1;
                else fprc[a] = 0;
                b = b/2;
                a++;
    }
    
    //the BIAS stored to array is inverted, use swap to arrange array
    x=1; y=8;
    while(x<=4){
               swap(fprc[x], fprc[y]);
               x++; y--;
               }
    
    //assuming that the input is a positive floating point, therefore
    fprc[0] = 0;
    
    //printing floating point as binary and checking for empty array, with respect to
    //storing the binary digits(from Whole Number) to array, and considering it as 0
    x=0; cout << endl;
    while(x<32){
                if(fprc[x] != 1 && fprc[x] != 0) fprc[x] = 0;
                cout << fprc[x];
                x++;
    }
    
    //finally translating BIN digits to HEX
    x = 0; y = 0; a=8; count = 0;
    while(x<8){
               while(y<4){
                          count = count + (fprc[y+(x*4)] * a);
                          a = a / 2;
                          y++;
               }
               final[x] = hexer(count);
               a=8;
               count=0;
               x++; y=0;
    }

    //printing HEX
    x=0;
    cout << "\nOutput: 0x";
    while(x<8){
               cout << final[x];
               x++;
    }
    
    getch();
    return 0;
}

int swap(int a, int b){
             int count;
             count =a;
             a = b;
             b = count;
         };
