#=================================
#====  MD5Mesh/Anim Loader  ======
#========  Zihao Zhang  ==========
#======  Copyleft @2012  =========
#=================================


import sys
import os
g_path = os.getcwd()
sys.path.append(g_path+"\\lib")
#sys.stdout = open("hello.txt",'w')
from types import *
from math import *
from Math3D import *
from OpenGL.GL import *
from OpenGL.GLU import *
import pygame
from pygame.locals import *
import numpy as np
from ColorRGB import *

class MD5_Bone():
	def __init__(self):
		self.index = 0 
		self.name = ""
		self.parent_index = 0
		self.flag = 0
		self.frame_offset = 0
		self.start_index = 0
		self.parent = ""

		self.bindpos = [0]*3
		self.bindmat = [None]*3
		for i in range(3): self.bindmat[i] = [0.0]*3

		# TODO: Vector and Quaternion Class
		self.position = Vector3()
		self.orientation = Quaternion()
		self.child = 0

class MD5_Bound():
	def __init__(self):
		self.min = Vector3()
		self.max = Vector3()

class MD5_Vert():
	def __init__(self):
		self.index = 0
		self.u = 0
		self.v = 0
		self.weight_index = 0
		self.weight_count = 0
		
		self.normal = Vector3()
		self.pos = Vector3()
		self.tex0 = Vector2()

class MD5_Tri():
	def __init__(self):
		self.index = 0
		self.x = 0
		self.y = 0
		self.z = 0

		self.indices = [0 for i in range(3)]

class MD5_Weight():
	def __init__(self):
		self.index = 0
		self.bone_index = 0
		self.bias = 0
		self.x = 0
		self.y = 0
		self.z = 0

		self.position = Vector3()

class MD5_Mesh():
	def __init__(self):
		self.index = 0

		self.shader = ""
		self.textid = 0

		self.numverts = 0 
		self.numtris = 0 
		self.numweights = 0
		self.verts = []
		self.tris = []
		self.weights = []

		self.Tex = []
		self.Index = []
		self.Vertex = []
		self.VertexBuffer = []

		self.PositionBuffer = []
		self.Tex2DBuffer = []
		self.NormalBuffer = []
		self.IndexBuffer = []

class MD5_Child():
	def __init__(self):
		self.index = 0
		self.next = 0

class MD5_BaseFrame():
	def __init__(self):
		self.position = []
		self.orientation = []

class MD5_Frame():
	def __init__(self):
		self.num = 0
		self.data = []

class MD5_Animation():
	def __init__(self):
		self.name = ""
		self.numFrames = 0
		self.numJoints = 0
		self.frameRate = 0
		self.numAnimatedComponents = 0
		self.bone = []
		self.boneBuffer = []
		self.bound = []
		self.baseframe = []
		self.frame =[]
		self.next = 0

		self.animTime = 0
	def Update(self,dTime):
		self.animTime+= dTime
		self.current_frame = self.animTime*self.frameRate%self.numFrames

	def PreBuildSkeleton(self,frame):
		bufferBones = []
		for i in range(self.numJoints):
			bone = self.bone[i]
			base = self.baseframe[i]
			bone.position = base.position
			bone.orientation = base.orientation
			j = 0

			if bone.flag & 1: 
				bone.position.x=frame.data[ bone.start_index+j ]
				j+=1
			if bone.flag & 2: 
				bone.position.y=frame.data[ bone.start_index+j ]
				j+=1
			if bone.flag & 4: 
				bone.position.z=frame.data[ bone.start_index+j ]
				j+=1
			if bone.flag & 8: 
				bone.orientation.x=frame.data[ bone.start_index+j ]
				j+=1	
			if bone.flag & 16: 
				bone.orientation.y=frame.data[ bone.start_index+j ]
				j+=1
			if bone.flag & 32: 
				bone.orientation.z=frame.data[ bone.start_index+j ]
				j+=1
			bone.orientation.ComputeQuatW()
			if bone.parent_index >= 0 :
				parentBone = self.bone[bone.parent_index]
				rotPos = parentBone.orientation*bone.position
				bone.position = parentBone.position+rotPos
				bone.orientation = parentBone.orientation*bone.orientation
				bone.orientation.normalise()
			bufferBones.append(bone)
		
		pl = []
		ol = []
		for i in bufferBones:
			pass
			#pl.append(str(i.position))
			#ol.append(str(i.orientation))
		#print (pl)
		#print (ol)
		
		self.boneBuffer.append(bufferBones)


