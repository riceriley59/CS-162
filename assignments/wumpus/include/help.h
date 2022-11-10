/*********************************************************************
** Filename: help.h
** Author: Riley Rice
** Date: 11-6-2022
** Description: This has some functions which help with error handling
*********************************************************************/

//header guard
#ifndef HELP
#define HELP

//include some basic libraries
#include <string>
#include <iostream>

//namespace std
using namespace std;

//helper funcitons for error handling
bool is_int(string);
int pow(int, int);
int string_to_int(string);
bool is_str(string);
bool is_str_with_under(string);
string to_lowercase(string);

#endif