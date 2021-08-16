//Matthew Bankson (mlb0126)
//project3_mlb0126.cpp
//How to compile: g++ project3_mlb0126.cpp

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

bool check_file(string);

vector<int> read_file(string);

void write_file(string, vector<int>);

vector<int> sort(vector<int>, vector<int>);

int main() {
//VARIABLES
   string file1;
   string file2;
   string file3;
   vector<int> numbers1;
   vector<int> numbers2;
   vector<int> numbers3;
   
   cout << "*** Welcome to Matthew's sorting program ***\n";
   
   do {
      cout << "Enter the first input file name: ";
      cin >> file1;
   } while (cin.fail() || !check_file(file1));
   numbers1 = read_file(file1);
   cout << "The list of " << numbers1.size() << " numbers in file "
      << file1 << " is:\n";
   for (int i = 0; i < numbers1.size(); i++) {
      cout << numbers1[i] << "\n";
   }
   
   do {
      cout << "\nEnter the second input file name: ";
      cin >> file2;
   } while (cin.fail() || !check_file(file2));
   numbers2 = read_file(file2);
   cout << "The list of " << numbers2.size() << " numbers in file "
      << file2 << " is:\n";
   for (int i = 0; i < numbers2.size(); i++) {
      cout << numbers2[i] << "\n";
   }
   
   numbers3 = sort(numbers1, numbers2);
   cout << "\nThe sorted list of " << numbers3.size() << " numbers is:";
   for (int i = 0; i < numbers3.size(); i++) {
      cout << " " << numbers3[i];
   }
   
   do {
      cout << "\nEnter the output file name: ";
      cin >> file3;
   } while (cin.fail());
   write_file(file3, numbers3);
   cout << "*** Please check the new file - " << file3 << " ***"
      << "\n*** Goodbye. ***";
   return 0;
}

bool check_file(string file) {
   ifstream stream;
   stream.open(file.c_str());
   if (stream.fail()) {
      return false;
   }
   stream.close();
   return true;
}

vector<int> read_file(string file) {
   ifstream stream;
   vector<int> v;
   int i;
   stream.open(file.c_str());
   while (stream >> i) {
      v.push_back(i);
   }
   stream.close();
   return v;
}

void write_file(string file, vector<int> v) {
   ofstream stream;
   stream.open(file.c_str());
   for (int i = 0; i < v.size(); i++) {
      stream << v[i] << "\n";
   }
   stream.close();
}

vector<int> sort(vector<int> v1, vector<int> v2) {
   vector<int> sorted;
   int i = 0;
   int j = 0;
   while (i < v1.size() && j < v2.size()) {
      if (v1[i] > v2[j]) {
         sorted.push_back(v2[j]);
         j++;
      }
      else if (v2[j] > v1[i]) {
         sorted.push_back(v1[i]);
         i++;
      }
      else {
         sorted.push_back(v1[i]);
         sorted.push_back(v2[j]);
         i++;
         j++;
      }
   }
   
   if (i < v1.size()) {
      while (i < v1.size()) {
         sorted.push_back(v1[i]);
         i++;
      }
   }
   
   if (j < v2.size()) {
      while (j < v2.size()) {
         sorted.push_back(v2[j]);
         j++;
      }
   }
   return sorted;
}
