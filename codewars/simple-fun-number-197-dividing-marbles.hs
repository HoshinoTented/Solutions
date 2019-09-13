module DividingMarbles.Kata (dividingMarbles) where

type Marbles = (Int,Int,Int,Int,Int,Int)
             
sumOf :: Marbles -> Int
sumOf (a, b, c, d, e, f) = a * 1 + b * 2 + c * 3 + d * 4 + e * 5 + f * 6

search :: Int -> [(Int, Int)] -> Bool
search 0 _ = True
search _ [] = False
search n ((0, w):s) = search n s
search n ((x, w):s) = if not $ search (n - w) $ (x - 1, w) : s then search n s else True

toList :: Marbles -> [(Int, Int)]
toList (a, b, c, d, e, f) = zip ms [1..6]
  where
    ms = [a, b, c, d, e, f]
  
dividingMarbles :: Marbles -> Bool
dividingMarbles marbles
  | odd sum =  False
  | foldr ((&&) . even . fst) True ls = True
  | otherwise = search (div sum 2) $ toList marbles
  where
    sum = sumOf marbles
    ls = toList marbles
