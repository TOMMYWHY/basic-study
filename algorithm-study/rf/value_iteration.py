import numpy as np
from gridworld import GridworldEnv

env = GridworldEnv()

def value_iteration(env,theta=0.0001,discount_factor=1.0):
    def one_step_lookahead(state,v):
        A= np.zeros(env.nA)
        for a in range(env.nA):
            for prob,next_state,reward,done in env.P[state][a]:
                A[a] += prob* (reward + discount_factor*v[next_state])
                
