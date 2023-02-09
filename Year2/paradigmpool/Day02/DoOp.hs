{-
-- EPITECH PROJECT, 2023
-- B-PDG-300-REN-3-1-PDGD01-mael.becel
-- File description:
-- Haskell
-}

-- Task 01 --
myElem :: Eq a => a -> [a] -> Bool
myElem _ [] = False
myElem x (y:ys) =
    if x == y then True
    else myElem x ys

-- Task 02 --
safeDiv :: Int -> Int -> Maybe Int
safeDiv _ 0 = Nothing
safeDiv a b = Just (a `div` b)

-- Task 03 --
safeNth :: [a] -> Int -> Maybe a
safeNth [] _ = Nothing
safeNth (x:xs) n =
    if n == 0 then Just x
    else safeNth xs (n - 1)

-- Task 04 --
safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc (Just x) = Just (x + 1)

-- Task 05 --
myLookup :: Eq a => a -> [(a,b)] -> Maybe b
myLookup _ [] = Nothing
myLookup x ((a, b):xs) =
    if x == a then Just b
    else myLookup x xs

-- Task 06 --
maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo _ Nothing _ = Nothing
maybeDo _ _ Nothing = Nothing
maybeDo f (Just x) (Just y) = Just (f x y)

-- Task 07 --

isNumber :: [Char] -> Bool
isNumber [] = True
isNumber ('-':[]) = False
isNumber ('-':xs)
    | (head(xs) <= '9' || head(xs) >= '0') = isNumber xs
isNumber (x:xs)
    | x >= '0' && x <= '9' = isNumber xs
    | otherwise = False


readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt a
    | isNumber a = Just (read a :: Int)
    | otherwise = Nothing


-- Task 08 --
-- fmap :: (a -> b) -> f a -> f b
-- fmap :: (String -> Int) -> IO String -> IO Int
getLineLength :: IO Int
getLineLength = fmap length getLine

-- Task 09 --
printAndGetLength :: String -> IO Int
printAndGetLength x = putStrLn x >> return (length x)


-- Task 10 --
drawMiddle :: Int -> String -> IO ()
drawMiddle x str =
    if x <= 0 then return ()
    else putStrLn str >> drawMiddle (x - 1) str

printBox :: Int -> IO ()
printBox 1 = putStrLn "++"
printBox 0 = return ()
printBox n =
    if n <= 0 then putStr ""
    else putStrLn ("+" ++ replicate ((n - 1) * 2 ) '-' ++ "+") >>
    drawMiddle (n - 2) ("|" ++ replicate ((n - 1) * 2 ) ' ' ++ "|") >>
    putStrLn ("+" ++ replicate ((n - 1) * 2 ) '-' ++ "+")

-- Task 11 --
concatLines :: Int -> IO String
concatLines 0 = return ""
concatLines n = getLine >>= \x -> concatLines (n - 1) >>= \y -> return (x ++ y)

-- Task 12 --
getInt :: IO (Maybe Int)
getInt = do
    x <- getLine
    return (readInt x)