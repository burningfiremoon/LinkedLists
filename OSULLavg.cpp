#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "OSULL.h"
#include "OSLL.h"


using namespace std;

static const int NUMS_OF_VALUES = 100000;

// Function to measure the average find speed
int measure_average_find_speed(OSLL<int> dll, OSULL<int,20> ull, int trials) {
    double total_time_dll = 0;
    double total_time_ull = 0;
    srand(time(nullptr));

    for (int i = 0; i < trials; ++i) {
        int target = rand() % NUMS_OF_VALUES + 1;

        clock_t start_time = clock();
        bool found_dll = dll.find(target);
        clock_t end_time = clock();
        total_time_dll += (double)(end_time - start_time) / CLOCKS_PER_SEC;

        start_time = clock();
        bool found_ull = ull.find(target);
        end_time = clock();
        total_time_ull += (double)(end_time - start_time) / CLOCKS_PER_SEC;

        if (!found_dll || !found_ull) {
            cout << "Value " << target << " not found." << endl;
            return -1; // Error
        }
    }

    // Save results to a text file
    ofstream outFile("find_speed_results.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "Doubly Linked List Average Find Speed: " << total_time_dll/trials << " seconds\n";
        outFile << "Unrolled Linked List Average Find Speed: " << total_time_ull/trials << " seconds\n";
        outFile << "The difference between the averages: " << total_time_dll/trials - total_time_ull/trials << " seconds\n";
        outFile << endl;
        outFile.close();
        cout << "Results appended to find_speed_results.txt" << endl;
    } else {
        cerr << "Unable to open file." << endl;
    }


    return 0;
}

int main() {
    const int trials = 100000;

    // Initialize Doubly Linked List
    OSLL<int> dll;
    for (int i = 1; i <= NUMS_OF_VALUES; ++i) {
        dll.insert(i);
    }
    cout << "initialization complete" << endl;

    // Initialize Unrolled Linked List
    OSULL<int,20> ull; // Example node capacity, adjust as needed
    for (int i = 1; i <= NUMS_OF_VALUES; ++i) {
        ull.insert(i);
    }

    cout << "initialization complete" << endl; 
    // Measure average find speed for both lists
    int average_time_dll, average_time_ull;
    average_time_dll, average_time_ull = measure_average_find_speed(dll, ull, trials);

    return 0;
}