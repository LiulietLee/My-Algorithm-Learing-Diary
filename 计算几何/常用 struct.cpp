struct Point {
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) {}
};

// 定义两点减法
Point operator - (const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
}

Point operator + (const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y);
}

struct Circle {
    Point center;
    double radius;
    Circle(Point c = Point(), double r = 0): center(c), radius(r) {}
};

struct Vector {
    double x, y;
    Vector(double x = 0, double y = 0): x(x), y(y) {}
    Vector(Point p): x(p.x), y(p.y) {}
    // 求该向量的正交单位向量
    Vector vertical() {
        double dis = sqrt(x * x + y * y);
        return Vector(-y / dis, x / dis);
    }
    // 取相反向量
    Vector reverse() {
        return Vector(-x, -y);
    }
    // 求向量的模
    double length() {
        return sqrt(x * x + y * y);
    }
    // 返回该向量延逆时针方向旋转至某一角度后的向量
    Vector rotate(double angle) {
        return Vector(x * cos(angle) - y * sin(angle), y * cos(angle) + x * sin(angle));
    }
    // 向量转化为点坐标
    Point toPoint() {
        return Point(x, y);
    }
};

// 向量数量积
double operator * (const Vector &a, const Vector &b) {
    return a.x * b.x + a.y * b.y;
}
// 向量数乘
Vector operator * (const double &a, const Vector &b) {
    return Vector(b.x * a, b.y * a);
}

// 向量叉积的模
double cross(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

// 求两向量夹角余弦值
double cosValueOfTwoVectors(Vector u, Vector v) {
    return (u * v) / (u.length() * v.length());
}

bool doubleEqual(double a, double b) {
    return fabs(a - b) < EPS;
}

struct Line {
    Point p1, p2;
    Line(Point p1 = Point(), Point p2 = Point()): p1(p1), p2(p2) {}
    // 取线段中点
    Point midPoint() {
        return Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
    }
    // 线段转化为向量，方向为 p2 -> p1
    Vector toVector() {
        return Vector(p1 - p2);
    }
    // 获取线段长度
    double length() {
        return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }
    // 判断点是否在线上
    bool isContainPoint(Point p) {
        return doubleEqual(cross(Vector(p1 - p), Vector(p2 - p)), 0) && Vector(p1 - p) * Vector(p2 - p) < EPS;
    }
};

struct InfinityLine {
    double k, b;
    InfinityLine(double k = 0, double b = 0):
        k(k), b(b) {}
    // 获取 x 对应的 y 值
    double valueOf(double x) {
        return k * x + b;
    }
};

// 求两直线交点，没有交点时返回 nil
Point* intersectionOfInfinityLines(InfinityLine a, InfinityLine b) {
    if (doubleEqual(a.k, b.k)) return nil;
    static Point p = Point();
    double x = (b.b - a.b) / (a.k - b.k);
    double y = a.valueOf(x);
    p = Point(x, y);
    return &p;
}

// 求两线段交点，没有交点时返回 nil
Point* intersectionOfLines(Line a, Line b) {
    if (doubleEqual(cross(a.toVector(), b.toVector()), 0)) return nil;
    static Point p = Point();
    Vector offset = (cross(b.toVector(), Vector(b.p1 - a.p1)) / cross(b.toVector(), Vector(a.p2 - a.p1))) * Vector(a.p2 - a.p1);
    p = a.p1 + offset.toPoint();
    if (a.isContainPoint(p) && b.isContainPoint(p)) {
        return &p;
    } else {
        return nil;
    }
}