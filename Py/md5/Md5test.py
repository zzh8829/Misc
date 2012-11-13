#=================================
#==== OpenGL.Test Framework ======
#========  Zihao Zhang  ==========
#======  Copyleft @2012  =========
#=================================

# Add Custom Libraries
import sys
import os
g_path = os.getcwd()
sys.path.append(g_path+"\\lib")
# Import Libraries
import OpenGL
import pygame
from pygame.locals import *
from OpenGL.GL import *
from OpenGL.GLU import *
from math import *
from random import *
from MD5Model import *
from ColorRGB import *
from GLUtil import *
from OBJLoader import *
step = 5;
xRot = 0;
yRot = 0;

background = BLACK
#gl_option = (HWSURFACE|OPENGL|DOUBLEBUF|FULLSCREEN)
gl_size = (1024,600)
gl_option = (OPENGL|DOUBLEBUF)
TITLE = "PyGame 3D Window"
ID_VIEW = 0
ID_FRONT = 1
ID_BACK = 2

FPS = 30

class CGame(object):
		"""Main Class"""
		def __init__(self):
			self.screen_size = gl_size
			self.display_init(self.screen_size)	
			self.running = True
			self.change = 1
			self.x_trans = 0
			self.y_trans = 0
			self.choose = 0
			self.listx = [ 0 for i in range(10)]
			self.listy = [ 0 for i in range(10)]
			self.clock = pygame.time.Clock()
			self.frame = 0
			self.mesh = MD5_Model()
			self.mesh.LoadMesh("hellknight.md5mesh")
			self.mesh.AddAnimation("walk.md5anim")
			self.mesh.ChooseAnimation(0)
			#self.obj = OBJ("garen.obj",swapyz=False)
			self.rotx,self.roty = (0,0)

			self.trax = 0
			self.tray = 0

		def run(self):
			while self.running:
				self.ResetBackground()
				self.event_handler(pygame.event.get())
				self.key_handler(pygame.key.get_pressed())

				glPushMatrix()
				self.DrawBeginScene()
				self.DrawMidScene()
				self.DrawEndScene()
				glPopMatrix()
				self.timer()
				pygame.display.flip()
			
		
		def display_init(self,screen_size):
			pygame.display.init()
			self.screen = pygame.display.set_mode(screen_size,gl_option)
			pygame.display.set_caption(TITLE)
			#icon = pygame.image.load(g_path+"\\res\\icon_48.png")
			#pygame.display.set_icon(icon)
			glClearColor(*background)
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
			
			self.w = self.screen_size[0]
			self.h = self.screen_size[1]
			aspectRatio= self.w/self.h;
			glViewport(0,0,self.w,self.h);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(25.0, self.w/self.h, 1 , 10000.0)
			#glOrtho(-100.0*aspectRatio,100.0*aspectRatio,-100.0,100.0,100.0,-100.0);
			glEnable (GL_DEPTH_TEST);
			'''
			glLightfv(GL_LIGHT0, GL_POSITION,  (-40, 200, 100, 0.0))
			glLightfv(GL_LIGHT0, GL_AMBIENT, (0.2, 0.2, 0.2, 1.0))
			glLightfv(GL_LIGHT0, GL_DIFFUSE, (0.5, 0.5, 0.5, 1.0))
			glEnable(GL_LIGHT0)
			glEnable(GL_LIGHTING)
			glEnable(GL_COLOR_MATERIAL)
			glEnable(GL_DEPTH_TEST)
			glShadeModel(GL_SMOOTH)   
			'''
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();

			pygame.mouse.set_visible(False)
		def ResetBackground(self):
			glClearColor(*background)
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)

		def DrawBeginScene(self):
			glEnable2D()

			glPushMatrix()
			glTranslatef(self.listx[ID_BACK],self.listy[ID_BACK],0.0)
			glBegin(GL_QUADS);
			glColor3f(0.0, 0.0, 1.0);
			glVertex2f(self.w-20, self.h);
			glVertex2f(self.w-20, self.h-20);
			glVertex2f(self.w, self.h-20);
			glVertex2f(self.w, self.h);
			glEnd();
			glPopMatrix()

			glDisable2D()

		def DrawMidScene(self):
			glColor4f(*WHITE)
			glTranslatef(0.0,0.0,self.listy[ID_VIEW])
			glRotate(self.rotx, 0, 1, 0)
			glRotate(-90, 1, 0, 0)
			#'''
			glPushMatrix()
			#glRotatef(xRot,1.0,0.0,0.0)
			#glRotatef(yRot,0.0,1.0,0.0)
			#glRotatef(45,0.0,1.0,0.0)
			self.mesh.Render()
			glPopMatrix()
			#'''
			'''
			glPushMatrix()
			
			glRotate(self.roty, 1, 0, 0)
			glRotate(self.rotx, 0, 1, 0)
			glCallList(self.obj.gl_list)
			glPopMatrix()
			'''
			'''
			cstep=0.04
			curSize=2
			z = -100.0
			glPushMatrix()
			glTranslatef(self.listx[ID_VIEW],self.listy[ID_VIEW],0.0)
			glRotatef(xRot,1.0,0.0,0.0)
			glRotatef(yRot,0.0,1.0,0.0)
			glLineWidth(3)
			glBegin(GL_LINE_STRIP)
			for rotate in range(0,int(2*pi*3*100000),5000):
				angle = rotate/10000
				x = 50.0*sin(angle)
				y = 50.0*cos(angle)
				glColor3f(random(),random(),random())
				glVertex3f(x, y, z)
				z += 0.5
				curSize +=cstep
			glEnd()
			glPopMatrix()
			'''
		def DrawEndScene(self):

			glEnable2D()

			glPushMatrix()
			glTranslatef(self.listx[ID_FRONT],self.listy[ID_FRONT],0.0)
			glBegin(GL_QUADS);
			glColor3f(1.0, 0.0, 0.0);
			glVertex2f(0.0, 0.0);
			glVertex2f(20.0, 0.0);
			glVertex2f(20.0, 20.0);
			glVertex2f(0.0, 20.0);
			glEnd();
			glPopMatrix()

			glDisable2D()

		def timer(self):
			global xRot,yRot,step
			'''
			if self.change :
				xRot+=step;
				yRot+=step;
			if(xRot>=360 or xRot <=-360 or yRot >=360 or yRot<=-360):
				xRot=0
				yRot=0
				#step = -step;
			'''
			self.clock.tick(FPS)
			if self.frame >= self.mesh.numFrames:
				self.frame = 0
			self.mesh.SetFrame(self.frame)
			self.frame+=1
			#pygame.mouse.set_pos([self.w/2, self.h/2])
			pygame.display.set_caption(TITLE +' FPS: %d' % self.clock.get_fps())

		def key_handler(self,keys):
			if keys[ord('a')]:
				self.x_trans=-5
			if keys[ord('d')]:
				self.x_trans=5
			if keys[ord('w')]:
				self.y_trans=5
			if keys[ord('s')]:
				self.y_trans=-5
			self.listx[self.choose]+=self.x_trans
			self.listy[self.choose]+=self.y_trans
			self.x_trans = self.y_trans = 0
		
		def event_handler(self,events):
			for event in events:
				if event.type == QUIT:
					self.running = False
				if event.type == KEYUP:
					if event.key == K_ESCAPE:
						self.running = False
					elif event.key == K_SPACE:
						self.change = not self.change
					elif event.key == K_1:
						self.choose = ID_VIEW
					elif event.key == K_2:
						self.choose = ID_FRONT
					elif event.key == K_3:
						self.choose = ID_BACK
				if event.type == MOUSEMOTION:
					i,j = event.rel
					self.rotx += i
					#self.roty += j
if __name__ == '__main__':
	game = CGame()
	game.run()
	pygame.quit()
