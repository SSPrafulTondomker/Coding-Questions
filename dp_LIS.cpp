#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;

int main()
{
    int i, j, n, x, y;
    vector <pair<int,int> >v;
    cin >> n;

    int lis[n];

    for (i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
        lis[i] = 1; 
    }
    
    sort(v.begin(), v.end());

    for (i = 1; i < n; i++){
        for (j = 0; j < i; j++){
            if (v[i].first > v[j].second && lis[i] < lis[j]+1)
                lis[i] = lis[j]+1;
        }
    }

    sort(lis, lis+n);

    cout << lis[n-1] << endl;
    return 0;
}