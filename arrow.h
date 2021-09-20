void Arrow(float x, float y) {
    glTranslatef(x - 0.01, y, 0);
    glScalef(0.5, 0.5, 1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0, 0);
    glVertex2f(-0.1, 0.1);
    glVertex2f(-0.1, -0.1);
    glEnd();
}