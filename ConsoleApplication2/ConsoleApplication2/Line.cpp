#include "Line.h"
Line::Line(Point p1, Point p2) {
	this->a = p1.getY() - p2.getY();
	this->b = p2.getX() - p1.getX();
	this->c = p1.getX() * p2.getY() - p2.getX() * p1.getY();
}
bool Line::hasCrossPoint(Line* l1, Line* l2) {
	double d = (l1->a * l2->b - l2->a * l1->b);
	return d != 0;
}
Point Line::CrossPoint(Line* l1, Line* l2) {
	double x;
	double y;
	double d = (l1->a * l2->b - l2->a * l1->b);
	x = (l1->b * l2->c - l2->b * l1->c) / d;
	y = (l1->c * l2->a - l2->c * l1->a) / d;
	return Point(x, y);
}
