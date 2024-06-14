# simu_football_positioning has two main parts and one incomplete parts
# src : in this folder logic of random generator is written and data is publihsed using zeromq
# tests: its a folder where client code is written which receives the data as subscriber using zeromq
# qtApp: shows how data is received and shown on qt graphicscene
#

# how to build
# mkdir build
# cmake ../
# make

# dependencies are protobuf library, zeromq and qt( optional)