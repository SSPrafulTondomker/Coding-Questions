#include <iostream>
using namespace std;
int main()
{
    int s[1000], n, m, i, j;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    cin >> s[i];
    int mat[1000][1000];
        for (i = 0; i <= m; i++){
            for (j = 0; j <= n; j++){
                if (j == 0)
                    mat[i][j] = 1;
                else
                mat[i][j] = 0;
            }
        }
        
        for (i = 1; i <= m; i++){
            for (j = 1; j <= n; j++){
                if (j-s[i-1] >= 0)
                mat[i][j] = mat[i-1][j] + mat[i][j-s[i-1]];
                else 
                mat[i][j] = mat[i-1][j];
            }
        }

        for (i = 0; i <= m; i++){
            for (j = 0; j <= n; j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
     return 0;
}