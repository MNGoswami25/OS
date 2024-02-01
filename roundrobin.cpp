#include <iostream>
#include <queue>
using namespace std;
struct Process
{
    int pno, btime, sbtime, wtime, lst;
};
void roundRobinScheduling(Process p[], int n, int ts)
{
    queue<int> q;
    int pp = -1, ptm = 0, count, twt = 0, totttime = 0;

    for (int i = 0; i < n; i++)
    {
        p[i].sbtime = p[i].btime;
        p[i].wtime = p[i].lst = 0;
        q.push(i);
    }
    cout << "Scheduling....\n";
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        count = p[i].btime;
        count = (count >= ts) ? ts : count;
        cout << "Process " << p[i].pno << " from " << ptm;
        ptm += count;
        cout << " to " << ptm << endl;
        p[i].btime -= count;
        if (pp != i)
        {
            pp = i;
            p[i].wtime += ptm - p[i].lst - count;
            p[i].lst = ptm;
        }
        if (p[i].btime > 0)
            q.push(i);
        else
        {
            twt += p[i].wtime;
            totttime += ptm;
        }
    }
    cout << "\nTotal Waiting Time: " << twt << endl;
    cout << "Average Waiting Time: " << static_cast<float>(twt) / n << endl;
    cout << "Total Turnaround Time: " << totttime << endl;
    cout << "Average Turnaround Time: " << static_cast<float>(totttime) / n << endl;
}
int main()
{
    int n, ts;
    cout << "\nRound Robin Scheduling............";
    cout << "\nEnter the number of processes: ";
    cin >> n;
    cout << "Enter the time slice: ";
    cin >> ts;
    Process p[n];
    cout << "Enter the burst time:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Process " << i + 1 << ": ";
        cin >> p[i].btime;
        p[i].pno = i + 1;
    }
    roundRobinScheduling(p, n, ts);
    return 0;
}
