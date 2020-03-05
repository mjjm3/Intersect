#pragma once
#include <unordered_set>
#include <functional>
class Point {
public:
	double x;
	double y;
	Point(double x, double y);
	bool operator==(const Point& p) const {
		return this->x == p.x && this->y == p.y;
	}
	double getX() const;
	double getY() const;
};

struct PointHashFunc
{
	size_t operator()(const Point& p) const noexcept
	{
		return std::hash<double>{}(p.getX()) ^ (std::hash<double>{}(p.getY()) << 1);
	}
};

 