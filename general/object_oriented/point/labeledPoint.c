#include "labeledPoint.h"
#include <stdlib.h>

struct LabeledPoint {
	double x, y;
	char *name;
};

struct LabeledPoint* makeLabeledPoint(double x, double y, char *label) {
	struct LabeledPoint *p = malloc(sizeof(struct LabeledPoint));
	p->x = x;
	p->y = y;
	p->name = label;
	return p;
}

void setLabel(struct LabeledPoint *lp, char *label) {
	lp->name = label;
}

char *getLabel(struct LabeledPoint *lp) {
	return lp->name;
}
