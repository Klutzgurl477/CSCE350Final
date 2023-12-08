/**
 * @file Patel_Yesha_InputFileGenerator.cpp
 * @author Yesha Patel (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

 #include <iostream>
 #include <fstream>
 #include <random>
 #include <ctime>

 using std::cin;
 using std::cout;
 using std::endl;

 int main() {
     std::random_device rd;
     std::mt19937 generator(rd());
     std::uniform_real_distribution<float> distribution(-100.0f, 100.0f);

     const int fileSize = 25;

     const int inputSize[] = {10,100,1000};

     for (int size : inputSize) {
         for (int fileNum = 1; fileNum <= fileSize; ++fileNum) {
             std::string fileName = "input_" +  std::to_string(size) + "_" +  std::to_string(fileNum) + ".txt";

             std::ofstream outputFile(fileName); // creates the read files

             if(!outputFile.is_open()){
                 std::cerr << "Error in reading the file: " << fileName << endl;
                 return 1;
             }

             // create random nums
             for (int i = 0; i < size; ++i) {
                 int randNum = distribution(generator);
                 outputFile << randNum << " \n";
             }
             // closing the file
             outputFile.close();

             cout << "file generated : " << fileName << endl;

         }
     }
     cout << "input file generated complete" << endl;
     return 0;
 }