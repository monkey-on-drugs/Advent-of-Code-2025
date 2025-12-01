#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int p1(){
    std::ifstream inputFile("day1_p1.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return -1; // Indicate an error
    }

    std::string line;
    char direction; long int distance, counter = 0;
    int position = 50; 
    while (std::getline(inputFile, line)) {
        direction = line[0];
        distance = std::stoi(line.substr(1));
        distance %= 100;
        if(direction == 'L'){
            position += (100 - distance);
            position %= 100;
        }
        else if(direction == 'R'){
            position += distance;
            position %= 100;
        }
        else return -1;
        if(position == 0) counter++;
    }
    inputFile.close();
    cout << "The answer is: " << counter << endl;
    return 0;
}

int p2(){
    std::ifstream inputFile("day1_p1.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return -1; // Indicate an error
    }

    std::string line;
    char direction; long int distance, counter = 0;
    int position = 50; 
    while (std::getline(inputFile, line)) {
        direction = line[0];
        distance = std::stoi(line.substr(1));
        if(direction == 'L'){
            int prev_position = position;
            counter += (distance / 100); distance %= 100;
            position += (100 - distance);
            if(position <= 100 && prev_position != 0) counter++;
            position = (position % 100);
        }
        else if(direction == 'R'){
            position += distance;
            if(position >= 100) counter += (position / 100);
            position %= 100;
        }
        else return -1;
    }
    inputFile.close();
    cout << "The answer is: " << counter << endl;
    return 0;
}

int main(){
    cout << p1() << endl;
    cout << p2() << endl;
    return 0;
}