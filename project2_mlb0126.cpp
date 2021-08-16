//Matthew Bankson (mlb0126)
//project2_mlb0126.cpp
//How to compile: g++ project2_mlb0126.cpp
//Received help from the handout given
//in class and from the questions asked
//on Piazza.

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
using namespace std;

//CONSTANTS
const int TOTAL_RUNS = 10000;
const int AARON_ACCURACY = 33;
const int BOB_ACCURACY = 50;

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
   return ((A_alive && B_alive) || (A_alive && C_alive) || (B_alive && C_alive));
}

void Aaron_shoots1(bool& B_alive, bool& C_alive) {
   assert(B_alive || C_alive);
   int shoot_target_result;
   if (C_alive == true) {
      shoot_target_result = rand()%100;
      if (shoot_target_result <= AARON_ACCURACY) {
         C_alive = false;
      }
   }
   else if (C_alive == false && B_alive == true) {
      shoot_target_result = rand()%100;
      if (shoot_target_result <= AARON_ACCURACY) {
         B_alive = false;
      }
   }
}

void Bob_shoots(bool& A_alive, bool& C_alive) {
   assert(A_alive || C_alive);
   int shoot_target_result;
   if (C_alive == true) {
      shoot_target_result = rand()%100;
      if (shoot_target_result <= BOB_ACCURACY) {
         C_alive = false;
      }
   }
   else if (C_alive == false && A_alive == true) {
      shoot_target_result = rand()%100;
      if (shoot_target_result <= BOB_ACCURACY) {
         A_alive = false;
      }
   }
}

void Charlie_shoots(bool& A_alive, bool& B_alive) {
   if (B_alive == true && A_alive == true) {
      B_alive = false;
   }
   else if (B_alive == false && A_alive == true) {
      A_alive = false;
   }
   else if (B_alive == true && A_alive == false) {
      B_alive = false;
   }
}

void Aaron_shoots2(bool& B_alive, bool& C_alive) {
   assert(B_alive || C_alive);
   if (B_alive == true && C_alive == true) {
      return;
   }
   int shoot_target_result;
   if (C_alive == true && B_alive == false) {
      shoot_target_result = rand()%100;
      if (shoot_target_result <= AARON_ACCURACY) {
         C_alive = false;
      }
   }
   else if (C_alive == false && B_alive == true) {
      shoot_target_result = rand()%100;
      if (shoot_target_result <= AARON_ACCURACY) {
         B_alive = false;
      }
   }
}

void Press_any_key(void) {
   cout << "Press Enter to contine...";
   cin.ignore().get();
}

void test_at_least_two_alive(void) {
   cout << "Unit Testing 1: Function - at_least_two_alive()\n";

   cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true));
   cout << "\tCase passed ...\n";

   cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true));
   cout << "\tCase passed ...\n";
   
   cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, false, true));
   cout << "\tCase passed ...\n";
   
   cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true, true, false));
   cout << "\tCase passed ...\n";
   
   cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(false, false, true));
   cout << "\tCase passed ...\n";
   
   cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
   assert(false == at_least_two_alive(false, true, false));
   cout << "\tCase passed ...\n";
   
   cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(true, false, false));
   cout << "\tCase passed ...\n";
   
   cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(false, false, false));
   cout << "\tCase passed ...\n";
}

void test_Aaron_shoots1(void) {
   cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
   
   bool bob_a = true;
   bool charlie_a = true;
   cout << "\tCase 1: Bob alive, Charlie alive\n"
      << "\t\tAaron is shooting at Charlie\n";
   Aaron_shoots1(bob_a, charlie_a);
   
   bob_a = false;
   charlie_a = true;
   cout << "\tCase 2: Bob dead, Charlie alive\n"
      << "\t\tAaron is shooting at Charlie\n";
   Aaron_shoots1(bob_a, charlie_a);
   
   bob_a = true;
   charlie_a = false;
   cout << "\tCase 3: Bob alive, Charlie dead\n"
      << "\t\tAaron is shooting at Bob\n";
   Aaron_shoots1(bob_a, charlie_a);
}

void test_Bob_shoots(void) {
   cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";

   bool aaron_a = true;
   bool charlie_a = true;
   cout << "\tCase 1: Aaron alive, Charlie alive\n"
      << "\t\tBob is shooting at Charlie\n";
   Bob_shoots(aaron_a, charlie_a);

   aaron_a = false;
   charlie_a = true;
   cout << "\tCase 2: Aaron dead, Charlie alive\n"
      << "\t\tBob is shooting at Charlie\n";
   Bob_shoots(aaron_a, charlie_a);

   aaron_a = true;
   charlie_a = false;
   cout <<"\tCase 3: Aaron alive, Charlie dead\n"
      << "\t\tBob is shooting at Aaron\n";
   Bob_shoots(aaron_a, charlie_a);
}

