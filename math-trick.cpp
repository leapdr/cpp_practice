#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

int numberSet[5][15]{
    {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29},
    {2, 3, 6, 7, 10, 11, 14, 15, 18, 19, 22, 23, 26, 27, 30},
    {4, 5, 6, 7, 12, 13, 14, 15, 20, 21, 22, 23, 28, 29, 30},
    {8, 9, 10, 11, 12, 13, 14, 15, 24, 25, 26, 27, 28, 29, 30},
    {16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30}
};

bool isWithinSet(int set[], int number){
    for( int i = 0; i < 5; i++ ){
        if( set[i] == number ){
            return true;
        }
    }

    return false;
}

int * generateRandomNumbers(){
    static int series[5] = {-1, -1, -1, -1, -1};

    srand((unsigned)time(0));
    int i = 0;
    while(series[4] == -1){
        int n = rand() % 5;

        // check if in series
        if(isWithinSet(series, n)){
            continue;
        }

        series[i] = n;
        i++;
    }

    // increment to make 1-5 random numbers
    for(int x = 0; x < 5; x++){
        series[x]+=1;
    }

    return series;
}

// show number sets and prompt user
bool isNumberInSet(int setIndex){
    char choice;

    // show number set
    cout << "-------------" << endl;
    for(int i = 0; i < 15; i++){
        cout << numberSet[setIndex][i] << ", ";
        if((i+1) % 3 == 0){
            cout << endl;
        }
    }
    cout << endl;

    // let user choose
    cout << "Is you number within this set of numbers?" << endl;
    cout << "Enter 'Y' or 'N': ";
    cin >> choice;

    if(choice == 'Y'){
        return true;
    } else {
        return false;
    }
}

int main(){
    int *numbers;
    int sum = 0;
    bool isFoundInSet;

    // generate unique random number set
    // 5,  3,  4,  1,  2
    numbers = generateRandomNumbers();
    
    // show number set
    for(int i = 0; i < 5; i++){
        isFoundInSet = isNumberInSet(numbers[i]-1);
        if(isFoundInSet){
            sum += numberSet[numbers[i]-1][0]; // pow(2, numbers[i]-1); // 
        }
    }

    // display guessed number
    cout << "Your number is: " << sum << endl;

    return 0;
}