#include "pch.h"
#include "CppUnitTest.h"
#include "../AiSD_laba1/AiSD_laba1.cpp";

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethodPushFront)
		{
			UnorderedList myList;
			int number, amount;
			amount = 3;
			for (int i = 0; i < amount; i++) {
				number = rand() % 10;
				myList.push_front(number);

			}
			Assert::IsTrue(myList.get_size() == 3);
		}
		TEST_METHOD(TestMethodPushBack)
		{
			UnorderedList myList;
			int number, amount;
			amount = 3;
			for (int i = 0; i < amount; i++) {
				number = rand() % 10;
				myList.push_front(number);
			}
			number = rand() % 10;
			myList.push_back(number);
			Assert::IsTrue(myList.get_size() == 4);
		}
		TEST_METHOD(TestMethodClear)
		{
			UnorderedList myList;
			int number, amount;
			amount = 3;
			for (int i = 0; i < amount; i++) {
				number = rand() % 10;
				myList.push_front(number);
			}
			myList.clear();
			Assert::IsTrue(myList.get_size() == 0);
		}

		TEST_METHOD(TestMethodIsEmpty)
		{
			UnorderedList myList;
			int number, amount;
			amount = 3;
			for (int i = 0; i < amount; i++) {
				number = rand() % 10;
				myList.push_front(number);
			}
			Assert::IsTrue(myList.isEmpty() == NULL);
		}
		TEST_METHOD(TestMethodPopFront)
		{
			UnorderedList myList;
			int number, amount;
			amount = 3;
			for (int i = 0; i < amount; i++) {
				number = rand() % 10;
				myList.push_front(number);
			}
			myList.pop_front();
			Assert::IsTrue(myList.get_size() == 2);
		}
		TEST_METHOD(TestMethodPopBack)
		{
			UnorderedList myList;
			int number, amount;
			amount = 3;
			for (int i = 0; i < amount; i++) {
				number = rand() % 10;
				myList.push_front(number);
			}
			myList.pop_back();
			Assert::IsTrue(myList.get_size() == 2);
		}
		TEST_METHOD(TestMethodGetSize)
		{
			UnorderedList myList;
			int number, amount;
			amount = 3;
			for (int i = 0; i < amount; i++) {
				number = rand() % 10;
				myList.push_front(number);
			}
			Assert::IsTrue(myList.get_size() == 3);
		}

		TEST_METHOD(TestMethodAt)
		{
			UnorderedList myList;
			int number, amount;
			amount = 3;
			for (int i = 0; i < amount; i++) {
				number = rand() % 10;
				myList.push_front(number);
			}

			Assert::IsTrue(myList.get_size() == 3);
		}
		TEST_METHOD(TestMethodInsert)
		{
			UnorderedList myList;
			int number, amount;
			amount = 3;
			for (int i = 0; i < amount; i++) {
				number = rand() % 10;
				myList.push_front(number);
			}
			myList.insert(3,3);
			Assert::IsTrue(myList.get_size() == 4);
		}
		TEST_METHOD(TestMethodSearch)
		{
			UnorderedList myList;
			int number, amount;
			amount = 3;
			for (int i = 0; i < amount; i++) {
				number = rand() % 10;
				myList.push_front(number);
			}
			Assert::IsTrue(myList.search(2) != false);
		}

		TEST_METHOD(TestMethodRemove)
		{
			UnorderedList myList;
			int number, amount;
			amount = 3;
			for (int i = 0; i < amount; i++) {
				number = rand() % 10;
				myList.push_front(number);
			}
			myList.remove(3);
			Assert::IsTrue(myList.get_size() != 3);
		}
		TEST_METHOD(TestMethodSet)
		{
			UnorderedList myList;
			int number, amount;
			amount = 3;
			for (int i = 0; i < amount; i++) {
				number = rand() % 10;
				myList.push_front(number);
			}
			myList.set(3,2);
			Assert::IsTrue(myList.at(2) == 3);
		}
		TEST_METHOD(TestMethodFindList)
		{
			UnorderedList myList;
			int number, amount;
			amount = 3;
			for (int i = 0; i < amount; i++) {
				number = rand() % 10;
				myList.push_front(number);
			}
			myList.find_list(3);
			Assert::IsTrue(myList.get_size() == 3);
		}

	};
}
