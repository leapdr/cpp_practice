// Aaron S. Basco
// A Sudoku puzzle solver implementing Penciling In and Crosshatching

#include <iostream>
#include <fstream>

using namespace std;

void pencilIn();
void crossHatch();
void removeNote(int, int, int);
void clearNote(int, int, int);
void cleanNote();
void claim(int, int, int);

int countNote(int, int);

bool complete();
bool checkXYB(int, int, int, int);
bool checkNote(int, int, int, int);
bool search(int, int, char, int);
bool searchNote(int, int, int);

int grid[9][9];
int gridNote[9][9][9];
bool hasSolution = true;
bool canRetry = false;

ofstream out;

int main(){
    ifstream in;
    bool solved = false, canRetry = true;
    
    in.open("sud.txt");
    out.open("sol.txt");
    
    for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                    in >> grid[i][j];
            }
    }
    
    pencilIn(); // initialize Penciling In process to the grid
    claim(10, 10, 10); // start claiming candidates to cell, box, row and column
    crossHatch(); // initialize Cross Hatching process to the grid
    
    if(complete()) out << "Puzzle Solved!!!" << endl;
    else out << "Puzzle Unsolved!!!" << endl;
    
    out << endl;
    for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                    if(grid[i][j] > 0) out << grid[i][j] << " ";
                    else out << "  ";
            }
            out << endl;
    }
    
    in.close();
    system("pause");
    return 0;
}

void pencilIn(){
     int box;
     out << "Initializing Penciling In. " << endl;
     out << "Writing notes ..." << endl;
     int count = 0;
     
     for(int i=0; i<9; i++){
             for(int j=0; j<9; j++){
                     box = ((i/3)*3) + (j/3);
                     if(grid[i][j]==0){ // check if the cell is not empty
                                       for(int x=1; x<10; x++){
                                               // check if the box, row or column already has the number
                                               // adds the number to notes if it has not
                                               if(checkXYB(x, box, i, j)){
//                                                              out << "Writing " << x << " to note at " << i 
//                                                              << " " << j << " " << count << "." << endl;
                                                              gridNote[i][j][count] = x;
                                                              count++;
                                               }
                                       }
                                       count = 0;
                     }
             }
     }
     
     out << "Starting initial cleanNote() process." << endl;
     cleanNote();
     out << "End of first cleanNote() process." << endl << endl;
     
     out << "Starting second cleanNote() process." << endl;
     cleanNote();
     out << "End of second cleanNote() process." << endl << endl;
     out << "End of initialized primary Penciling In Process." << endl << endl;
}

void crossHatch(){
     out << "Initializing Cross Hatching process." << endl;
     int num = 1;
     int box, cell;
     int y, x;
     int puty, putx;
     box = cell = 0;
     out << "Cross Hatching ..." << endl;
     while(num < 10){
              while(box < 9){
//                        out << "Try " << num << " at box " << box << "." << endl;
                        for(int i=0; i<3; i++){
                                y = ((box/3)*3)+i;
                                for(int j=0; j<3; j++){
                                        x = ((box%3)*3)+j;
                                        if(checkXYB(num, box, y, x) && grid[y][x] == 0){
                                                          if(!checkNote(num, box, y, x)){
                                                                            puty = y;
                                                                            putx = x;
                                                                            cell++;
                                                          }
                                        }
                                }
                        }
                        if(cell == 1){
                                out << "Writing " << num << " at " << puty << " " << putx << "." << endl;
                                grid[puty][putx] = num;
                                clearNote(num, puty, putx);
                                canRetry = true;
                                cleanNote();
                                claim(box, puty, putx);
                                }
                        cell = 0;
                        box ++;
              }
              box = 0;
              
              if(canRetry == true){
                          num = 1;
                          canRetry = false;
              }
              else num ++;
     }
     
     out << "End of Cross Hatching process. " << endl << endl;
}

