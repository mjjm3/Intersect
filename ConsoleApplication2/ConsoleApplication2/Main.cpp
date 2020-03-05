// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <fstream>
#include "Line.h"
#include "Circle.h"
using namespace std;
int main(int argc, char* argv[])
{
	ifstream in;
	ofstream out;
	if (argc != 5) {
		cout << "wrong args" << endl;
		return 1;
	}
	in.open(argv[2]);
	out.open(argv[4]);
	int N;
	in >> N;
	std::vector<Line*> lines;
	std::vector<Circle*> circles;
	std::unordered_set<Point, PointHashFunc> set;
	 
	for (int i = 0; i < N; i++) {
		char type;
		in >> type;
		if (type == 'L') {
			double x1, y1, x2, y2;
			in >> x1 >> y1 >> x2 >> y2;
			lines.push_back(new Line(Point(x1, y1), Point(x2, y2)));
		}
		else {
			double x, y, r;
			in >> x >> y >> r;
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

	out << set.size() <<std::endl;
	 
}
 