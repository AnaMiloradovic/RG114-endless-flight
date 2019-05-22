#include "include/draw.h"

void draw_track(){
    // glColor3f(0, 1, 0);
    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, names[0]);
        glBegin(GL_QUADS);
            glNormal3f(0, 1, 0);

            glTexCoord2f(0, 0);
            glVertex3f(-100, -0.1, 10);
            glTexCoord2f(30, 0);
            glVertex3f(106, -0.1, 10);          
            glTexCoord2f(30, 30);
            glVertex3f(-100, -0.1, -100);
            glTexCoord2f(0, 30);
            glVertex3f(106, -0.1, -100);
            
        glEnd();
        glDisable(GL_TEXTURE_2D);

    glPopMatrix();

    glPushMatrix();

        GLfloat ambient_coeffs[] = { 1, 1, 0, 1 };
        // GLfloat diffuse_coeffs[] = { 0.2, 1, 0, 1 };
        GLfloat diffuse_coeffs[] = { 0.86, 0.7, 0.57, 1 };
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_coeffs);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_coeffs);

        // glLineWidth(10);
        glBegin(GL_POLYGON);
            glNormal3f(0, -1, 0);

            glVertex3f(0, 0, 10);
            glVertex3f(0, 0, -100);
            glVertex3f(6, 0, -100);
            glVertex3f(6, 0, 10);
        glEnd();

    glPopMatrix();
}

void draw_plane(){

    float v0[] = {0, 0, -5};
    float v1[] = {-3, 1-cos(y_param*speed), 0.5};
    float v2[] = {-0.25, 1, 0};
    float v3[] = {0, 0, 0};
    float v4[] = {0.25, 1, 0};
    float v5[] = {3, 1-cos(y_param*speed), 0.5};

    glPushMatrix();

        GLfloat ambient_coeffs_plane[] = { 0.8, 0.8, 0.85, 0.5 };
        GLfloat diffuse_coeffs_plane[] = { 0.9, 0.9, 0.95, 1 };
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_coeffs_plane);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_coeffs_plane);

        glTranslatef(player_x, 0.2 + cos(y_param)/5, player_z+1);

        glScalef(0.2, 0.2, 0.2);

        glBegin(GL_TRIANGLES);
            glNormal3f(0,1,0);
            glVertex3fv(v0);  
            glVertex3fv(v1); 
            glVertex3fv(v2);

            glNormal3f(1,0.25,0);
            glVertex3fv(v0);   
            glVertex3fv(v2);
            glVertex3fv(v3);

            glNormal3f(-1,0.25,0);
            glVertex3fv(v0);  
            glVertex3fv(v3); 
            glVertex3fv(v4);

            glNormal3f(0,1,0);
            glVertex3fv(v0); 
            glVertex3fv(v4);
            glVertex3fv(v5);
        glEnd();

    glPopMatrix();
}

void draw_tree_1(){

    glPushMatrix();

        // Drawing tree
        glPushMatrix();
            GLfloat diffuse_coeffs_tree1[] = { 0.169, 0.114, 0.055, 1 };
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_coeffs_tree1);
            glTranslatef(0, 1, 0);
            glRotatef(90, 1, 0, 0);
            
            GLUquadricObj *tree1 = gluNewQuadric();
            gluCylinder(tree1, 0.1, 0.1, 1, 40, 40);
        glPopMatrix();
        
        // Drawing treetop
        glPushMatrix();
            GLfloat diffuse_coeffs_treetop1[] = { 0.0, 0.5, 0.0, 1 };
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_coeffs_treetop1);
            glScalef(1, 1, 1);
            glTranslatef(0, 1.3, 0);
           
            glutSolidSphere(0.6, 40, 40);
        glPopMatrix();

    glPopMatrix();
}

void draw_tree_2(){

    glPushMatrix();

        // Drawing tree
        glPushMatrix();
            GLfloat diffuse_coeffs_tree2[] = { 0.396, 0.263, 0.129, 1 };
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_coeffs_tree2);
            glTranslatef(0, 1, 0);
            glRotatef(90, 1, 0, 0);

            GLUquadricObj *tree2 = gluNewQuadric();
            gluCylinder(tree2, 0.1, 0.1, 1, 40, 40);
        glPopMatrix();

        // Drawing treetop
        glPushMatrix();
            GLfloat diffuse_coeffs_treetop2[] = { 0.0, 0.19, 0.0, 1 };
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_coeffs_treetop2);
            glTranslatef(0, 0.2, 0);
            glRotatef(-90, 1, 0, 0);
            
            GLUquadricObj *treetop2 = gluNewQuadric();
            gluCylinder(treetop2, 0.5, 0.0, 2, 40, 40);
        glPopMatrix();

    glPopMatrix();
}