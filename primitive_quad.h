void QUAD(float x, float y, float width, float height, std::string str) {
    glColor3f(0, 1, 1);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x, y - height);
    glVertex2f(x + width, y - height);
    glVertex2f(x + width, y);
    glEnd();
    glColor3f(0, 0, 0);
    printf("%f\n",((str.length()+1.0)/2)*0.012);
    glRasterPos2d(x + width / 2- ((str.length()+1.0)/2)*0.02, y - height / 2);
    glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char *) str.c_str());

}