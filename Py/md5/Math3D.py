#=================================
#==== 3DMath Computing lib  ======
#========  Zihao Zhang  ==========
#======  Copyleft @2012  =========
#=================================

import sys, struct, string

from types import *
from os import path
from math import *

class Vector3():
	"""Vector3 Class"""
	def __init__(self,x=0,y=0,z=0):
		self.x = x
		self.y = y
		self.z = z

	def __mul__(self,other):
		rt  = Vector3()
		if isinstance(other,Vector3):
			#print ("MulMul...")
			return self.crossProduct(other)

		elif isinstance(other,Quaternion):
			print ("WTF ? O_O")
		else :
			rt.x = self.x*other
			rt.y = self.y*other
			rt.z = self.z*other
			return rt

	def __add__(self,other):
		rt = Vector3()
		rt.x = self.x+other.x
		rt.y = self.y+other.y
		rt.z = self.z+other.z
		return rt

	def __sub__(self,other):
		rt = Vector3()
		rt.x = self.x-other.x
		rt.y = self.y-other.y
		rt.z = self.z-other.z
		return rt

	def __str__(self):
		return "%.2f %.2f %.2f"%(self.x,self.y,self.z)
	def normalise(self):
		fLen = sqrt(self.x**2 + self.y**2+self.z**2)

		if fLen > 0:
			invLen = 1/fLen
			self.x *= invLen
			self.y *= invLen
			self.z *= invLen

		return fLen

	def crossProduct(self,other):
		pro = Vector3()
		pro.x = self.y*other.z - self.z*other.y
		pro.y = self.z*other.x - self.x*other.z
		pro.z = self.x*other.y - self.y*other.x

		return pro

	def dotProduct(self,other):
		rt = Vector3()
		rt.x = self.x*other.x
		rt.y = self.y*other.y
		rt.z = self.z*other.z
		return rt

class Vector2():
	"""Vector2 Class"""
	def __init__(self):
		self.x = 0
		self.y = 0

class Quaternion():
	"""Quaternion Class"""
	def __init__(self,x=0,y=0,z=0):
		self.x = x
		self.y = y
		self.z = z
		self.w = 0
		self.ComputeQuatW()

	def __mul__(self,other):

		if isinstance(other,Vector3):
			#print ("damn...")
			qvec = Vector3()
			qvec.x = self.x 
			qvec.y = self.y
			qvec.z = self.z
			uv = qvec.crossProduct(other);
			uuv = qvec.crossProduct(uv);
			uv = uv * (2.0 * self.w);
			uuv = uuv * 2.0;
			return other + uv + uuv;
		if isinstance(other,Quaternion):
			rt = Quaternion()
			rt.w = self.w * other.w - self.x * other.x - self.y * other.y - self.z * other.z
			rt.x = self.w * other.x + self.x * other.w + self.y * other.z - self.z * other.y
			rt.y = self.w * other.y + self.y * other.w + self.z * other.x - self.x * other.z
			rt.z = self.w * other.z + self.z * other.w + self.x * other.y - self.y * other.x
			return rt
		else:
			rt = Quaternion()
			rt.w*=other
			rt.x*=other
			rt.y*=other
			rt.z*=other
			rt.ComputeQuatW()
			return rt

	def __str__(self):
		return "%.2f %.2f %.2f %.2f"%(self.w,self.x,self.y,self.z)
	def ComputeQuatW(self):
		t = 1.0 - (self.x*self.x+self.y*self.y+self.z*self.z)
		if t > 0: self.w = -sqrt(t)
		else : self.w = 0


	def Rotate(self,v):
		temp = Vector3()
		temp.x = self.x
		temp.y = self.y
		temp.z = self.z

		uv= temp*v;
		uuv= temp*uv;
		uv= uv*self.w*2.0;
		uuv= uuv*2.0;
		uv += v
		uv += uuv
		return uv;
	
	def normalise(self):
		length = self.w*self.w+self.x*self.x+self.y*self.y+self.z*self.z
		factor = 1/sqrt(length)
		self = self * factor
		return length

def quaternion2matrix(q):
	xx = q[0] * q[0]
	yy = q[1] * q[1]
	zz = q[2] * q[2]
	xy = q[0] * q[1]
	xz = q[0] * q[2]
	yz = q[1] * q[2]
	wx = q[3] * q[0]
	wy = q[3] * q[1]
	wz = q[3] * q[2]
	return [[ 1.0 - 2.0 * (yy + zz)	,		2.0 * (xy + wz),		2.0 * (xz - wy), 0.0],
			[		2.0 * (xy - wz)	, 1.0 - 2.0 * (xx + zz),		2.0 * (yz + wx), 0.0],
			[		2.0 * (xz + wy)	,	 	2.0 * (yz - wx),  1.0 - 2.0 * (xx + yy), 0.0],
			[					0.0	, 					0.0,					0.0, 1.0]]
