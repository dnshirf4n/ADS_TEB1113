#include <bits/stdc++.h>
using namespace std;

// Function to rotate a matrix represented by a vector of vectors
void rotateMatrix(vector<vector<int>>& mat) {
  
    int m = mat.size();
    int n = mat[0].size();
  
    int row = 0, col = 0;
    int prev, curr;

    // Rotate the matrix in layers
    while (row < m && col < n) {
        if (row + 1 == m || col + 1 == n)
            break;

        // Store the first element of the next row
        prev = mat[row + 1][col];

        // Move elements of the first row
        for (int i = col; i < n; i++) {
            curr = mat[row][i];
            mat[row][i] = prev;
            prev = curr;
        }
        row++;

        // Move elements of the last column
        for (int i = row; i < m; i++) {
            curr = mat[i][n - 1];
            mat[i][n - 1] = prev;
            prev = curr;
        }
        n--;

        // Move elements of the last row
        if (row < m) {
            for (int i = n - 1; i >= col; i--) {
                curr = mat[m - 1][i];
                mat[m - 1][i] = prev;
                prev = curr;
            }
        }
        m--;

        // Move elements of the first column
        if (col < n) {
            for (int i = m - 1; i >= row; i--) {
                curr = mat[i][col];
                mat[i][col] = prev;
                prev = curr;
            }
        }
        col++;
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    rotateMatrix(mat);

    // Print the rotated matrix
    for (auto& r : mat) {
        for (int val : r)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}