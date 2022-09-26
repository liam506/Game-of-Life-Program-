#ifndef BOOLMATRIX_H
#define BOOLMATRIX_H

class boolMatrix
{
public: // Available for clients use.
static const int NUM_ROWS = 20;
static const int NUM_COLS = 20;
boolMatrix();
bool get(int row, int col) const;
void set(int row, int col, bool value);
int rowCount(int row) const;
int colCount(int col) const;
int totalCount() const;
void print()const;

private: // Can only be used within the class, Client cannot call it.
bool matrix[NUM_ROWS][NUM_COLS];
};
#endif // BOOLMATRIX_H
