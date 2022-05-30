#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab_12_oop_6.4\main.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int arr[] = { 3, 10, 99, 3, 2, 3 };
			int c;
			search<int>(arr, 6, 3, c);
			Assert::AreEqual(c, 3);
		}
	};
}
