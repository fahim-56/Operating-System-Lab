#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Define a structure to hold process details
struct Process
{
    int id;         // Process ID
    int arrival;    // Arrival time
    int burst;      // Burst time (CPU time required)
    int start;      // Start time of execution
    int finish;     // Finish time of execution
    int waiting;    // Waiting time
    int turnaround; // Turnaround time
};

// FCFS scheduling algorithm
void fcfsScheduling(vector<Process>& processes)
{
    int time = 0; // Track the current time of the CPU

    // Calculate start time, finish time, and waiting time for each process
    for (int i = 0; i < processes.size(); i++)
    {
        // Process starts only after it arrives
        if (time < processes[i].arrival)
        {
            time = processes[i].arrival;
        }

        // Calculate start time and finish time
        processes[i].start = time;
        processes[i].finish = time + processes[i].burst;

        // Calculate waiting time and turnaround time
        processes[i].waiting = processes[i].start - processes[i].arrival;
        processes[i].turnaround = processes[i].finish - processes[i].arrival;

        // Update the current time
        time = processes[i].finish;
    }
}

// Print the results
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

    // Calculate and display average waiting time and turnaround time
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
    // Define the processes (id, arrival time, burst time)
    vector<Process> processes =
    {
        {1, 0, 5, 0, 0, 0, 0},  // Process 1: Arrival = 0, Burst = 5
        {2, 1, 3, 0, 0, 0, 0},  // Process 2: Arrival = 1, Burst = 3
        {3, 2, 8, 0, 0, 0, 0},  // Process 3: Arrival = 2, Burst = 8
        {4, 3, 6, 0, 0, 0, 0},  // Process 4: Arrival = 3, Burst = 6
    };

    // Call FCFS scheduling function
    fcfsScheduling(processes);

    // Print the results
    printResults(processes);

    return 0;
}
