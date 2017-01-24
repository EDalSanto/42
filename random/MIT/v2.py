class V2(object):
	"""
	A class that represents two-dimensional vectors
	"""
	def __init__(self, vect1, vect2):
		self.vect1 = vect1
		self.vect2 = vect2
	
	def __str__(self):
		return "V2[%s, %s]" % (self.vect1, self.vect2)	
	
	def getX(self):
		return self.vect1

	def getY(self):
		return self.vect2

	def add(self, other):
		return V2(other.vect1 + self.vect1, other.vect2 + self.vect2)

	def	mul(self, other):
		return V2(other.vect1 * self.vect1, other.vect2 * self.vect2)

	def __add__(self, other):
		return self.add(other)

if __name__=='__main__':
	a = V2(1.0, 2.0)
	b = V2(2.2, 3.3)
	print "vector a: %s, vector b: %s" % (a.__str__(), b.__str__())
	print "adding vector a and b: %s" % (a + b)
