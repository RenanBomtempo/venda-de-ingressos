#include "csvprocessor.h"

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

std::vector<Usuario*> LerUsuarios (const string_table table) {
    std::vector<Usuario*> usuarios;

    for (string_vector u : table) {
        // Pegar dados do usuario
        std::string nome;
        int id, idade;
        float saldo;
        std::stringstream ss;

        // ID
        ss.str(u[ID]);
        ss >> id;

        // Nome
        nome = u[NOME];

        // Idade
        ss.str(u[IDADE]);
        ss >> idade;

        // Saldo
        ss.str(u[SALDO]);
        ss >> saldo; 
        
        // Criar Objetos 
        if (u[CATEG] == "adulto") {
           Adulto *a = new Adulto(id, nome, idade, saldo);
           usuarios.push_back(dynamic_cast<Usuario*>(a));
        }
        else if (u[CATEG] == "idoso") {
            Idoso *i = new Idoso(id, nome, idade, saldo);
            usuarios.push_back(dynamic_cast<Usuario*>(i));
        }
        else if (u[CATEG] == "criança" || u[CATEG] == "crianca" ) {
            int responsavel;
            ss.str(u[RESPONSAVEL]);
            ss >> responsavel;

            Crianca *c = new Crianca(id, nome, idade, saldo, dynamic_cast<Adulto*>(usuarios[responsavel]));
            usuarios.push_back(dynamic_cast<Usuario*>(c));
        }
    }

    return usuarios;
}