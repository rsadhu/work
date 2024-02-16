import threading
import time
import requests


def timetaken(func):
  def wrapper():
    s_time = time.time()
    func()
    print(f" {func.__name__} took {time.time() - s_time} seconds")
  return wrapper






if __name__ == "__main__":
    connectNow()