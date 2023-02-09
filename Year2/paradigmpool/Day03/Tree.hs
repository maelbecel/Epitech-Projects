{-
-- EPITECH PROJECT, 2023
-- B-PDG-300-REN-3-1-PDGD03-mael.becel
-- File description:
-- Haskell
-}

-- Task 11
data Tree a = Empty | Node (Tree a) a (Tree a) deriving (Show)

-- Task 12
addInTree :: Ord a => a -> Tree a -> Tree a
addInTree x Empty = Node Empty x Empty
addInTree x (Node left value right)
    | x < value = Node (addInTree x left) value right
    | x > value = Node left value (addInTree x right)
    | otherwise = Node left value right

-- Task 13
instance Functor Tree where
    fmap x Empty = Empty
    fmap x (Node left value right) = Node (fmap x left) (x value)
        (fmap x right)

-- Task 14
listToTree :: Ord a => [a] -> Tree a
listToTree [] = Empty
listToTree (x:xs) = addInTree x (listToTree xs)

-- Task 15
treeToList :: Ord a => Tree a -> [a]
treeToList Empty = []
treeToList (Node left value right) = treeToList left ++ [value] ++
    treeToList right

-- Task 16
treeSort :: Ord a => [a] -> [a]
treeSort [] = []
treeSort (x:xs) = treeToList (listToTree (x:xs))

-- Task 17
instance Foldable Tree where
    foldr f acc Empty = acc
    foldr f acc (Node left value right) = foldr f (f value (foldr f acc
        right)) left