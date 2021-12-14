#include <iostream>
using namespace std;

float addition(float a, float b){
    return a + b;
}

float substraction(float a, float b){
    return a - b;
}

float multiplication(float a, float b){
    return a * b;
}

float division(float a, float &b){
    while( b == 0 ){
        cout << "Division by zero is invalid" << endl;
        cout << "Enter non-zero integer: ";
        cin >> b;
    }

    return a / b;
}

bool isFloat(string inputString){
    for (int i = 0; i < inputString.length(); i++){
        if(isdigit(inputString[i]) == false && inputString[i] != '.' && inputString[i] != '-'){
            return false;
        }
    }

    return true;
}

bool isInteger(string inputString){
    for (int i = 0; i < inputString.length(); i++){
        if(isdigit(inputString[i]) == false && inputString[i] != '-'){
            return false;
        }
    }

    return true;
}

void zodiacCalculator(int year, int month, int day){
    if ((month == 1 && day >= 20) || (month == 2 && day <= 18))
    {
        cout << "Your zodiac sign is AQUARIUS\n";
    }
    else if ((month == 2 && day >= 29) || (month == 3 && day <= 20))
    {
        cout << "Your zodiac sign is PISCES\n";
    }
    else if ((month == 3 && day >= 21) || (month == 4 && day <= 19))
    {
        cout << "Your zodiac sign is ARIES\n";
    }
    else if ((month == 4 && day >= 20) || (month == 5 && day <= 20))
    {
        cout << "Your zodiac sign is TAURUS\n";
    }
    else if ((month == 5 && day >= 21) || (month == 6 && day <= 20))
    {
        cout << "Your zodiac sign is GEMINI\n";
    }
    else if ((month == 6 && day >= 21) || (month == 7 && day <= 22))
    {
        cout << "Your zodiac sign is CANCER\n";
    }
    else if ((month == 7 && day >= 23) || (month == 8 && day <= 22))
    {
        cout << "Your zodiac sign is LEO\n";
    }
    else if ((month == 8 && day >= 23) || (month == 9 && day <= 22))
    {
        cout << "Your zodiac sign is VIRGO\n";
    }
    else if ((month == 9 && day >= 23) || (month == 10 && day <= 22))
    {
        cout << "Your zodiac sign is LIBRA\n";
    }
    else if ((month == 10 && day >= 23) || (month == 11 && day <= 21))
    {
        cout << "Your zodiac sign is SCORPIO\n";
    }
    else if ((month == 11 && day >= 22) || (month == 12 && day <= 21))
    {
        cout << "Your zodiac sign is SAGITTAURUS\n";
    }
    else if ((month == 12 && day >= 22) || (month == 1 && day <= 19))
    {
        cout << "Your zodiac sign is CAPRICORN\n";
    }
    else
    {
        cout << "Cannot determine zodiac for date: " << year << "-" << month << "-" << day << endl;
    }
}

int main()
{
    bool exit = false;

    while(!exit){
        char Choice;
        string in1, in2; 
        float num1, num2;
        int result;

        bool isValidDate = false;
        string y, m, d;
        int year, month, day;
        cout << "Choose a Category" << endl;
        cout << "Enter a, If you choose Simple Calculator" << endl;
        cout << "Enter b, if you choose Zodiac Sign" << endl;
        cin >> Choice;
    
        switch (Choice)
        {
        case 'a':
            cout << " You have chosen Simple Calculator " << endl;

            while( true ){
                /* operation */
                char op;

                cout << " Enter First Number: ";
                cin >> in1;
                cout << " Enter Second Number: ";
                cin >> in2;

                /* validate input, check if integer */
                bool isInputFloat = isFloat(in1) && isFloat(in2);

                if(!isInputFloat){
                    cout << "Invalid inputs." << endl; 
                    continue;
                } else {
                    /* typecast string to float*/
                    num1 = stof(in1);
                    num2 = stof(in2);
                }
    
                cout << " Choose Operator you want to perfrom? " << endl;
                cout << " A. Addition" << endl;
                cout << " B. Subtraction" << endl;
                cout << " C. Multiplication" << endl;
                cout << " D. Division" << endl;
                cout << " Please Enter A, B ,C or D?" << endl;
                cin >> op;

                if ((op == 'A') || (op == 'a'))
                {
                    cout << " The Sum of " << num1 << " and " << num2 << " is: ";
                    cout << addition(num1, num2) << endl;
                }
                else if ((op == 'B') || (op == 'b')) 
                {
                    cout << " The Difference of " << num1 << " and " << num2 << " is: ";
                    cout << substraction(num1, num2) << endl;
                }
                else if ((op == 'C') || (op == 'c'))
                {
                    cout << " The Product of " << num1 << " and " << num2 << " is: ";
                    cout << multiplication(num1, num2) << endl;
                }
                else if ((op == 'D') || (op == 'd'))
                {
                    float divResult = division(num1, num2);
                    cout << " The Quotients of " << num1 << " and " << num2 << " is: ";
                    cout << divResult << endl;
                }
                else
                {
                    cout << " You Enter Wrong Keyword: " << endl << endl;
                    continue;
                }
                break;
            }
            break;
        case 'b': case 'B':

            while(!isValidDate){
                cout << "You choose Zodiac Sign\n";
                cout << "Enter your Birth year: ";
                cin >> y;
                cout << "Enter your Birth month: ";
                cin >> m;
                cout << "Enter your the day of your birth: ";
                cin >> d;

                /* check if date is valid */

                if( isInteger(y) && isInteger(m) && isInteger(d) ){
                    year = stoi(y);
                    month = stoi(m);
                    day = stoi(d);
                } else {
                    month = 0;
                }

                if(day < 1 || year < 1){
                    month = 0;
                }

                bool isLeapYear = year % 4 == 0;
                
                switch(month){
                    case 1:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:
                    case 12:
                        if(day > 31){
                            cout << "Invalid date." << endl;
                        }
                        else{
                            isValidDate = true;
                        }
                        break;
                    case 4:
                    case 6:
                    case 9:
                    case 11:
                        if(day > 30){
                            cout << "Invalid date." << endl;
                        }
                        else{
                            isValidDate = true;
                        isValidDate = false;
                        }
                        break;
                    case 2:
                        if((isLeapYear && day > 29) || (!isLeapYear && day > 28)){
                            cout << "Invalid date." << endl;
                        }
                        else{
                            isValidDate = true;
                        }
                        break;
                    default: 
                        cout << "Invalid date." << endl;
                        isValidDate = false;
                        break;
                }
            }

            zodiacCalculator(year, month, day);

            break;
        default:
            cout << "Invalid choice." << endl;
            continue;
        }

        char select;
        cout << "Would you like to perform other calculations?(Y/N)" << endl;
        cin >> select;

        if(select == 'Y'|| select =='y'){
            exit = false;
        }else if(select =='N'||select =='n'){
            exit = true;
        }
    }

    return 0;
}