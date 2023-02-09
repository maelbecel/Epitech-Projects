{-
-- EPITECH PROJECT, 2023
-- Rush 1
-- File description:
-- main
-}

import System.Environment ( getArgs )
import Control.Monad (liftM)
import System.Exit
import Text.Read
import Action

data Tree a = Empty | Node (Tree a) a (Tree a) deriving (Show)

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree a Empty = Node Empty a Empty
addInTree a (Node left b right)
    | a < b = Node (addInTree a left) b right
    | otherwise = Node left b (addInTree a right)

listToTree :: Ord a => [a] -> Tree a
listToTree [] = Empty
listToTree (x:xs) = addInTree x (listToTree xs)

treeToList :: Ord a => Tree a -> [a]
treeToList Empty = []
treeToList (Node left b right) = treeToList left ++ [b] ++ treeToList right

treeSort :: Ord a => [a] -> [a]
treeSort a = treeToList (listToTree a)

getArgsInt :: [String] -> [Maybe Int]
getArgsInt [] = []
getArgsInt (x:xs) = (readMaybe x :: Maybe Int) : getArgsInt xs

goodInput :: [Maybe Int] -> Bool
goodInput [] = True
goodInput (Nothing:xs) = False
goodInput (x:xs) = goodInput xs

fromJust :: Maybe a -> a
fromJust (Just a) = a

maybeIntToInt :: [Maybe Int] -> [Int]
maybeIntToInt [] = []
maybeIntToInt (x:xs) = fromJust x : maybeIntToInt xs

isSorted :: Ord a => ([a], [a]) -> IO ()
isSorted (a, [])
    | treeSort a == a = putStrLn "OK"
    | otherwise = putStrLn "KO"
isSorted (a, b) = putStrLn "KO"

getTuples :: IO ([a], [b]) -> IO [a]
getTuples ioTuple = liftM fst ioTuple


checkWords :: [String] -> Bool
checkWords [] = True
checkWords ("sa":xs) = checkWords xs
checkWords ("sb":xs) = checkWords xs
checkWords ("sc":xs) = checkWords xs
checkWords ("pa":xs) = checkWords xs
checkWords ("pb":xs) = checkWords xs
checkWords ("ra":xs) = checkWords xs
checkWords ("rb":xs) = checkWords xs
checkWords ("rr":xs) = checkWords xs
checkWords ("rra":xs) = checkWords xs
checkWords ("rrb":xs) = checkWords xs
checkWords ("rrr":xs) = checkWords xs
checkWords _ = False

doList :: [a] -> [a] -> [Char] -> ([a], [a])
doList list_a list_b op = loopInActions list_a list_b (words op)

loopInActions :: [a] -> [a] -> [String] -> ([a], [a])
loopInActions list_a list_b [] = (list_a, list_b)
loopInActions list_a list_b (x:xs) = loopInActions
    (fst (searchAction x list_a list_b))
    (snd (searchAction x list_a list_b)) xs

main :: IO ()
main = do
    args <- getArgs
    op <- getLine
    let intArgs = getArgsInt args
    if (goodInput intArgs == False || checkWords (words op) == False)
        then exitWith (ExitFailure 84)
    else isSorted (doList (maybeIntToInt intArgs) [] op)