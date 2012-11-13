import sys
import os
g_path = os.getcwd()
sys.path.append(g_path+"\\lib")
import pygame
from pygame.locals import *
from OpenGL.GL import *
from OpenGL.GLU import *
from math import *


def glEnable2D():
	""" make opengl behave like you are drawing in 2d.
	"""
	vPort = glGetIntegerv(GL_VIEWPORT)

	glMatrixMode(GL_PROJECTION)
	glPushMatrix()
	glLoadIdentity()  

	glOrtho(0, vPort[2], 0, vPort[3], -1, 1)
	glMatrixMode(GL_MODELVIEW)
	glPushMatrix()
	glLoadIdentity()
	glDisable(GL_CULL_FACE);
	glClear(GL_DEPTH_BUFFER_BIT);


def glDisable2D():
	""" Use when you've finished drawing in 2D.
	"""
	glMatrixMode(GL_PROJECTION)
	glPopMatrix()
	glMatrixMode(GL_MODELVIEW)
	glPopMatrix()