{-
-- EPITECH PROJECT, 2023
-- B-PDG-300-REN-3-1-PDGD01-mael.becel
-- File description:
-- Haskell
-}

import System.Environment
import System.Exit

isNumber :: [Char] -> Bool
isNumber [] = True
isNumber ('-':[]) = False
isNumber ('-':xs)
    | (head(xs) <= '9' || head(xs) >= '0') = isNumber xs
isNumber (x:xs)
    | x >= '0' && x <= '9' = isNumber xs
    | otherwise = False

safeNth :: [String] -> Int -> String
safeNth [] _ = ""
safeNth (x:xs) n =
    if n == 0 then x
    else safeNth xs (n - 1)

doOperand :: Int -> Char -> Int -> String
doOperand a '/' 0 = error "Division by zero"
doOperand a '%' 0 = error "Modulo by zero"
doOperand a '+' b = show (a + b)
doOperand a '-' b = show (a - b)
doOperand a '*' b = show (a * b)
doOperand a '/' b = show (a `div` b)
doOperand a '%' b = show (a `mod` b)
doOperand a op b = error ("Unknown operator " ++ "'" ++ [op] ++ "'")

errorHandle :: [String] -> Bool
errorHandle [] = True
errorHandle (x:xs)
    | (length xs) /= 2 = True
    | (length (safeNth xs 0)) /= 1 = True
    | (safeNth xs 0) == "/" && (safeNth xs 1) == "0" = True
    | (safeNth xs 0) == "%" && (safeNth xs 1) == "0" = True
    | isNumber x == False || isNumber (safeNth xs 1) == False = True
    | otherwise = False

main :: IO ()
main = do
    args <- getArgs
    if (errorHandle args) then exitWith (ExitFailure 84)
    else putStrLn (doOperand (read (safeNth args 0) :: Int)
        (head (safeNth args 1)) (read (safeNth args 2) :: Int))