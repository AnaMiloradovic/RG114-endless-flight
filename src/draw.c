#include "include/draw.h"



void draw_track(){
    glPushMatrix();

        // static GLfloat material_ambient[] = { 0, 1, 0, 1 };
        // static GLfloat material_diffuse[] = { 0, 1, 0, 1 };

        // glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
        // glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);

        glColor3f(0.3, 1, 0);
        glLineWidth(10);
        glBegin(GL_QUADS);
            glNormal3f(0, 1, 0);
            glVertex3f(0, 0, 10);
            glVertex3f(0, 0, -100);
            glVertex3f(6, 0, -100);
            glVertex3f(6, 0, 10);
        glEnd();

    glPopMatrix();
}

void draw_plane(){
    glPushMatrix();

        glColor3f(0, 0, 1);
        glTranslatef(player_x, 0, player_z);
        glTranslatef(0, 0, 1);
        glScalef(0.25, 0.25, 0.25);

        // static GLfloat material_ambient[] = { 0, 0, 0, 1 };
        // static GLfloat material_diffuse[] = { 0, 1, 0, 1 };

        // glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient);
        // glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);

        glBegin(GL_TRIANGLE_FAN);
            
            glVertex3f(0, 0, -5);
           
            glVertex3f(-3, 1, 0.5);
            
            glVertex3f(-0.25, 1, 0);
            
            glVertex3f(0, 0, 0);
            
            glVertex3f(0.25, 1, 0);
            
            glVertex3f(3, 1, 0.5);
        glEnd();

        // glutSolidSphere(0.5, 40, 40);

    glPopMatrix();
}