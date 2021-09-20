void Print_text(float x, float y, float r, float g, float b, const std::string str) {
    glColor3f(r, g, b);
    glRasterPos2d(x, y);
    glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char *) str.c_str());
}