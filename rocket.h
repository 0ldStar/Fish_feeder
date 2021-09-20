

class fish {
public:
    float delta_x = 0;
    float delta_y = 0;
    float buble_delta_y = 0;
    float speed = 0;
    float buble_speed = 0;
    float x = 0, y = 0;
    double size = 0;


    void fish_skelet() {
        glRotatef(90 * MOVE, 0, 0, 1);
        glScalef(size, size, 1);
        glRotatef(135, 0, 0, 1);
        //Body
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0, 0, 0);
        glVertex2f(0.02, 0.02);
        glColor3f(1, 0, 0);
        glVertex2f(0.5, 0);
        glColor3f(0, 1, 0);
        glVertex2f(0, 0.5);
        glEnd();
        //Tail
        glTranslatef(0.25, 0.25, 0);
        glScaled(0.5, 0.5, 0.5);
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0, 0, 0);
        glVertex2f(0, 0);
        glColor3f(1, 0, 0);
        glVertex2f(0.5, 0);
        glColor3f(0, 1, 0);
        glVertex2f(0, 0.5);
        glEnd();

        double x1, y1;
        int b = 50;
        double l = 0.1;
        double a = M_PI * 2 / b;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1, 1, 1);
        for (int i = -1; i < b; i++) {
            x1 = sin(a * i) * l;
            y1 = cos(a * i) * l;
            glVertex2f(x1 - 0.35, y1 - 0.35);
        }
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        for (int i = -1; i < b; i++) {
            x1 = sin(a * i) * l / 1.5;
            y1 = cos(a * i) * l / 1.5;
            glColor3f(0, 0, 0);
            glVertex2f(x1 - 0.35, y1 - 0.35);
        }
        glEnd();
    }

    void fish_animation() {
        glPushMatrix();
        //bubble_animation();
        switch (MOVE) {
            case (0):
            case (1):
                speed = abs(speed);
                break;
            case (2):
            case (3):
                speed = -abs(speed);
                break;
            default:
                break;
        }
        glTranslatef(x + delta_x, y + delta_y, 0);
        if ((x + delta_x - 0.5 * size) > 1) {
            x = -1;
            delta_x = 0;
        }
        if ((x + delta_x + 0.5 * size) < -1) {
            x = 1;
            delta_x = 0;
        }
        if ((y + delta_y - 0.5 * size) > 1) {
            y = -1;
            delta_y = 0;
        }
        if ((y + delta_y + 0.5 * size) < -1) {
            y = 1;
            delta_y = 0;
        }
        fish_skelet();
        glPopMatrix();

        if ((MOVE == 0) || (MOVE == 2))delta_x += speed;
        if ((MOVE == 1) || (MOVE == 3))delta_y += speed;
        buble_delta_y += buble_speed;
    }

};

