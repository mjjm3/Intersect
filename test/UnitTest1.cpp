#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication2/Line.h"
#include "../ConsoleApplication2/Circle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Line l1(Point(1, 2), Point(2, 3));
			Line l2(Point(1, 2), Point(2, 1));
			Assert::IsTrue(Line::hasCrossPoint(&l1, &l2));
		}
		TEST_METHOD(TestMethod2)
		{
			Line l1(Point(0, 0), Point(1, 1));
			Line l2(Point(1, 0), Point(2, 1));
			Assert::IsFalse(Line::hasCrossPoint(&l1, &l2));
		}
		TEST_METHOD(TestMethod3)
		{
			Line l1(Point(0, 0), Point(1, 1));
			Line l2(Point(0, 0), Point(1, 1));
			Assert::IsFalse(Line::hasCrossPoint(&l1, &l2));
		}
		TEST_METHOD(TestMethod4)
		{
			Line l1(Point(0, 0), Point(0, 1));
			Line l2(Point(2, 3), Point(1, 1));
			Assert::IsTrue(Line::hasCrossPoint(&l1, &l2));
		}
		TEST_METHOD(TestMethod5)
		{
			Line l1(Point(0, 0), Point(0, 1));
			Circle c(0, 0, 2);
			Assert::AreEqual(1,Line::CrossPoints(&l1, &c,new Point(),new Point()));
			 
		}
		TEST_METHOD(TestMethod6)

		{
			//œ‡«–
			Line l1(Point(2, 0), Point(2, 1));
			Circle c(0, 0, 2);
			Assert::AreEqual(1, Line::CrossPoints(&l1, &c, new Point(), new Point()));

		}
		TEST_METHOD(TestMethod7)
		{
			Line l1(Point(0, 2), Point(1, 2));
			Circle c(0, 0, 2);
			Assert::AreEqual(1, Line::CrossPoints(&l1, &c, new Point(), new Point()));
		}
		TEST_METHOD(TestMethod8)
		{
			Circle c(0, 0, 2);
			Circle c2(0, 0, 2);
			Assert::AreEqual(0, Circle::CrossPoints(&c, &c2, new Point(), new Point()));

		}
		TEST_METHOD(TestMethod9)
		{
			Circle c(0, 0, 2);
			Circle c2(0, 0, 1);
			Assert::AreEqual(0, Circle::CrossPoints(&c, &c2, new Point(), new Point()));

		}
		TEST_METHOD(TestMethod10)
		{
			Circle c(0, 0, 1);
			Circle c2(2, 0, 1);
			Assert::AreEqual(1, Circle::CrossPoints(&c, &c2, new Point(), new Point()));

		}
	};
}
