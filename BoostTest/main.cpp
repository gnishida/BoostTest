#include <assert.h>
#include "Polygon2D.h"

/**
 * このテストでは、Polygon2DとBBoxを、BoostのGeometryコンセプトを付与することで、
 * Boostの様々な関数を利用できるようにしている。
 *
 * @author Gen Nishida
 */

int main() {
	Polygon2D polygon;
	polygon.push_back(QVector2D(0, 0));
	polygon.push_back(QVector2D(0, 10));
	polygon.push_back(QVector2D(10, 10));
	polygon.push_back(QVector2D(5, 5));	
	polygon.push_back(QVector2D(10, 0));
	polygon.push_back(QVector2D(0, 0));

	assert(polygon.area() == 75);

	// ringのための各種関数を利用できる
	std::cout << "Centroid: " << polygon.centroid().x() << "," << polygon.centroid().y() << std::endl;

	assert(!polygon.contains(QVector2D(9, 5)));
	assert(polygon.contains(QVector2D(3, 5)));
	assert(polygon.contains(QVector2D(1, 1)));
	assert(!polygon.contains(QVector2D(7, 4)));

	Polygon2D polygon2 = polygon.convexHull();
	assert(polygon2.area() == 100);

	BBox bbox = polygon.envelope();
	assert(bbox.contains(QVector2D(5, 5)));
	assert(bbox.contains(QVector2D(9, 5)));
	assert(bbox.midPt().x() == 5);
	assert(bbox.midPt().y() == 5);

	BBox bbox2;
	bbox2.addPoint(QVector2D(3, 1));
	bbox2.addPoint(QVector2D(10, 10));
	bbox2.addPoint(QVector2D(5, 6));
	bbox2.addPoint(QVector2D(0, 0));
	assert(!bbox2.contains(QVector2D(20, 20)));
	assert(bbox2.contains(QVector2D(5, 5)));
	assert(bbox2.dx() == 10);
	assert(bbox2.dy() == 10);

	return 0;
}
