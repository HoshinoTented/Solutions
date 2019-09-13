module Codewars.Kata.Combos where

combos' :: Int -> Int -> [[Int]]
combos' _ 0 = [[]]
combos' last n = foldr (\i l -> foldr (\j l' -> (i : j) : l') [] (combos' i (n - i)) ++ l) [] [last..n]

combos :: Int -> [[Int]]
combos = combos' 1
