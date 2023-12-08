all: quicksort inputfilegenerator averagetime

Patel_Yesha_QuickSort: Patel_Yesha_QuickSort.cpp
	g++ -o Patel_Yesha_QuickSort Patel_Yesha_QuickSort.cpp -std=c++17 -Wall

Patel_Yesha_InputFileGenerator: Patel_Yesha_InputFileGenerator.cpp
	g++ -o Patel_Yesha_InputFileGenerator Patel_Yesha_InputFileGenerator.cpp -std=c++17 -Wall

Patel_Yesha_AverageTime: Patel_Yesha_AverageTime.cpp
	g++ -o Patel_Yesha_AverageTime Patel_Yesha_AverageTime.cpp -std=c++17 -Wall

clean:
	rm -f Patel_Yesha_QuickSort Patel_Yesha_InputFileGenerator Patel_Yesha_AverageTime
