class Polynomial:
	"""
	class with methods for performing algebriac operations on polynomials
	"""
	def __init__(self, coeffs):
		self.coeffs = coeffs 

	def coeff(self, i):
		return self.coeffs[len(self.coeffs) - 1 - i]

	def get_coeff(self):
		return self.coeffs

	def power_detective(self, loc):
		return len(self.coeffs) - loc - 1	

	def add(self, other):
		biggest = Polynomial(max(self.coeffs, other.coeffs, key=len))
		smallest = Polynomial(min(self.coeffs, other.coeffs, key=len))
		new_coeffs = [0] * len(biggest.get_coeff())
		diff_detective = abs(len(self.coeffs) - len(other.coeffs))
		new_coeffs[:diff_detective] = biggest.get_coeff()[:diff_detective]
		for cf in xrange(diff_detective, len(biggest.get_coeff())):
			new_coeffs[cf] = biggest.coeff(biggest.power_detective(cf)) + smallest.coeff(smallest.power_detective(cf - diff_detective))
		np = Polynomial(new_coeffs)
		return np

#	def	mul(self, other):

	
if __name__=='__main__':
	p1 = Polynomial([1, 2, 3])
	p2 = Polynomial([100, 200, 300, 400])
	p3 = p1.add(p2) 
	print "test adding big to small: %s" % (p3.get_coeff() == [100, 201, 302, 403]) 
	p4 = p2.add(p1)
	print "test adding big to small: %s" % (p4.get_coeff() == [100, 201, 302, 403]) 
