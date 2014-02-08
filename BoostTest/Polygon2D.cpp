#include "Polygon2D.h"
#include <boost/geometry/geometry.hpp> 

/*void Polygon2D::push_back(const QVector2D &pt) {
	this->push_back(pt);
}*/

float Polygon2D::area() {
	return boost::geometry::area(*this);
}

QVector2D Polygon2D::centroid() {
	QVector2D ret;
	boost::geometry::centroid(*this, ret);

	return ret;
}

bool Polygon2D::contains(const QVector2D &pt) {
	return boost::geometry::within(pt, *this);
}

Polygon2D Polygon2D::convexHull() {
	Polygon2D hull;
	Polygon2D poly;
	
	boost::geometry::convex_hull(*this, hull);

	return hull;
}

BBox Polygon2D::envelope() {
	BBox bbox;
	boost::geometry::envelope(*this, bbox);
	return bbox;
}
