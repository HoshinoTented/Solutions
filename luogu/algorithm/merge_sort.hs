module MergeSort where

import Data.List

-- List ->  Sorted List
mergeSort :: (Eq a, Ord a) => [a] -> [a]
mergeSort (x:[]) = [x]
mergeSort xs = merge (mergeSort $ fst subs) (mergeSort $ snd subs)
  where
    mid = length xs `div` 2
    subs = splitAt mid xs
  

-- Sequence -> Other Sequence -> Merged
merge :: (Eq a, Ord a) => [a] -> [a] -> [a]
merge [] ys = ys
merge xs [] = xs
merge (x:xs) (y:ys) = if x < y then x : merge xs (y:ys) else y : merge (x:xs) ys

  

