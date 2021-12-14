//Aaron S. Basco
//BS Computer Science 3A
//Algorithm
//
//This program sorts an Array
//The Array contains 2 series of sorted value
//A[0 - m] => first sorted series of the Array A
//A[m - n] => second sorted series of the Array A
//B[n] => new array for the full sorted Array A

#include <stdio.h>
#include <conio.h>
#define MAX_INT = 1000000;

int main(){
    int count;
    
    //Prompting Array Size
    int array_size;
    printf("Enter size of array: ");
    scanf("%d", &array_size);

    //Scanning array values
    int A[array_size];
    printf("Enter array values: ");
    for(count=0; count<array_size; count++){
            scanf("%d", &A[count]);
            }

    //Finding the limit of the first sorted series in the array
    int limit=0;
    while(A[limit] < A[limit+1]) limit++;
    limit++;

    //
    int a=0, b=limit, min1, min2, temp[array_size];
    for(count=0; count < array_size; count++){
                 if(a<limit){
                            if(A[a] < A[b]){ temp[count] = A[a]; a++; }
                            else{ temp[count] = A[b]; b++; }}
                 else if(a>=limit){ temp[count] = A[b]; }
                 else if(b>=array_size){ temp[count] = A[a]; }
                 }
    
    //Printing and assigning temporary array to original array
    for(count=0; count < array_size; count++){
                 A[count] = temp[count];
                 printf("%d ", A[count]);
                 }
    
    getch();
    return 0;
}

// 0 - 2
// 1 - 5
// 2 - 7
// -----
// 3 - 1
// 4 - 4
// 5 - 8
