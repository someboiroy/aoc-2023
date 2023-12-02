#include <ctype.h>
#include <fstream>
#include <iostream>
#include <map>
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

string numCheck(map<string, int> a, string b) {

  for (const auto &pair : a) {
    if (b.find(pair.first) != std::string::npos) {
      return pair.first;
    }
  }
  return "";
}

int numberParseAndSum(vector<string> a) {

  int sum = 0;
  int val1 = 0;
  int val2 = 0;
  map<string, int> mp;

  mp["one"] = 1;
  mp["two"] = 2;
  mp["three"] = 3;
  mp["four"] = 4;
  mp["five"] = 5;
  mp["six"] = 6;
  mp["seven"] = 7;
  mp["eight"] = 8;
  mp["nine"] = 9;

  for (string line : a) {

    int i = 0;
    string temp = "";
    string maybeWord = "";

    while (!isdigit(line[i]) && maybeWord.empty()) {

      temp = temp + line[i];

      maybeWord = numCheck(mp, temp);

      if (maybeWord.empty()) {
        i++;
      }
    }

    if (isdigit(line[i])) {
      val1 = line[i] - '0';

    } else {
      val1 = mp[maybeWord];
    }

    i = line.length() - 1;
    temp = "";
    maybeWord = "";

    while (!isdigit(line[i]) && maybeWord.empty()) {
      temp = temp + line[i];

      string reversedTemp(temp.rbegin(), temp.rend());
      maybeWord = numCheck(mp, reversedTemp);

      if (maybeWord.empty()) {
        i--;
      }
    }

    if (isdigit(line[i])) {
      val2 = line[i] - '0';

    } else {
      val2 = mp[maybeWord];
    }

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
