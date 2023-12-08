import threading

def worker():
    print("worker"+ str(threading.Thread.native_id))


if __name__ == "__main__":
    print("main starts")

    ths = []
    total_threads = 8
    for i in range(total_threads):
      t  = threading.Thread(target=worker)
      t.start()
      ths.append(t)



    for t in ths:
        t.join()


