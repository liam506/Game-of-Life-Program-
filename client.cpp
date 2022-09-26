//The main client program
#include <iostream>
#include <fstream>
#include <cassert>
#include "boolmatrix.h"

using namespace std;
void firstgen(boolMatrix& generation);
void getNextGen(boolMatrix& generation,boolMatrix &nextGeneration);
void fateDeadCell(boolMatrix& generation,boolMatrix &nextGeneration,int liveNeighbors,int row,int col);
void fateLiveCell(boolMatrix& generation, boolMatrix &nextGeneration, int liveNeighbors,int row,int col);
bool checkOutBounds(int row, int col);
void printResults(boolMatrix& generation);
void tallyLiveNeighbors(const boolMatrix& generation, int& liveNeighbors,int row,int col);
int main()
{
boolMatrix generation;
int numGen, liveNeighbors, row, col;
cout << "How many generations in total?: " << endl;
cin >> numGen;
firstgen(generation);

generation.print(); //prints first generations.
cout << "Total alive in row 10 = " << generation.rowCount(10) << endl;
cout << "Total alive in col 10 = " << generation.colCount(10) << endl;
cout << "Total alive = " << generation.totalCount() << endl << endl;
for(int count = 1; count <=numGen; count++)
{
boolMatrix nextGeneration;
getNextGen(generation,nextGeneration);
  cout<<"The grid after "<<count<<" generations have passed."<<endl;
  cout<<"(GENERATION #"<<count<<") GAME OF currentgen STATISTICS"<<endl;
printResults(nextGeneration);
generation = nextGeneration;//for next iteration the new generation becomes starting point
}

system("pause");
return 0;
}
void firstgen(boolMatrix& generation) //stores data file info into array.
{
ifstream infile("pr3a.txt.txt");
assert(infile);
int row, col;

infile >> row >> col;
while (infile) {
generation.set(row, col, true);
infile >> row >> col;
}
infile.close();
}
void getNextGen(boolMatrix& generation,boolMatrix &nextGeneration) //gets all subsequent generations.
{
int liveNeighbors;
for(int row = 0; row < boolMatrix::NUM_ROWS; row++)
{
for(int col = 0; col < boolMatrix::NUM_ROWS; col++)
{
liveNeighbors = 0;
if(generation.get(row,col) == false){
fateDeadCell(generation,nextGeneration, liveNeighbors,row,col);
}else if(generation.get(row,col) == true){
fateLiveCell(generation,nextGeneration,liveNeighbors,row,col);
}
}
}
}

void tallyLiveNeighbors(boolMatrix& generation,int& liveNeighbors,int row,int col)
{
if(checkOutBounds(row-1, col-1) && generation.get(row-1,col-1) == true){
liveNeighbors++;

}
if(checkOutBounds(row-1, col) && generation.get(row-1,col) == true){
liveNeighbors++;

}

if(checkOutBounds(row-1,col+1) && generation.get(row-1,col+1) == true){
liveNeighbors++;

}

if( checkOutBounds(row, col-1) && generation.get(row,col-1) == true){
liveNeighbors++;

}

if(checkOutBounds(row, col+1) && generation.get(row,col+1) == true){
liveNeighbors++;

}
if(checkOutBounds(row+1, col-1) && generation.get(row+1,col-1) == true){
liveNeighbors++;

}

if(checkOutBounds(row+1, col) && generation.get(row+1,col)== true){
liveNeighbors++;

}

if(checkOutBounds(row+1, col+1) && generation.get(row+1,col+1) == true){
liveNeighbors++;

}
}

void fateDeadCell(boolMatrix& generation, boolMatrix &nextGeneration,int liveNeighbors,int row,int col)
{
tallyLiveNeighbors(generation,liveNeighbors,row,col);

if(liveNeighbors == 3){
nextGeneration.set(row,col,true);
}else {
nextGeneration.set(row,col,false);
}
}
void fateLiveCell(boolMatrix& generation,boolMatrix &nextGeneration,int liveNeighbors,int row,int col)
{
tallyLiveNeighbors(generation,liveNeighbors,row,col);

if((liveNeighbors <= 1) || (liveNeighbors >= 4)){
nextGeneration.set(row,col,false);
}else if((liveNeighbors == 2) || (liveNeighbors == 3)){
nextGeneration.set(row,col,true);
}
}
bool checkOutBounds(int row, int col)
{
if(row < 0 || row >= boolMatrix::NUM_ROWS || col< 0 || col >= boolMatrix::NUM_COLS)
{
return false;
}
else
return true;
}
void printResults(boolMatrix& generation)
{
generation.print(); //prints subsequent generations
cout << "Total alive in row 10 = " << generation.rowCount(10) << endl;
cout << "Total alive in col 10 = " << generation.colCount(10) << endl;
cout << "Total alive = " << generation.totalCount() << endl << endl;
}
