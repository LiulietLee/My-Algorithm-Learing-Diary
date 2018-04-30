struct Point {
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) {}
};

// 定义两点减法
Point operator - (const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
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

// 求两向量夹角余弦值
double cosValueOfTwoVectors(Vector u, Vector v) {
    return (u * v) / (u.length() * v.length());
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
};
