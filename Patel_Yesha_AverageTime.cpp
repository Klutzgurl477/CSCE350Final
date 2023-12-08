/**
 * @file Patel_Yesha_AverageTime.cpp
 * @author Patel Yesha (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
 #include <iostream>
 #include <fstream>
 #include <unordered_map>
 #include <iomanip>

 using std::cout;
 using std::endl;

 int main(int argc, char* argv[]) {

     std::ifstream executionFile("Patel_Yesha_executionTime.txt", std::ios_base::app);

     if(!executionFile.is_open()) {
        std::cerr << "Error in opening Patel_Yesha_executionTime.txt" << endl;
        return 1;
     }
     std::unordered_map<int, double> executionSize;
     std::unordered_map<int, int> executionTime;
     int size;
     double time;

     // Read input sizes and execution times from the execution file
     while (executionFile >> size >> time) {
        executionSize[size] += time;
        executionTime[size]++;
     }

     executionFile.close();

     // calculating the average time
     std::ofstream averageExecutionTimeFile("Patel_Yesha_averageExecutionTime.txt");
     if(!averageExecutionTimeFile.is_open()) {
         std::cerr << "Error in opening averageExecutionTime.txt" << endl;
         return 1;
     }
     // calculates the average time and writes it to the averageExecutionTime.txt
     for (const auto& finalSizes : executionSize) {
        int inputSize = finalSizes.first;
        double averageTime = finalSizes.second / executionTime[size];
        averageExecutionTimeFile << std::noshowpos << inputSize << "\t\t\t\t" << std::scientific << std::setprecision(2) << averageTime << endl;
     }
    averageExecutionTimeFile.close();

     return 0;
 }