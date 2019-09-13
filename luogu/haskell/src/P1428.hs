module P1428 (main)  where

main :: [Int] -> [Int]
main = cute []

-- Left Side Fishes -> Others Fishes -> Not Cuter Then Themself
cute :: [Int] -> [Int] -> [Int]
cute _ [] = []
cute xs (f:fs) = cuteValue : cute (xs ++ [f]) fs
  where
    cuteValue = foldr (\x c -> if f > x then c + 1 else c) 0 xs
