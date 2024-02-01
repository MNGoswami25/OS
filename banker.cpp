#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m, i, j, k;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the number of resources: ";
    cin >> m;
    vector<vector<int>> alloc(n, vector<int>(m));
    cout << "Enter the Allocation Matrix:\n";
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> alloc[i][j];
    vector<vector<int>> max(n, vector<int>(m));
    cout << "Enter the Maximum Matrix:\n";
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> max[i][j];
    vector<int> avail(m);
    cout << "Enter the Available Resources:\n";
    for (j = 0; j < m; j++)
        cin >> avail[j];
    vector<int> f(n), ans(n);
    int ind = 0;
    for (k = 0; k < n; k++)
        f[k] = 0;
    vector<vector<int>> need(n, vector<int>(m));
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    int y = 0;
    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (f[i] == 0)
        {
            flag = 0;
            cout << "The following system is not safe" << endl;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "Following is the SAFE Sequence\n";
        for (i = 0; i < n - 1; i++)
            cout << " P" << ans[i] << " ->";
        cout << " P" << ans[n - 1] << endl;
    }
    return 0;
}
