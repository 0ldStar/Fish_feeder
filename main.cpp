#include <cstring>
#include <GL/freeglut.h>
#include <windows.h>
#include <sstream>
#include <cmath>

int MOVE = 0;
bool ENTER = false;

#include <iostream>
#include "rocket.h"
#include "sparkles.h"
#include "arrow.h"
#include "text_field.h"
#include "OpenGL_func.h"
#include "primitive_quad.h"
#include "key_control.h"
#include "prerender.h"

using namespace std;


int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow) {
    WNDCLASSEX wcex;
    HWND hwnd;
    HDC hDC;
    HGLRC hRC;
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;
    float delta_y = 0.0f;
    int food_counter = 0;
    int point_counter = 0;
//________________________________________________________
    //Defining Rendering Options
    fish alpha;
    alpha.speed = 0.0045;
    alpha.buble_speed = 0.001;
    alpha.x = -0.5;
    alpha.y = 0.5;
    alpha.size = 0.3;

//________________________________________________________

    //FOOD CREATE
//________________________________________________________
    /* register window class */
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_OWNDC;
    wcex.lpfnWndProc = WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH) GetStockObject(BLACK_BRUSH);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = "GLSample";
    wcex.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);


    if (!RegisterClassEx(&wcex)) {
        return 0;
    }

    /* create main window */
    hwnd = CreateWindowEx(0,
                          "GLSample",
                          "OpenGL Sample",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          1000,
                          1000,
                          nullptr,
                          nullptr,
                          hInstance,
                          nullptr);

    ShowWindow(hwnd, nCmdShow);

    /* enable OpenGL for the window */
    EnableOpenGL(hwnd, &hDC, &hRC);
    glutInit(&_argc, _argv);
    while (!bQuit) {
        /* check for messages */
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT) {
                bQuit = TRUE;
            } else {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        } else {
            prerender(&hDC, &delta_y, &food_counter, &bQuit);
        }
    }
    bQuit = 0;
    food *a = new food[food_counter];
    for (int i = 0; i <= food_counter; i++) {
        if ((i % 4) == 0) {
            a[i].x = (pow(-1, i) * (float) (rand() % 10)) / 10;
            a[i].y = (pow(-1, i) * (float) (rand() % 10)) / 10;

        }
        if ((i % 4) == 1) {
            a[i].x = (pow(-1, i) * (float) (rand() % 10)) / 10;
            a[i].y = (pow(-1, i + 1) * (float) (rand() % 10)) / 10;
        }
        if ((i % 4) == 2) {
            a[i].x = (pow(-1, i + 1) * (float) (rand() % 10)) / 10;
            a[i].y = (pow(-1, i + 1) * (float) (rand() % 10)) / 10;
        }
        if ((i % 4) == 3) {
            a[i].x = (pow(-1, i + 1) * (float) (rand() % 10)) / 10;
            a[i].y = (pow(-1, i) * (float) (rand() % 10)) / 10;
        }
        a[i].size = (pow(-1, i + 1) * (float) (rand() % 5)) / 10;
    }
    /* program main loop */
    while (!bQuit) {
        /* check for messages */
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT) {
                bQuit = TRUE;
            } else {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        } else {
            /* OpenGL fish_animation code goes here */

            glClearColor(0.0f, 0.38f, 0.46f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            glLoadIdentity();


            for (int i = 0; i <= food_counter; i++) {
                a[i].food_skelet();
                double X = alpha.x + alpha.delta_x;
                double Y = alpha.y + alpha.delta_y;
                double x = a[i].x;
                double y = a[i].y;
                if ((abs(X - x) < abs(0.1 * a[i].size)) && (abs(Y - y) < abs(0.1 * a[i].size))) {
                    alpha.size += abs(a[i].size / 10);
                    a[i].size = 0;
                    point_counter++;
                }
            }
            // char *a = itoa(point_counter);
            ostringstream ss;
            ss << point_counter;
            Print_text(0.9, -0.9, 0, 0, 0, ss.str());
            alpha.fish_animation();
            if (point_counter == food_counter) {
                MOVE = 4;
                QUAD(-0.2, 0.2, 0.6, 0.2, "YOU WON!!!");
            }
            SwapBuffers(hDC);

            theta += 1.0f;
            Sleep(1);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL(hwnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow(hwnd);

    return msg.wParam;
}









