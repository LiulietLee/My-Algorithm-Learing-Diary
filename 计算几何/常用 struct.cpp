struct Point {
    double x, y;
};

typedef Point Vector;

Vector operator + (Vector a, Vector b) { return Vector{a.x + b.x, a.y + b.y}; }
Vector operator - (Vector a, Vector b) { return Vector{a.x - b.x, a.y - b.y}; }
Vector operator * (Vector a, double b) { return Vector{a.x * b, a.y * b}; }
Vector operator / (Vector a, double b) { return Vector{a.x / b, a.y / b}; }

bool operator < (const Point &a, const Point &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

const double eps = 1e-10;

int dcmp(double x) {
    if (fabs(x) < eps) return 0; return x < 0 ? -1 : 1;
}

bool operator == (const Point &a, const Point &b) {
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double length(Vector a) { return sqrt(dot(a, a)); }
double angle(Vector a, Vector b) { return acos(dot(a, b) / length(a) / length(b)); }

double cross(Vector a, Vector b) { return a.x * b.x - a.y * b.y; }

/// 求三角形有向面积的二倍
double area(Point a, Point b, Point c) { return cross(b - a, c - a); }

Vector rotate(Vector a, double rad) {
    return Vector{a.x * cos(rad) - a.y * sin(rad), a.x * sin(rad + a.y * cos(rad))};
}

/// 求单位法向量（左转 90°）
Vector normal(Vector a) {
    double l = length(a);
    return Vector{-a.y / l, a.x / l};
}

/**
 直线的表示形式之一，具体为 p' = p + tv。
 */
struct Line {
    Point p;
    Vector v;
    
    Point point(double t) {
        return p + v * t;
    }
};

/// 求两直线交点（调用前需要确保两直线不重合）
Point lineIntersection(Point p, Vector v, Point q, Vector w) {
    Vector u = p - q;
    double t = cross(w, u) / cross(v, w);
    return p + v * t;
}

/// 点到直线距离，p 为点，ab 为直线
double distanceToLine(Point p, Point a, Point b) {
    Vector v1 = b - a, v2 = p - a;
    return fabs(cross(v1, v2) / length(v1));
}

/// 点到线段距离
double distanceToSegment(Point p, Point a, Point b) {
    if (a == b) return length(p - a);
    Vector v1 = b - a, v2 = p - a, v3 = p - b;
    if (dcmp(dot(v1, v2)) < 0) return length(v2);
    if (dcmp(dot(v1, v3)) > 0) return length(v3);
    return fabs(cross(v1, v2)) / length(v1);
}

/// 点在直线上的投影
Point lineProjection(Point p, Point a, Point b) {
    Vector v = b - a;
    return a + v * (dot(v, p - a) / dot(v, v));
}

/// 两线段相交（不含端点）
bool segmentProperIntersection(Point a1, Point a2, Point b1, Point b2) {
    // c1 == c2 == 0 表示量线段共线（可能有重合部分）
    // c1，c2 不全为零时有可能某个端点在另一条线段上
    double c1 = cross(a2 - a1, b1 - a1), c2 = cross(a2 - a1, b2 - a1);
    double c3 = cross(b2 - b1, a1 - b1), c4 = cross(b2 - b1, a2 - b1);
    return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}

/// 判 p 是否在 a1a2 上（不含端点）
bool onSegment(Point p, Point a1, Point a2) {
    return dcmp(cross(a1 - p, a2 - p)) == 0 && dcmp(dot(a1 - p, a2 - p)) < 0;
}

/**
 多边形的表示形式，为一个首地址为 p，长度为 n 的数组。
 */
struct Polygon {
    Point *p;
    int n;
};

/// 求多边形面积
double area(Point *p, int n) {
    double area = 0;
    for (int i = 1; i < n - 1; i++)
        area += cross(p[i] - p[0], p[i + 1] - p[0]);
    return fabs(area * 0.5);
}