def euler2matrix(e):
	#euler is assumed to be a float[3], with YAW, PITCH, ROLL (in this order) in degrees
	return matrix_multiply(
			matrix_multiply(
				matrix_rotate_z(e[0]/180*math.pi),
				matrix_rotate_y(e[1]/180*math.pi)),
			matrix_rotate_x(e[2]/180*math.pi)		)

def matrix2quaternion(m):
	s = math.sqrt(abs(m[0][0] + m[1][1] + m[2][2] + m[3][3]))
	if s == 0.0:
		x = abs(m[2][1] - m[1][2])
		y = abs(m[0][2] - m[2][0])
		z = abs(m[1][0] - m[0][1])
		if	 (x >= y) and (x >= z): return 1.0, 0.0, 0.0, 0.0
		elif (y >= x) and (y >= z): return 0.0, 1.0, 0.0, 0.0
		else:											 return 0.0, 0.0, 1.0, 0.0
	return quaternion_normalize([
		-(m[2][1] - m[1][2]) / (2.0 * s),
		-(m[0][2] - m[2][0]) / (2.0 * s),
		-(m[1][0] - m[0][1]) / (2.0 * s),
		0.5 * s,
		])

def quaternion_normalize(q):
	l = math.sqrt(q[0] * q[0] + q[1] * q[1] + q[2] * q[2] + q[3] * q[3])
	return q[0] / l, q[1] / l, q[2] / l, q[3] / l

def quaternion_multiply(q1, q2):
	r = [
		q2[3] * q1[0] + q2[0] * q1[3] + q2[1] * q1[2] - q2[2] * q1[1],
		q2[3] * q1[1] + q2[1] * q1[3] + q2[2] * q1[0] - q2[0] * q1[2],
		q2[3] * q1[2] + q2[2] * q1[3] + q2[0] * q1[1] - q2[1] * q1[0],
		q2[3] * q1[3] - q2[0] * q1[0] - q2[1] * q1[1] - q2[2] * q1[2],
		]
	d = math.sqrt(r[0] * r[0] + r[1] * r[1] + r[2] * r[2] + r[3] * r[3])
	r[0] /= d
	r[1] /= d
	r[2] /= d
	r[3] /= d
	return r

def matrix_translate(m, v):
	m[3][0] += v[0]
	m[3][1] += v[1]
	m[3][2] += v[2]
	return m

def matrix_multiply(b, a):
	return [ [
		a[0][0] * b[0][0] + a[0][1] * b[1][0] + a[0][2] * b[2][0],
		a[0][0] * b[0][1] + a[0][1] * b[1][1] + a[0][2] * b[2][1],
		a[0][0] * b[0][2] + a[0][1] * b[1][2] + a[0][2] * b[2][2],
		0.0,
		], [
		a[1][0] * b[0][0] + a[1][1] * b[1][0] + a[1][2] * b[2][0],
		a[1][0] * b[0][1] + a[1][1] * b[1][1] + a[1][2] * b[2][1],
		a[1][0] * b[0][2] + a[1][1] * b[1][2] + a[1][2] * b[2][2],
		0.0,
		], [
		a[2][0] * b[0][0] + a[2][1] * b[1][0] + a[2][2] * b[2][0],
		a[2][0] * b[0][1] + a[2][1] * b[1][1] + a[2][2] * b[2][1],
		a[2][0] * b[0][2] + a[2][1] * b[1][2] + a[2][2] * b[2][2],
		 0.0,
		], [
		a[3][0] * b[0][0] + a[3][1] * b[1][0] + a[3][2] * b[2][0] + b[3][0],
		a[3][0] * b[0][1] + a[3][1] * b[1][1] + a[3][2] * b[2][1] + b[3][1],
		a[3][0] * b[0][2] + a[3][1] * b[1][2] + a[3][2] * b[2][2] + b[3][2],
		1.0,
		] ]

