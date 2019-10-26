#ifndef CSV_PROCESSOR_H
#define CSV_PROCESSOR_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

typedef std::vector<std::vector<std::string>> string_table;
typedef std::vector<std::string>string_vector;

/* Takes a string 'str' and breaks it into tokens delimited by 'delim'.
 * It returns a vector<string>
 */
string_vector SplitStringWithDelim (const std::string str, const char delim);

/* This function simply prints the string table (2D vector of strings) to the terminal.
 */
void PrintStringTable (string_table str_tb);

/* Opens a text file (e.g. txt, CSV) and stores all data inside a string table (2D vector of strings).
 * Each line of the table corresponds to a line on the file and contains individual strings from that line. 
 */
string_table CSVtoStringTable (std::string file_name);

#endif//CSV_PROCESSOR_H