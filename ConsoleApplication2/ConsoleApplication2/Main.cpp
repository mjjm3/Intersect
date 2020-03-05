// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include "Line.h"
#include "Circle.h"
int main()
{
	int N;
	std::cin >> N;
	std::vector<Line*> lines;
	std::vector<Circle*> circles;
	std::unordered_set<Point, PointHashFunc> set;
	for (int i = 0; i < N; i++) {
		char type;
		std::cin >> type;
		if (type == 'L') {
			double x1, y1, x2, y2;
			std::cin >> x1 >> y1 >> x2 >> y2;
			lines.push_back(new Line(Point(x1, y1), Point(x2, y2)));
		}
		else {
			double x, y, r;
			std::cin >> x >> y >> r;
			circles.push_back(new Circle(x, y, r));
		}
	}
	for (int i = 0; i < lines.size(); i++) {
		for (int j = i + 1; j < lines.size(); j++) {
			if (Line::hasCrossPoint(lines[i], lines[j])) { 
			set.insert(Line::CrossPoint(lines[i], lines[j]));
			}
		}
	}
	for (int i = 0; i < circles.size(); i++) {
		for (int j = i + 1; j < circles.size(); j++) {
			Point p1(0,0);
			Point p2(0,0);
			int ret = Circle::CrossPoints(circles[i], circles[j], &p1, &p2);
			if (ret == 1) {
				set.insert(p1);
				set.insert(p2);
			}
		}
	}
	for (int i = 0; i < lines.size(); i++) {
		for (int j = 0; j < circles.size(); j++) {
			Point p1(0, 0);
			Point p2(0, 0);
			int ret = Line::CrossPoints(lines[i], circles[j], &p1, &p2);
			if (ret == 1) {
				set.insert(p1);
				set.insert(p2);
			}
		}
	}

	std::cout << set.size() <<std::endl;
	 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
