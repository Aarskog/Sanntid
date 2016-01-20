from threading import Thread
i=0


def one():
    global i
    for x in range(0,1000000):
        i += 1
    print "one: ",i
def two():
    global i
    for y in range(0,1000000):
        i -= 1
    print "two: ",i
        
def main():

    threadOne = Thread(target = one,args = (),)
    threadOne.start()
    
    threadTwo = Thread(target = two,args = (),)
    threadTwo.start()


    threadOne.join()
    threadTwo.join()
    
    print i

main()
