#include <iostream>
#include <iomanip>
#include <cassert>
#include "boolmatrix.h" // class's header file
using namespace std;
// class constructor
boolMatrix::boolMatrix()
{
for (int row = 0; row < NUM_ROWS; row++){
for (int col = 0; col < NUM_COLS; col++){
matrix[row][col] = false;
}
}

}
bool boolMatrix::get(int row, int col) const
{
assert(row>=0 && row<NUM_ROWS && col>=0 && col<NUM_COLS);
return matrix[row][col];
}
void boolMatrix::set(int row, int col, bool value)
{
assert(row>=0 && row<NUM_ROWS && col>=0 && col<NUM_COLS);
matrix[row][col] = value;
}
int boolMatrix::rowCount(int row) const
{
assert(row>=0 && row<NUM_ROWS );
int rowtotal = 0;

for (int col = 0; col < NUM_COLS; col++){
if ( matrix[row][col] == true ){
rowtotal++;
}
}
return rowtotal;
}

int boolMatrix::colCount(int col) const
{
assert(col>=0 && col<NUM_COLS);
int colTotal = 0;

for (int row = 0; row < NUM_ROWS; row++){
if ( matrix[row][col] == true ){
colTotal++;
}

}
return colTotal;
}

int boolMatrix::totalCount() const
{
int total = 0;
for (int row = 0; row < NUM_ROWS; row++){
for (int col = 0; col < NUM_COLS; col++){
if ( matrix[row][col] == true ){
total++;
}
}
}
return total;

}
void boolMatrix::print() const
{
cout << " ";

for (int col = 0; col < NUM_COLS; col++)
{
cout << col % 10;
}
cout << endl;

for (int row = 0; row < NUM_ROWS; row++)
{
cout << setw(2) << row % 100;
for (int col = 0; col < NUM_COLS; col++){
if ( matrix[row][col] == true ){
cout << "*";
} else if ( matrix[row][col] == false ){
cout << " ";
}
}
cout << endl;
}
}
