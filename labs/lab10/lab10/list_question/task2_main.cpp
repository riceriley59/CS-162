
#include <iostream>
#include <chrono>
#include <iomanip>
#include <unistd.h>
#include "list.h"
using namespace std;

string print_list_to_str(ListNode* head);
void print_list(ListNode* head);
ListNode* add_node(ListNode* head, int val);
void delete_list(ListNode** head);
void print_result (string actual, string expected, int num);
void test1(string expected);
void test2(string expected);
void test3(string expected);
void test4(string expected);
void test5(string expected);
void test6(string expected);
int get_memory_usage_kb(long* vmrss_kb, long* vmsize_kb);


int main(int argc, char const *argv[])
{
	//variables for memory calculation
	long vmrss, vmsize;

	//construct expected results
	ListNode* t1 = NULL;
	for (int i = 1; i < 4; i++)
		t1 = add_node(t1, i+1);
	string expected1 = print_list_to_str(t1);
	

	ListNode* t2 = NULL;
	for (int i = 0; i < 3; i++)
		t2 = add_node(t2, i+1);
	string expected2 = print_list_to_str(t2);
	

	ListNode* t3 = NULL;
	string expected3 = print_list_to_str(t3);
	
	ListNode* t4 = NULL;
	t4 = add_node(t4, 25);
	string expected4 = print_list_to_str(t4);
	

	ListNode* t5 = NULL;
	t5 = add_node(t5, 81);
	string expected5 = print_list_to_str(t5);
	

	ListNode* t6 = NULL;
	for (int i = 0; i < 25000; i++)
		t6 = add_node(t6, i+1);
	for (int i = 25001; i < 50000; i++)
		t6 = add_node(t6, i+1);
	string expected6 = print_list_to_str(t6);
	

	//get time stamp before testing
    auto start = chrono::high_resolution_clock::now(); 

    //testing
	test1(expected1);
	test2(expected2);
	test3(expected3);
	test4(expected4);
	test5(expected5);
	test6(expected6);

	//get time stamp after testing
    auto end = chrono::high_resolution_clock::now(); 
    
    //calculate and print time taken
    double time_taken =  
      chrono::duration_cast<chrono::nanoseconds>(end - start).count(); 
    time_taken *= 1e-9; 
  
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(9); 
    cout << " sec" << endl; 

	get_memory_usage_kb(&vmrss, &vmsize);
    printf("Current memory usage: VmRSS = %6ld KB, VmSize = %6ld KB\n", vmrss, vmsize);

    
	return 0;
}