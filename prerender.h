void prerender(HDC *hDC, float *delta_y, int *food_counter, BOOL *bQuit) {
    glClearColor(0.0f, 0.38f, 0.46f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    Print_text(-0.16, 0.3, 1, 1, 0, "FISH FEEDER");
    Print_text(-0.4, 0.2, 1, 1, 0, "HOW MUCH FOOD DO YOU WANT?");
    QUAD(-0.2, 0.1, 0.4, 0.1, "5");
    QUAD(-0.2, -0.05, 0.4, 0.1, "50");
    QUAD(-0.2, -0.2, 0.4, 0.1, "100");
    Arrow(-0.2, 0.05f + *delta_y);
    if (MOVE == 1) {
        *delta_y += 0.15f;
        MOVE = -1;
    }
    if (MOVE == 3) {
        *delta_y -= 0.15f;
        MOVE = -1;
    }
    printf("%d\n", (int) (*delta_y * 100) / 15);
    if (abs(*delta_y - 0.15f) < 0.001) *delta_y = -0.3f;
    if (abs(*delta_y + 0.45f) < 0.001) *delta_y = 0.0f;
    if (ENTER) {
        switch ((int) (*delta_y * 100) / 15) {
            case 0:
                *food_counter = 5;
                break;
            case -1:
                *food_counter = 50;
                break;
            case -2:
                *food_counter = 100;
                break;
            default:
                break;
        }
        ENTER = false;
        *bQuit = 1;
    }
    SwapBuffers(*hDC);
}