void test_Charlie_shoots(void) {
   cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";

   bool aaron_a = true;
   bool bob_a = true;
   cout << "\tCase 1: Aaron alive, Bob alive\n"
      << "\t\tCharlie is shooting at Bob\n";
   Charlie_shoots(aaron_a, bob_a);
   assert(aaron_a == true && bob_a == false);

   aaron_a = false;
   bob_a = true;
   cout << "\tCase 2: Aaron dead, Bob alive\n"
      << "\t\tCharlie is shooting at Bob\n";
   Charlie_shoots(aaron_a, bob_a);
   assert(aaron_a == false && bob_a == false);

   aaron_a = true;
   bob_a = false;
   cout << "\tCase 3: Aaron alive, Bob dead\n"
      << "\t\tCharlie is shooting at Aaron\n";
   Charlie_shoots(aaron_a, bob_a);
   assert(aaron_a == false && bob_a == false);
}

void test_Aaron_shoots2(void) {
   cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";

   bool bob_a = true;
   bool charlie_a = true;
   cout << "\tCase 1: Bob alive, Charlie alive\n"
      << "\t\tAaron intentionally misses his first shot\n"
      << "\t\tBoth Bob and Charlie are alive.\n";
   Aaron_shoots2(bob_a, charlie_a);
   
   bob_a = false;
   charlie_a = true;
   cout << "\tCase 2: Bob dead, Charlie alive\n"
      << "\t\tAaron is shooting at Charlie\n";
   Aaron_shoots2(bob_a, charlie_a);
   
   bob_a = true;
   charlie_a = false;
   cout << "\tCase 3: Bob alive, Charlie dead\n"
      << "\t\tAaron is shooting at Bob\n";
   Aaron_shoots2(bob_a, charlie_a);
}

//Variables
bool aaronAlive;
bool bobAlive;
bool charlieAlive;
int aaronWins1 = 0;
int aaronWins2 = 0;
int bobWins = 0;
int charlieWins = 0;

int main() {
   cout << "*** Welcome to Matthew's Duel Simulator ***\n";
   srand(time(0));
   test_at_least_two_alive();
   Press_any_key();
   test_Aaron_shoots1();
   Press_any_key();
   test_Bob_shoots();
   Press_any_key();
   test_Charlie_shoots();
   Press_any_key();
   test_Aaron_shoots2();
   Press_any_key();
   
   cout << "Ready to test strategy 1 (run 10000 times):\n";
   Press_any_key();
   for (int i = 0; i < TOTAL_RUNS; i++) {
      aaronAlive = true;
      bobAlive = true;
      charlieAlive = true;
      while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
         if (aaronAlive) {
            Aaron_shoots1(bobAlive, charlieAlive);
         }
         if (bobAlive) {
            Bob_shoots(aaronAlive, charlieAlive);
         }
         if (charlieAlive) {
            Charlie_shoots(aaronAlive, bobAlive);
         }
      }
      if (aaronAlive) {
         aaronWins1++;
      }
      if (bobAlive) {
         bobWins++;
      }
      if (charlieAlive) {
         charlieWins++;
      }
   }
   cout << "Aaron won " << aaronWins1 << "/10000 duels or " << static_cast<double>(aaronWins1) / TOTAL_RUNS * 100 << "%\n"
      << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS * 100 << "%\n"
      << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) / TOTAL_RUNS * 100 << "%\n"
      << endl;
      
   bobWins = 0;
   charlieWins = 0;
   cout << "Ready to test strategy 2 (run 10000 times):\n";
   Press_any_key();
   for (int i = 0; i < TOTAL_RUNS; i++) {
      aaronAlive = true;
      bobAlive = true;
      charlieAlive = true;
      while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
         if (aaronAlive) {
            Aaron_shoots2(bobAlive, charlieAlive);
         }
         if (bobAlive) {
            Bob_shoots(aaronAlive, charlieAlive);
         }
         if (charlieAlive) {
            Charlie_shoots(aaronAlive, bobAlive);
         }
      }
      if (aaronAlive) {
         aaronWins2++;
      }
      if (bobAlive) {
         bobWins++;
      }
      if (charlieAlive) {
         charlieWins++;
      }
   }
   
   cout << "Aaron won " << aaronWins2 << "/10000 duels or " << static_cast<double>(aaronWins2) / TOTAL_RUNS * 100 << "%\n"
      << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS * 100 << "%\n"
      << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) / TOTAL_RUNS * 100 << "%\n"
      << endl;
   
   if (aaronWins1 > aaronWins2) {
      cout << "Strategy 1 is better than strategy 2.\n";
   }
   else {
      cout << "Strategy 2 is better than strategy 1.\n";
   }
   return 0;
}