#import threading
from threading import Thread, Lock
i=0
lock = Lock()


def one():
    global i
    for x in range(0,1000001):
        lock.acquire()
        i += 1
        lock.release()
def two():
    global i
    for y in range(0,1000000):
        lock.acquire()
        i -=1
        lock.release()
   	 
def main():

    threadOne = Thread(target = one,args = (),)
    threadOne.start()
    
    threadTwo = Thread(target = two,args = (),)
    threadTwo.start()


    threadOne.join()
    threadTwo.join()
    print (i)
    
main()
