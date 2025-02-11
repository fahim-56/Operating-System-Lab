//Time Scheduling

#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Process
{
    int id;
    int arrival;
    int burst;
    int start;
    int finish;
    int waiting;
    int turnaround;
};

void fcfsScheduling(vector<Process>& processes)
{
    int time = 0;

    for (int i = 0; i < processes.size(); i++)
    {
        if (time < processes[i].arrival)
        {
            time = processes[i].arrival;
        }

        processes[i].start = time;
        processes[i].finish = time + processes[i].burst;

        processes[i].waiting = processes[i].start - processes[i].arrival;
        processes[i].turnaround = processes[i].finish - processes[i].arrival;

        time = processes[i].finish;
    }
}

void printResults(const vector<Process>& processes)
{
    cout << "Process ID | Arrival Time | Burst Time | Start Time | Finish Time | Waiting Time | Turnaround Time\n";
    cout << "----------------------------------------------------------------------------------------------\n";
    for (const auto& p : processes)
    {
        cout << p.id << "           | " << p.arrival << "            | " << p.burst << "          | "
             << p.start << "            | " << p.finish << "           | " << p.waiting << "            | "
             << p.turnaround << "\n";
    }

    double totalWaiting = 0, totalTurnaround = 0;
    for (const auto& p : processes)
    {
        totalWaiting += p.waiting;
        totalTurnaround += p.turnaround;
    }

    cout << "\nAverage Waiting Time: " << totalWaiting / processes.size() << endl;
    cout << "Average Turnaround Time: " << totalTurnaround / processes.size() << endl;
}

int main()
{
    vector<Process> processes =
    {
        {1, 0, 5, 0, 0, 0, 0},  
        {2, 1, 3, 0, 0, 0, 0},  
        {3, 2, 8, 0, 0, 0, 0},  
        {4, 3, 6, 0, 0, 0, 0},  
    };

    fcfsScheduling(processes);

    printResults(processes);

    return 0;
}
