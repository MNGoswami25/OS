#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> frames(20, -1);
    vector<int> pages(50);
    int frameCount, pageCount, pageFaults = 0;
    cout << "Enter number of pages: ";
    cin >> pageCount;
    cout << "Enter the reference string: ";
    for (int i = 0; i < pageCount; i++)
        cin >> pages[i];
    cout << "Enter number of frames: ";
    cin >> frameCount;
    cout << "\nPage\tFrames\n";
    for (int i = 0; i < pageCount; i++) {
        int page = pages[i];
        bool pageFound = false;
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == page || frames[j] == -1) {
                if(frames[j] == -1){
                    frames[j] = page;
                    pageFaults++;
                }
                pageFound = true;
                break;
            }
        }
        if (!pageFound) {
            int replaceIndex = 0;
            int leastRecentlyUsed = INT_MIN;
            int j = i - 1;
            for (int k = 0; k < frameCount; k++) {
                int m = j;
                while (pages[m] != frames[k]) {
                    m--;
                }
                if(leastRecentlyUsed<i - m){
                    leastRecentlyUsed=i-m;
                    replaceIndex=k;
                }
            }
            frames[replaceIndex] = page;
            pageFaults++;
        }
        cout << page << "\t";
        for (int j = 0; j < frameCount; j++)
            cout << frames[j] << "\t";
        cout << endl;
    }
    cout << "\nThe number of page faults is " << pageFaults << endl;
    return 0;
}
