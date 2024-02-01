#include <iostream>
#include <vector>
using namespace std;
void firstFit(vector<int>& blockSize, int m, vector<int>& processSize, int n) {
    vector<int> allocation(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}
int main() {
    int m, n;
    cout << "Enter the number of blocks: ";
    cin >> m;
    vector<int> blockSize(m);
    cout << "Enter the size of blocks:\n";
    for (int i = 0; i < m; i++) {
        cout << "Block " << i + 1 << ": ";
        cin >> blockSize[i];
    }
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<int> processSize(n);
    cout << "Enter the size of processes:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> processSize[i];
    }
    firstFit(blockSize, m, processSize, n);
    return 0;
}