class MD5_Model():
	def __init__(self):

		self.numJoints = 0
		self.numMeshes = 0
		self.numAnim = 0

		self.Bones = []
		self.Meshes = []
		self.Animations = []

		self.current_animation = 0
		self.current_frame = 0

		self.LocalToWorldMatrix =  glGetFloatv( GL_MODELVIEW_MATRIX )

	def LoadMesh(self,filename):

		print ("Loading Mesh %s"%filename)
		meshfile = open(filename,"r")
		lines = meshfile.readlines()
		meshfile.close()
		tot_lines = len(lines)
		mesh_num = 0

		for line_num in range(0,tot_lines):
			cur_line = lines[line_num]
			words = cur_line.split()
			if not words: continue

			if words[0] == "MD5Version":
				MD5Version = int(words[1])
				print(words[0],MD5Version)

			elif words[0] == "numJoints":
				self.numJoints = int(words[1])
				print(words[0],self.numJoints)

			elif words[0] == "numMeshes":
				self.numMeshes = int(words[1])
				print(words[0],self.numMeshes)

			elif words[0] == "joints":

				for bone_num in range(self.numJoints):
					self.Bones.append(MD5_Bone())
					line_num+=1
					cur_line = lines[line_num]
					words = cur_line.split()

					while not words:
						line_num+=1
						cur_line = lines[line_num]
						words = cur_line.split()

					self.Bones[bone_num].index = bone_num
					self.Bones[bone_num].name = words[0][1:-1]
					self.Bones[bone_num].parent_index = int(words[1])
					if self.Bones[bone_num].parent_index>=0:
						self.Bones[bone_num].parent = self.Bones[self.Bones[bone_num].parent_index].name

					# Normal Method
					self.Bones[bone_num].bindpos[0] = float(words[3])
					self.Bones[bone_num].bindpos[1] = float(words[4])
					self.Bones[bone_num].bindpos[2] = float(words[5])
					qx = float(words[8])
					qy = float(words[9])
					qz = float(words[10])
					qw = 1 - qx*qx - qy * qy - qz * qz
					if qw<0: qw = 0
					else : qw = -sqrt(qw)
					self.Bones[bone_num].bindmat = quaternion2matrix([qx,qy,qz,qw])

					# 3DMath Class : Beta version
					self.Bones[bone_num].position.x = float(words[3])
					self.Bones[bone_num].position.y = float(words[4])
					self.Bones[bone_num].position.z = float(words[5])	

					self.Bones[bone_num].orientation.x = float(words[8])
					self.Bones[bone_num].orientation.y = float(words[9])
					self.Bones[bone_num].orientation.z = float(words[10])
					self.Bones[bone_num].orientation.ComputeQuatW()

			elif words[0] == "mesh":
				self.Meshes.append(MD5_Mesh())
				self.Meshes[mesh_num].index = mesh_num
				while not words or words[0]!="}":
					line_num += 1
					cur_line = lines[line_num]
					words = cur_line.split()
					if not words: continue

					if words[0] == "shader":
						if(words[1]=="\"\""):
							self.Meshes[mesh_num].textid = 0
							print ("No Shader Image")
						else :
							self.Meshes[mesh_num].shader = str(words[1])[1:-1]
							print("shader",self.Meshes[mesh_num].shader)
							try:
								surf = pygame.image.load(self.Meshes[mesh_num].shader)
							except:
								surf = pygame.image.load(self.Meshes[mesh_num].shader+".bmp")

							image = pygame.image.tostring(surf,'RGBA',1)
							width = surf.get_width()
							height = surf.get_height()
							texid = self.Meshes[mesh_num].textid = glGenTextures(1)
							glBindTexture(GL_TEXTURE_2D, texid)
							glPixelStorei(GL_UNPACK_ALIGNMENT,1)
							'''
							glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,   GL_LINEAR)
							glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,   GL_LINEAR)
							glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ix, iy, 0, GL_RGBA, GL_UNSIGNED_BYTE, image)
							'''

							'''
							glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
							glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
							glTexImage2D(GL_TEXTURE_2D, 0, 3, ix,iy, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
							'''
							#'''
							glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
							glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
							glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
							#glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
							#glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
							glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,GL_UNSIGNED_BYTE, image)
							#gluBuild2DMipmaps( GL_TEXTURE_2D, 3, ix, iy,GL_RGBA, GL_UNSIGNED_BYTE, image);
							#'''
					elif words[0] == "numverts":
						self.Meshes[mesh_num].numverts = int(words[1])
						print("numverts",self.Meshes[mesh_num].numverts)
						self.Meshes[mesh_num].Tex = np.array(range(self.Meshes[mesh_num].numverts*2),dtype='f')
						for vert_num in range(self.Meshes[mesh_num].numverts):
							self.Meshes[mesh_num].verts.append(MD5_Vert())

							line_num+=1
							cur_line = lines[line_num]
							words = cur_line.split()

							while not words:
								line_num+=1
								cur_line = lines[line_num]
								words = cur_line.split()

							self.Meshes[mesh_num].verts[vert_num].index = int(words[1])
							self.Meshes[mesh_num].verts[vert_num].u = float(words[3])
							self.Meshes[mesh_num].verts[vert_num].v = float(words[4])
							self.Meshes[mesh_num].verts[vert_num].weight_index = int(words[6])
							self.Meshes[mesh_num].verts[vert_num].weight_count = int(words[7])

							self.Meshes[mesh_num].verts[vert_num].tex0.x  = float(words[3])
							self.Meshes[mesh_num].verts[vert_num].tex0.y  = float(words[4])
							self.Meshes[mesh_num].Tex[vert_num*2] = float(words[3])
							self.Meshes[mesh_num].Tex[vert_num*2+1] = float(words[4])

					elif words[0] == "numtris":
						self.Meshes[mesh_num].numtris = int(words[1])
						print("numtris",self.Meshes[mesh_num].numtris)
						self.Meshes[mesh_num].Index  = np.array(range(self.Meshes[mesh_num].numtris*3),dtype='i')
						for tri_num in range(self.Meshes[mesh_num].numtris):
							self.Meshes[mesh_num].tris.append(MD5_Tri())

							line_num+=1
							cur_line = lines[line_num]
							words = cur_line.split()

							while not words:
								line_num+=1
								cur_line = lines[line_num]
								words = cur_line.split()

							self.Meshes[mesh_num].tris[tri_num].index = int(words[1])

							self.Meshes[mesh_num].tris[tri_num].x = float(words[2])
							self.Meshes[mesh_num].tris[tri_num].y = float(words[3])
							self.Meshes[mesh_num].tris[tri_num].z = float(words[4])

							self.Meshes[mesh_num].tris[tri_num].indices[0] = int(words[2])
							self.Meshes[mesh_num].tris[tri_num].indices[1] = int(words[3])
							self.Meshes[mesh_num].tris[tri_num].indices[2] = int(words[4])

							self.Meshes[mesh_num].Index[tri_num*3]=int(words[2])
							self.Meshes[mesh_num].Index[tri_num*3+1]=int(words[3])
							self.Meshes[mesh_num].Index[tri_num*3+2]=int(words[4])

					elif words[0] == "numweights":
						self.Meshes[mesh_num].numweights = int(words[1])
						print("numweights",self.Meshes[mesh_num].numweights)
						for weight_num in range(self.Meshes[mesh_num].numweights):
							self.Meshes[mesh_num].weights.append(MD5_Weight())

							line_num+=1
							cur_line = lines[line_num]
							words = cur_line.split()

							while not words:
								line_num+=1
								cur_line = lines[line_num]
								words = cur_line.split()

							self.Meshes[mesh_num].weights[weight_num].index = int(words[1])
							self.Meshes[mesh_num].weights[weight_num].bone_index = int(words[2])
							self.Meshes[mesh_num].weights[weight_num].bias = float(words[3])
							self.Meshes[mesh_num].weights[weight_num].x = float(words[5])
							self.Meshes[mesh_num].weights[weight_num].y = float(words[6])
							self.Meshes[mesh_num].weights[weight_num].z = float(words[7])

							self.Meshes[mesh_num].weights[weight_num].position.x = float(words[5])
							self.Meshes[mesh_num].weights[weight_num].position.y = float(words[6])
							self.Meshes[mesh_num].weights[weight_num].position.z = float(words[7])
				
				self.BuildMesh(self.Meshes[mesh_num],self.Bones)
				#self.BuildNormal(self.Meshes[mesh_num])
				mesh_num+=1
		print ("LoadMesh Finished")

	def AddAnimation(self,filename):

		print ("Adding Animation %s"%filename)
		animfile = open(filename,"r")
		lines = animfile.readlines()
		animfile.close()
		tot_lines = len(lines)
		newAnim = MD5_Animation()
		newAnim.name = filename.split('.')[0]

		for line_num in range(0,tot_lines):
			cur_line = lines[line_num]
			words = cur_line.split()
			if not words: continue

			if words[0] == "MD5Version":
				MD5Version = int(words[1])
				print(words[0],MD5Version)

			elif words[0] == "numFrames":
				newAnim.numFrames = int(words[1])
				print(words[0],newAnim.numFrames)

			elif words[0] == "numJoints":
				newAnim.numJoints = int(words[1])
				print(words[0],newAnim.numJoints)

			elif words[0] == "frameRate":
				newAnim.frameRate = int(words[1])
				print(words[0],newAnim.frameRate)

			elif words[0] == "numAnimatedComponents":
				newAnim.numAnimatedComponents = int(words[1])
				print(words[0],newAnim.numAnimatedComponents)

			elif words[0] == "hierarchy":
				for bone_num in range(newAnim.numJoints):

					newBone = MD5_Bone()
	
					line_num+=1
					cur_line = lines[line_num]
					words = cur_line.split()
					while not words:
						line_num+=1
						cur_line = lines[line_num]
						words = cur_line.split()

					newBone.index = bone_num
					newBone.name = words[0]
					newBone.parent_index = int(words[1])
					newBone.flag = int(words[2])
					newBone.start_index = int(words[3])
					newAnim.bone.append(newBone)

			elif words[0] == "bounds":
				for i in range(newAnim.numFrames):
					line_num+=1
					cur_line = lines[line_num]
					words = cur_line.split()
					newBound = MD5_Bound()
					newBound.min = Vector3(float(words[1]),float(words[2]),float(words[3]))
					newBound.max = Vector3(float(words[6]),float(words[7]),float(words[8]))
					newAnim.bound.append(newBound)

			elif words[0] == "baseframe":
				for i in range(newAnim.numJoints):
					line_num+=1
					cur_line = lines[line_num]
					words = cur_line.split()
					newBaseframe = MD5_BaseFrame()
					newBaseframe.position = Vector3(float(words[1]),float(words[2]),float(words[3]))
					newBaseframe.orientation = Quaternion(float(words[6]),float(words[7]),float(words[8]))
					newAnim.baseframe.append(newBaseframe)

			elif words[0] == "frame":
				newFrame = MD5_Frame()
				newFrame.num = int(words[1])
				line_num+=1
				cur_line = lines[line_num]
				words = cur_line.split()
				while words[0]!="}":
					for i in words:
						newFrame.data.append(float(i))
					line_num+=1
					cur_line = lines[line_num]
					words = cur_line.split()
				newAnim.frame.append(newFrame)
				newAnim.PreBuildSkeleton(newFrame)
				
		self.Animations.append(newAnim)
		self.numAnim+=1
		print ("AddAnimation Finished")

	def BufferBone(self,index):
		for m in range(self.numMeshes):
			for f in range(self.Animations[index].numFrames):
				vBuffer = np.array(range(self.Meshes[m].numverts*3),dtype='f')
				for i in range(self.Meshes[m].numverts):
					finalPos = Vector3()
					for j in range(self.Meshes[m].verts[i].weight_count):
						wei = self.Meshes[m].weights[self.Meshes[m].verts[i].weight_index + j]
						joi = (self.Animations[index].boneBuffer[f])[wei.bone_index]
						rotPos = joi.orientation.Rotate(wei.position);
						finalPos = finalPos + (rotPos + joi.position) * wei.bias
						#print (str(finalPos),end = " " )
					vBuffer[i*3] = finalPos.x
					vBuffer[i*3+1] = finalPos.y
					vBuffer[i*3+2] = finalPos.z
				#print (f,vBuffer)
				self.Meshes[m].VertexBuffer.append(vBuffer)

	def SetFrame(self,index):
		#self.BuildSkeleton(self.Animations[self.current_animation],self.Animations[self.current_animation].frame[index])
		#self.current_bone = self.Animations[self.current_animation].boneBuffer[f]
		self.current_frame = index
		for m in range(self.numMeshes):
			self.Meshes[m].Vertex = self.Meshes[m].VertexBuffer[index]
		#self.PreBuildBone(index)
		#self.BuildBone()
		#self.BuildMesh()

	def ChooseAnimation(self,index):
		self.current_animation = index
		self.numFrames = self.Animations[index].numFrames
		#self.current_bone = self.Animations[index].bone
		self.BufferBone(index)
	'''
	def Update(self,dTime):
		self.Animations[self.current_animation].Update(dTime)
		for i in range(self.numMeshes):
			self.BuildMesh(self.Meshes[i],self.Animations[self.current_animation].bone)
	'''

	def Render(self):
		glPushMatrix()

		glMultMatrixf(self.LocalToWorldMatrix)
		for i in range(self.numMeshes):
			self.RenderMesh(self.Meshes[i])

		glPopMatrix()

	def RenderMesh(self,mesh):
		#glColor3f( 1.0, 0.9, 0.1 );
		glEnable(GL_TEXTURE_2D)
		glBindTexture( GL_TEXTURE_2D, mesh.textid );
		glEnableClientState( GL_TEXTURE_COORD_ARRAY );
		glFrontFace(GL_CCW)
		#glEnableClientState( GL_NORMAL_ARRAY );
		glTexCoordPointer( 2, GL_FLOAT, 0, mesh.Tex );

		glEnableClientState( GL_VERTEX_ARRAY );
		glVertexPointer( 3, GL_FLOAT, 0, mesh.Vertex);
		#glNormalPointer( GL_FLOAT, 0, self.Normal);

		
		glDrawElements( GL_TRIANGLES,mesh.numtris*3, GL_UNSIGNED_INT, mesh.Index );
		#glDisableClientState( GL_NORMAL_ARRAY );
		glDisableClientState( GL_TEXTURE_COORD_ARRAY );
		glDisableClientState( GL_VERTEX_ARRAY );
		glBindTexture( GL_TEXTURE_2D, 0 );
		glDisable(GL_TEXTURE_2D)

	def BuildMesh(self,mesh,bones):
		mesh.Vertex = np.array(range(mesh.numverts*3),dtype='f')
		for i in range(mesh.numverts):
			finalPos = Vector3()
			for j in range(mesh.verts[i].weight_count):
				wei = mesh.weights[mesh.verts[i].weight_index + j]
				joi = bones[wei.bone_index]
				rotPos = joi.orientation.Rotate(wei.position);
				finalPos = finalPos + (rotPos + joi.position) * wei.bias
			mesh.Vertex[i*3] = finalPos.x
			mesh.Vertex[i*3+1] = finalPos.y
			mesh.Vertex[i*3+2] = finalPos.z

	

	def BuildNormal(self,mesh):
		mesh.Normal = np.array(range(mesh.numverts))
		for i in range(mesh.numtris):
			v0 = mesh.verts[mesh.tris[i].indices[0]].pos;
			v1 = mesh.verts[mesh.tris[i].indices[1]].pos;
			v2 = mesh.verts[mesh.tris[i].indices[2]].pos;

			normal = (v2 - v0).crossProduct(v1 - v0 )
			#print (normal.x,normal.y,normal.z)
			mesh.verts[ mesh.tris[i].indices[0] ].normal += normal;
			mesh.verts[ mesh.tris[i].indices[1] ].normal += normal;
			mesh.verts[ mesh.tris[i].indices[2] ].normal += normal;

		for i in range(mesh.numverts):

			normal = mesh.verts[i].normal.normalise()
			mesh.NormalBuffer.append( normal );

			self.Normal[i] = normal

			mesh.verts[i].normal = Vector3()

			for j in range(mesh.verts[i].weight_count):

				wei = mesh.weights[mesh.verts[i].weight_index + j]
				joi = self.Bones[wei.bone_index];
				mesh.verts[i].normal += ( joi.orientation *normal ) * wei.bias
