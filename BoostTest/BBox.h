#pragma once

#include <vector>
#include <QVector2D>
#include <boost/geometry/geometries/register/point.hpp>
#include <boost/geometry/geometries/register/box.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>



class BBox {
public:
	QVector2D minPt, maxPt;

public:
	BBox() {}
	~BBox() {}
};

/**
 * QVector2DをBoostのpointの代替として使用
 */
BOOST_GEOMETRY_REGISTER_POINT_2D_GET_SET(QVector2D, float, boost::geometry::cs::cartesian, x, y, setX, setY)

/**
 * BBoxをBoostのboxの代替として使用
 */
BOOST_GEOMETRY_REGISTER_BOX(BBox, QVector2D, minPt, maxPt)

