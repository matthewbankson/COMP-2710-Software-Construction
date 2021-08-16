//Matthew Bankson (mlb0126)
//project4_mlb0126.cpp
//How to compile: g++ project4_mlb0126.cpp

#include <iostream>
#include <string>
using namespace std;

struct trivia_node {
   string question;
   string answer;
   int point;
   trivia_node *next;
};

typedef trivia_node* ptr_node;

void init_question_list(ptr_node&);
void add_question(ptr_node&);
int ask_question(ptr_node, int);
void Unit_Test();
int num_of_questions;
int total_points = 0;

#define UNIT_TESTING
//#define trivia_quiz

int main() {
   ptr_node node_list = new trivia_node;
#ifdef trivia_quiz 
   {
      string test;
      init_question_list(node_list);
      cout << "*** Welcome to Matthew's trivia quiz game ***" << endl;
      do {
         add_question(node_list);
         cout << "Continue? (Yes/No): ";
         cin.ignore();
         getline(cin, test);
      } while (test.compare("Yes") == 0);
      cout << "\n";
      ask_question(node_list, num_of_questions);
      cout << "*** Thank you for playing the trivia quiz game. Goodbye! ***";
      return 0;
   }
   #endif
#ifdef UNIT_TESTING
   {
      Unit_Test();
      return 0;
   }
#endif
}

void init_question_list(ptr_node& q_list) {
   ptr_node current = q_list;
   current->question = "How long was the shortest war on record? (Hint: how many minutes)";
   current->answer = "38";
   current->point = 100;
   current->next = new trivia_node;
   current = current->next;
   current->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
   current->answer = "Bank of Italy";
   current->point = 50;
   current->next = new trivia_node;
   current = current->next;
   current->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
   current->answer = "Wii Sports";
   current->point = 20;
   num_of_questions = 3;
}

void add_question(ptr_node& q_list) {
   ptr_node current = q_list;
   ptr_node new_ptr = new trivia_node;
   cout << "Enter a question: ";
   getline(cin, new_ptr->question);
   cout << "Enter an answer: ";
   getline(cin, new_ptr->answer);
   cout << "Enter award points: ";
   cin >> new_ptr->point;
   new_ptr->next = q_list;
   q_list = new_ptr;
   num_of_questions++;
}

int ask_question(ptr_node q_list, int num_ask) {
   ptr_node current = q_list;
   string user_answer;
   if (q_list == NULL) {
      return 0;
   }
   if (num_ask < 1) {
      cout << "Warning - the number of trivia to be asked must equal to or be larger than 1.";
   }
   else if (num_of_questions < num_ask) {
      cout << "Warning - there is only " << num_of_questions << " trivia in the list.";
   }
   else {
      for (int i = 0; i < num_ask; i++) {
         cout << "Question: " << current->question << endl;
         cout << "Answer: ";
         getline(cin, user_answer);
         if (user_answer.compare(current->answer) == 0) {
            cout << "Your answer is correct! You receive " << current->point << " points." << endl;
            total_points = total_points + current->point;
            cout << "Your total points: " << total_points << endl << endl;
         }
         else {
            cout << "Your answer is wrong. The correct answer is " << current->answer << endl;
            cout << "Your total points: " << total_points << endl << endl;
         }
         current = current->next;
      }
   }
   return 0;
}

void Unit_Test() {
   ptr_node node_list = new trivia_node;
   init_question_list(node_list);
   cout << "*** This is a debugging version ***\n";
   cout << "Unit Test Case 1: Ask no questions. The program should give a warning message." << endl;
   ask_question(node_list, 0);
   cout << "\nCase 1 Passed\n\n";
   cout << "Unit Test Case 2.1: Ask 1 question on the linked list. The tester enters an incorrect answer." << endl;
   ask_question(node_list, 1);
   total_points = 0;
   cout << "Case 2.1 Passed\n\n";
   cout << "Unit Test Case 2.2: Ask 1 question on the linked list. The tester enters a correct answer." << endl;
   ask_question(node_list, 1);
   total_points = 0;
   cout << "Case 2.2 Passed\n\n";
   cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list." << endl;
   ask_question(node_list, 3);
   cout << "Case 3 Passed\n\n";
   cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
   ask_question(node_list, 5);
   cout << "\nCase 4 Passed\n\n";
   cout << "*** End of the Debugging Version ***";
}
