#include <cmath>

class food {
public:
    double x = 0, y = 0;
    double size = 0.5;

    void food_skelet(){
        glPushMatrix();
        double x1, y1;
        int b = 50;
        double l = 0.1;
        double a = M_PI * 2 / b;
        glTranslatef(x,y,0);
        glScalef(size,size,1);
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1, 1, 1);
        for (int i = -1; i < b; i++) {
            x1 = sin(a * i) * l;
            y1 = cos(a * i) * l;
            glVertex2f(x1 , y1);
        }
        glEnd();
        glPopMatrix();
    }

};