void claim(int box, int y, int x){
    int county = 0;
    int countx = 0;
    int coory1, coorx1, coory2, coorx2;
            
    if(box == 10 && y == 10 && x == 10){  
            out << "Initializing claim() process." << endl;      
            for(int i=0; i<9; i++){
                    for(int j=0; j<9; j++){
                        if(countNote(i, j) == 1){
                          out << "Claiming " << gridNote[i][j][0] << " at " << i << " " << j << "." << endl;
                           grid[i][j] = gridNote[i][j][0];
                           clearNote(gridNote[i][j][0], i, j);
                        }
                    }
            }
            
            for(int n=1; n<10; n++){
                    for(int i=0; i<9; i++){
                            for(int j=0; j<9; j++){
                                    if(searchNote(n, i, j)){countx ++; coory1=i; coorx1=j;}
                                    if(searchNote(n, j, i)){county ++; coory2=j; coorx2=i;}
                            }
                            if(countx == 1){
                                      out << "Claiming " << n << " at " << coory1 << " " << coorx1 << "." << endl;
                                      grid[coory1][coorx1] = n;
                                      clearNote(n, coory1, coorx1);
                                      cleanNote();
                            }
                            if(county == 1){
                                      out << "Claiming " << n << " at " << coory2 << " " << coorx2 << "." << endl;
                                      grid[coory2][coorx2] = n;
                                      clearNote(n, coory2, coorx2);
                                      cleanNote();
                            }
                            countx = 0; county = 0;
                    }
            }
            out << "End of initial claim() process." << endl << endl;
     }
     else{
          int checkx = 0;
          int checky = 0;
          int checkb = 0;
          int i1, j1, i2, j2, i3, j3;
          
          for(int n = 1; n<10; n++){
              for(int count = 0; count<9; count++){
                      if(searchNote(n, y, count)){ checkx++; i1 = y; j1 = count;}
                      if(searchNote(n, count, x)){ checky++; i2 = count; j2 = x;}
                      if(searchNote(n, ((box/3)*3)+(count/3), ((box%3)*3)+(count%3))){
                                       i3 = ((box/3)*3)+(count/3);
                                       j3 = ((box%3)*3)+(count%3);
                                       checkb++;
                      }
              }
              
              if(checkx == 1){
                        out << "Claiming " << n << " at " << i1 << " " << j1 << endl;
                        grid[i1][j1] = n;
                        clearNote(n, i1, j1);
                        cleanNote();
              }
              if(checky == 1){
                        out << "Claiming " << n << " at " << i2 << " " << j2 << endl;
                        grid[i2][j2] = n;
                        clearNote(n, i2, j2);
                        cleanNote();
              }
              if(checkb == 1){
                        out << "Claiming " << n << " at " << i3 << " " << j3 << endl;
                        grid[i3][j3] = n;
                        clearNote(n, i3, j3);
                        cleanNote();
              }
              
              checkx = checky = checkb = 0;
          }
     }
}

void cleanNote(){
     int box;
     out << "Removing Notes ... " << endl;
     
     for(int i=0; i<9; i++){
             for(int j=0; j<9; j++){
                     box = ((i/3)*3) + (j/3);
                     if(grid[i][j]==0){
                           for(int x=0; x<9 && gridNote[i][j][x] > 0 && gridNote[i][j][x] < 10; x++){
                                   if(checkNote(gridNote[i][j][x], box, i, j)){
                                        removeNote(gridNote[i][j][x], i, j);
                                        x=0;
                                   }
                           }
                     }
             }
     }
}

int countNote(int i, int j){
    int count = 0;
    for(int c=0; c<9; c++){
            if(gridNote[i][j][c] > 0 && gridNote[i][j][c] < 10) count++;
    }
    return count;
}

void clearNote(int n, int i, int j){
     int box = ((i/3)*3) + (j/3);
     out << "Clearing Notes ... " << endl;
     
     for(int count=0; count<9; count++){
             if(searchNote(n, i, count)) removeNote(n, i, count);
             if(searchNote(n, count, j)) removeNote(n, count, j);
             if(searchNote(n, ((box/3)*3)+(count/3), ((box%3)*3)+(count%3)))
              removeNote(n, ((box/3)*3)+(count/3), ((box%3)*3)+(count%3)); // box
     }
     
     gridNote[i][j][0] = 0;
     gridNote[i][j][1] = 0;
}

