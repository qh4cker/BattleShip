#include "point.h"


class Rect {
public:
	Rect();
	Rect(int x, int y, int w = 0, int h = 0);
	~Rect();

	Point getPosition() const;
	int getWidth() const;
	int getHeight() const;
	Rect getRectangle() const;

	void setWidth(int width);
	void setHeight(int height);
	void setPos(int x, int y);
	void setRectangle(Rect& rectangle);

	void read(std::istream& os);
	void print(std::ostream& os) const;
	void draw(std::ostream& os) const;

	int surface() const;
	int perimeter() const;

private:
	Point coord;
	int w;
	int h;
};