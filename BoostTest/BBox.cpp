#include "BBox.h"
#include <boost/geometry/geometry.hpp> 

bool BBox::contains(const QVector2D& pt) {
	return boost::geometry::within(pt, *this);
}

