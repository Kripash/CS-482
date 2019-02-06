# kf.py updated file for robot estimation assignment
# pset[3]
# (C) 2017 David Feil-Seifer


import numpy as np
import math
from scipy import stats
import scipy.stats

# kf_update: update state estimate [u, sigma] with new control [xdot] and measurement [z]
# 	parameters:
#			u : 2x1 vector with state estimate (x) at time t-1 and control (xdot) at time t
#			sigma: 2x2 matrix with covariance at time t-1
#			z (int): observed (uncertain) measurement of state (x) at time t
#	returns: [u sigma] updated state with estimate at time t

def kf_update(u, sigma, z):

	z_matrix = np.matrix([z])
	F = np.matrix([[1.0, 1.0], [0.0, 1.0]])
	H = np.matrix([1.0,0.0])


	sigma_x = np.matrix([[.1, .25], [.25, .5]])
	#sigma_x = np.matrix([[1, 1], [1, 1]])
	sigma_z = np.matrix([10])
	
	F_sigma = np.add(np.dot(np.dot(F,sigma),F.T),sigma_x)

	k_of_t_right_side = np.add(np.dot(np.dot(H,F_sigma), H.T), sigma_z).I
	k_of_t = np.dot(np.dot(F_sigma,H.T), k_of_t_right_side)

	temp = np.dot(H, F) 
	correction = np.dot(temp, u)		
	current_state = np.dot(F,u)
	right_correction = 	np.dot(k_of_t, (np.subtract(z_matrix, correction)))
	next_state = np.add(current_state, right_correction)

	identity_matrix = np.matrix([[1.0, 0.0], [0.0, 1.0]])
	I_k_h = np.subtract(identity_matrix,np.dot(k_of_t, H))

	sigma = np.dot(I_k_h, F_sigma)	
	u = next_state[:]

	return [u, sigma]


# door_update: update estimate of door locations
# 	parameters:
#			u : 2x1 vector with state estimate (x) at time t-1 and control (xdot) at time t-1
#			sigma: 2x2 matrix with covariance at time t-1
#			d (binary): door sensor at time t-1 
#			door_dist (array of size 10): probability (0..1) that a door exists at each location (0..9)
#	returns: [door_dist] updated door distribution

def door_update(u, sigma, d, door_dist):

	p_true_when_s		= 0.6;
	p_true_when_not_s	= 0.2;

	p_false_when_not_s	= 0.8;
	p_false_when_s		= 0.4;
	

	temp = u[0]
	index = int(temp / 100)
	
	
	if(0 <= index <= 9):
		if d:
			p_of_door = (p_true_when_s * (door_dist[index])) + (p_true_when_not_s * (1 - (door_dist[index])))
			normalizer = (1 / p_of_door)
			bel_true = (normalizer * (p_true_when_s * (door_dist[index])))
			bel_false = (normalizer * (p_true_when_not_s * (1 - (door_dist[index]))))
			door_dist[index] = bel_true
		else:
			p_of_door = (p_false_when_not_s * (1 - door_dist[index])) + (p_false_when_s * ((door_dist[index])))
			normalizer = (1 / p_of_door)
			bel_true = normalizer * (p_false_when_not_s * (1 - door_dist[index]))
			bel_false = normalizer * (p_false_when_s * ((door_dist[index])))
			door_dist[index] = bel_false

	return door_dist


















