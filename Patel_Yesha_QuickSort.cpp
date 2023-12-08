/**
 * @file Patel_Yesha_QuickSort.cpp
 * @author Yesha Patel (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

 #include <iostream>
 #include <fstream> // ofstream, ifstream
 #include <vector> 
 #include <chrono>  // for std::chorno
 #include <iomanip> // used for setprecision

 using std::cout;
 using std::endl;
 using std::vector;

 int medianOfThree(vector<float>& arr, int start, int end) {
    int middle = (start + end)/ 2;

    // checks the arr[start], arr[middle], arr[end]
    if (arr[start] > arr[middle]) {
        std::swap(arr[start], arr[middle]);
    }
    if (arr[middle] > arr[end]) {
        std::swap(arr[middle], arr[end]);
    }
    if (arr[start] > arr[middle]) {
        std::swap(arr[start], arr[middle]);
    }
    return middle;
 }

 int parition(vector<float>& arr, int start, int end) {
     int pivotIndex = medianOfThree(arr, start, end); // giving the pivot correct element
     std::swap(arr[start], arr[pivotIndex]); // this will the pivot and start element

     float pivot = arr[start];
     int count = start + 1;
     for (int i = start + 1; i <= end; i++) {
         if (arr[i] < pivot) {
             std::swap(arr[count], arr[i]);
             count++;
         }
     }

     int pFinal = count - 1;
     std::swap(arr[start], arr[pFinal]);

     return pFinal;
 }
 void quickSort(vector<float>& arr, int start, int end) {
     // base case
     if (start < end) {
         int _p = parition(arr, start, end); // parition the values

         // quicksort the left values
         quickSort(arr, start, _p - 1);

         //quicksort right values
         quickSort(arr, _p + 1, end);
         }
     }

     

 int main(int argc, char* argv[]) {
     if (argc != 3) {
        std::cerr << "Error in reading: " << argv[0] << " <input_file> <output_file>" << endl;
        return 1;
    }

     vector<float>arr;

     // inputfile 
     std::ifstream inputFile(argv[1]);
     

     // to check if the file is open
     if (!inputFile.is_open()) {
         std::cerr << "Error in opening input file: " << argv[1] << endl;
         return 1;
     }

     float num;
    
     // read the input file
     while (inputFile >> num) {
         arr.push_back(num);
     }

    // creates the output stream
     std::ofstream outputFile(argv[2]);

     if (!outputFile.is_open()) {
     std::cerr << "Error in opening output file" << argv[2] << endl;
     return 1;
     }
     // record the start time
     auto start = std::chrono::high_resolution_clock::now();
     // perform quick sort
     quickSort(arr, 0, arr.size()-1);

     // record the stop time
     auto stop = std::chrono::high_resolution_clock::now();
     auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
     double dT = static_cast<double>(duration);

     // write the sorted float nums to the output file
     for (float& numbers : arr) {
         outputFile << numbers << " ";
     }
     outputFile.close(); 
     // display the sort time
     // cout << "Execution Time: " << duration.count() << " microseconds" << endl;

     std::ofstream executionFile("Patel_Yesha_executionTime.txt", std::ios_base::app);
     executionFile << std::noshowpos << arr.size() << "\t\t\t\t" <<  std::scientific << std::setprecision(2) << dT<<"\n";
     executionFile.close();

     // close the file
     inputFile.close();
     

     cout << "Sorting is done!" << endl;

     return 0;
 }