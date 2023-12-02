#include <ctype.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string line;
ifstream input;

vector<string> getFullInput() {

  vector<string> a;

  input.open("input.txt");

  if (input.is_open()) {

    while (getline(input, line)) {
      a.push_back(line);
    }
  }
  input.close();
  return a;
}

vector<string> getTestInput() {
  vector<string> a;

  input.open("input.txt");
  for (int i = 0; i < 10; i++) {

    getline(input, line);
    a.push_back(line);
  }
  input.close();
  return a;
}

int numberParseAndSum(vector<string> a) {
  
  int sum = 0; 
  int val1 = 0;
  int val2 = 0;


  for (string line : a) {

    int i = 0;
    while (!isdigit(line[i])) {
      i++;
    }

    val1 = line[i] - '0';

    i = line.length() - 1;
    while (!isdigit(line[i])) {
      i--;
    }
    val2 = line[i] - '0';

    sum = sum + val1 * 10;
    sum = sum + val2;
    
  }
  return sum;
}

int main() {

  // vector<string> testInput;
  // testInput = getTestInput();
  // numberParseAndSum(testInput);
  
  vector<string> fullInput;
  fullInput = getFullInput();

  int sum = numberParseAndSum(fullInput);
  cout << sum; 


  return 0;
}
