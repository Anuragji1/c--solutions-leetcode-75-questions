**Equal Row And Column Pairs**

Problem Statement 22) Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

 

Example 1:


Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]
Example 2:


Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
Output: 3
Explanation: There are 3 equal row and column pairs:
- (Row 0, Column 0): [3,1,2,2]
- (Row 2, Column 2): [2,4,2,2]
- (Row 3, Column 2): [2,4,2,2]
 

Constraints:

n == grid.length == grid[i].length
1 <= n <= 200
1 <= grid[i][j] <= 105

----------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>> col;
        vector<int> temp;
        //storing grid in column order
        for(int i=0;i<grid.size();i++){ 
            for(int j=0;j<grid.size();j++){
                temp.push_back(grid[j][i]);
            }
            col.push_back(temp);
            temp.clear();
        }
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i]==col[j]) //comparing each row vector to each column vector 
                count++;
            }
        }
        return count;
    }
};

----Explanation :-
Counting Equal Rows and Columns:

Grid Transposition:

It creates a new vector of vectors col to store the transposed grid. Transposition means swapping rows and columns.
It uses nested loops to iterate through the grid vector. The outer loop iterates over the columns (j) of the grid, and the inner loop iterates over the rows (i).
Inside the loops, it creates a temporary vector temp to store the elements of a column during the iteration.
For each element (grid[j][i]), it pushes it into the temp vector. This effectively builds a new column vector from the elements in each row at the same column index (j) across all rows.
After iterating through all elements, it pushes the completed temp vector (representing a column) into the col vector. This process effectively transposes the grid, where rows become columns and vice versa.
It clears the temp vector to prepare for the next iteration.
Comparing Rows and Columns:

It initializes a counter variable count to store the number of equal row-column pairs found.
It uses nested loops again to iterate through both the original grid and the transposed col vector.
The outer loop iterates over the rows (i) of the original grid.
The inner loop iterates over the columns (j) of the transposed col vector (which now represents the grid's columns).
Inside the nested loops, it compares the current row (grid[i]) from the original grid with the current column (col[j]) from the transposed grid using the comparison operator (grid[i] == col[j]).
If the row and column vectors are equal, it means a corresponding row in the original grid has the same elements as a column in the transposed grid (which represents a column in the original grid). In this case, the counter count is incremented.
Returning the Count:

After iterating through all possible row-column combinations, the count variable will hold the total number of pairs where a row in the original grid is equal to a column in the grid.
The function returns the count as the result.
