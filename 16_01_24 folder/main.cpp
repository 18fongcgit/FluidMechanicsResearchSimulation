#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <chrono>

using namespace std;

int main()
{
    // Measure time for an if statement
    auto start_if = std::chrono::high_resolution_clock::now();
      int count = 0;

    for (int i = 0; i < INT_MAX; i++) {
        if (i % 2 == 0) {
            // Code inside the if statement
            count++;
        } 
        //  else if ( i % 3 == 0){

        // }
        // if ( i % 3 == 0){

        // }
    }
    auto stop_if = std::chrono::high_resolution_clock::now();
    auto duration_if = std::chrono::duration_cast<std::chrono::microseconds>(stop_if - start_if);
    std::cout << "Time taken by if statement: " << duration_if.count() / 1000<< " milliseconds\n";

    auto start_switch = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < INT_MAX; ++i) {
        switch (i % 2) {
            case 0:
                // Code inside the switch statement
                break;
            case 1:

                break;
            // You can add more cases if needed
        }
    }

    auto stop_switch = std::chrono::high_resolution_clock::now();
    auto duration_switch = std::chrono::duration_cast<std::chrono::microseconds>(stop_switch - start_switch);
    std::cout << "Time taken by switch statement: " << duration_switch.count()/1000 << " microseconds\n";


    

    // Measure time for a while loop
    auto start_while = std::chrono::high_resolution_clock::now();

    int j = 0;
    while (j < INT_MAX) {
        // Code inside the while loop
        j++;
    }

    auto stop_while = std::chrono::high_resolution_clock::now();
    auto duration_while = std::chrono::duration_cast<std::chrono::microseconds>(stop_while - start_while);
    std::cout << "Time taken by while loop: " << duration_while.count() / 1000 << " milliseconds\n";

    return 0;
}
