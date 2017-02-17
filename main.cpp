#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;
static int year = 0;
int speed;
int score=0;
char ch='a';
int chance=0;
int level;

void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    //glColor3f (1.0, 1.0, 1.0);




/////red1
    glPushMatrix();
    glColor3f (1.0, 0.0, 0.0);
    glRotatef ((GLfloat) year, 0.0, 1.0, 0.0);
    //cout<<year<<endl;
    glTranslatef (2.0, 0.0, 0.0);
    glutSolidSphere(0.2, 10, 8);
    glPopMatrix();

//////green1
    glPushMatrix();
    glColor3f (0.0, 1.0, 0.0);
    glRotatef ((GLfloat) year+60, 0.0, 1.0, 0.0);

    glTranslatef (2.0, 0.0, 0.0);
    glutSolidSphere(0.2, 10, 8);
    glPopMatrix();


    ////blue1
    glColor3f (0.0, 0.0, 1.0);
    glPushMatrix();
    glRotatef ((GLfloat) year+120, 0.0, 1.0, 0.0);

    glTranslatef (2.0, 0.0, 0.0);
    glutSolidSphere(0.2, 10, 8);
    glPopMatrix();


    //red2
    glPushMatrix();
    glColor3f (1.0, 0.0, 0.0);
    glRotatef ((GLfloat) year+180, 0.0, 1.0, 0.0);

    glTranslatef (2.0, 0.0, 0.0);
    glutSolidSphere(0.2, 10, 8);
    glPopMatrix();


    ////green2
    glPushMatrix();
    glColor3f (0.0, 1.0, 0.0);
    glRotatef ((GLfloat) year+240, 0.0, 1.0, 0.0);

    glTranslatef (2.0, 0.0, 0.0);
    glutSolidSphere(0.2, 10, 8);
    glPopMatrix();

    ////blue2
    glPushMatrix();
    glColor3f (0.0, 0.0, 1.0);
    glRotatef ((GLfloat) year+300, 0.0, 1.0, 0.0);
    glTranslatef (2.0, 0.0, 0.0);
    glutSolidSphere(0.2, 10, 8);
    glPopMatrix();

    if(ch=='r')
    {
        glColor3f (1.0, 0.0, 0.0);
        glPushMatrix();
        // glRotatef ((GLfloat) year, 0.0, 1.0, 0.0);
        glTranslatef (0.0, 0.0, 2.0);
        glutSolidSphere(0.05, 10, 8);
        glPopMatrix();
        if((year>=85&&year<=95)||(year>=265&&year<=275))
        {
            score++;
            cout<<"Score : "<<score<<"\n";
        }
        else
        {
            cout<<"Score : "<<"Failed"<<"\n";
        }
        Sleep(50);
        ch='a';

    }

    else if(ch=='g')
    {
        glColor3f (0.0, 1.0, 0.0);
        glPushMatrix();

        glTranslatef (0.0, 0.0, 2.0);
        glutSolidSphere(0.2, 10, 8);
        glPopMatrix();
        if((year>=25&&year<=35)||(year>=205&&year<=215))
        {
            score++;
            cout<<"Score : "<<score<<"\n";
        }
        else
        {
            cout<<"Score : "<<"Failed"<<"\n";
        }
        Sleep(50);
        ch='a';

    }

    else if(ch=='b')
    {
        glColor3f (0.0, 0.0, 1.0);
        glPushMatrix();

        glTranslatef (0.0, 0.0, 2.0);
        glutSolidSphere(0.2, 10, 8);
        glPopMatrix();
        if((year>=145&&year<=155)||(year>=325&&year<=335))
        {
            score++;
            cout<<"Score : "<<score<<"\n";
        }
        else
        {
            cout<<"Score : "<<"Failed"<<"\n";
        }
        Sleep(50);
        ch='a';

    }

    if(chance>4)
    {
        cout<<"\n\nFinal Score : "<<score<<"\n";
        exit(-1);

    }
    glutPostRedisplay();

    glFlush();

    glutSwapBuffers();
}

void spinning()
{
    year = (year + 5) % 360;
    Sleep(speed);
    glutPostRedisplay();
}


void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard (unsigned char key, int x, int y)
{
    switch (key)
    {

    case 'r':
        ch='r';
        chance++;
        break;

    case 'g':
        ch='g';
        chance++;
        break;


    case 'b':
        ch='b';
        chance++;
        break;
    }
}

int main(int argc, char** argv)
{

    cout<<"Enter Level (1 or 2) :\n";

    cin>>level;
    if(level==1)
    {
        speed=500;
    }
    else if(level==2)
    {
        speed=50;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(spinning);
    glutMainLoop();
    return 0;
}
