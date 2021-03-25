#include <iostream>
#include <vector>
#include <map>

using namespace std;

void printT (int arr[], int n){
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void heapify(int arr[], int n, int root){
    int l, r, larg;

    larg = root;
    l = 2*root + 1;
    r = 2*root + 2;

    if (l < n && arr[l] < arr[root])
        larg = l;
    if (r < n && arr[r] < arr[root])
        larg = r;
    
    if (larg != root){
        swap(arr[larg], arr[root]);
        heapify(arr, n, larg);
    }
}

void build(int arr[], int n){
    int i, j;

    for (i = n/2; i >= 0; i--){
        heapify(arr, n, i);
    }

    for (i = n-1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    printT(arr, n);
}
int main()
{
    int n, i, j;
    cin >> n;

    int arr[n+1];

    for (i = 0; i < n; i++)
        cin >>arr[i];

    build(arr, n);
    printT(arr, n);
    return 0;
}