{-
-- EPITECH PROJECT, 2023
-- B-PDG-300-REN-3-1-PDGD01-mael.becel
-- File description:
-- Haskell
-}

mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x =
    if x < 0 then  True
    else False

myAbs :: Int -> Int
myAbs x =
    if x < 0 then (x*(-1))
    else (x)

myMin :: Int -> Int -> Int
myMin x y =
    if x < y then x
    else y

myMax :: Int -> Int -> Int
myMax x y =
    if x > y then x
    else y

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (x, y) = x

mySnd :: (a, b) -> b
mySnd (x, y) = y

mySwap :: (a, b) -> (b, a)
mySwap (x, y) = (y, x)

myHead :: [a] -> a
myHead [] = error "Empty List"
myHead (x:xs) = x

myTail :: [a] -> [a]
myTail [] = error "Empty List"
myTail (x:xs) = xs

myLength :: [a] -> Int
myLength [] = 0
myLength (x:xs) = 1 + myLength xs

myNth :: [a] -> Int -> a
myNth [] n = error "List index out of range"
myNth (x:xs) 0 = x
myNth (n:xs) y = myNth xs (y-1)

myTake :: Int -> [a] -> [a]
myTake 0 _ = []
myTake n [] = []
myTake n (x:xs) = x : myTake (n-1) xs

myDrop :: Int -> [a] -> [a]
myDrop 0 xs = xs
myDrop n [] = []
myDrop n (x:xs) = myDrop (n-1) xs

myAppend :: [a] -> [a] -> [a]
myAppend [] [] = []
myAppend [] (x:xs) = x : myAppend [] xs
myAppend (x:xs) [] = x : myAppend xs []
myAppend (x:xs) (y:ys) = x : myAppend xs (y:ys)

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (x:xs) = myAppend (myReverse xs) [x]

myInit :: [a] -> [a]
myInit [] = error "Empty List"
myInit (x:xs) = myReverse (myTail (myReverse (x:xs)))

myLast :: [a] -> a
myLast [] = error "Empty List"
myLast (x:xs) = myHead (myReverse (x:xs))

myZip :: [a] -> [b] -> [(a, b)]
myZip [] [] = []
myZip [] (x:xs) = []
myZip (x:xs) [] = []
myZip (x:xs) (y:ys) = (x, y) : myZip xs ys

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip ((x, y):xs) = (x : myFst (myUnzip xs), y : mySnd (myUnzip xs))

myMap :: (a -> b) -> [a] -> [b]
myMap funct [] = []
myMap funct (x:xs) = funct x : myMap funct xs

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter funct [] = []
myFilter funct (x:xs) =
    if funct x == True then x : myFilter funct xs
    else myFilter funct xs

myFoldl :: (a -> b -> a) -> a -> [b] -> a
myFoldl funct x [] = x
myFoldl funct x (y:ys) = myFoldl funct (funct x y) ys

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr funct x [] = x
myFoldr funct x (y:ys) = funct y (myFoldr funct x ys)

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition funct [] = ([], [])
myPartition funct (x:xs) =
    if funct x == True then (x : myFst (myPartition funct xs),
    mySnd (myPartition funct xs))
    else (myFst (myPartition funct xs), x : mySnd (myPartition funct xs))

myNegate :: Bool -> Bool
myNegate x =
    if x == True then False
    else True

myComposeFunctions :: (a -> a -> Bool) ->  (a -> a -> Bool) -> (a -> a -> Bool)
myComposeFunctions funct1 funct2 x y =
    if funct1 x y == True then True
    else funct2 x y

myFilterReverse :: (a -> Bool) -> [a] -> [a]
myFilterReverse funct [] = []
myFilterReverse funct (x:xs) =
    if funct x == False then x : myFilterReverse funct xs
    else myFilterReverse funct xs


myQuickSort :: (a -> a -> Bool) -> [a] -> [a]
myQuickSort func [] = []
myQuickSort func (x:xs) = myAppend b (myAppend [x] s)
    where
        s = myQuickSort func (myFilter (func x) xs)
        b = myQuickSort func (myFilterReverse (func x) xs)