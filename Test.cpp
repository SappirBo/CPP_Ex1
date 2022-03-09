/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 *
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input)
{
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good input")
{
	// Test Case 1
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													"@-------@\n"
													"@-@@@@@-@\n"
													"@-@---@-@\n"
													"@-@@@@@-@\n"
													"@-------@\n"
													"@@@@@@@@@"));
	// Test Case 2
	CHECK(nospaces(mat(9, 5, '#', '-')) == nospaces("#########\n"
													"#-------#\n"
													"#-#####-#\n"
													"#-------#\n"
													"#########"));
	// Test Case 3
	CHECK(nospaces(mat(1, 1, '#', '^')) == nospaces("#"));
	// Test Case 4
	CHECK(nospaces(mat(13, 3, '$', '-')) == nospaces("$$$$$$$$$$$$$\n"
													 "$-----------$\n"
													 "$$$$$$$$$$$$$"));
	// Test Case 5
	CHECK(nospaces(mat(3, 7, '(', '-')) == nospaces("(((\n"
													"(-(\n"
													"(-(\n"
													"(-(\n"
													"(-(\n"
													"(-(\n"
													"((("));
	// Test Case 6
	CHECK(nospaces(mat(11, 1, '#', '_')) == nospaces("###########"));
	// Test Case 7
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													"@-------@\n"
													"@-@@@@@-@\n"
													"@-@---@-@\n"
													"@-@@@@@-@\n"
													"@-------@\n"
													"@@@@@@@@@"));
	// Test Case 8
	CHECK(nospaces(mat(31, 31, '#', '^')) == nospaces("###############################\n"
													  "#^^^^^^^^^^^^^^^^^^^^^^^^^^^^^#\n"
													  "#^###########################^#\n"
													  "#^#^^^^^^^^^^^^^^^^^^^^^^^^^#^#\n"
													  "#^#^#######################^#^#\n"
													  "#^#^#^^^^^^^^^^^^^^^^^^^^^#^#^#\n"
													  "#^#^#^###################^#^#^#\n"
													  "#^#^#^#^^^^^^^^^^^^^^^^^#^#^#^#\n"
													  "#^#^#^#^###############^#^#^#^#\n"
													  "#^#^#^#^#^^^^^^^^^^^^^#^#^#^#^#\n"
													  "#^#^#^#^#^###########^#^#^#^#^#\n"
													  "#^#^#^#^#^#^^^^^^^^^#^#^#^#^#^#\n"
													  "#^#^#^#^#^#^#######^#^#^#^#^#^#\n"
													  "#^#^#^#^#^#^#^^^^^#^#^#^#^#^#^#\n"
													  "#^#^#^#^#^#^#^###^#^#^#^#^#^#^#\n"
													  "#^#^#^#^#^#^#^#^#^#^#^#^#^#^#^#\n"
													  "#^#^#^#^#^#^#^###^#^#^#^#^#^#^#\n"
													  "#^#^#^#^#^#^#^^^^^#^#^#^#^#^#^#\n"
													  "#^#^#^#^#^#^#######^#^#^#^#^#^#\n"
													  "#^#^#^#^#^#^^^^^^^^^#^#^#^#^#^#\n"
													  "#^#^#^#^#^###########^#^#^#^#^#\n"
													  "#^#^#^#^#^^^^^^^^^^^^^#^#^#^#^#\n"
													  "#^#^#^#^###############^#^#^#^#\n"
													  "#^#^#^#^^^^^^^^^^^^^^^^^#^#^#^#\n"
													  "#^#^#^###################^#^#^#\n"
													  "#^#^#^^^^^^^^^^^^^^^^^^^^^#^#^#\n"
													  "#^#^#######################^#^#\n"
													  "#^#^^^^^^^^^^^^^^^^^^^^^^^^^#^#\n"
													  "#^###########################^#\n"
													  "#^^^^^^^^^^^^^^^^^^^^^^^^^^^^^#\n"
													  "###############################"));
	// Test Case 9
	CHECK(nospaces(mat(5, 5, '8', '-')) == nospaces("88888\n"
													"8---8\n"
													"8-8-8\n"
													"8---8\n"
													"88888"));
	// Test Case 10
	CHECK(nospaces(mat(1, 7, '#', '^')) == nospaces("#\n"
													"#\n"
													"#\n"
													"#\n"
													"#\n"
													"#\n"
													"#"));
}

TEST_CASE("Bad input")
{
	CHECK_THROWS(mat(10, 5, '$', '%'));
	CHECK_THROWS(mat(1, 4, '$', '%'));
	CHECK_THROWS(mat(0, 0, '$', '%'));
	CHECK_THROWS(mat(91, 91, '\n', '%'));
	CHECK_THROWS(mat(1, 5, '$', '\r'));
	CHECK_THROWS(mat(15, 5, ' ', '&'));
	CHECK_THROWS(mat(2, 5, '\t', '%'));
	CHECK_THROWS(mat(17, 59, '$', '\t'));
	CHECK_THROWS(mat(2, 5, '$', '%'));
	CHECK_THROWS(mat(7, 5, '\n', '\n'));
}

/* Add more test cases here */
