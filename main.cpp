#include <iostream>
#include <cmath>
#include <sstream>
#include "functions.h"
using namespace std;

bool setBit(int& number, int order) {
    if (order < 0 || order > 31) {
        return false;
    }
    int bitToSet = 1 << order;
    number |= bitToSet;
    return true;
}

int countBits(int number) {
    int count = 0;
    while (number > 0) {
        if (number & 1) {
            count++;
        }
        number >>= 1;
    }
    return count;
}

double mean(double array[], int numElements) {
    if (numElements == 0) {
        return NAN;
    }

    double sum = 0.0;
    for (int i = 0; i < numElements; ++i) {
        sum += array[i];
    }

    return sum / static_cast<double>(numElements);
}

double stddev(double array[], int numElements) {
    if (numElements == 0) {
        return NAN;
    }

    double mean = 0.0;
    for (int i = 0; i < numElements; ++i) {
        mean += array[i];
    }
    mean /= static_cast<double>(numElements);


    double variance = 0.0;
    for (int i = 0; i < numElements; ++i) {
        double diff = array[i] - mean;
        variance += diff * diff;
    }
    variance /= static_cast<double>(numElements);

    return sqrt(variance);
}

const int MAX_SIZE = 100;

std::pair<double, double> findMaxTwo(double numbers[], int numElements) {
    std::pair<double, double> result;

    if (numElements == 0) {
        result.first = result.second = std::nan("");
    } else if (numElements == 1) {
        result.first = result.second = numbers[0];
    } else {
        double max1 = std::max(numbers[0], numbers[1]);
        double max2 = std::min(numbers[0], numbers[1]);

        for (int i = 2; i < numElements; ++i) {
            if (numbers[i] > max1) {
                max2 = max1;
                max1 = numbers[i];
            } else if (numbers[i] > max2) {
                max2 = numbers[i];
            }
        }

        result.first = max1;
        result.second = max2;
    }

    return result;
}

int countWords(std::string text) {
    std::istringstream stream(text);
    std::string word;
    int wordCount = 0;

    while (stream >> word) {
        wordCount++;
    }

    return wordCount;
}

std::string code(std::string text) {
    for (char &c : text) {
        if (isalpha(c)) { // Csak betűket kezelünk
            if (c == 'z') {
                c = 'a'; // 'z' esetén visszaállunk 'a'-ra (ciklikusan)
            } else if (c == 'Z') {
                c = 'A'; // 'Z' esetén visszaállunk 'A'-ra (ciklikusan)
            } else {
                c++; // Minden más betűt átugrunk a következőre az ábécében
            }
        }
    }
    return text;
}

std::string decode(std::string text) {
    for (char &c : text) {
        if (isalpha(c)) {
            if (c == 'a') {
                c = 'z';
            } else if (c == 'A') {
                c = 'Z';
            } else {
                c--;
            }
        }
    }
    return text;
}

#include <cctype>

std::string capitalizeWords(std::string text) {
    bool newWord = true; // Jelzi, hogy új szó kezdődik
    for (char &c : text) {
        if (isalpha(c)) {
            if (newWord) {
                c = toupper(c); // Az első karakter nagybetű
                newWord = false;
            } else {
                c = tolower(c); // A többi karakter kisbetű
            }
        } else {
            newWord = true; // Nem betű karakter, új szó kezdődik
        }
    }
    return text;
}

int main(){
    //cout<<"Hello"<<endl;
    ///1. FELADAT
    /*for (int i = 0; i <= 127; i++) {
        int bitCount = countBits(i);
        std::cout << "Szam: " << i << ", Egyes bitek szama: " << bitCount << std::endl;
    }*/

    ///2.FELADAT
   /* for (int i = 0; i < 35; ++i) {
        int n = 0;
        if(setBit(n, i)){
            cout<<i<<" ---> " << n <<endl;
        }else{
            cout<<"Impossible operation!" << endl;
        }
    }*/

    ///3.FELADAT
    /*double numbers[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int numElements = sizeof(numbers) / sizeof(numbers[0]);

    double average = mean(numbers, numElements);

    if (std::isnan(average)) {
        std::cout << "A tomb ures, az atlag nem ertelmezheto." << std::endl;
    } else {
        std::cout << "A tomb atlaga: " << average << std::endl;
    }*/

    ///4.FELADAT
    /*double numbers[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int numElements = sizeof(numbers) / sizeof(numbers[0]);

    double standardDeviation = stddev(numbers, numElements);

    if (std::isnan(standardDeviation)) {
        std::cout << "A tomb ures, a szoras nem ertelmezheto." << std::endl;
    } else {
        std::cout << "A tomb szorasa: " << standardDeviation << std::endl;
    }*/

    ///5.FELADAT
    /*   double numbers[] = {3.0, 1.0, 5.0, 2.0, 4.0};
    int numElements = sizeof(numbers) / sizeof(numbers[0]);

    std::pair<double, double> maxTwo = findMaxTwo(numbers, numElements);

    if (std::isnan(maxTwo.first) || std::isnan(maxTwo.second)) {
        std::cout << "A tomb ures, vagy csak egy elemet tartalmaz." << std::endl;
    } else {
        std::cout << "A ket legnagyobb elem: " << maxTwo.first << " es " << maxTwo.second << std::endl;
    }*/

    ///KARAKTERLANCOK
    ///1.FELADAT
    /*int main(int argc, char *argv[]) {
    double sum = 0.0;

    for (int i = 1; i < argc; ++i) {
        std::istringstream inputstream(argv[i]);
        double number;

        if (inputstream >> number) {
            sum += number;
        }
    }

    std::cout << "Az osszeg: " << sum << std::endl;

    return 0;
}*/

    ///2.FELADAT
    /*std::string text = "Ez egy pelda szoveg a szavak szamanak megszamolasara.";
    int numWords = countWords(text);

    std::cout << "A szovegben talalhato szavak szama: " << numWords << std::endl;*/

    ///3.FELADAT
   /* std::string text = "Hello, World! 123";
    std::string codedText = code(text);
    std::cout << "Kodolt szoveg: " << codedText << std::endl;

    std::string decodedText = decode(codedText);
    std::cout << "Dekodolt szoveg: " << decodedText << std::endl;*/

    ///4.FELADAT
    /*std::string line;
    while (std::getline(std::cin, line)) {
        std::string capitalizedLine = capitalizeWords(line);
        std::cout << capitalizedLine << std::endl;
    }*/

    return 0;
}

/*
#include <iostream>
int main(){
    std::cout<<"Hello"<<std::endl;
    return 0;
}*/
