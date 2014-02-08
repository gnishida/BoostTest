#pragma once

#include "BBox.h"
#include <vector>
#include <QVector2D>
#include <boost/geometry/geometries/register/point.hpp>
#include <boost/geometry/geometries/register/linestring.hpp> 
#include <boost/geometry/geometries/register/ring.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>

/**
 * QVector2DをBoostのpointの代替として使用
 */
//BOOST_GEOMETRY_REGISTER_POINT_2D_GET_SET(QVector2D, float, boost::geometry::cs::cartesian, x, y, setX, setY)



class Polygon2D : public std::vector<QVector2D> {
private:
	bool corrected;

public:
	Polygon2D() {}
	~Polygon2D() {}

	//void push_back(const QVector2D &pt);
	float area();
	QVector2D centroid();
	bool contains(const QVector2D &pt);
	Polygon2D convexHull();
	BBox envelope();
};

/**
 * Polygon2DをBoostのringの代替として使用
 */
BOOST_GEOMETRY_REGISTER_RING(Polygon2D)