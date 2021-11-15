import random
import sys

my_list = list(range(-500, 500))
random.shuffle(my_list)
print (my_list[0:int(sys.argv[1])])
