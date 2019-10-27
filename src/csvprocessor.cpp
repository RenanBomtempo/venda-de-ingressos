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
        // Dados gerais
        std::string nome = u[uNOME];
        int id = stoi(u[uID]);
        int idade = stoi(u[uIDADE]);
        float saldo = stof(u[uSALDO]); 

        // Dados especificos
        if (u[uCATEG] == "adulto") {
            Adulto *a = new Adulto(id, nome, idade, saldo);
            usuarios.push_back(dynamic_cast<Usuario*>(a));
        }
        else if (u[uCATEG] == "idoso") {
            Idoso *i = new Idoso(id, nome, idade, saldo);
            usuarios.push_back(dynamic_cast<Usuario*>(i));
        }
        else if (u[uCATEG] == "criança" || u[uCATEG] == "crianca" ) {
            int responsavel;
            responsavel = stoi(u[uRESPONSAVEL]);

            Crianca *c = new Crianca(id, nome, idade, saldo, (Adulto*)(usuarios[responsavel]));
            usuarios.push_back(dynamic_cast<Usuario*>(c));
        }
    }

    return usuarios;
}

std::vector<Evento*> LerEventos (const string_table table, const std::vector<Usuario*> usuarios) {
    std::vector<Evento*> eventos;
    
    for (string_vector ev : table) {
        if (ev[1] == "cinema") {
            // Dados cinema
            int id = stoi(ev[eID]);
            int num_tipos = stoi(ev[eNUMTIPO-1]);
            int duracao = stoi(ev[ev.size()-1]);
            std::string nome = ev[eNOME-1];
            Usuario *dono = usuarios[stoi(ev[eDONO-1])];

            std::vector<int> capacidades;
            std::vector<int> precos;
            for (int i = 0; i < num_tipos; i++) {
                capacidades.push_back(stoi(ev[eCAP1-1 + (2*i)]));
                precos.push_back(stoi(ev[ePRE1-1 + (2*i)]));
            }

            std::vector<int> horarios;
            for (u_int i = 7 + (2*num_tipos); i < ev.size()-1; i++)
                horarios.push_back(stoi(ev[i]));

            // Add to vector of Eventos
            Cinema *c = new Cinema(id, nome, dono, capacidades, precos, duracao, horarios);
            eventos.push_back(dynamic_cast<Evento*>(c));
        } else {
            // Dados gerais
            int id = stoi(ev[eID]);
            int num_tipos = stoi(ev[eNUMTIPO]);
            std::string categoria = ev[eCATEG];
            std::string sub_categoria = ev[eSUBCATEG];
            std::string nome = ev[eNOME];
            Usuario *dono = usuarios[stoi(ev[eDONO])];
            
            std::vector<int> capacidades;
            std::vector<int> precos;
            for (int i = 0; i < num_tipos; i++) {
                capacidades.push_back(stoi(ev[eCAP1 + (2*i)]));
                precos.push_back(stoi(ev[ePRE1 + (2*i)]));
            }

            // Dados especificos
            if (categoria == "adulto") {
                int quota_idoso = stoi(ev[6 + (2*num_tipos)]);

                if (sub_categoria == "boate") {
                    int inicio = stoi(ev[ev.size() - 2]);
                    int fim = stoi(ev[ev.size() - 1]);

                    // Add to vector of Eventos
                    Boate *b = new Boate(id, nome, dono, capacidades, precos, quota_idoso, inicio, fim);
                    eventos.push_back(dynamic_cast<Evento*>(b));
                }
                else if (sub_categoria == "show") {
                    int abertura = stoi(ev[7 + (2*num_tipos)]);

                    std::vector<std::string> artistas;
                    for (u_int i = 8 + (2*num_tipos); i < ev.size(); i++)
                        artistas.push_back(ev[i]);

                    // Add to vector of Eventos
                    Show *s = new Show(id, nome, dono, capacidades, precos, quota_idoso, abertura, artistas);
                    eventos.push_back(dynamic_cast<Evento*>(s));
                }
            }
            else if (categoria == "infantil") {
                std::vector<int> horarios;
                for (u_int i = 6 + (2*num_tipos); i < ev.size(); i++)
                    horarios.push_back(stoi(ev[i]));

                // Add to vector of Eventos
                TeatroFantoche *t = new TeatroFantoche(id, nome, dono, capacidades, precos, horarios);
                eventos.push_back(dynamic_cast<Evento*>(t));
            }
        }
    }

    return eventos;
}
