#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// A függvény, amely kiírja az átadott értékeket
void printValues(int col1, int col2, int col3, int col5, int col6,int arfcnDl) {
    std::cout << "1. oszlop: " << col1 << std::endl;
    std::cout << "2. oszlop: " << col2 << std::endl;
    std::cout << "3. oszlop: " << col3 << std::endl;
    std::cout << "4. oszlop: " << col5 << std::endl;
    std::cout << "5. oszlop: " << col6 << std::endl;

    double F_DL = col2 + 0.1 * (arfcnDl - col3);
    std::cout << "Downlink abszolut frekvencia: " << F_DL << " MHz" << std::endl;
    
}

int main() {
    std::string filename = "c:/1/data.txt"; // A fájl neve
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Nem sikerült megnyitni a fájlt: " << filename << std::endl;
        return 1;
    }

    int arfcnDl;
    std::cout << "Adja meg az arfcnDL erteket ";
    std::cin >> arfcnDl;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string token;
        int column = 0;
        int col1, col2, col3, col5, col6, col7;
        int lowerBound = -1, upperBound = -1;

        while (std::getline(ss, token, ',')) { // a , szeparátor és token értéke a szeparaált érték, végig megy a soron, a token egy átmenti változó és a szeparátor közötti értéket tárolja, a szeparátor a - jel most itt
            if (column == 0) {
                col1 = std::stoi(token); // átalakítja a token értékét számmá, mert ugye stringénk olvastuk be
            }
            else if (column == 1) {
                col2 = std::stoi(token);
            }
            else if (column == 2) {
                col3 = std::stoi(token);
            }
            else if (column == 3) {
                size_t dashPos = token.find('-'); // ha token pl 600-1199 a 3. oszlopban
                if (dashPos != std::string::npos) { // ha talált - jelet akkor nem egyenlõ
                    lowerBound = std::stoi(token.substr(0, dashPos)); // kimásolja a stringet a - jel poziciójáig
                    upperBound = std::stoi(token.substr(dashPos + 1)); // kimásolja a stringet a - jelet követõ karakter poziciójától a string - token - végéig
                }
            }
            else if (column == 4) {
                col5 = std::stoi(token);
            }
            else if (column == 5) {
                col6 = std::stoi(token);
            }            
            column++;
        }

        if (lowerBound != -1 && upperBound != -1 && arfcnDl >= lowerBound && arfcnDl <= upperBound) {
            printValues(col1, col2, col3, col5, col6, arfcnDl);
            break; // Ha megtaláltuk a megfelelõ tartományt, kiléphetünk a ciklusból
        }
    }

    file.close();
    return 0;
}
