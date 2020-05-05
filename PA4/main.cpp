#include <string>
#include <regex>

#include "HashTable.hpp"
#include "CSVEditor.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    regex expr(".*,.*,(.*),(.*)");
	
    string inputPath = "./input.csv";
    string rosterPath = "./roster.csv";
    string outputPath = "./output.csv";
	
	int m = 0; 
	
	
    cout << "Number of students in roster: ";
    cin >> m;

    CSVEditor editor(inputPath, rosterPath, outputPath, expr, m);
    editor.readCSVToTable();
    cout << "Survived read" << endl;
    editor.writeCSVToFile();
	cout << "Survived write" << endl;
	
    tuple<int, int, double> stats = editor.getStats();
	cout << "Survived tuple" << endl;
    
	cout << "minimum chain len = " << get<0>(stats) << endl;
	cout << "maximum chain len = " << get<1>(stats) << endl;
	cout << "average chain len = " << std::get<2>(stats) << endl;
	
    return 0;    
}
