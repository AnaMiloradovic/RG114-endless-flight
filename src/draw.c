#include "include/draw.h"

void draw_track(){
    glPushMatrix();

        glColor3f(0.3, 1, 0);

        GLfloat ambient_coeffs[] = { 1, 1, 0, 1 };
        GLfloat diffuse_coeffs[] = { 0.2, 1, 0, 1 };
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_coeffs);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_coeffs);

        glLineWidth(10);
        glBegin(GL_QUADS);
            glNormal3f(0, -1, 0);
            glVertex3f(0, 0, 10);
            glNormal3f(0, -1, 0);           
            glVertex3f(0, 0, -100);
            glNormal3f(0, -1, 0);
            glVertex3f(6, 0, -100);
            glNormal3f(0, -1, 0);
            glVertex3f(6, 0, 10);
        glEnd();

    glPopMatrix();
}

void draw_plane(){
    glPushMatrix();

        // glColor3f(0, 0, 1);
        GLfloat ambient_coeffs[] = { 0.8, 0.8, 0.85, 1 };
        GLfloat diffuse_coeffs[] = { 0.9, 0.9, 0.95, 1 };
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_coeffs);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_coeffs);

        glTranslatef(player_x, 0.2 + cos(y_param)/5, player_z);

        glScalef(0.25, 0.25, 0.25);

        float v0[] = {0, 0, -5};
        float v1[] = {-3, 1-cos(y_param), 0.5};
        float v2[] = {-0.25, 1, 0};
        float v3[] = {0, 0, 0};
        float v4[] = {0.25, 1, 0};
        float v5[] = {3, 1-cos(y_param), 0.5};

        glBegin(GL_TRIANGLES);
            glNormal3f(0,1,0);
            glVertex3fv(v0);  
            glNormal3f(0,1,0);         
            glVertex3fv(v1); 
            glNormal3f(0,1,0);           
            glVertex3fv(v2);

            glNormal3f(0,0.5,0);
            glVertex3fv(v0);   
            glNormal3f(0,0.5,0);        
            glVertex3fv(v2);
            glNormal3f(0,0.5,0);            
            glVertex3fv(v3);

            glNormal3f(0,-0.5,0);
            glVertex3fv(v0);  
            glNormal3f(0,-0.5,0);         
            glVertex3fv(v3); 
            glNormal3f(0,-0.5,0);           
            glVertex3fv(v4);

            glNormal3f(0,1,0);
            glVertex3fv(v0); 
            glNormal3f(0,1,0);           
            glVertex3fv(v4);
            glNormal3f(0,1,0);            
            glVertex3fv(v5);
        glEnd();

        // glutSolidSphere(0.5, 40, 40);

    glPopMatrix();
}

void set_normal_and_vertex_cylinder(float u, float v)
{
    glNormal3f(
            sin(v),
            0,
            cos(v)
            );
    glVertex3f(
            sin(v),
            u,
            cos(v)
            );
}

void set_normal_and_vertex_cone(float u, float v)
{
    glNormal3f(
            -u * sin(v),
            -u,
            u * cos(v)
            );
    glVertex3f(
            u / 10 * sin(v),
            u,
            u / 10 * cos(v)
            );
}

void draw_tree_1(){
    float u, v;

    glPushMatrix();

        glPushMatrix();
            glScalef(0.1, 1, 0.1);
            // crtamo stablo
            for (u = 0; u < 1; u += M_PI / 20) {
                glBegin(GL_TRIANGLE_STRIP);
                for (v = 0; v <= 2*M_PI + EPSILON; v += M_PI / 20) {
                    set_normal_and_vertex_cylinder(u, v);
                    set_normal_and_vertex_cylinder(u + M_PI / 20, v);
                }
                glEnd();
            }
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0, 1, 0);
            glScalef(0.8, 1.5, 0.8);
            // crtamo krosnju
            glutSolidSphere(0.5, 40, 40);
        glPopMatrix();

    glPopMatrix();
}

void draw_tree_2(){
    float u, v;

    glPushMatrix();

        glPushMatrix();
            glScalef(0.1, 1, 0.1);
            // crtamo stablo
            for (u = 0; u < 1; u += M_PI / 20) {
                glBegin(GL_TRIANGLE_STRIP);
                for (v = 0; v <= 2*M_PI + EPSILON; v += M_PI / 20) {
                    set_normal_and_vertex_cylinder(u, v);
                    set_normal_and_vertex_cylinder(u + M_PI / 20, v);
                }
                glEnd();
            }
        glPopMatrix();

        glPushMatrix();
            glRotatef(180, 0, 0, 1);
            glTranslatef(0, -3.5, 0);
            // glScalef(0.8, 1.5, 0.8);
            // crtamo krosnju
            for (u = 0; u < M_PI; u += M_PI / 20) {
                glBegin(GL_TRIANGLE_STRIP);
                for (v = 0; v <= 2*M_PI + EPSILON; v += M_PI / 20) {
                    set_normal_and_vertex_cone(u, v);
                    set_normal_and_vertex_cone(u + M_PI / 20, v);
                }
                glEnd();
            }
        glPopMatrix();

    glPopMatrix();
}