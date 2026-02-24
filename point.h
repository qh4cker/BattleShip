#pragma once
#include <ostream>
#include <fstream>



class Point {
private:
	int x, y;
	int color;

public:

	Point() { x = y = color = 0; }
	Point(int x, int y) : x(x), y(y), color(7) {}
	Point(int x, int y, int color) : x(x), y(y), color(color) {}
	Point(const Point &point);
	Point(Point &point);
	~Point();

	int getX() const;
	int getY() const;
	int getColor() const;
	Point getPoint() const;

	void setX(int x);
	void setY(int y);
	void setColor(int color);
	void setPosition(int x, int y);
	void setPoint(Point point);

	void print(std::ostream& os) const;
	void draw(std::ostream& os) const;
	void read(std::istream& os);




	bool operator==(const Point& other)const;
	bool operator!=(const Point& other)const;
	Point& operator=(const Point& other);
	Point operator+(const Point& other) const;
	Point operator-(const Point& other) const;
	std::ostream& operator<<(std::ostream& out) const;
	std::istream& operator>>(std::istream& in);
	//void operator<<(std::ostream& other);
	//void operator>>(std::istream& other);
};

void setDrawColor(int color);
void goToXY(int xpos, int ypos);

void openFile(std::ifstream& file, const std::string& fileName);
int readFile(std::ifstream& monFlux, Point points[]);