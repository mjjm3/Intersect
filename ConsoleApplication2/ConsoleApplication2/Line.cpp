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
int Line::CrossPoints(Line* l, Circle* cir, Point* p1, Point* p2) {
	double k = - l->a / l->b;
	double b = - l->c / l->b;
	double c = -cir->x;
	double d = -cir->y;
	double r = cir->r;

	if (k == INFINITY) {
		double x = -l->c / l->a;
		double der = sqrt(r * r - (x + c) * (x + c));
		if (der >= 0) {
			double y1 = -d + der;
			double y2 = -d - der;
			p1->x = x;
			p1->y = y1;
			p2->x = x;
			p2->y = y2;
			return 1;
		}
	}
	else {
		double der = sqrt((k * k + 1) * r * r - c * c * k * k + (2 * c * d + 2 * b * c) * k - d * d - 2 * b * d - b * b);
		if (der >= 0) {
			double x1 = -(der + (d + b) * k + c) / (k * k + 1);
			double x2 = (der - (d + b) * k - c) / (k * k + 1);
			double y1 = k * x1 + b;
			double y2 = k * x2 + b;
			p1->x = x1;
			p1->y = y1;
			p2->x = x2;
			p2->y = y2;
			return 1;
		}
	}
	return 0;


 
	 
}