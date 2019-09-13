module P1200 (goOrStay) where

import Data.List

letter :: Char -> Int
letter c = maybe undefined (\x -> x) (elemIndex c ['A'..'Z']) + 1

-- Name of the Star -> Name of the team -> Go or Stay
goOrStay :: String -> String -> IO ()
goOrStay s t = putStrLn $ if eval s == eval t then "Go" else "Stay"

eval :: String -> Int
eval s = foldr (\a b -> b * (letter a)) 1 s `mod` 47
