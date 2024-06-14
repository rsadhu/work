# simu_football_positioning has two main parts and one incomplete parts
# src : in this folder logic of random generator is written and data is publihsed using zeromq
# tests: its a folder where client code is written which receives the data as subscriber using zeromq
# qtApp: non functional( have compilation issues), intention was to create a gui which would show players moving
# on field of 100x100, and the data positioning would be fed from randomizer code.{ unfortunately have to leave it as time constraints
# didnt let me proceed}
#

# how to build
# mkdir build
# cmake ../
# make

# dependencies are protobuf library, zeromq and qt( optional)