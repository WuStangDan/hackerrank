string kangaroo(int x1, int v1, int x2, int v2) {
    if (x1 >= x2) {
        if (v1 > v2)
            return "NO";
    } else {
        if (v2 > v1)
            return "NO";
    }
    int fast_x, fast_v;
    int slow_x, slow_v;
    if (v1 > v2) {
        fast_x = x1;
        fast_v = v1;
        slow_x = x2;
        slow_v = v2;
    } else {
        fast_x = x2;
        fast_v = v2;
        slow_x = x1;
        slow_v = v1;
    }
    int fast_jump = 0;
    int slow_jump = 0;
    while (true) {
        if (fast_x == slow_x && fast_jump == slow_jump)
            return "YES";
        if (fast_jump < slow_jump && fast_x > slow_x) {
            //cout << fast_jump << "<" << slow_jump << " " << fast_x << ">" << slow_x << endl;
            return "NO";
        }
        if (fast_x < slow_x) {
            fast_x += fast_v;
            fast_jump += 1;
        } else {
            slow_x += slow_v;
            slow_jump += 1;
        }
    }
    return "NO";
}
