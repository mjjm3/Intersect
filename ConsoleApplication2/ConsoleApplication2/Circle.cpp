#include "Circle.h"
Circle::Circle(double x, double y, double r) {
	this->x = x;
	this->y = y;
	this->r = r;
}

int Circle::CrossPoints(Circle* c1, Circle* c2, Point* p1, Point* p2)
{
	float a1, b1, R1, a2, b2, R2;
	a1 = c1->x;
	b1 = c1->y;
	R1 = c1->r;

	a2 = c2->x;
	b2 = c2->y;
	R2 = c2->r;
	float R1R1 = R1 * R1;
	float a1a1 = a1 * a1;
	float b1b1 = b1 * b1;
	float a2a2 = a2 * a2;
	float b2b2 = b2 * b2;
	float R2R2 = R2 * R2;

	float subs1 = a1a1 - 2 * a1 * a2 + a2a2 + b1b1 - 2 * b1 * b2 + b2b2;
	float subs2 = -R1R1 * a1 + R1R1 * a2 + R2R2 * a1 - R2R2 * a2 + a1a1 * a1 - a1a1 * a2 - a1 * a2a2 + a1 * b1b1 - 2 * a1 * b1 * b2 + a1 * b2b2 + a2a2 * a2 + a2 * b1b1 - 2 * a2 * b1 * b2 + a2 * b2b2;
	float subs3 = -R1R1 * b1 + R1R1 * b2 + R2R2 * b1 - R2R2 * b2 + a1a1 * b1 + a1a1 * b2 - 2 * a1 * a2 * b1 - 2 * a1 * a2 * b2 + a2a2 * b1 + a2a2 * b2 + b1b1 * b1 - b1b1 * b2 - b1 * b2b2 + b2b2 * b2;
	float sigma = sqrt((R1R1 + 2 * R1 * R2 + R2R2 - a1a1 + 2 * a1 * a2 - a2a2 - b1b1 + 2 * b1 * b2 - b2b2) * (-R1R1 + 2 * R1 * R2 - R2R2 + subs1));
	if (sigma >= 0 && subs1 != 0)
	{
		double x1 = (subs2 - sigma * b1 + sigma * b2) / (2 * subs1);
		double x2 = (subs2 + sigma * b1 - sigma * b2) / (2 * subs1);
		double y1 = (subs3 + sigma * a1 - sigma * a2) / (2 * subs1);
		double y2 = (subs3 - sigma * a1 + sigma * a2) / (2 * subs1);
		p1->x =x1;
		p1->y =y1;
		p2->x = x2;
		p2->y = y2;
		return 1;
	}
	return 0;

}
 