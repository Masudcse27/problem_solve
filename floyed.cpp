#include<bits/stdc++.h>
using namespace std;
int matrix[5][5];
void Floyd_Warshall(int n){
    for (int k = 0; k <n ; k++) {
        for (int i = 0; i <n; i++) {
        for (int j = 0; j <n; j++) {
            if (matrix[i][k] + matrix[k][j] < matrix[i][j])
            matrix[i][j] = matrix[i][k] + matrix[k][j];
        }
        
        }
    }
}
int main(){
    matrix[0][0]=0;
    matrix[0][1]=3;
    matrix[0][2]=50;
    matrix[0][3]=5;
    matrix[1][0]=2;
    matrix[1][1]=0;
    matrix[1][2]=50;
    matrix[1][3]=4;
    matrix[2][0]=50;
    matrix[2][1]=1;
    matrix[2][2]=0;
    matrix[2][3]=50;
    matrix[3][0]=50;
    matrix[3][1]=50;
    matrix[3][2]=3;
    matrix[3][3]=0;
    Floyd_Warshall(4);
}
/*
0 3 IN  5
2 0 in 4
in 1 0 in
in in 3 0

*/