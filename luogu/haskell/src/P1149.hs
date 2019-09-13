module P1149 where

import Data.Char

-- number :: Number -> Stick count
number :: Int -> Int
number 0 = 6
number 1 = 2
number 2 = 5
number 3 = 5
number 4 = 4
number 5 = 5
number 6 = 6
number 7 = 3
number 8 = 7
number 9 = 6
number num = sum $ map (\c -> number $ ord c - ord '0') $ show num

search :: Int -> Int
search max = foldr (\i s -> s + foldr (\j s' -> if number i + number j + number (i + j) == max then s' + 1 else s') 0 [0..1000]) 0 [0..1000]

main :: IO ()
main = do
    n <- read <$> getLine

    print $ search n - 4