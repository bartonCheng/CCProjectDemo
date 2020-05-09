#include "Shape.h"
double Shape::Volume(int i)
{
	return shape_height * shape_length * shape_width * i;
}

