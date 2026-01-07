//
//  main.cpp
//  Created by Daniel Zuniga on 10/24/25.
//

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

vector<int> tempMatrix;
int rows, cols, max_value;
bool in_the_matrix;

void setup()
{
    cout << "[#] enter the number of rows: ";
    cin >> rows;
    cout << "[#] enter the number of columns: ";
    cin >> cols;
    cout << "[#] enter the max value: ";
    cin >> max_value;
}


void generateMatrix(vector<vector<int>> &matrix, int n_rows, int n_columns, int maxVal)
{
    for (int h = 0; h < n_rows; h++)
    {
        for (int v = 0; v < n_columns; v++)
        {
            matrix[h][v] = (rand() % maxVal + 1);
        }
    }
}

void myLinearSearch(vector<vector<int>> &matrix, int value)
{
    in_the_matrix = false;
    vector<vector<int>> p; // store pairs of rows and columns
    //cout << value << endl << endl << matrix[value].size();
    for (int r = 0; r < matrix.size(); r++)
    {
        for (int c = 0; c < matrix[r].size(); c++)
        {
            if (matrix[r][c] == value)
            {
                p.push_back({r+1, c+1});
                //cout << matrix[r][c];
                in_the_matrix = true;
            }
                
        }
        
    }
    if (!in_the_matrix)
    {
        cout << "[!] Value " << value << " not found in the matrix." << endl;
        return;
    }
    cout << "[=] " << p.size() << " times were founded in the matrix with the value of " << value << ".\n";
    cout << "                         (V, H)" << endl;
    for (auto item : p)
    {
        cout << "[>] Found "<<value<<" at indices: (" << item[0] << ", " << item[1] << ")"<< endl;
    }
}
void mySwap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void Display(vector<vector<int>> &matrix)
{
    for (const auto& row: matrix)
    {
        for (auto num: row)
        {
            cout << num << "\t";
        }
        cout << endl;
    }
}
void selection(vector<vector<int>> &matrix,string sort)
{
    string ascending="ascending", descending="descending";
    /* "as-is" | "ascending" | "descending" */
    
    if (sort == ascending || sort == descending)
    {
        cout << "\n-- Matrix after Bubble Sort ("<<sort<<") --\n\n";
        tempMatrix.clear();
        for (auto& row : matrix)
        {
            for (auto num : row)
            {
                tempMatrix.push_back(num);
            }
        }
        //cout << tempMatrix.size() << endl; // 16
        //cout << tempMatrix.size() - 1 << endl; // 15
        int total = (int)tempMatrix.size(); // 16

        for (int o = 0; o < total - 1; ++o) {
            bool swapped = false;
            for (int index = 0; index < total - 1 - o; ++index) {
                bool desordenado = \
                (sort == ascending  && tempMatrix[index] > tempMatrix[index+1])
                ||
                (sort == descending && tempMatrix[index] < tempMatrix[index+1]);
                // ---------------
                if (desordenado) {
                    mySwap(tempMatrix[index], tempMatrix[index+1]);
                    swapped = true;
                }
            }
            if (!swapped) break;  // allset.
        }

        
        int index = 0;
        for (int x = 0; x < rows; ++x)
            for (int i = 0; i < cols; ++i)
                matrix[x][i] = tempMatrix[index++];
        
        Display(matrix);
    }
}
int main() {
    
    setup();
    
    vector<vector<int>> matrix(rows, vector<int>(cols));
    generateMatrix(matrix, rows, cols, max_value);
    
    cout << "\n-- Generated Matrix (total units: "<<(cols * rows)<<") --\n\n";
    Display(matrix);
    
    int key;
    cout << "\nEnter a number to search in the matrix: ";
    cin >> key;
    
    myLinearSearch(matrix, key);
    
    if (in_the_matrix)
    {
        selection(matrix, "ascending");
        selection(matrix, "descending");
    }
    
    return 0;
}
