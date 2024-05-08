import datetime

start_time = datetime.datetime.now()

i=0
while(i < 1000000000):
    i+=1

end_time = datetime.datetime.now()

# Calculate the time difference
time_difference = end_time - start_time

# Convert the time difference to milliseconds
milliseconds = time_difference.total_seconds() * 1000

print("Time difference in milliseconds:", milliseconds)
    