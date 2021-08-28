struct LabeledPoint;
struct LabeledPoint* makeLabeledPoint(double x, double y, char *label);

void setLabel(struct LabeledPoint *lp, char *label);
char *getLabel(struct LabeledPoint *lp);
