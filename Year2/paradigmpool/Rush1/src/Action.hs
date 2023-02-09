{-
-- EPITECH PROJECT, 2023
-- Rush 1
-- File description:
-- Do all actions
-}

module Action (searchAction) where


searchAction :: [Char] -> [b] -> [b] -> ([b], [b])
searchAction "sa" list_a list_b = sa list_a list_b
searchAction "sb" list_a list_b = sb list_a list_b
searchAction "sc" list_a list_b = sc list_a list_b
searchAction "pa" list_a list_b = pa list_a list_b
searchAction "pb" list_a list_b = pb list_a list_b
searchAction line list_a list_b = searchRotate line list_a list_b

searchRotate :: [Char] -> [b] -> [b] -> ([b], [b])
searchRotate "ra" list_a list_b = ra list_a list_b
searchRotate "rb" list_a list_b = rb list_a list_b
searchRotate "rr" list_a list_b = rr list_a list_b
searchRotate "rra" list_a list_b = rra list_a list_b
searchRotate "rrb" list_a list_b = rrb list_a list_b
searchRotate "rrr" list_a list_b = rrr list_a list_b
searchRotate a list_a list_b = error ("KO : bad parameter " ++ a )

swapTuple :: ([a], [a]) -> ([a], [a])
swapTuple (x, y) = (y, x)

swapFirsts :: [a] -> [a]
swapFirsts [] = []
swapFirsts [x] = [x]
swapFirsts (x:y:xs) = y:x:xs

pushToFirstOther :: [a] -> [a] -> ([a], [a])
pushToFirstOther [] ys = ([], ys)
pushToFirstOther (x:xs) ys = (xs, x:ys)

rotateRight :: [a] -> [a]
rotateRight [] = []
rotateRight [x] = [x]
rotateRight (x:xs) = xs ++ [x]

rotateLeft :: [a] -> [a]
rotateLeft [] = []
rotateLeft [x] = [x]
rotateLeft (x:xs) = last xs : x : init xs

sa :: [a] -> [a] -> ([a], [a])
sa a b = (swapFirsts a, b)


sb :: [a] -> [a] -> ([a], [a])
sb a b = (a, swapFirsts b)

sc :: [a] -> [a] -> ([a], [a])
sc a b = (swapFirsts a, swapFirsts b)

pa :: [a] -> [a] -> ([a], [a])
pa xs ys = swapTuple( pushToFirstOther ys xs)

pb :: [a] -> [a] -> ([a], [a])
pb xs ys = pushToFirstOther xs ys

ra :: [a] -> [a] -> ([a], [a])
ra xs ys = (rotateRight xs, ys)

rb :: [a] -> [a] -> ([a], [a])
rb xs ys = (xs, rotateRight ys)

rr :: [a] -> [a] -> ([a], [a])
rr xs ys = (rotateRight xs, rotateRight ys)

rra :: [a] -> [a] -> ([a], [a])
rra xs ys = (rotateLeft xs, ys)

rrb :: [a] -> [a] -> ([a], [a])
rrb xs ys = (xs, rotateLeft ys)

rrr :: [a] -> [a] -> ([a], [a])
rrr xs ys = (rotateLeft xs, rotateLeft ys)

