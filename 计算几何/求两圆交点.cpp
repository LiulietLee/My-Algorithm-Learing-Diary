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