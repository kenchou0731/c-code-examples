#include "point.h"
#include "labeledPoint.h"
#include <stdio.h>

int main(int argc, char** argv) {
	struct LabeledPoint* origin = makeLabeledPoint(0.0, 0.0, "origin");
	struct LabeledPoint* lowerLeft = makeLabeledPoint(-1.0, -1.0, "lowerLeft");
	printf("distance = %f\n", getDistance((struct Point*) origin, (struct Point*) lowerLeft));
}
