class BitMan:        
    def flip_bit(self,x,pos):
        mask = 1<<pos
        return x ^ mask

    def set_bit(self,x,pos):
        return x | 1<<pos
    
    def reset_bit(self,x,pos=0):
        return x & ~1<<pos
    
    def countBits(self,x):
        cnt=0;
        while(x>0):            
            if x&1 is 1:
                cnt=cnt+1
          #  print (x)
            x=x>>1
        return cnt
    def countDiffBits(self,a,b):
        return self.countBits(a^b)
        
                

if __name__=="__main__":
    b = BitMan()
    print( b.flip_bit(4,0))
    print( b.set_bit(4,1))
    print( b.reset_bit(7,1))
    print(" number of set bits ")
    print (b.countBits(7))
    print(b.countDiffBits(5,12))
