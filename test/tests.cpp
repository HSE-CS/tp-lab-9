//  Copyright DBarinov
#include <gtest/gtest.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"	

TEST(TASK1, TEST1) {
	std::vector<std::string> v_string = { "helllo", "world", "this", "is", "demo" };
	bubbleSort(v_string, [](std::string& _str1, std::string& _str2) {
		return _str1.length() > _str2.length(); });
	std::vector<std::string> result = { "is", "this", "demo", "world", "helllo" };
	EXPECT_EQ(result, v_string);
}

TEST(TASK1, TEST2) {
	std::vector<std::string> v_string = { "helllo", "world", "this", "is", "demo" };
	bubbleSort(v_string, [](std::string& _str1, std::string& _str2) {
		return _str1.length() < _str2.length(); });
	std::vector<std::string> result =
	{ "helllo", "world", "this", "demo", "is" };
	EXPECT_EQ(result, v_string);
}

TEST(TASK1, TEST3) {
	std::vector<std::string> v_string = { "helllo", "world", "this", "is", "demo" };
	bubbleSort(v_string, [](std::string& _str1, std::string& _str2) {
		return _str1 < _str2; });
	std::vector<std::string> result =
	{ "demo", "helllo", "is", "this", "world" };
	EXPECT_EQ(result, v_string);
}

TEST(TASK1, TEST4) {
	std::vector<std::string> v_string = { "helllo", "world", "this", "is", "demo" };
	bubbleSort(v_string, [](std::string& _str1, std::string& _str2) {
		return _str1 > _str2; });
	std::vector<std::string> result =
	{ "world", "this", "is", "helllo", "demo" };
	EXPECT_EQ(result, v_string);
}

TEST(TASK1, TEST5) {
	std::vector<std::string> v_string = { "helllo", "world", "this", "is", "demo" };
	bubbleSort(v_string, [](std::string& _str1, std::string& _str2) {
		return _str1[_str1.size() - 1] < _str2[_str2.size() - 1]; });
	std::vector<std::string> result =
	{ "world", "helllo", "demo", "this", "is" };
	EXPECT_EQ(result, v_string);
}

TEST(TASK1, TEST6) {
	std::vector<std::string> v_string = { "helllo", "world", "this", "is", "demo" };
	bubbleSort(v_string, [](std::string& _str1, std::string& _str2) {
		return _str1[0] < _str2[0]; });
	std::vector<std::string> result =
	{ "demo", "helllo", "is", "this", "world" };
	EXPECT_EQ(result, v_string);
}
