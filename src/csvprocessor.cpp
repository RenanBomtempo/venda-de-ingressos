#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

typedef std::vector<std::vector<std::string>> string_table;
typedef std::vector<std::string>string_vector;

string_vector SplitStringWithDelim (const std::string str, const char delim) {
    // Convert string to a stream to allow the use of the getline() function
    std::stringstream str_stream(str);

    // Vector containing string tokens
    string_vector splitted_str;
    std::string token;

    while (getline(str_stream, token, delim)) 
        splitted_str.push_back(token);
    
    return splitted_str;
}

void PrintStringTable (string_table str_tb) {
    int i=0;
    for (auto l : str_tb) {
        std::cout << "Line " << "[" << i++ << "] - ";

        for (auto s : l)
            std::cout << "\'" << s << "\' ";
        
        std::cout << "\n";
    }
}

string_table CSVtoStringTable (std::string file_name) {
    // Open CSV file
    std::ifstream csv_file(file_name);
    if (!csv_file.is_open()) {
        perror("Could not open file");
        exit(0);
    }

    // 2D vector of strings with all CSV data.
    // Exemple for getting string:[1][3] -> 4th string of the 1st line.
    string_table str_table;

    // Data of a single line broken into tokens (strings)
    string_vector data_record;

    // Read each line
    std::string line;
    while(getline(csv_file, line)) {
        // Split string into tokens
        data_record = SplitStringWithDelim(line, ',');

        // Store splitted string in the string table
        str_table.push_back(data_record);
    }

    csv_file.close();

    return str_table;
}
