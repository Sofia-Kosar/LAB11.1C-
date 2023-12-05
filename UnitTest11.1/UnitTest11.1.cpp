#include <fstream>
#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <string>
#include "../LAB11.2/LAB11.2.cpp"

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char t[100] = "queue";
			char e[100] = "even";
			char o[100] = "odd";
			ofstream fout(t, ios::binary);
			string s = "1397624758254";
			fout << s << endl;
			ProcessBIN1(t, e, o);
			ifstream fin(e, ios::binary);
			char c;
			fin.read((char*)&c, sizeof(c));
			Assert::AreEqual(c, '6');
		}
	};
}
