#include <GL/glut.h>
#include <cmath>
#include<algorithm>
void setPixel(int x, int y) {
glBegin(GL_POINTS);
glVertex2i(x, y);
glEnd();
}
void ddaLine(int x1, int y1, int x2, int y2) {
int dx = x2 - x1;
int dy = y2 - y1;
int steps = std::max(std::abs(dx), std::abs(dy)); 
float xIncrement = float(dx) / steps;
float yIncrement = float(dy) / steps;
float x = x1, y = y1;
for (int i = 0; i < steps; i++) {
setPixel(round(x), round(y));
x += xIncrement;
y += yIncrement;
}
}
void Bresenham(int x1, int y1, int x2, int y2) {
int dx = abs(x2 - x1);
int dy = abs(y2 - y1);
int incx = (x2 > x1) ? 1 : -1;
int incy = (y2 > y1) ? 1 : -1;
int x = x1, y = y1;
glBegin(GL_POINTS);
if (dx > dy) {
int p = 2 * dy - dx;
for (int i = 0; i <= dx; i++) {
glVertex2i(x, y);
x += incx;
if (p >= 0) {
y += incy;
p -= 2 * dx;
}
p += 2 * dy;
}
} else {
int p = 2 * dx - dy;
for (int i = 0; i <= dy; i++) {
glVertex2i(x, y);
y += incy;
if (p >= 0) {
x += incx;
p -= 2 * dy;
}
p += 2 * dx;
}
}
glEnd();
}
void display() {
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0, 1.0, 1.0);
// Draw letter 'S' using DDA
ddaLine(50, 250, 150, 250);
ddaLine(150, 250, 150, 300);
ddaLine(150, 300, 50, 300);
ddaLine(50, 300, 50, 350);
ddaLine(50, 350, 150, 350);
// Draw letter 'A' using DDA
Bresenham(170, 250, 220, 350);
Bresenham(220, 350, 270, 250);
ddaLine(195, 300, 245, 300);
// Draw letter 'B' using DDA
ddaLine(290, 250, 290, 350);
ddaLine(290, 350, 390, 350);
ddaLine(390, 350, 390, 300);
ddaLine(390, 300, 290, 300);
ddaLine(390, 300, 390, 250);
ddaLine(390, 250, 290, 250);
glFlush();
}
int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(800, 400);
glutCreateWindow("FIRST THREE CHARACTERS OF MY NAME");
gluOrtho2D(0, 800, 0, 400);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
