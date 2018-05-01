#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <functional>
#define MAXSIZE 50010
#define MAXN 9999
#define MAXND MAXN / 10
#define INF 99999999
#define MAXEDGE 1000000
#define MAXVERTEX 10
#define EPS 0.00001
#define PI 3.14159265
#define nil NULL
typedef long long ll;
using namespace std;

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

// 以该边向外生成一个等边三角形，返回此三角形的外接圆
Circle generateCircleFromLineAndPoint(Line line, Point p) {
    Point mid = line.midPoint();
    Vector v = line.toVector();
    Vector vv = v.vertical();
    
    // 判断生成的向量是否指向三角形内部
    if (vv * Vector(p.x - mid.x, p.y - mid.y) > EPS) {
        // 如果指向内部需要将其反向
        vv = vv.reverse();
    }
    
    double dis = line.length() / (2 * sqrt(3));
    double xOffset = vv.x * dis;
    double yOffset = vv.y * dis;
    Point center = Point(mid.x + xOffset, mid.y + yOffset);
    double r = Line(center, line.p1).length();
    return Circle(center, r);
}

// 判断两 double 型是否相等
bool doubleEqual(double a, double b) {
    return fabs(a - b) < EPS;
}

// 求两圆交点
vector<Point> crossPointsWithCircles(Circle a, Circle b) {
    vector<Point> result;
    
    double dis = Line(a.center, b.center).length();
    // 如果无交点直接返回空 result
    if (dis > a.radius + b.radius || dis < fabs(a.radius - b.radius)) {
        return result;
    }
    
    // 基于圆 a 和 b 生成两个位于 x 轴上的新圆，求出新圆的一个交点
    Circle cala = Circle(Point(), a.radius);
    Circle calb = Circle(Point(dis, 0), b.radius);
    double calCrossX = (cala.radius * cala.radius + dis * dis - calb.radius * calb.radius) / (2 * dis);
    double calCrossY = sqrt(cala.radius * cala.radius - calCrossX * calCrossX);
    
    // 求出新圆圆心连线生成的向量与 x 正方向的夹角
    Vector horV = Vector(1, 0);
    Vector circleCenterV = Vector(b.center - a.center);
    double angle = acos(cosValueOfTwoVectors(horV, circleCenterV));
    if (circleCenterV.y < 0) {
        angle = 2 * PI - angle;
    }
    
    // 通过坐标变换将新圆交点转化为 a 和 b 的交点
    Vector offset = Vector(a.center);
    Vector crossV = Vector(calCrossX, calCrossY);
    crossV = crossV.rotate(angle);
    crossV.x += offset.x; crossV.y += offset.y;
    result.push_back(crossV.toPoint());
    
    // 如果判断是否有第二个交点
    if (doubleEqual(0, calCrossY)) {
        return result;
    }
    
    // 求第二个交点坐标
    crossV = Vector(calCrossX, -calCrossY);
    crossV = crossV.rotate(angle);
    crossV.x += offset.x; crossV.y += offset.y;
    result.push_back(crossV.toPoint());
    
    return result;
}

// 处理 -0.000 的情况
double flush(double n) {
    if (doubleEqual(0, n)) {
        return 0;
    } else {
        return n;
    }
}

int main() {
    Point p[3];
    
    for (int i = 0; i < 3; i++) {
        cin >> p[i].x >> p[i].y;
    }
    
    // 判断有没有大于 120° 的角，如果有的话角的顶点就是答案
    for (int i = 0; i < 3; i++) {
        Vector v1 = Vector(p[(i + 1) % 3] - p[i]);
        Vector v2 = Vector(p[(i + 2) % 3] - p[i]);
        if (cosValueOfTwoVectors(v1, v2) < -0.5) {
            printf("%.6f %.6f", p[i].x, p[i].y);
            return 0;
        }
    }
    
    // 如果没有大于 120° 的角，则找到一点使得该点与另外三点中任意两点连线形成的角均为 120°
    Circle c1 = generateCircleFromLineAndPoint(Line(p[0], p[1]), p[2]);
    Circle c2 = generateCircleFromLineAndPoint(Line(p[1], p[2]), p[0]);
    
    vector<Point> crossPoints = crossPointsWithCircles(c1, c2);
    for (vector<Point>::iterator it = crossPoints.begin(); it != crossPoints.end(); it++) {
        bool isVertex = false;
        // 这里需要判断交点是不是三个点之一
        for (int i = 0; i < 3; i++) {
            if (Line(p[i], *it).length() < EPS) {
                isVertex = true;
                break;
            }
        }
        if (!isVertex) {
            printf("%.6f %.6f", flush(it->x), flush(it->y));
            break;
        }
    }
    
    return 0;
}
