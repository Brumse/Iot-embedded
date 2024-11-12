#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>

class YamlParser {
public:
    //konstruktor
    YamlParser(const std::string& filename) {
        //kolla om det går att öppna filen
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Failed open file: " << filename << std::endl;
            exit(0);
        }
        //skapa variabler
        std::string line;
        std::string currentKey;

        while (std::getline(file, line)) {
            // hoppa över komentarer och tomma rader
            if (line.empty() || line[0] == '#') continue;

            //ta bort "tabbar"
            size_t start = line.find_first_not_of(" \t");
            line = line.substr(start);

            //hanterar listan där raden börjar på -
            if (line[0] == '-') {
                    data[currentKey].push_back(line.substr(1));
            } else {
                //hanterar key-value paren dvs rader med :
                size_t colonPos = line.find(':');
                if (colonPos != std::string::npos) {
                    std::string key = line.substr(0, colonPos);
                    std::string value = line.substr(colonPos + 1);

                    //tar bort mellanrum från value
                    size_t valueStart = value.find_first_not_of(" \t");
                    if (valueStart != std::string::npos) {
                        value = value.substr(valueStart);
                    }

                    //uppdaterar currentKey och lagrar värdet
                    currentKey = key;
                    if (!value.empty() && value[0] != '-') {
                        data[currentKey] = { value };
                    }
                }
            }
        }
    }

    //hämtar första value som en sträng för angiven key
    std::string getString(const std::string& key) const {
        auto it = data.find(key);
        if (it != data.end() && !it->second.empty()) {
            return it->second[0];
        }
        return "";
    }

    //hämtar alla värden från key listan 
    std::vector<std::string> getList(const std::string& key) const {
        auto it = data.find(key);
        if (it != data.end()) {
            return it->second;
        }
        return {};
    }
        //bool för om personen är gift
        bool getBool(const std::string& key) const {
        auto it = data.find(key);
        if (it != data.end() && !it->second.empty()) {
            // Konvertera till bool
            return it->second[0] == "true"||it->second[0]=="yes"; 
        }
        return false;
    }

private:
    std::unordered_map<std::string, std::vector<std::string>> data;
};

int main() {
    //Skapa parseobjekt och läs in filen
    YamlParser parser("file.yml");

    // Hämta data
    std::string name = parser.getString("name");
    std::string age = parser.getString("age");
    bool isMarried = parser.getBool("isMarried");
    bool hasCar = parser.getBool("hasCar");
    std::vector<std::string> items = parser.getList("items");

    // Skriv ut värden
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Is married: " <<std::boolalpha<< isMarried << std::endl;
    std::cout << name <<" has a car: " <<std::boolalpha<< hasCar << std::endl;
    std::cout << "Items:" << std::endl;
    for (const auto& item : items) {
        std::cout << "- " << item << std::endl;
    }

    return 0;
}