bool complete(){
     for(int y=0; y<9; y++){
             for(int x=0; x<9; x++){
                     if(grid[y][x] == 0) return false;
             }
     }
     return true;
}
     
void removeNote(int n, int y, int x){
     int step=0;
     for(int c=0; c<9; c++){
             if(gridNote[y][x][c] == n){
                                  if(gridNote[y][x][c+1] > 0 && gridNote[y][x][c+1] < 10){
                                         step=c+1;
                                         while(step!=9 && gridNote[y][x][step] < 10 && gridNote[y][x] > 0){
                                                       gridNote[y][x][step-1] = gridNote[y][x][step];
                                                       step++;
                                         }
                                  }
                                  else gridNote[y][x][c] = 0;
                                  
//                                  out << "Removing " << n << " at " << y << " " << x <<  "." << endl;
                                  return;
             }
     }
}

bool checkXYB(int x, int box, int i, int j){
     // check row (i), column(j) and box(box) if it already has the number(x)
     
     for(int count=0; count<9; count++){
             if(grid[i][count] == x) return false; // x coordinates
             if(grid[count][j] == x) return false; // y coordinates
             if(grid[((box/3)*3)+(count/3)][((box%3)*3)+(count%3)] == x) return false; // box
     }
     
     return true;
}

bool checkNote(int x, int box, int i, int j){
     int bx1, bx2, by1, by2;
     bool check = true;
     
     if(box%3==0){ bx1 = box + 1; bx2 = box + 2;}
     else if(box%3==1){ bx1 = box - 1; bx2 = box + 1;}
     else if(box%3==2){ bx1 = box - 1; bx2 = box - 2;}
     
     if(box/3==0){ by1 = box + 3; by2 = box + 6;}
     else if(box/3==1){ by1 = box - 3; by2 = box + 3;}
     else if(box/3==2){ by1 = box - 3; by2 = box - 6;}
     
     check = search(x, bx1, 'x', i) || search(x, bx2, 'x', i)
           || search(x, by1, 'y', j) || search(x, by2, 'y', j);
     
     return check;
}

bool search(int n, int b, char dir, int val){
     int x = (b%3)*3;
     int y = (b/3)*3;
     bool c = true;
     bool a, d;    
     int val1, val2;
     
     if(val%3 == 0){val1 = val+1; val2 = val+2;}
     else if(val%3 == 1){val1 = val-1; val2 = val+1;}
     else if(val%3 == 2){val1 = val-1; val2 = val-2;}
     
     if(dir == 'x'){
            int x1, x2, x3;
            x1 = x;
            x2 = x+1;
            x3 = x+2;
            c = (searchNote(n, val, x3) || searchNote(n, val, x2) || searchNote(n, val, x1))
                && (!searchNote(n, val1, x1) && !searchNote(n, val1, x2) && !searchNote(n, val1, x3))
                && (!searchNote(n, val2, x1) && !searchNote(n, val2, x2) && !searchNote(n, val2, x3));
     }
     else if(dir == 'y'){
            int y1, y2, y3;
            y1 = y;
            y2 = y+1;
            y3 = y+2;
            c = (searchNote(n, y1, val) || searchNote(n, y2, val) || searchNote(n, y3, val))
                && (!searchNote(n, y1, val1) && !searchNote(n, y2, val1) && !searchNote(n, y3, val1))
                && (!searchNote(n, y1, val2) && !searchNote(n, y2, val2) && !searchNote(n, y3, val2));
     }
     
     return c;
}

bool searchNote(int x, int i, int j){
     for(int count=0; count<9; count++){
             if(gridNote[i][j][count] > 0 && gridNote[i][j][count] < 10
                && gridNote[i][j][count] == x) return true;
             if(gridNote[i][j][count] > 9)return false;
     }
     return false;
}