def matrix_invert(m):
	det = (m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2])
		 - m[1][0] * (m[0][1] * m[2][2] - m[2][1] * m[0][2])
		 + m[2][0] * (m[0][1] * m[1][2] - m[1][1] * m[0][2]))
	if det == 0.0: return None
	det = 1.0 / det
	r = [ [
			det * (m[1][1] * m[2][2] - m[2][1] * m[1][2]),
		  - det * (m[0][1] * m[2][2] - m[2][1] * m[0][2]),
			det * (m[0][1] * m[1][2] - m[1][1] * m[0][2]),
			0.0,
		], [
		  - det * (m[1][0] * m[2][2] - m[2][0] * m[1][2]),
			det * (m[0][0] * m[2][2] - m[2][0] * m[0][2]),
		  - det * (m[0][0] * m[1][2] - m[1][0] * m[0][2]),
			0.0
		], [
			det * (m[1][0] * m[2][1] - m[2][0] * m[1][1]),
		  - det * (m[0][0] * m[2][1] - m[2][0] * m[0][1]),
			det * (m[0][0] * m[1][1] - m[1][0] * m[0][1]),
			0.0,
		] ]
	r.append([
		-(m[3][0] * r[0][0] + m[3][1] * r[1][0] + m[3][2] * r[2][0]),
		-(m[3][0] * r[0][1] + m[3][1] * r[1][1] + m[3][2] * r[2][1]),
		-(m[3][0] * r[0][2] + m[3][1] * r[1][2] + m[3][2] * r[2][2]),
		1.0,
		])
	return r

def matrix_rotate_x(angle):
	cos = math.cos(angle)
	sin = math.sin(angle)
	return [
		[1.0,	0.0, 0.0, 0.0],
		[0.0,	cos, sin, 0.0],
		[0.0,  -sin, cos, 0.0],
		[0.0,	0.0, 0.0, 1.0],
		]

def matrix_rotate_y(angle):
	cos = math.cos(angle)
	sin = math.sin(angle)
	return [
		[cos, 0.0, -sin, 0.0],
		[0.0, 1.0,	0.0, 0.0],
		[sin, 0.0,	cos, 0.0],
		[0.0, 0.0,	0.0, 1.0],
		]

def matrix_rotate_z(angle):
	cos = math.cos(angle)
	sin = math.sin(angle)
	return [
		[ cos, sin, 0.0, 0.0],
		[-sin, cos, 0.0, 0.0],
		[ 0.0, 0.0, 1.0, 0.0],
		[ 0.0, 0.0, 0.0, 1.0],
		]

def matrix_rotate(axis, angle):
	vx	= axis[0]
	vy	= axis[1]
	vz	= axis[2]
	vx2 = vx * vx
	vy2 = vy * vy
	vz2 = vz * vz
	cos = math.cos(angle)
	sin = math.sin(angle)
	co1 = 1.0 - cos
	return [
		[			vx2 * co1 + cos,   vx * vy * co1 + vz * sin,   vz * vx * co1 - vy * sin, 0.0],
		[  vx * vy * co1 - vz * sin, 			vy2 * co1 + cos,   vy * vz * co1 + vx * sin, 0.0],
		[  vz * vx * co1 + vy * sin,   vy * vz * co1 - vx * sin, 			vz2 * co1 + cos, 0.0],
		[0.0, 0.0, 0.0, 1.0],
		]

def matrix_scale(fx, fy, fz):
	return [
		[ fx, 0.0, 0.0, 0.0],
		[0.0,  fy, 0.0, 0.0],
		[0.0, 0.0,	fz, 0.0],
		[0.0, 0.0, 0.0, 1.0],
		]

def point_by_matrix(p, m):
	return [p[0] * m[0][0] + p[1] * m[1][0] + p[2] * m[2][0] + m[3][0],
			p[0] * m[0][1] + p[1] * m[1][1] + p[2] * m[2][1] + m[3][1],
			p[0] * m[0][2] + p[1] * m[1][2] + p[2] * m[2][2] + m[3][2]]

def point_distance(p1, p2):
	return math.sqrt((p2[0] - p1[0]) ** 2 + (p2[1] - p1[1]) ** 2 + (p2[2] - p1[2]) ** 2)

def vector_by_matrix(p, m):
	return [p[0] * m[0][0] + p[1] * m[1][0] + p[2] * m[2][0],
			p[0] * m[0][1] + p[1] * m[1][1] + p[2] * m[2][1],
			p[0] * m[0][2] + p[1] * m[1][2] + p[2] * m[2][2]]

def vector_length(v):
	return math.sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2])

def vector_normalize(v):
	l = math.sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2])
	try:
		return v[0] / l, v[1] / l, v[2] / l
	except:
		return 1, 0, 0

def vector_dotproduct(v1, v2):
	return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]

def vector_crossproduct(v1, v2):
	return [
		v1[1] * v2[2] - v1[2] * v2[1],
		v1[2] * v2[0] - v1[0] * v2[2],
		v1[0] * v2[1] - v1[1] * v2[0],
		]

def vector_angle(v1, v2):
	s = vector_length(v1) * vector_length(v2)
	f = vector_dotproduct(v1, v2) / s
	if f >=	1.0: return 0.0
	if f <= -1.0: return math.pi / 2.0
	return math.atan(-f / math.sqrt(1.0 - f * f)) + math.pi / 2.0