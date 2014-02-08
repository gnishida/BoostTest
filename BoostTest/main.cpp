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

	// ringのための各種関数を利用できる
	std::cout << "Area: " << polygon.area() << std::endl;
	std::cout << "Centroid: " << polygon.centroid().x() << "," << polygon.centroid().y() << std::endl;
	std::cout << "Within: " << polygon.contains(QVector2D(9, 5)) << std::endl;
	std::cout << "Within: " << polygon.contains(QVector2D(3, 5)) << std::endl;
	std::cout << "Within: " << polygon.contains(QVector2D(1, 1)) << std::endl;
	std::cout << "Within: " << polygon.contains(QVector2D(7, 4)) << std::endl;

	Polygon2D polygon2 = polygon.convexHull();
	BBox bbox = polygon.envelope();

	return 0;
}
