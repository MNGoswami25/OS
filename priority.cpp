#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Process {
    int pno;
    int pri;
    int btime;
    int wtime;
};
int main() {
    int n;
    int tbm = 0, totwtime = 0, totttime = 0;
    cout << "\n PRIORITY SCHEDULING.\n";
    cout << "\n Enter the number of processes: ";
    cin >> n;
    vector<Process> processes(n);
    cout << "Enter the burst time and priority:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> processes[i].btime >> processes[i].pri;
        processes[i].pno = i + 1;
        processes[i].wtime = 0;
    }
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.pri < b.pri;
    });
    cout << "\n Process\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        processes[i].wtime = tbm;  // Update waiting time for the current process

        totwtime += processes[i].wtime;
        tbm += processes[i].btime;

        cout << processes[i].pno << "\t\t" << processes[i].btime << "\t\t" 
             << processes[i].wtime << "\t\t" << processes[i].wtime + processes[i].btime << endl;
    }
    totttime = tbm;  // Total turnaround time is the completion time of the last process
    cout << "\n Total Waiting Time: " << totwtime;
    cout << "\n Average Waiting Time: " << (float)totwtime / n;
    cout << "\n Total Turnaround Time: " << totttime;
    cout << "\n Average Turnaround Time: " << (float)totttime / n;

    return 0;
}
