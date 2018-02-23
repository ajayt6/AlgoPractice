import unittest



class pyset:
    
    
    def __init__(self):
        self.l = []
        self.size = 0
        
    def size_of(self):
        return self.size
        
    def add(self,elem):
        
        lastNonePos = None
        for e in self.l:
            if e == elem:
                return False
            elif e is None:
                lastNonePos = self.l.index(e)
            
        if lastNonePos is not None:
            self.l[lastNonePos] = elem
            
        else:
            self.l.append(elem)
        
        self.size = self.size + 1
        return True
    
    def contains_internal(self,elem):
        
        for e in self.l:
            if e == elem:
                return True,self.l.index(e)
            
        return False,None
    
    def contains(self,elem):
        return self.contains_internal(elem)[0]
    
    def remove(self,elem):
        
        result = self.contains_internal(elem)
        if result[0] :
            self.l[result[1]] = None
            self.size = self.size - 1
            return True            
        
        else:
            #The element is not there to be removed
            return False


        
        
class TestPyset(unittest.TestCase):
    
    
    def setUp(self):
        self.ps = pyset()
        
    def test_sizeIsZeroAtStart(self):
        
        self.assertEqual(self.ps.size, 0)
        
        
        # should raise an exception for an immutable sequence
        #self.assertRaises(TypeError, random.shuffle, (1,2,3))
        
    def test_addElementEmptySetReturnTrue_SizeIsOne(self):
        self.assertTrue(self.ps.add(4))
        self.assertEqual(self.ps.size,1)
        
    def test_addElementSizeIncreasesByOne(self):
        cSize = self.ps.size
        self.ps.add(2)
        self.assertEqual(self.ps.size,cSize+1)
        
    def test_removeElementSizeDecreasesByOne(self):
        self.ps.add(666)
        cSize = self.ps.size
        self.ps.remove(666)
        self.assertEqual(self.ps.size,cSize-1)
        
    def test_checkContainsFalse_ThenAddElementCheckCOntainsTrue(self):
        self.assertFalse(self.ps.contains(666))
        
        self.ps.add(666)
        
        self.assertTrue(self.ps.contains(666))
    
    def test_checkContainsTrue_ThenRemoveELementCHeckCOntainsFalse(self):
        self.ps.add(666)
        
        self.assertTrue(self.ps.contains(666))
        
        self.ps.remove(666)
        
        self.assertFalse(self.ps.contains(666))
        
    def test_addSameElementMultipleTimesSizeDoesNotIncrease(self):
        self.ps.add(666)
        cSize = self.ps.size
        
        self.ps.add(666)
        newSize = self.ps.size
        
        self.assertEqual(cSize,newSize)
        
        cSize = newSize
        
        self.ps.add(666)
        newSize = self.ps.size
        
        self.assertEqual(cSize,newSize)
        
    def test_removeElementThatDoesNotExist_gracefulFalse(self):
        self.assertFalse(self.ps.remove(666))

        
    '''
    def test_choice(self):
        element = random.choice(self.seq)
        self.assertTrue(element in self.seq)
    '''
        
def test(a):
    b=a
    c=a+2
    d=45
    return b,c,d

    
def say_hello():
    print('Hello, World')

if __name__ == '__main__':
    print(test(3)[1])
    print(type({}))    
    print ( isinstance({},dict) )
    print("going to start tests")
    unittest.main()
    
