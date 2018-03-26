from pythymiodw import *
from pythymiodw import io
from pythymiodw.sm import *
from libdw import sm
from boxworld import thymio_world

class MySMClass(sm.SM):
    start_state = 'start'
    def get_next_values(self, state, inp):
 
        ground = inp.prox_ground.delta
        left = ground[0]
        right = ground[1]
        ## All possible states
        if state == 'start' and left > 200 and right > 200:
            next_state = 'start'

        elif state == 'start' and left < 200 and right < 200:
            next_state = 'left'

        elif state == 'moving' and left > 200 and right > 200:
            next_state = 'right'

        elif state == 'moving' and left > 200 and right < 200:
            next_state = 'moving'

        elif state == 'moving' and left < 200 and right < 200:
            next_state = 'left'

        elif state == 'left' and left > 200 and right < 200:
            next_state = 'moving'

        elif state == 'left' and left > 200 and right > 200:
            next_state = 'right'
           
        elif state == 'left' and left < 200 and right < 200:
            next_state = 'left' 



        elif state == 'right' and left > 200 and right < 200:
            next_state = 'moving'

        elif state == 'right' and left > 200 and right > 200:
            next_state = 'right'

        print(state)

        ## Controlling speed for the possible cases
        if next_state == 'left':
            return next_state, io.Action(fv = 0, rv = 0.5)

        if next_state == 'moving' or next_state == 'start':
            return next_state, io.Action(fv = 0.1, rv = 0.0)

        if next_state == 'right':
            return next_state, io.Action(fv = 0, rv = -0.5)

        def done(self,state):
            if state=='halt':
                return True
            else:
                return False

MySM=MySMClass()

############################

m=ThymioSMReal(MySM, thymio_world)
try:
    m.start()
except KeyboardInterrupt:
    m.stop()

        


        

        
